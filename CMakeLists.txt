cmake_minimum_required(VERSION 3.14)
project(fractol C)

set(CMAKE_C_STANDARD 99)

add_executable(fractol
        fractol.h
        keycode.h
        fractol.c
        functions_change_color.c
        functions_key_code.c
        functions_malloc.c
        functions_support.c)