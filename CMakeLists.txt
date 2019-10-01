cmake_minimum_required(VERSION 3.14)
project(checker C)

set(CMAKE_C_STANDARD 99)
file (GLOB SRC checker/libft/*.c)

add_executable(checker ${SRC} checker/main.c checker/checker.h checker/stack.c checker/stack.h checker/ft_ll_atoi.c checker/do_rules.c)