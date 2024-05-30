project(glad LANGUAGES C)

set_target_properties(PROPERTIES VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED glad.c)
include_directories(include)