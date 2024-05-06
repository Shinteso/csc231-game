add_library(items
  bite.cpp
        sword_red_gem.cpp
        knife.cpp
        spear.cpp
#        next_floor.cpp
#        shotgun.cpp
#        saber_blue.cpp
#        saber_red.cpp
        launcher.cpp
        next_floor.cpp
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
