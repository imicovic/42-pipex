# Welcome to 42 Wolfsburg project pipex

Project pipex aims to introduce students to POSIX API through file operations, file descriptor manipulation and process management, synchronization and interprocess communication.

### Usage
```bash
make
./pipex file1 "cmd1 [parameter][argument]" "cmd2 [parameter][argument]" file2
```
Which will have the same effect as for example
```bash
< file1 cat | grep include > file2
```
To run the program with more than 2 commands run
```bash
make bonus # As this is bonus part of the project
./pipex file1 "cmd1 [parameter][argument]" "cmd2 [parameter][argument]" "cmd3 [parameter][argument]" "cmdn [parameter][argument]" file2
```
Commands which are to be ran without arguments can be passed without double quotes.<br>
For more information about the project requirements check the [subject](en.subject.pdf) page.
