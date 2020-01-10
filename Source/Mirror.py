class Mirror:
    """
    Represents a Telescope Parabolic Mirror and the tools to analyse it.
    """

    # class attributes
    name = ""
    diameter = 1.0
    
    best_fit_d = 0.0
    best_fit_K = 0.0
    best_fit_RoC = 1.0
    
    user_defined_K = 0.0
    user_defined_RoC = 0.0
    
    def __init__(self, name, diameter, K, RoC):
        self.name = name
        self.diameter = diameter
        self.user_defined_K = K
        self.user_defined_RoC = RoC

    def set(self):
        #TBD
        print("TBD")

    def get(self):
        #TBD
        print("TBD")

    def aspheric_surface_function(self, function_parameters, function_input, function_output):
        #TBD
        print("TBD")
        
    def aspheric_surface_function_jacobian(self, function_parameters, function_input, function_output):
        #TBD
        print("TBD")


