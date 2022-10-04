//
//  main.c
//  file_redundancy
//
//  Created by 筱因 on 2022/10/4.
//

#include "file_xor.h"
int main(int argc, char * argv[]) {
    menu(argc, ++argv, &file_1, &file_2);
    file_1_size = file_read(file_1, &buffer_1);
    file_2_size = file_read(file_2, &buffer_2);
    file_xor(&buffer_1, &buffer_2);
    free(buffer_1);
    free(buffer_2);
    return 0;
}
