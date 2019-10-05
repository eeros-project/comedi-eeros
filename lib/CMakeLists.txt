include_directories(../include/)

set(COMEDIEEROS_SRCS ComediDevice.cpp DigIn.cpp DigOut.cpp AnalogIn.cpp AnalogOut.cpp Fqd.cpp)

add_library(comedieeros SHARED ${COMEDIEEROS_SRCS})
add_library(comedieeros_static ${COMEDIEEROS_SRCS})


target_link_libraries(comedieeros comedi eeros)
set_target_properties(comedieeros PROPERTIES VERSION ${LIBRARY_VERSION})

target_link_libraries(comedieeros_static comedi eeros)

INSTALL(TARGETS comedieeros comedieeros_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

