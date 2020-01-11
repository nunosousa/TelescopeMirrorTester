import numpy as np
from scipy.optimize import curve_fit
from math import sqrt


class Mirror:
    """
    Represents a Telescope Parabolic Mirror and the tools to analyse it.
    """
    def __init__(self, name, diameter, radius_of_curvature):
        self.mirror_details = {'name': name, 'diameter': diameter, 'expected_k': -1.0,
                               'expected_radius_of_curvature': radius_of_curvature,
                               'best_fit_d': 0.0, 'best_fit_k': -1.0, 'best_fit_radius_of_curvature': radius_of_curvature}

        self.test_measurement_data_f = np.array([])
        self.test_measurement_data_r = np.array([])

    def set_parameter(self, parameter, value):
        if parameter in self.mirror_details:
            self.mirror_details[parameter] = value

    def get_parameter(self, parameter):
        if parameter in self.mirror_details:
            return self.mirror_details[parameter]

    def set_test_measurement_data(self, r, f):
        self.test_measurement_data_f = r
        self.test_measurement_data_r = f

    def find_best_fit_conic(self):
        """
        Find the best fit conic for the given test data and desired mirror parameters.
        """
        f_plus_radius_of_curvature = self.test_measurement_data_f + self.mirror_details['expected_radius_of_curvature']
        p0 = np.array([0.0, self.mirror_details['expected_k'], self.mirror_details['expected_radius_of_curvature']])

        popt = curve_fit(self.aspheric_surface_function,
                         self.test_measurement_data_r,
                         f_plus_radius_of_curvature,
                         p0, None, False, True)

        return popt

    def aspheric_surface_function(self, r, d, k, radius_of_curvature):
        """
        Representation of the aspheric surface function.
        """

        l = np.sqrt(radius_of_curvature * radius_of_curvature - (1 + k) * np.multiply(r, r))
        a = np.multiply((radius_of_curvature + l), (radius_of_curvature + l))
        b = 2 * (radius_of_curvature + l)
        c = np.divide((1 + k) * np.multiply(r, r), l)
        e = np.divide(np.multiply(r, r), radius_of_curvature + l)

        f = np.divide(a, np.add(b, c))
        f = np.add(f, e) + d

        return f

    def aspheric_surface_function_jacobian(self, function_parameters, function_input, function_output):
        """
        Representation of the aspheric surface jacobian function.
        """

        return 0
