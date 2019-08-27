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
![Flowchart](https://i.ibb.co/tpjpPw9/diagrama.png)
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
