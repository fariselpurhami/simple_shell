0x16. C - Simple Shell

Description

A simple UNIX command interpreter. mini_shell is the user interface to communicate with the operative system services.

This project consists in the creation of a simple shell that will allow the user to interact with the system using commands.

It handles the PATH to find the programs it will execute. It will use the execve() system call to perform the commands. The execution of the programs will be done under children processes using fork(). CTRL+C won't close the program, with the command exit close the shell.
