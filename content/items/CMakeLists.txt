add_library(items
  bite.cpp
        sword_red_gem.cpp
        knife.cpp
        spear.cpp
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
