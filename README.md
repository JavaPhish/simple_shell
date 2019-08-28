# hsh

### Description

hsh (Holberton shell) is an implementation of a shell in C that seeks to emulate the basic functionality of the original sh ([Thompson shell]([https://en.wikipedia.org/wiki/Thompson_shell)), but hopefully with much-improved memory management! 
### Features

The hsh utilizes a dynamic memory allocation system in an attempt to ensure no memory leakages.

The hsh is able to be utilized in interactive and non-interactive modes. 

It reads from standard input and parses the input, interpreting if commands are builtins or system commands. It initializes non-builtin commands utilizing the `fork()` function to ensure that the shell program remains active in the parent process whilst and until execution completes. 

### Functionality

As the hsh emulates basic shell functionality, the following limitations are observed:

-   Commands must be on a single line.
-   Arguments must be separated by whitespace.
-   No quoting arguments or escaping whitespace.
-   No piping or redirection.
-   Only builtins are:  `cd`,  `env`,  `exit`

## Installation

All of the c files in this repository, as well as the header file, must be present in a directory and compiled with hsh as the name of the executable.

Example:
```c
gcc *.c -o hsh
```

## Usage Examples
Interactive Mode:
```c
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
Non-Interactive Mode:
```c
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
```
```c
$ cat test_ls_2
/bin/ls
/bin/ls
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Contributing
Any pull requests for adding features or fixing bugs will be manually reviewed. Please see the AUTHORS file for contact information. 

## License

This code is in the public domain (see [UNLICENSE](https://github.com/brenns10/lsh/blob/master/UNLICENSE) for more details). This means you can use, modify, and distribute it without any restriction. We appreciate, but don't require, acknowledgement in derivative works.