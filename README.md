# Simple Shell - C prorgramming language

This simple Shell - **Holbishell** - is a prorgramm that provides an interface for users to get access to the kernel's services. In other words the  **Holbishell** works as a command interpreter.

This shell is able to run default commands and also some other that have been built in (More info inside the Man Page).

# Getting Started

First. Clone this repository in your machine.
```sh
$ git clone https://github.com/joshuaciencia/simple_shell.git
```
Go to the directory "simple_shell".
```sh
$ cd simple_shell 
```
After this, it will be necessary to compile the program, for that we included a Makefile (it is a file that compilates and executes the file at the same time.) it is used like this:
```sh
$ make 
```
If you want to know how the Shell is compilated and executed, you can run 
```sh
$ cat Makefile
```
After this... you are ready to use our Holbishell.

##  Usage

The holbishell has two modes: **Interactive** in which the shell takes the commands from the standard input, executes them and gets ready to read another command-line.

As an example you can use the <b>ls</b> command for listing files in the current directory:

```sh
$ ls
_atoi.c AUTHORS built_ins.c _environ.c _error_handler.c holberton.h Makefile
$ 
```
The other mode is non-interactive. For this, the command should be passed thru a pipe
```
$ echo "/bin/ls" | ./hsh
_atoi.c AUTHORS built_ins.c _environ.c _error_handler.c holberton.h Makefile
```
## Algorithm
![Flowchart](https://www.draw.io/?lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&title=Untitled%20Diagram.drawio#R5VtdV6M4GP4te9FznAvnQMJXL7XqzO7Z3fGcOmf0MtJYskMJG1Lb%2Bus3gQQKoYqjhdq9UMnbBJLnfd7P4ghOFusvDKXRX3SG4xGwZusRvBgBYNswEH%2BkZFNIPNsuBHNGZoXIqgRT8oTVSi1dkhnOlKwQcUpjTtK6MKRJgkNekyHG6Ko%2B7YHGs5ogRXNsCKYhik3pDzLjUSENgF%2FJv2Iyj%2FSTbW9cfLJAerI6SRahGV1tieDlCE4Ypby4WqwnOJbg1XG52vFpuTGGE95lwdWE%2Fjt1nlL4fbz5w4Lw9ke8OoXFXR5RvFQHVpvlG40AnglA1JAyHtE5TVB8WUnPGV0mMywfY4lRNedPSlMhtIXwH8z5RmkXLTkVoogvYvVp8Uz5oJ1nU6KMLlmInzmQ5ghic8yfmQdKDQjqYrrAnG3EOoZjxMljfR9IcWhezqtgFhcK6Vegbhuof0txIrcdYfkbswUR%2BMlHJ7NcG4jx8uNplD%2Bioaa6ElYR4XiaohyrlTDNNsAfMeN4%2FTzkJkRqgaa1smvoFMNVZSS2tuFoy0A8a0%2BYusfGZNCRyc6QTAYG6jebVJDUQwtJueQ%2BS3NUvFgc4fyeiau5vIozseo0Nj8QvJUAJsIGfhuc47Z%2FYCT3j43kTkeSe0OS3DFQ%2F4IrdxzSxSJ3000qE%2BnRkfi5Xz48YPayUZgzrFOZAmEekwSffJL5yzIJOaFJ8dHA5gHtl80D9mkethlYP7h9eB3tw7baNdWPgXgG7NM0JpWJaAOwSCKwkhn8T5xkn00LOCmNSWU%2B4tzZp8GJ7gSHRvTjy9utrkx338h0tfSaCjJWKg4s%2F7NbU3IZ%2FPVNiq2pdQ0Flht5g06D%2F40Kx3tRoefXFQiCfhUIjq4E6axRMGgRore5BfxkV1LWzLHwmmQ8y0OT%2BHV9dvN1JCvb5jLK8jBGYp5PFSe4MqNSRBf3y6yfiDS2685KN6S2Q5IVmCHJtvYWk8w0%2BW9qgCSOzOtoMJyRJ3SfT5CUT6V95ptzz0fuhZBIjmcF3eUCFJN5Iq5j%2FCBvJXEkIYrPlJhLOznPBPokmd%2FkRiMy%2BHdB3bPcZpBwTNzbMgGwN9RNp3O5lqmXkVoJigyfSXmwnknZromf14Kfsy%2F8wNGV1Pa4q9MetKjW29wC%2FveqBVo44oHJ6ho5YcnDLbrqrKMfupqofXC6gq4lLgiGpCswa9wJw4hLssoeTxiRWBasKaMhzrK8yJUQrXG4zCe90Cx6oOyn7PBM1KJHrEcrRPjJ8J7b8WHDGMr2z3bO4UDTGvZWBsOj6%2FeAoKM1wEEbPnqbW8CnrCjGctpPby6%2Bfb8ZnLOubTc467Rw1vN7dODQrFWuGV2kEjo0R7IKOTzQxgODBkzQ7nBmIPWhawvTvwLLhN3ps7YAZkV3JiPbeVkHD05W6Ac1zNrqiV4TNGhiZoakZHYmX00Ro4QmuA6KODjb3EoABR3U8E7hmQ8u1rXRRo9E1Xer7yGu76pbiFG1SA70mncMXLBz829H4NpSmNtCci17Y4%2FQDWCNL67dIEJxUKNH2NJsrBey4269RqF3tNmaphzSzv36jXpZ73fXtnxYP5%2FuC1WULnbwro1P1zEp%2FqGyLuh2JK8D2snbT9YF23o9eX2RlQXG1hfEeSYWiWojbqk%2FBvbbZU1QxjrX8Ntlq7LmB9x9gWumtM857jBGWUbChu9WPth6hQ%2F%2BVX%2F%2FjvQHXd%2FCgDu%2Be%2BvHd5f5kPZtY%2FBrvrvcUNnEbdzonZx38%2F0I2%2B%2FDGbtDOOMDYLFW4stOHA7pxPU2D7x0Br7XLEeGrgId86WHAyudTdCgNzBortm3fC6stdQjOqaVcay06z7qis5fQe%2By6p7qiub3WrpR%2F9rYZDdfNYL7KSxAMzapDe%2BMmc13%2FYJaIfLaWCaG1X8%2BFNOr%2Fx%2BBl%2F8B)
# Manual
We provided a man page in the repository, it can be run like this:
```
$ man ./man_1_page
```
and you will se something like this 

```sh
HOLBISHELL(1)                       General Commands Manual                                HOLBISHELL(1)

NAME
       Simple Holbishell

SYNOPSIS
       #include holberton.h

       ./hsh -> executes

DESCRIPTION
       Simple Holbishell is a prorgramm that provides an interface for users to get access to the kernel's 
       services.  
       This shell works as a command interpreter in two modes:

       Interactive Mode

       In this mode, the shell takes the commands from the standard input, executes them and gets ready to 
       read another command-line.

       Non-interactive Mode

       This mode reads the commands from a file sent thru a pipe, the commands will be executed and the shell 
       won't ask for more commands.

       The Holbishell is fully written in C programming language, it uses systemcalls and regular C functions.

ARGUMENTS
       This Shell does not support arguments.

INVOCATION
       In order to invoke this shell it is necessary to run the ./hsh command. We also provided a Makefile 
       to make the compiltion easier.
```
# Files
| File | Description |
| ------ | ------ |
|[AUTHORS](https://github.com/joshuaciencia/simple_shell/blob/Test/AUTHORS "AUTHORS") | Provides names and contacts to all the people that collaborated to this project |
| [Makefile](https://github.com/joshuaciencia/simple_shell/blob/Test/Makefile "Makefile") | Contains the compilation flags and executes the programm |
| [README.md](https://github.com/joshuaciencia/simple_shell/blob/Test/README.md "README.md")| <3 you know what it is <3 |
| [_atoi.c](https://github.com/joshuaciencia/simple_shell/blob/Test/_atoi.c "_atoi.c")| Function that converts an alpha character to an integer |
| [_environ.c](https://github.com/joshuaciencia/simple_shell/blob/Test/_environ.c "_environ.c")| Contains all the functions related to the enviroment variable (setenv, unsetenv, printenv etc.)  |
| [_error_handler.c](https://github.com/joshuaciencia/simple_shell/blob/Test/_error_handler.c "_error_handler.c") |  Function that handles the different kind of errors that the holbishell can face |
| [_printd.c](https://github.com/joshuaciencia/simple_shell/blob/Test/_printd.c "_printd.c") | Function that prints an integer |
| [_printer.c](https://github.com/joshuaciencia/simple_shell/blob/Test/_printer.c "_printer.c") |Contains all the print-related functions (_putchar.c, _puts.c etc)  |
| [_string.c](https://github.com/joshuaciencia/simple_shell/blob/Test/_string.c "_string.c") | Contains every function used to handle strings (_strcmp, _strdup, _strlen, and so on)  |
| [_strtok.c](https://github.com/joshuaciencia/simple_shell/blob/Test/_strtok.c "_strtok.c") | Function used to tokenize a string |
| [built_ins.c](https://github.com/joshuaciencia/simple_shell/blob/Test/built_ins.c "built_ins.c") | This file contains all the functions to handle the built in commands (exit, cd, env, setenv, unsetenv) |
| [holberton.h](https://github.com/joshuaciencia/simple_shell/blob/Test/holberton.h "holberton.h") | Header file, it addresses all the function prototypes we used |
| [man_1_page](https://github.com/joshuaciencia/simple_shell/blob/Test/man_1_page "man_1_page") | Manual page to check everytime you feel overwhelmed using this holbishell |
| [prompt.c](https://github.com/joshuaciencia/simple_shell/blob/Test/prompt.c "prompt.c") | contains the main function, from this one all the others are called and implemented |
| [shell_execute.c](https://github.com/joshuaciencia/simple_shell/blob/Test/shell_execute.c "shell_execute.c") | This is the core file of the shell, here are the processes executed |


# Version
* 0.0.1
    * (27-08-2019) First version
# Authors
* Joshua "Ciencia" Hernández [Twitter](https://twitter.com/JoshuaH63560195)
* Dani "Neosphere" Gómez [Twitter](https://twitter.com/darkinss)
	Holberton School Students. Medellín Cohort 0.
