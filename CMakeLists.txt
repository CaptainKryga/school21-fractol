cmake_minimum_required(VERSION 3.13)
project(fractol C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror ")

find_library(OPEN_GL Open_Gl)
find_library(APP_KIT AppKit)
include_directories(.)
include_directories(libftprintf)
include_directories(libftprintf/libft)
include_directories(minilibx)
include_directories(minilibx_macos)

file(GLOB all
        "*.h"
        "*.c"
        )

file(GLOB libftprintf
        "libftprintf/*.h"
        "libftprintf/*.c"
        )

file(GLOB libft
        "libftprintf/libft/*.h"
        "libftprintf/libft/*.c"
        )

add_definitions(${GCC_COMPILE_FLAGS})
add_executable(fractol ${all} ${src} ${libft} fractol_mandelbrot.c fractol_julia.c)
target_link_libraries(fractol mlx ${APP_KIT} ${GCC_COMPILE_FLAGS})
TARGET_LINK_LIBRARIES(fractol ${OpenGL})