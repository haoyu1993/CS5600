/*
 * file:        part-1.c
 * description: Part 1, CS5600 Project 2, Fall 2023
 */

/* THE ONLY INCLUDE FILE */
#include "sysdefs.h"

/* write these functions */

int read(int fd, void *ptr, int len);
int write(int fd, void *ptr, int len);
void exit(int err);
 

/*The read function is given to you in the starter code, by analogy write the
  write() function and the exit() function. 
  __NR_read is defined in file sysdefs.h, it is the system call number 
  for the system function that performs reading. 
    A link is provided after each function, to read about this system call function
  in the Linux manual page */

int read(int fd, void *ptr, int len) {
	if (len < 0) {
		return -1;
	}

	return syscall(__NR_read, fd, ptr, len);
} /*https://man7.org/linux/man-pages/man2/read.2.html */


int write(int fd, void *ptr, int len) {
    int result;
    __asm__ volatile("syscall"
                     : "=a"(result)
                     : "0"(__NR_write), "D"(fd), "S"(ptr), "d"(len)
                     : "cc", "rcx", "r11");
    return result;
}






void exit(int err) {
    __asm__ volatile("syscall"
                     :
                     : "a"(__NR_exit), "D"(err)
                     : "cc", "rcx", "r11");
}



/* Factor, factor! Don't put all your code in main()!
   Write new functions using the functions you just wrote
*/


/* read one line from stdin (file descriptor 0) into a buffer pointed to by ptr. : */
void do_readline(char *buf, int len) {
    char c;
    int i = 0;
    while (i < len - 1) {
        if (read(0, &c, 1) < 1)
            exit(1);  // 处理读取错误

        if (c == '\n' || c == '\0') {
            buf[i] = '\0';
            break;
        }

        buf[i++] = c;
    }
    buf[len - 1] = '\0'; // 确保以 null 结尾
}





/* print a string to stdout (file descriptor 1) */
void print_and_clean(int fd, void *ptr, int max_len) {
	/* This function prints a string pointed to by ptr to stdout by repeatedly calling
	function write() you wrote above.
	You will call write to print 1 byte at a time.
	After you print a character, clean the corresponding buffer location by replacing
	the character printed by 0 */


	/* add your code here*/



}





void main(void)
{
	/* reads a line of input from standard input (file descriptor 0)
	   if the line starts with �q�, �u�, �i�, �t� then exit
	   otherwise print the line to standard output (file descriptor 1) and loop.
	   You can assume that input lines are never more than 200 bytes long. 
	   Remember that you can�t return from the main function � you have to call exit.
	   Remember that you can�t use any functions other than the ones that you write 
	   yourself. That means no printf � use GDB for your debugging (and no strcmp for
	   string comparisons, or malloc for allocating memory).   */

	/* add your code here */
}
