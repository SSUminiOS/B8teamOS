#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "system.h"
#include "montecarlo_pi.h"
#include "OS_time.h"
#include "createfile.h"
#include "deletefile.h"
#include "writefile.h"

void print_minios(char* str);

int main() {
    print_minios("[MiniOS SSU] Hello, World!");

    char *input;

    while(1) {
        // readline을 사용하여 입력 받기
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input,"exit") == 0) {
            break;
        }

        else if (strcmp(input,"minisystem") == 0) {
            minisystem();
        }
        
        else if (strcmp(input,"montecarlo_pi") ==0) {
            double pi = montecarlo_pi(4);
            printf("montecarlo_pi value : %f\n", pi);
        }
        
        else if (strcmp(input,"time") ==0) {
            get_time();
        }
        
        else if (strcmp(input, "createfile") == 0) {
            char filename[256];
            printf("Enter filename: ");
            scanf("%s", filename);
            createfile(filename); // createfile 시스템 콜 호출
        }
        
        else if (strcmp(input, "deletefile") == 0) {
            char filename[256];
            printf("Enter filename: ");
            scanf("%s", filename);
            deletefile(filename); // deletefile 시스템 콜 호출
        }
        
        else if (strcmp(input, "writefile") == 0) {
            int result = writefile();
            if (result == -1) {
            printf("Write failed.\n");
            } else {
              printf("Write successful.\n");
              }
        }      
        else system(input);
}

    // 메모리 해제
    free(input);
    print_minios("[MiniOS SSU] MiniOS Shutdown........");

    return(1);
}

void print_minios(char* str) {
        printf("%s\n",str);
}
