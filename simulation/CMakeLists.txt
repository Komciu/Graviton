add_library(SimLib simulation.cpp simulation.h)
target_link_libraries(SimLib PUBLIC EntityLib)
target_include_directories(SimLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
