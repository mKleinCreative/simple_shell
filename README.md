# simple_shell

<img src="https://svgsilh.com/svg/576487.svg" alt="Simple Shell">

## DESCRIPTION
A simple UNIX command interpreter created for Holberton School as a partner project with Michael Klein and Wendy Leung.

## REQUIREMENTS

* Allowed editors: ```vi```, ```vim```, ```emacs```
* All files will be compiled on Ubuntu 14.04 LTS
* Programs and functions will be compiled with ```gcc 4.8.4``` using the flags ```-Wall``` ```-Werror``` ```-Wextra``` ```and -pedantic```
* All files should end with a new line
* Code should use the ```Betty``` style. it will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style\
.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to
* Authorized functions and system calls:
  * ```access``` (```man 2 access```)
  * ```chdir``` (```man 2 chdir```)
  * ```close``` (```man 2 close```)
  * ```closedir``` (```man 3 closedir```)
  * ```execve``` (```man 2 execve```)
  * ```exit``` (```man 3 exit```)
  * ```fork``` (```man 2 fork```)
  * ```free``` (```man 3 free```)
  * ```stat``` (```__xstat```)(```man 2 stat```)
  * ```lstat``` (```__lxstat```)(```man 2 lstat```)
  * ```fstat``` (```__fxstat)(```man 2 fstat```)
  * ```getcwd``` (```man 3 getcwd```)
  * ```getline``` (```man 3 getline```)
  * ```kill``` (```man 2 kill```)
  * ```malloc``` (```man 3 malloc```)
  * ```open``` (```man 2 open```)
  * ```opendir``` (```man 3 opendir```)
  * ```perror``` (```man 3 perror```)
  * ```read``` (```man 2 read```)
  * ```readdir``` (```man 3 readdir```)
  * ```signal``` (```man 2 signal```)
  * ```strtok``` (```man 3 strtok```)
  * ```wait``` (```man 2 wait```)
  * ```waitpid``` (```man 2 waitpid```)
  * ```wait3``` (```man 2 wait3```)
  * ```wait4``` (```man 2 wait4```)
  * ```write``` (```man 2 write```)
  * ```_exit``` (```man 2 _exit```)
  * ```isatty``` (```man 3 isatty```)
  * ```fflush``` (```man 3 fflush```)

## QUICK START
Git clone the repository:

```
git clone https://github.com/mKleinCreative/simple_shell.git
```
Compile simple_shell this way:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Execute the shell.
```
./hsh
```
## SYNTAX
You can use the same syntax for running commands in other shells:
```
<command> <flags or options> <argument 1> <argument 2> ...
```
In non-interactive mode:
```
<command> | ./hsh
```
## EXAMPLE
Interactive mode:
```
/bin/ls
```
Non-interactive mode
```
echo "/bin/ls" | ./hsh
```
## BUILTINS
`exit` - exit the shell

## BUGS
Memory problems and exit does not work

## AUTHORS

**Michael Klein** [Github](https://github.com/mKleinCreative)
**Wendy Leung** [Github](https://github.com/wendyblogtech)
