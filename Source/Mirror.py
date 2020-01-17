import numpy as np
from scipy.integrate import solve_ivp
from scipy.optimize import curve_fit
from scipy import interpolate


def aspheric_surface_function(r, d, k, radius_of_curvature):
    """
    Representation of the aspheric surface function.
    """
    l = np.sqrt((radius_of_curvature * radius_of_curvature) - ((1 + k) * np.multiply(r, r)))

    num_1_a = np.multiply((radius_of_curvature + l), (radius_of_curvature + l))
    den_1_a = 2 * (radius_of_curvature + l)
    den_1_b = np.divide((1 + k) * np.multiply(r, r), l)

    frac_1 = np.divide(num_1_a, np.add(den_1_a, den_1_b))
    frac_2 = np.divide(np.multiply(r, r), radius_of_curvature + l)

    return np.add(frac_1, frac_2) + d


def aspheric_surface_function_jacobian(r, d, k, radius_of_curvature):
    """
    Representation of the aspheric surface jacobian function.
    """
    sample_number = r.size

    l = np.sqrt((radius_of_curvature * radius_of_curvature) - ((1 + k) * np.multiply(r, r)))

    # Partial derivative on d
    part_div_d = np.negative(np.ones(sample_number))

    # Partial derivative on k
    num_k_1_a = radius_of_curvature + l
    num_k_1_b = np.divide(np.multiply(r, r), l)
    num_k_1_c = 2 * (radius_of_curvature + l)
    num_k_1_d = np.divide((1 + k) * np.multiply(r, r), l)
    num_k_1_e = np.multiply(r, r)
    num_k_1_f = np.multiply(radius_of_curvature + l, radius_of_curvature + l)
    num_k_1_g = np.divide(np.add(l, (1 + k) * np.reciprocal(2 * l)), np.multiply(l, l))
    num_k_1_h = np.reciprocal(l)
    num_k_1_A = np.multiply(np.multiply(num_k_1_a, num_k_1_b), np.add(num_k_1_c, num_k_1_d))
    num_k_1_B = np.multiply(np.multiply(num_k_1_e, num_k_1_f), np.subtract(num_k_1_g, num_k_1_h))
    num_k_1 = np.add(num_k_1_A, num_k_1_B)

    den_k_1_a = 2 * (radius_of_curvature + l)
    den_k_1_b = np.divide((1 + k) * np.multiply(r, r), l)
    den_k_1 = np.multiply(np.add(den_k_1_a, den_k_1_b), np.add(den_k_1_a, den_k_1_b))

    num_k_2 = np.multiply(r, np.multiply(r, np.multiply(r, r)))
    den_k_2 = 2 * np.multiply(l, np.multiply(radius_of_curvature + l, radius_of_curvature + l))

    part_div_k = np.subtract(np.divide(num_k_2, den_k_2), np.divide(num_k_1, den_k_1))

    # Partial derivative on the radius of curvature
    num_r_o_c_1_a = 2 * (radius_of_curvature + l)
    num_r_o_c_1_b = 1 + (radius_of_curvature * np.reciprocal(l))
    num_r_o_c_1_c = 2 * (radius_of_curvature + l)
    num_r_o_c_1_d = np.divide((1 + k) * np.multiply(r, r), l)
    num_r_o_c_1_e = np.multiply(radius_of_curvature + l, radius_of_curvature + l)
    num_r_o_c_1_f = 2 + (2 * radius_of_curvature * np.reciprocal(l))
    num_r_o_c_1_g = np.divide(radius_of_curvature * (1 + k) * np.multiply(r, r), np.multiply(l, np.multiply(l, l)))
    num_r_o_c_1_A = np.multiply(num_r_o_c_1_a, np.multiply(num_r_o_c_1_b, np.add(num_r_o_c_1_c, num_r_o_c_1_d)))
    num_r_o_c_1_B = np.multiply(num_r_o_c_1_e, np.subtract(num_r_o_c_1_f, num_r_o_c_1_g))
    num_r_o_c_1 = np.subtract(num_r_o_c_1_A, num_r_o_c_1_B)

    den_r_o_c_1_a = 2 * (radius_of_curvature + l)
    den_r_o_c_1_b = np.divide((1 + k) * np.multiply(r, r), l)
    den_r_o_c_1 = np.multiply(np.add(den_r_o_c_1_a, den_r_o_c_1_b), np.add(den_r_o_c_1_a, den_r_o_c_1_b))

    num_r_o_c_2 = np.multiply(np.multiply(r, r), 1 + (radius_of_curvature * np.reciprocal(l)))
    den_r_o_c_2 = np.multiply(radius_of_curvature + l, radius_of_curvature + l)

    part_div_r_o_c = np.subtract(np.divide(num_r_o_c_1, den_r_o_c_1), np.divide(num_r_o_c_2, den_r_o_c_2))

    jacobian_vector = np.vstack((part_div_d, part_div_k, part_div_r_o_c))
    jacobian_vector = np.transpose(jacobian_vector)

    return jacobian_vector


def aspheric_surface_ode(r, z, f):
    """
    Representation of the aspheric surface function.
    """
    dz = np.divide(r, np.subtract(f, z))

    return dz


class Mirror:
    """
    Represents a Telescope Parabolic Mirror and the tools to analyse it.
    """

    def __init__(self, name, diameter, radius_of_curvature):
        self.mirror_details = {'name': name, 'diameter': diameter, 'expected_k': -1.0,
                               'expected_radius_of_curvature': radius_of_curvature,
                               'best_fit_d': 0.0, 'best_fit_k': -1.0,
                               'best_fit_radius_of_curvature': radius_of_curvature}

        self.test_measurement_data_f = np.array([])
        self.test_measurement_data_r = np.array([])

        self.sample_points_number = 100

    def set_parameter(self, parameter, value):
        if parameter in self.mirror_details:
            self.mirror_details[parameter] = value

    def get_parameter(self, parameter):
        if parameter in self.mirror_details:
            return self.mirror_details[parameter]

    def set_test_measurement_data(self, r, f):
        self.test_measurement_data_r = r
        self.test_measurement_data_f = f

    def find_best_fit_conic(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        f_plus_radius_of_curvature = self.test_measurement_data_f + self.mirror_details['expected_radius_of_curvature']
        p0 = np.array([0.0, self.mirror_details['expected_k'], self.mirror_details['expected_radius_of_curvature']])

        best_fit_parameters, estimated_covariance = curve_fit(f=aspheric_surface_function,
                                                              xdata=self.test_measurement_data_r,
                                                              ydata=f_plus_radius_of_curvature,
                                                              p0=p0,
                                                              check_finite=True,
                                                              method="lm",
                                                              jac=aspheric_surface_function_jacobian)

        self.mirror_details['best_fit_d'] = best_fit_parameters[0]
        self.mirror_details['best_fit_k'] = best_fit_parameters[1]
        self.mirror_details['best_fit_radius_of_curvature'] = best_fit_parameters[2]

        return best_fit_parameters

    def test_measurement_data_analysis(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        f_plus_radius_of_curvature = self.test_measurement_data_f + self.mirror_details['expected_radius_of_curvature']

        test_data_interpolation_function = interpolate.interp1d(self.test_measurement_data_r,
                                                                f_plus_radius_of_curvature,
                                                                kind="cubic",
                                                                fill_value="extrapolate")

        r_sample_points = np.linspace(0.0, self.mirror_details['diameter'] / 2, num=self.sample_points_number)

        f_test_data_interpolated_points = test_data_interpolation_function(r_sample_points)

        ode_solution = solve_ivp(fun=lambda r, z: aspheric_surface_ode(r, z, test_data_interpolation_function(r)),
                                 t_span=[r_sample_points[0], r_sample_points[-1]],
                                 y0=[0.0],
                                 method="RK45",
                                 t_eval=r_sample_points,
                                 dense_output=True)

        results = (r_sample_points,
                   f_test_data_interpolated_points - self.mirror_details['expected_radius_of_curvature'],
                   np.transpose(ode_solution.y))

        return results

    def generate_best_fit_conic_samples(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        r_sample_points = np.linspace(0.1, self.mirror_details['diameter'] / 2, num=self.sample_points_number)

        f_sample_points = aspheric_surface_function(r_sample_points,
                                                    self.mirror_details['best_fit_d'],
                                                    self.mirror_details['best_fit_k'],
                                                    self.mirror_details['best_fit_radius_of_curvature'])

        return r_sample_points, f_sample_points - self.mirror_details['best_fit_radius_of_curvature']

    def generate_desired_conic_samples(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        r_sample_points = np.linspace(0.1, self.mirror_details['diameter'] / 2, num=self.sample_points_number)

        f_sample_points = aspheric_surface_function(r_sample_points, 0.0,
                                                    self.mirror_details['expected_k'],
                                                    self.mirror_details['expected_radius_of_curvature'])

        return r_sample_points, f_sample_points - self.mirror_details['expected_radius_of_curvature']
