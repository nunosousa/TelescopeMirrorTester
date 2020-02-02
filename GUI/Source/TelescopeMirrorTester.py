from Mirror import Mirror
import numpy as np
import matplotlib.pyplot as pyplot

test = 213

mirror_name = "My Telescope Mirror"
mirror_diameter = 203.5
mirror_radius_of_curvature = 2132.0
conic_constant = -1.0
best_fit_vertex_offset = 0.0
roc_std = 5.0
foucault_std = 0.02

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

if test == 213:
    # Test data - Test 213 b
    r = np.array(
        [5.73, 31.02, 38.87, 45.63, 49.60, 50.95, 53.56, 56.14, 59.10, 62.95, 66.45, 70.51, 74.62, 77.33, 78.90, 81.57,
         84.55, 86.39, 89.15, 91.90, 95.27, 97.36])
    f = np.array(
        [0.00, 0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 0.90, 1.00, 1.10, 1.20, 1.30, 1.40, 1.50, 1.60, 1.70,
         1.80, 1.90, 2.00, 2.10])

# Create mirror object and set desired parameters
my_telescope_mirror = Mirror(mirror_name, mirror_diameter, mirror_radius_of_curvature)
my_telescope_mirror.set_parameter("expected_k", conic_constant)

# Set test data
measurements_std = np.ones(f.size) * foucault_std
measurements_std[0] = roc_std
my_telescope_mirror.set_test_measurement_data(r, f, measurements_std)

# Run best fit algorithm directly based on test data (Foucault/Wire offsets)
raw_data_best_fit_parameters, p_std = my_telescope_mirror.find_best_fit_conic_on_offset_data()

# Generate data vectors for plotting
# Radius of curvature
best_fit_r_sample_points, best_fit_f_sample_points = my_telescope_mirror.generate_best_fit_conic_offset_samples()
expected_r_sample_points, expected_f_sample_points = my_telescope_mirror.generate_desired_conic_offset_samples()
# Mirror profile
# - Integrated
r_interpolated, f_interpolated, mirror_profile = my_telescope_mirror.integrate_mirror_test_data()
# - From expected parameters
expected_r_sample_points, expected_z_sample_points = my_telescope_mirror.generate_desired_conic_samples()
# - From raw data best fit parameters
best_fit_r_sample_points, raw_data_best_fit_z_sample_points = my_telescope_mirror.generate_best_fit_conic_samples()

# Run best fit algorithm based on integrated (mirror profile) test data
integrated_data_best_fit_parameters, p_std = my_telescope_mirror.find_best_fit_conic_on_integrated_data()

# Generate data vectors for plotting
# Mirror profile
# - From raw data best fit parameters
best_fit_r_sample_points, integrated_best_fit_z_sample_points = my_telescope_mirror.generate_best_fit_conic_samples()

# Display results ------------------------------------------------------------------------------------------------------
pyplot.figure(1)

# Plot test measurement data, best fit curve and interpolated data
pyplot.subplot(1, 2, 1)
pyplot.title('Foucault/Wire test results')
pyplot.plot(expected_r_sample_points, expected_f_sample_points, "b-",
            label="Expected curve (d = {:+.3f}, k = {:+.3f}, RoC = {:+.3f})".format(0.0,
                                                                                    my_telescope_mirror.get_parameter(
                                                                                        "expected_k"),
                                                                                    my_telescope_mirror.get_parameter(
                                                                                        "expected_radius_of_curvature")))
pyplot.plot(best_fit_r_sample_points, best_fit_f_sample_points, "r-",
            label="Best fit curve (d = {:+.3f}, k = {:+.3f}, RoC = {:+.3f})".format(raw_data_best_fit_parameters[0],
                                                                                    raw_data_best_fit_parameters[1],
                                                                                    raw_data_best_fit_parameters[2]))
pyplot.scatter(r, f, label="Raw test data")
pyplot.plot(r_interpolated, f_interpolated, "g-", label="Raw test data (interpolated)")
pyplot.xlabel('Mirror radius [mm]')
pyplot.ylabel('Foucault/Wire test offsets [mm]')
pyplot.legend()

pyplot.subplot(1, 2, 2)
pyplot.title('Foucault/Wire test error')
pyplot.plot(best_fit_r_sample_points, np.subtract(f_interpolated, best_fit_f_sample_points), "r-",
            label="Raw test data - Best fit curve")
pyplot.plot(best_fit_r_sample_points, np.zeros(f_interpolated.size), "k--")
pyplot.xlabel('Mirror radius [mm]')
pyplot.ylabel('Foucault/Wire test offset error [mm]')
pyplot.legend()

# Display results ------------------------------------------------------------------------------------------------------
pyplot.figure(2)

# Plot mirror profile
pyplot.subplot(2, 2, 1)
pyplot.title('Mirror profile error (based on raw data)')
pyplot.plot(r_interpolated, np.subtract(mirror_profile, raw_data_best_fit_z_sample_points), "r-",
            label="Best fit error curve (d = {:+.3f}, k = {:+.3f}, RoC = {:+.3f})".format(
                raw_data_best_fit_parameters[0],
                raw_data_best_fit_parameters[1],
                raw_data_best_fit_parameters[2]))
pyplot.plot(r_interpolated, np.zeros(mirror_profile.size), "k--")
pyplot.xlabel('Mirror radius [mm]')
pyplot.ylabel('Mirror height [mm]')
pyplot.legend()

pyplot.subplot(2, 2, 2)
pyplot.title('Mirror profile error (based on integrated profile)')
pyplot.plot(r_interpolated, np.subtract(mirror_profile, integrated_best_fit_z_sample_points), "r-",
            label="Best fit error curve (d = {:+.3f}, k = {:+.3f}, RoC = {:+.3f})".format(
                integrated_data_best_fit_parameters[0],
                integrated_data_best_fit_parameters[1],
                integrated_data_best_fit_parameters[2]))
pyplot.plot(r_interpolated, np.zeros(mirror_profile.size), "k--")
pyplot.xlabel('Mirror radius [mm]')
pyplot.ylabel('Mirror height [mm]')
pyplot.legend()

pyplot.subplot(2, 1, 2)
pyplot.title('Mirror profile error')
pyplot.plot(r_interpolated, np.subtract(mirror_profile, expected_z_sample_points), "b-",
            label="Expected curve (d = {:+.3f}, k = {:+.3f}, RoC = {:+.3f})".format(0.0,
                                                                                    my_telescope_mirror.get_parameter(
                                                                                        "expected_k"),
                                                                                    my_telescope_mirror.get_parameter(
                                                                                        "expected_radius_of_curvature")))
pyplot.plot(r_interpolated, np.zeros(mirror_profile.size), "k--")
pyplot.xlabel('Mirror radius [mm]')
pyplot.ylabel('Mirror height [mm]')
pyplot.legend()

pyplot.show()
