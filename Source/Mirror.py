import numpy as np
from scipy.optimize import curve_fit
from math import sqrt


class Mirror:
    """
    Represents a Telescope Parabolic Mirror and the tools to analyse it.
    """

    def __init__(self, name, diameter, k, radius_of_curvature):
        self.mirror_details = {'name': name, 'diameter': diameter, 'user_defined_K': k,
                               'user_defined_RoC': radius_of_curvature,
                               'best_fit_d': 0.0, 'best_fit_K': k, 'best_fit_RoC': radius_of_curvature}

        #self.test_measurements

def set_parameter(self, parameter):
    # TBD
    # https://docs.python.org/3/tutorial/controlflow.html#unpacking-argument-lists
    # https://docs.python.org/3/tutorial/datastructures.html#tut-tuples

    # if parameter in self.mirror_details
    # self.mirror_details[parameter] = parameter
    pass


def get_parameter(self, parameter):
    pass


def find_best_fit_conic(self):
    """
    Find the best fit conic for the given test data and desired mirror parameters.
    """

    curve_fit(aspheric_surface_function)


def aspheric_surface_function(self, r, d, K, RoC):
    """
    Representation of the aspheric surface function.
    """
    l = sqrt(RoC * RoC - (1 + K) * r * r)
    f = ((RoC + l) * (RoC + l)) / (2 * (RoC + l) + ((1 + K) * r * r) / l)
    f = f + (r * r) / (RoC + l)
    f = f + d

    return f


def aspheric_surface_function_jacobian(self, function_parameters, function_input, function_output):
    """
    Representation of the aspheric surface jacobian function.
    """

    return 0
