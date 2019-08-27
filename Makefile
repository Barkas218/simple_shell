all :
	gcc -Wall -Werror -Wextra -pedantic -g -o hsh *.c
	valgrind --leak-check=yes --show-leak-kinds=all ./hsh
	#gdb set follow-fork-mode child ./hsh
	#./hsh
