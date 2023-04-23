#=============================
# Add sources
#=============================
target_sources(firmware
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/adc.c
		${CMAKE_CURRENT_LIST_DIR}/adc.h
		${CMAKE_CURRENT_LIST_DIR}/timer0_clk.c
		${CMAKE_CURRENT_LIST_DIR}/timer0_clk.h
		${CMAKE_CURRENT_LIST_DIR}/timer1_nec.c
		${CMAKE_CURRENT_LIST_DIR}/timer1_nec.h
		${CMAKE_CURRENT_LIST_DIR}/timer2_pwm.c
		${CMAKE_CURRENT_LIST_DIR}/timer2_pwm.h
		${CMAKE_CURRENT_LIST_DIR}/twi_master.c
		${CMAKE_CURRENT_LIST_DIR}/twi_master.h
		${CMAKE_CURRENT_LIST_DIR}/uart.c
		${CMAKE_CURRENT_LIST_DIR}/uart.h
)
