cmake_minimum_required(VERSION 3.7)
project(server)

set(CMAKE_CXX_STANDARD 11)

add_executable(server main.cpp sql_module/mysql_connect.h test_moduel/test_moduel.cpp test_moduel/test_moduel.h test_moduel/Register.cpp common/CommonData.h common/Register.cpp)

add_subdirectory(test_moduel)

include_directories(common json_serialization)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/install/include")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/install/lib")
link_libraries(librttr_core)
target_link_libraries(server ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/librttr_core.so)

link_directories(“/usr/local/lib”) # lib文件夹的路径
link_libraries(libmysql) # 直接写这个
target_link_libraries(server mysqlcppconn) # 项目名称 libmysql
