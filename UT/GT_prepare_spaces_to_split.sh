#!/bin/sh
cc -g3 GT_prepare_spaces_to_split.c ../src/handle_spaces.c ../libft/libft.a && valgrind --leak-check=full ./a.out && rm ./a.out