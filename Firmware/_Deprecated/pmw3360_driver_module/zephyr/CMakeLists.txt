if(CONFIG_DAC_MCP4716)
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(pmw3360.c)
  zephyr_library_sources(pmw3360_priv.c)
endif()
