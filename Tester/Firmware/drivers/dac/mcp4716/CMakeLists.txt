zephyr_library()

zephyr_library_sources_ifdef(CONFIG_DAC_MCP4716	dac_mcp4716.c)
