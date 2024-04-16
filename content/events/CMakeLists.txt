add_library(events
  updatefov.cpp
        opendoor.cpp
        closedoor.cpp
)

target_include_directories(events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(events PUBLIC engine)
