//
//  file_xor.h
//  file_redundancy
//
//  Created by 筱因 on 2022/10/4.
//

#ifndef file_xor_h
#define file_xor_h
#define NAME 200

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char file_1[NAME];
char file_2[NAME];
char *buffer_1;
char *buffer_2;
long long file_1_size;
long long file_2_size;
void menu(int argc, char *argv[], char (*file_1)[NAME], char (*file_2)[NAME]);
long long file_read(char *file, char **buffer);
void file_wrire(char *buffer, long long file_size);
void file_xor(char **buffer_1, char **buffer_2);

#endif /* file_xor_h */
