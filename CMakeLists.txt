cmake_minimum_required(VERSION 2.6)
project(flinkeeros)

## Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(EEROS REQUIRED)
include_directories(${EEROS_INCLUDE_DIR})
link_directories(${EEROS_LIB_DIR})

include_directories(${ADDITIONAL_INCLUDE_DIRS})
link_directories(${ADDITIONAL_LINK_DIRS})

find_path(COMEDI_INCLUDE_DIR NAMES comedi.h comedilib.h)
if(COMEDI_INCLUDE_DIR)
        include_directories(${COMEDI_INCLUDE_DIR})
endif()

find_library(COMEDI_LIBRARY comedi)
if(COMEDI_LIBRARY)
	message(STATUS "-> libcomedi available")
	set(COMEDI_LIBRARY_DIR ${COMEDI_LIBRARY_DIR} comedi)
endif()

add_subdirectory(lib)
add_subdirectory(test)

INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/ComediDevice.hpp 
	${CMAKE_CURRENT_SOURCE_DIR}/include/DigIn.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/DigOut.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/AnalogIn.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/AnalogOut.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/Fqd.hpp
DESTINATION include)