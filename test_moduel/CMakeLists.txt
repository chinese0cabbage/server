project(test_moduel)

include_directories(include)

AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_library(test_moduel SHARED test.h test.cpp test_moduel.h)
target_link_directories(test_moduel PUBLIC ${PROJECT_SOURCE_DIR})