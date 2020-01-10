import numpy as np
from scipy.optimize import curve_fit
from math import sqrt

class Mirror:
    """
    Represents a Telescope Parabolic Mirror and the tools to analyse it.
    """

    def __init__(self, name, diameter, K, RoC):
		self.mirror_details = {'name': "", 'diameter': 0, 'user_defined_K': 0, 'user_defined_RoC': 0, 'best_fit_d': 0, 'best_fit_K': 0, 'best_fit_RoC': 0}
        self.mirror_details['name'] = name
        self.mirror_details['diameter'] = diameter

        self.mirror_details['user_defined_K'] = K
        self.mirror_details['user_defined_RoC'] = RoC

        self.mirror_details['best_fit_d'] = 0.0
        self.mirror_details['best_fit_K'] = self.user_defined_K
        self.mirror_details['best_fit_RoC'] = self.user_defined_RoC
		
		
        self.test_measurements

    def set_parameter(self):
        #TBD
		#https://docs.python.org/3/tutorial/controlflow.html#unpacking-argument-lists
		#https://docs.python.org/3/tutorial/datastructures.html#tut-tuples
        print("TBD")

    def get_parameter(self):
        #TBD
        print("TBD")

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


