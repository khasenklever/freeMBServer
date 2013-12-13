# ---------------------------------------------------------
cmake_minimum_required(VERSION 2.6)


set(FREEMODBUS_SRC 
	modbus/mb.c
	modbus/functions/mbfunccoils.c
	modbus/functions/mbfuncdiag.c
	modbus/functions/mbfuncdisc.c
	modbus/functions/mbfuncholding.c
	modbus/functions/mbfuncinput.c
	modbus/functions/mbfuncother.c
	modbus/functions/mbutils.c
	modbus/functions/mbutils.c
)

if (FREEMODBUS_USE_TCP)
	set(FREEMODBUS_SRC ${FREEMODBUS_SRC} 
		modbus/tcp/mbtcp.c)
endif()

if (WIN32)
	set(FREEMODBUS_PLATFORM
		demo/WIN32TCP/Port/portevent.c
		demo/WIN32TCP/Port/portother.c
		demo/WIN32TCP/Port/porttcp.c
		demo/WIN32TCP/Port/porttimer.c
		)
	set(FREEMODBUS_PLATFORM_INC demo/WIN32TCP/Port)
endif (WIN32)

## TODO TEST OTHER PLATFORMS




include_directories( modbus/include modbus/tcp ${FREEMODBUS_PLATFORM_INC} )
#add_definitions(-DFT2_BUILD_LIBRARY)
add_library(${FREEMODBUS_TARGET} ${FREEMODBUS_SRC} ${FREEMODBUS_PLATFORM})
