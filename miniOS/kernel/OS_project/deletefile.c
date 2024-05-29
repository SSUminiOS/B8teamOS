#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int deletefile(const char *filename) {
    // 파일 존재 여부 확인
    struct stat st;
    if (stat(filename, &st) != 0) {
        perror("Error checking file existence");
        return -1;
    }

    // 파일 삭제
    if (remove(filename) == 0) {
        printf("File %s deleted successfully.\n", filename);
        return 0;
    } else {
        perror("Error deleting file");
        return -1;
    }
}
