cmake_minimum_required(VERSION 3.10)
project(GalaxyEngine VERSION 1.0.0 DESCRIPTION "星河游戏引擎项目" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

aux_source_directory(src source)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
add_executable(${PROJECT_NAME} ${source})

add_subdirectory(deps/glfw)
add_subdirectory(deps/glm)
add_subdirectory(deps/glad)

target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)

target_include_directories(${PROJECT_NAME} PUBLIC deps/glfw/include)
target_include_directories(${PROJECT_NAME} PUBLIC deps/glm/include)
target_include_directories(${PROJECT_NAME} PUBLIC deps/glad/include)
