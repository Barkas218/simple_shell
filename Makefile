ill :
	gcc -Wall -Werror -Wextra -pedantic -g -o hsh *.c
	valgrind --leak-check=yes ./hsh
	#gdb ./hsh
	#./hsh
