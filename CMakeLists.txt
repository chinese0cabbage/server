cmake_minimum_required(VERSION 3.7)
project(server)

set(CMAKE_CXX_STANDARD 11)

add_executable(server main.cpp sql_module/mysql_connect.h test_moduel/test_moduel.cpp test_moduel/test_moduel.h test_moduel/Register.cpp common/CommonData.h common/Register.cpp)

add_subdirectory(test_moduel)
#add_library(test_moduel SHARED test_moduel/test_moduel.cpp test_moduel/test_moduel.h)

include_directories(common json_serialization)

link_directories("usr/lib/x86_64-linux-gnu")
link_libraries(pthread)
target_link_libraries(server pthread)

include_directories("/usr/local/include/glog")
link_directories("/usr/local/lib")
link_libraries(libglog.a)
target_link_libraries(server glog)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/install/include")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/install/lib")
link_libraries(librttr_core)
target_link_libraries(server ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/librttr_core.so)

link_directories(“/usr/local/lib”) # lib文件夹的路径
link_libraries(libmysql) # 直接写这个
target_link_libraries(server mysqlcppconn) # 项目名称 libmysql
