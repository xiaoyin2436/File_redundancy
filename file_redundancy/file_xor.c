//
//  file_xor.c
//  file_redundancy
//
//  Created by 筱因 on 2022/10/4.
//

#include "file_xor.h"
void menu(int argc, char *argv[], char (*file_1)[NAME], char (*file_2)[NAME]){
    if(argc == 1){
        printf("请输入一个文件名：");
        scanf("%s",*file_1);
        printf("请输入另一个文件名：");
        scanf("%s",*file_2);
    }else if(argc == 3){
        strcpy(*file_1, *argv++);
        strcpy(*file_2, *argv);
    }else{
        printf("输入不合法");
    }
    return;
}

long long file_read(char *file, char **buffer){
    FILE *file_p = NULL;
    printf("%s",file);
    long long file_size;
    file_p = fopen(file, "rb");
    if(file_p == NULL){
        printf("文件打开失败...");
        exit(1);
    }
    
    fseek(file_p, 0, SEEK_END);
    file_size = ftell(file_p);
    fseek(file_p, 0, SEEK_SET);
    *buffer = (char *)malloc(file_size);
    //memset(*buffer, 0, file_size);
    fread(*buffer, 1, file_size, file_p);
    fclose(file_p);
    //free(*buffer);
    
    return file_size;
}

void file_wrire(char *buffer, long long file_size){
    FILE *file_p = NULL;
    char file_name[NAME];
    printf("\n请输入生成文件名：");
    scanf("%s",file_name);
    file_p = fopen(file_name, "wb+");
    if (file_p == NULL){
        printf("生成文件失败...");
        exit(1);
    }else{
        fwrite(buffer, 1, file_size, file_p);
    }
    fclose(file_p);
}

void file_xor(char **buffer_1, char **buffer_2){
    //char **xor_buffer;
    long long size = file_1_size > file_2_size ? file_1_size : file_2_size;
    //char *buffer_file_1;
    //char *buffer_file_2;
    //char *xor_buffer;
    char *buffer_file_1 = (char *)malloc(size);
    char *buffer_file_2 = (char *)malloc(size);
    char *xor_buffer = (char *)malloc(size);
    memset(buffer_file_1, 0, size);
    memset(buffer_file_2, 0, size);
    for (long long index = 0; index < file_1_size; index ++) {
        buffer_file_1[index] = (*buffer_1)[index];
    }
    for (long long index = 0; index < file_2_size; index ++) {
        buffer_file_2[index] = (*buffer_2)[index];
    }
    
    for (long long index = 0; index < size; index ++){
        xor_buffer[index] = buffer_file_1[index] ^ buffer_file_2[index];
    }
    file_wrire(xor_buffer, size);
    free(buffer_file_1);
    free(buffer_file_2);
    free(xor_buffer);
}

