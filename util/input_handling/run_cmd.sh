clear
gcc ../../libft/libft.a pipe_split.c cmd_split.c ../whitespace.c -o cmd_test
./cmd_test " 'bla1 '| thing '|||||| 2 | blu3 |"
rm cmd_test