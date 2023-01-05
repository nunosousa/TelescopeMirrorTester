if(CONFIG_DAC_MCP4716)
  zephyr_include_directories(.)

  zephyr_library()
  zephyr_library_sources(dac_mcp4716.c)
endif()
