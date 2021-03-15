project(test_moduel)

include_directories(include)

AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_library(shared_1 SHARED include/test.h src/test.cpp)
target_link_directories(shared_1 PUBLIC ${PROJECT_SOURCE_DIR})