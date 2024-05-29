#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "writefile.h"

int writefile() {
    char filename[256];
    printf("Enter filename: ");
    scanf("%255s", filename);  // 파일 이름 입력 받기 (최대 255자)

    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("writefile");
        return -1;
    }

    char buffer[256];
    printf("Enter content to write (max 255 characters): ");
    scanf(" %[^\n]", buffer);  // 파일 내용 입력 받기 (공백 포함하여 한 줄)

    ssize_t bytes_written = write(fd, buffer, strlen(buffer));
    if (bytes_written == -1) {
        perror("writefile");
        close(fd);
        return -1;
    }

    close(fd);
    return bytes_written;
}
