all :
	gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
	valgrind --leak-check=full ./hsh
	#./hsh
