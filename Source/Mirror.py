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

        curve_fit(self.aspheric_surface_function)

    def aspheric_surface_function(self, r, d, k, radius_of_curvature):
        """
        Representation of the aspheric surface function.
        """
        l = sqrt(radius_of_curvature * radius_of_curvature - (1 + k) * r * r)
        f = ((radius_of_curvature + l) * (radius_of_curvature + l)) / (2 * (radius_of_curvature + l) + ((1 + k) * r * r) / l)
        f = f + (r * r) / (radius_of_curvature + l)
        f = f + d

        return f

    def aspheric_surface_function_jacobian(self, function_parameters, function_input, function_output):
        """
        Representation of the aspheric surface jacobian function.
        """

        return 0
