CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

option(FREEMODBUS_USE_TCP        "modbus TCP"                 ON) 

set( FREEMODBUS_TARGET freemodbus) 
set( FREEMODBUS_ROOT freemodbus-v1.5.0/)

set ( TARGET MBServer) 
project(${TARGET})

SET(${TARGET}_HEADERS  Serveur.h mbpollthread.h fcallback.h )
SET(${TARGET}_SOURCES main.cpp 
			 Serveur.cpp mbpollthread.cpp fcallback.c)
SET(QT5_RCCS  )
SET(QT5_UIS )

# Below is required to set debugging enrinment under Visual studio 2010
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
include(CreateLaunchers)
 
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
	MESSAGE ("-- Host system is 64 bits  CMAKE_SIZEOF_VOID_P=${CMAKE_SIZEOF_VOID_P} --")
else( CMAKE_SIZEOF_VOID_P EQUAL 8 )
	MESSAGE ("-- Host system is 32 bits  CMAKE_SIZEOF_VOID_P=${CMAKE_SIZEOF_VOID_P} --")
endif( CMAKE_SIZEOF_VOID_P EQUAL 8 )


if(MSVC)
# Instruct CMake where to find cmake related stuffs
#set (CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.0.2\\5.0.2\\msvc2010_opengl\\")
set (CMAKE_PREFIX_PATH 
	"C:\\Qt\\5.1.1\\msvc2012_64_opengl"
	"c:\\Program Files\\Microsoft SDKs\\Windows\\v7.1\\Lib\\"
	)
 
# Set QTDIR to Qt5 SDK path
#set (QTDIR "C:/Qt/Qt5.0.2/5.0.2/msvc2010_opengl")
set (QTDIR "C:/Qt/5.1.1/msvc2012_64_opengl")
set (RUN_ENV "PATH=${QTDIR}/bin")
MESSAGE ("-- RUN_ENV: ${RUN_ENV}")
endif(MSVC)



# Find the QtWidgets library
find_package(OpenGL REQUIRED)

#find_package(Qt5Widgets)
#find_package( Qt5Core REQUIRED )
find_package(Qt5SerialPort REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5PrintSupport REQUIRED)

QT5_ADD_RESOURCES ( ${TARGET}_RCCS ${QT5_RCCS} )
QT5_WRAP_UI(UIS_HDRS
    ${QT5_UIS}
)

subdirs(freemodbus-v1.5.0)
include_directories( ${FREEMODBUS_ROOT}/modbus/include 
		${FREEMODBUS_ROOT}/demo/WIN32TCP/Port )

 # GUI Type
 if(WIN32)
   set(GUI_TYPE WIN32)
 endif(WIN32)
 if(APPLE)
   set(GUI_TYPE MACOSX_BUNDLE)
 endif(APPLE)


# Tell CMake to create the sample1 executable
#add_executable(${TARGET} ${GUI_TYPE} ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_RCCS} ${UIS_HDRS})
add_executable(${TARGET} ${${TARGET}_HEADERS} ${${TARGET}_SOURCES} ${${TARGET}_RCCS} ${UIS_HDRS})

if(WIN32)
  target_link_libraries(${TARGET} wsock32 ws2_32)
endif()

# Use the Widgets module from Qt 5.
qt5_use_modules(${TARGET} OpenGL Gui Widgets Network SerialPort PrintSupport)

TARGET_LINK_LIBRARIES ( ${TARGET}
    ${OPENGL_LIBRARIES}
	${FREEMODBUS_TARGET}
)

# Create the launcher for VS2010
if (MSVC_IDE)
# Set ENVIRONMENT. This will make VS debugger to refer qt5 related DLLs properly
create_target_launcher(${TARGET} ENVIRONMENT  "PATH=${QTDIR}/bin")
#create_target_launcher(sample1 ENVIRONMENT  ${RUN_ENV})
endif(MSVC_IDE)
