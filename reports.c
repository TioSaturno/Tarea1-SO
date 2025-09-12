#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include <signal.h>
#define BUFFER 256
typedef struct report
{
    int pid;
    int counter;
} report;
report *reports = NULL;
int size = 0; 
int main(){
    const char *fifo_path = "fifo_path_reports"; 
    int fd_chat;
    mkfifo(fifo_path, 0666);
    fd_chat = open(fifo_path, O_RDONLY);
    char reporte[BUFFER];
    while(1){
        memset(reporte, 0, BUFFER);  
        int n = read(fd_chat, reporte, BUFFER - 1);
        if(n>0){
            reporte[n] = '\0';  
            if(strncmp(reporte, "Reportar", 8) == 0){
                int pid_reportado = atoi(reporte + 9);
                if(pid_reportado > 0){
                  for(int i = 0; i < size; i++){
                      if(reports[i].pid == pid_reportado){
                          reports[i].counter++;
                          printf("Cliente %d ha sido reportado %d veces\n", pid_reportado, reports[i].counter);
                    if(reports[i].counter >= 10){
                        kill(pid_reportado, SIGKILL);
                        printf("Cliente %d ha sido bloqueado por recibir %d reportes\n", pid_reportado, reports[i].counter);
                    }
                    break;
                  }
                }
               struct report *tmpfile = realloc(reports, (size + 1) * sizeof(struct report));
               if(tmpfile == NULL){
                perror("Realloc failed");
                exit(1);
            }
                reports = tmpfile;
                reports[size].pid = pid_reportado;
                reports[size].counter = 1;
                size++;
                printf("Cliente %d ha sido registrado con 1 reporte\n", pid_reportado);
        }

    }
    
   }
  }
    close(fd_chat);
    unlink(fifo_path);
    free(reports); //esto es para liberar el espacio de memoria
    return 0;
}