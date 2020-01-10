from Mirror import Mirror
import numpy as np
import matplotlib.pyplot as pyplot


test = 167

mirror_name = "My Telescope Mirror"
mirror_diameter = 203.5
mirror_radius_of_curvature = 2132.0

if test == 158:
    # Test data - Test 158
    f = np.array([42.80, 45.50, 48.06, 52.01, 55.00, 58.03, 61.29, 63.66, 65.85, 70.51, 71.83, 76.65, 78.26])
    r = np.array([0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 0.90, 1.00, 1.10, 1.20, 1.30, 1.40])

if test == 167:
    # Test data - Test 167
    f = np.array([0.60, 0.70, 0.80, 0.90, 1.00, 1.10, 1.20, 1.30, 1.40, 1.45, 1.50, 1.55, 1.60, 1.65, 1.70, 1.75, 1.80, 1.85, 1.90, 1.95, 2.00])
    r = np.array([49.14, 52.85, 55.22, 61.06, 65.42, 68.53, 72.53, 74.06, 76.96, 78.39, 79.91, 81.06, 82.16, 84.38, 85.83, 87.21, 89.09, 90.55, 92.70, 95.68, 99.52])

my_telescope_mirror = Mirror(mirror_name, mirror_diameter, mirror_radius_of_curvature)
my_telescope_mirror.set_test_measurement_data(r, f)
my_telescope_mirror.set_parameter("expected_k", -1.0)
my_telescope_mirror.find_best_fit_conic()

pyplot.plot(r, f)
pyplot.show()
