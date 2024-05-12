# Code Examples

This repository contains a collection of code examples written in C and C++. The code examples demonstrate various programming concepts and techniques.

## File Descriptions

- **aio02.c**: This program reads data from the `/dev/random` device using asynchronous I/O operations. It demonstrates the use of the `aio_read` function for asynchronous I/O in C. The program reads a specified size of data (1MB in this case) from the device one byte at a time and prints the number of bytes read.

- **frw01.c**: This program copies data from one file to another using the standard I/O library in C. It opens a source file for reading and a destination file for writing, then reads data from the source file into a buffer and writes it to the destination file. The size of the data to be copied can be specified as a command-line argument.

- **seek01.c**: This program creates a file and writes a single byte to it at a specific position (1,000,000 bytes from the start of the file). It demonstrates file handling operations in C, including creating a file, writing to a file at a specific position using `lseek`, and closing a file.

- **mmap02.c**: This program copies data from one file to another using memory mapping. It opens a source file and a destination file, maps the source file into memory, and then copies the data to the destination file. It demonstrates the use of the `mmap` and `memcpy` functions for memory-mapped file I/O in C.

- **rw01.c**: This program copies data from one file to another using low-level I/O operations in C. It opens a source file for reading and a destination file for writing, then reads data from the source file into a buffer and writes it to the destination file one byte at a time. The size of the data to be copied can be specified as a command-line argument.

- **ard.cpp**: This program is written for the Arduino platform. It reads the state of several buttons and displays the state on an LCD. It demonstrates digital input reading and LCD interfacing on Arduino.
