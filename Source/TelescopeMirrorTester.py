from Mirror import Mirror
import numpy as np
import matplotlib.pyplot as pyplot

test = 167

mirror_name = "My Telescope Mirror"
mirror_diameter = 203.5
mirror_radius_of_curvature = 2132.0
conic_constant = -1.0
best_fit_vertex_offset = 0.0

if test == 158:
    # Test data - Test 158
    r = np.array([0.0, 42.80, 45.50, 48.06, 52.01, 55.00, 58.03, 61.29, 63.66, 65.85, 70.51, 71.83, 76.65, 78.26])
    f = np.array([0.0, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 0.90, 1.00, 1.10, 1.20, 1.30, 1.40])

if test == 167:
    # Test data - Test 167
    r = np.array(
        [0.0, 49.14, 52.85, 55.22, 61.06, 65.42, 68.53, 72.53, 74.06, 76.96, 78.39, 79.91, 81.06, 82.16, 84.38, 85.83,
         87.21, 89.09, 90.55, 92.70, 95.68, 99.52])
    f = np.array(
        [0.0, 0.60, 0.70, 0.80, 0.90, 1.00, 1.10, 1.20, 1.30, 1.40, 1.45, 1.50, 1.55, 1.60, 1.65, 1.70, 1.75, 1.80,
         1.85, 1.90, 1.95, 2.00])

if test == 1670:
    # Test data - Test 167
    r = np.array(
        [0.0, 49.14, 52.85, 55.22, 61.06, 65.42, 68.53, 72.53, 74.06, 76.96, 78.39, 79.91, 81.06, 82.16, 84.38, 85.83,
         87.21, 89.09, 90.55])
    f = np.array(
        [0.0, 0.60, 0.70, 0.80, 0.90, 1.00, 1.10, 1.20, 1.30, 1.40, 1.45, 1.50, 1.55, 1.60, 1.65, 1.70, 1.75, 1.80,
         1.85])

my_telescope_mirror = Mirror(mirror_name, mirror_diameter, mirror_radius_of_curvature)
my_telescope_mirror.set_parameter("expected_k", conic_constant)
my_telescope_mirror.set_parameter("expected_d", best_fit_vertex_offset)


roc_std = 5.0
foucault_std = 0.02
measurements_std = np.ones(f.size)*foucault_std
measurements_std[0] = roc_std

my_telescope_mirror.set_test_measurement_data(r, f, measurements_std)
best_fit_parameters, p_std = my_telescope_mirror.find_best_fit_conic()

print(p_std)

# Display results
pyplot.figure(1)

# Plot test measurement data, best fit curve and interpolated data
best_fit_r_sample_points, best_fit_f_sample_points = my_telescope_mirror.generate_best_fit_conic_offset_samples()
expected_r_sample_points, expected_f_sample_points = my_telescope_mirror.generate_desired_conic_offset_samples()
r_interpolated, f_interpolated, mirror_profile = my_telescope_mirror.test_measurement_data_analysis()

pyplot.subplot(2, 1, 1)
pyplot.title('Mirror measurement data')
pyplot.plot(expected_f_sample_points, expected_r_sample_points, "b-",
            label="Expected curve (d = {:+.3f}, k = {:+.3f}, RoC = {:+.3f})".format(my_telescope_mirror.get_parameter(
                                                                                        "expected_d"),
                                                                                    my_telescope_mirror.get_parameter(
                                                                                        "expected_k"),
                                                                                    my_telescope_mirror.get_parameter(
                                                                                        "expected_radius_of_curvature")))
pyplot.plot(best_fit_f_sample_points, best_fit_r_sample_points, "r-",
            label="Best fit curve (d = {:+.3f}, k = {:+.3f}, RoC = {:+.3f})".format(best_fit_parameters[0],
                                                                                    best_fit_parameters[1],
                                                                                    best_fit_parameters[2]))
pyplot.scatter(f, r, label="Collected test data")
pyplot.plot(f_interpolated, r_interpolated, "g-", label="Collected test data (interpolated)")
pyplot.ylabel('Mirror radius [mm]')
pyplot.xlabel('Foucault/Wire test offsets [mm]')
pyplot.legend()

# Plot mirror profile
best_fit_r_sample_points, best_fit_z_sample_points = my_telescope_mirror.generate_best_fit_conic_samples()
expected_r_sample_points, expected_z_sample_points = my_telescope_mirror.generate_desired_conic_samples()

pyplot.subplot(2, 1, 2)
pyplot.title('Mirror profile')
pyplot.plot(r_interpolated, np.subtract(mirror_profile, best_fit_z_sample_points), "b-",
            label="Mirror profile error (best fit)")
pyplot.plot(r_interpolated, np.subtract(mirror_profile, expected_z_sample_points), "r-",
            label="Mirror profile error (expected)")
pyplot.xlabel('Mirror radius [mm]')
pyplot.ylabel('Mirror height [mm]')
pyplot.legend()

pyplot.show()
