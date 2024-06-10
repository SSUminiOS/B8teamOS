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
#include "syscall.h"
#include "event_control.h"

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
        
        //현우
        else if (strcmp(input,"time") ==0) {
            get_time();
        }
        
        //지민
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
        
        //인아
        else if (strcmp(input, "IPC_write") == 0) {
            IPC_W();
        }
        
         else if (strcmp(input, "IPC_read") == 0) {
            IPC_R();
        }
        
        //준영
        else if (strcmp(input, "fork") == 0) {
            Fork();
        }
        
        else if (strcmp(input, "exec") == 0) {
            Exec();
        } 
        
        else if (strcmp(input, "abort") == 0) {
            Abort();
        }
        
        else if (strcmp(input, "exit_program") == 0) {
            int status;
            printf("Enter exit status: ");
            scanf("%d", &status);
            Exit(status);
        }
        
        else if (strcmp(input, "wait_time") == 0) {
            int seconds;
            printf("Enter wait time in seconds: ");
            scanf("%d", &seconds);
            wait_time(seconds);  
        }
        
        else if (strcmp(input, "wait_event") == 0) {
            wait_for_event();
        }
        
        else if (strcmp(input, "signal_event") == 0) {
            signal_event();
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
//ㅇㅇ
