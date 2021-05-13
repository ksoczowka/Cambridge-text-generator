cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(Generator)

set(SRC_LIST
 src/funcs.cpp
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(${PROJECT_NAME} src/main.cpp)
add_library(lib STATIC ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} lib)
