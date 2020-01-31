import numpy as np
from scipy.integrate import solve_ivp
from scipy.optimize import curve_fit
from scipy import interpolate


def aspheric_surface_offset_function(r, d, k, radius_of_curvature):
    """
    Representation of the aspheric surface function.
    """
    fraction_1 = np.divide(np.power(r, 2), radius_of_curvature * (
            np.sqrt(1 - ((k + 1) / (radius_of_curvature * radius_of_curvature)) * np.power(r, 2)) + 1))
    fraction_2 = radius_of_curvature * np.sqrt(
        1 - ((k + 1) / (radius_of_curvature * radius_of_curvature)) * np.power(r, 2))

    return np.add(fraction_1, fraction_2) + d


def aspheric_surface_offset_function_jacobian(r, d, k, radius_of_curvature):
    """
    Representation of the aspheric surface jacobian function.
    """
    sample_number = r.size

    l = np.sqrt(np.negative((k * np.power(r, 2) - radius_of_curvature * radius_of_curvature + np.power(r, 2)) / (
            radius_of_curvature * radius_of_curvature)))

    # Partial derivative on d
    part_div_d = np.ones(sample_number)

    # Partial derivative on k
    num = np.multiply(np.power(r, 2), np.add((2 * radius_of_curvature * radius_of_curvature * l),
                                             np.add(np.negative(k * np.power(r, 2)),
                                                    2 * (radius_of_curvature * radius_of_curvature - np.power(r, 2)))))
    den = 2 * radius_of_curvature * radius_of_curvature * radius_of_curvature * np.multiply(l, np.power(l + 1, 2))

    part_div_k = np.negative(np.divide(num, den))

    # Partial derivative on the radius of curvature
    num = np.add(np.multiply(2 * radius_of_curvature * radius_of_curvature - np.power(r, 2), l),
                 np.add(np.negative(k * np.power(r, 2)),
                        2 * (radius_of_curvature * radius_of_curvature - np.power(r, 2))))

    den = radius_of_curvature * radius_of_curvature * np.multiply(l, np.power(l + 1, 2))

    part_div_r_o_c = np.divide(num, den) # check if this makes sence
    #part_div_r_o_c = np.zeros(sample_number)

    jacobian_vector = np.vstack((part_div_d, part_div_k, part_div_r_o_c))
    jacobian_vector = np.transpose(jacobian_vector)

    return jacobian_vector


def aspheric_surface_equation(r, d, k, radius_of_curvature):
    """
    Representation of the aspheric surface function.
    """
    l = np.sqrt((radius_of_curvature * radius_of_curvature) - ((1 + k) * np.multiply(r, r)))

    num = np.multiply(r, r)
    den = radius_of_curvature + l
    z = num / den + d

    return z


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
        self.mirror_details = {'name': name, 'diameter': diameter,
                               'expected_k': -1.0,
                               'expected_radius_of_curvature': radius_of_curvature,
                               'best_fit_d': 0.0, 'best_fit_k': -1.0,
                               'best_fit_radius_of_curvature': radius_of_curvature}

        self.test_measurement_data_r = np.array([])
        self.test_measurement_data_f = np.array([])
        self.test_measurement_data_f_standard_deviation = np.array([])

        self.sample_points_number = 100

    def set_parameter(self, parameter, value):
        if parameter in self.mirror_details:
            self.mirror_details[parameter] = value

    def get_parameter(self, parameter):
        if parameter in self.mirror_details:
            return self.mirror_details[parameter]

    def set_test_measurement_data(self, r, f, f_std):
        self.test_measurement_data_r = r
        self.test_measurement_data_f = f
        self.test_measurement_data_f_standard_deviation = f_std

    def find_best_fit_conic(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        f_plus_radius_of_curvature = self.test_measurement_data_f + self.mirror_details['expected_radius_of_curvature']

        p0 = np.array([0.0, self.mirror_details['expected_k'], self.mirror_details['expected_radius_of_curvature']])
        
        p_scale = np.array([0.001, 1, self.mirror_details['expected_radius_of_curvature']])

        best_fit_parameters, estimated_covariance = curve_fit(f=aspheric_surface_offset_function,
                                                              xdata=self.test_measurement_data_r,
                                                              ydata=f_plus_radius_of_curvature,
                                                              p0=p0,
                                                              sigma=self.test_measurement_data_f_standard_deviation,
                                                              absolute_sigma=True,
                                                              check_finite=True,
                                                              method="trf",
                                                              jac=aspheric_surface_offset_function_jacobian,
                                                              x_scale=p_scale,#"jac",
                                                              loss="soft_l1",
                                                              verbose=2)

        p_standard_deviation = np.sqrt(np.diag(estimated_covariance))

        self.mirror_details['best_fit_d'] = best_fit_parameters[0]
        self.mirror_details['best_fit_k'] = best_fit_parameters[1]
        self.mirror_details['best_fit_radius_of_curvature'] = best_fit_parameters[2]

        return best_fit_parameters, p_standard_deviation

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
                   np.reshape(ode_solution.y, (-1)))

        return results

    def generate_best_fit_conic_offset_samples(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        r_sample_points = np.linspace(0.1, self.mirror_details['diameter'] / 2, num=self.sample_points_number)

        f_sample_points = aspheric_surface_offset_function(r_sample_points,
                                                           self.mirror_details['best_fit_d'],
                                                           self.mirror_details['best_fit_k'],
                                                           self.mirror_details['best_fit_radius_of_curvature'])
        
        best_fit_offset = self.mirror_details['best_fit_radius_of_curvature'] + self.mirror_details['best_fit_d'] - self.mirror_details['expected_radius_of_curvature']

        return r_sample_points, \
               f_sample_points - self.mirror_details['best_fit_radius_of_curvature'] - self.mirror_details['best_fit_d'] + best_fit_offset

    def generate_desired_conic_offset_samples(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        r_sample_points = np.linspace(0.1, self.mirror_details['diameter'] / 2, num=self.sample_points_number)

        f_sample_points = aspheric_surface_offset_function(r_sample_points, 0.0,
                                                           self.mirror_details['expected_k'],
                                                           self.mirror_details['expected_radius_of_curvature'])

        return r_sample_points, f_sample_points - self.mirror_details['expected_radius_of_curvature']

    def generate_best_fit_conic_samples(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        r_sample_points = np.linspace(0.0, self.mirror_details['diameter'] / 2, num=self.sample_points_number)

        z_sample_points = aspheric_surface_equation(r_sample_points,
                                                    0.0,  # self.mirror_details['best_fit_d'],
                                                    self.mirror_details['best_fit_k'],
                                                    self.mirror_details['best_fit_radius_of_curvature'])

        return r_sample_points, z_sample_points

    def generate_desired_conic_samples(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        r_sample_points = np.linspace(0.0, self.mirror_details['diameter'] / 2, num=self.sample_points_number)

        z_sample_points = aspheric_surface_equation(r_sample_points, 0.0,
                                                    self.mirror_details['expected_k'],
                                                    self.mirror_details['expected_radius_of_curvature'])

        return r_sample_points, z_sample_points
