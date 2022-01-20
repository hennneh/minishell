clear
gcc ../../libft/libft.a input_split.c -o pipe_test
./pipe_test " 1 | thing || 2 | 3 |"
rm pipe_test