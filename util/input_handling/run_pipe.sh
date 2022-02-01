clear
gcc ../../libft/libft.a pipe_split.c -o pipe_test
./pipe_test " 'bla1 '| thing '|||||| 2 | blu3 |"
rm pipe_test