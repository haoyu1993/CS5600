#include "elf64.h"
#include "sysdefs.h"

extern void *vector[];

/* ---------- */

/* write these functions */
int read(int fd, void *ptr, int len); // Done in part1
int write(int fd, void *ptr, int len); // Done in part1
void exit(int err);                   // Done in part1
int open(char *path, int flags);
int close(int fd);
int lseek(int fd, int offset, int flag);
void *mmap(void *addr, int len, int prot, int flags, int fd, int offset);
int munmap(void *addr, int len);

/* ---------- */

/* Write the three 'system call' functions - do_readline, do_print, do_getarg */
void do_readline(char *buf, int len) {
    char c;
    int i;
    for (i = 0; i < len - 1; i++) {
        if (read(0, &c, 1) <= 0) {
            break; // Handle read error or end of file
        }
        buf[i] = c;
        if (c == '\n') {
            buf[i + 1] = '\0';
            break;
        }
    }
    buf[len - 1] = '\0';
}

void do_print(char *buf) {
    int i = 0;
    while (buf[i] != '\0') {
        write(1, &buf[i], 1);
        buf[i] = '\0'; // Clean the printed character
        i++;
    }
}

char *do_getarg(int i) {
    // Your implementation here
}

/* ---------- */

/* This is where you write the details of the function exec(char* filename) called by main() */
void exec(char *filename) {
    // Your implementation here
    int fd = open(filename, 0);
    if (fd < 0) {
        exit(1); // Open failed
    }

    Elf64_Ehdr hdr;
    if (read(fd, &hdr, sizeof(hdr)) != sizeof(hdr)) {
        close(fd);
        exit(1); // Read ELF header failed
    }

    if (hdr.e_ident[0] != 0x7F || hdr.e_ident[1] != 'E' || hdr.e_ident[2] != 'L' || hdr.e_ident[3] != 'F') {
        close(fd);
        exit(1); // Not a valid ELF file
    }

    // Your code for loading and executing the ELF file here

    close(fd); // Close the file descriptor when done
}

/* ---------- */
void main(void) {
    vector[0] = do_readline;
    vector[1] = do_print;
    vector[2] = do_getarg;

    char filename[200];
    do_readline(filename, 200);

    exec(filename); // Execute the specified ELF file
}
