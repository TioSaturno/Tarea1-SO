#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h> 
#include <sys/stat.h>
#define BUFFER 256

int main(){
   int reports = 0;
   int pid = getpid();
   printf("Conectando Cliente %d\n", pid);

   const char *fifo_path = "fifo_path";
   int fd_chat;

   mkfifo(fifo_path, 0666);
   printf("Cliente conectado \n");
   while(1){
       char mensaje[BUFFER];
       printf("Escriba un mensaje(Ingrese \"Salir\" para desconectarse): \n");
       printf("Para reportar a alguien use el formato: Reportar <PID>\n");
       printf("Para clonar el cliente actual en una nueva terminal, escriba: Clonar\n");
       fd_chat = open(fifo_path, O_WRONLY);
       fgets(mensaje, BUFFER, stdin);
       sprintf(mensaje + strlen(mensaje), " (Cliente %d)", pid);
       if(strncmp(mensaje, "Salir", 5) == 0){
           printf("Desconectando cliente %d\n", pid);
           close(fd_chat);
           break;
       }
         if(strncmp(mensaje, "Reportar", 8) == 0){

              printf("Cliente %d ha realizado %d reportes\n", pid, reports);
              const char *fifo_reports = "fifo_path_reports";
              int fd_reports = open(fifo_reports, O_WRONLY);
              if(fd_reports != -1){
                  write(fd_reports, mensaje, strlen(mensaje));
                  close(fd_reports);
              }
              close(fd_chat);
              continue;
         }
         if(strncmp(mensaje, "Clonar", 6) == 0){
             int child_pid = fork();
             if(child_pid == 0){
                 execl("/usr/bin/gnome-terminal", "gnome-terminal", "--", "./client", NULL);
                 perror("execl failed");
                 exit(1);
             } else if(child_pid > 0){
                 printf("Cliente %d ha clonado un nuevo cliente con PID %d en nueva terminal\n", pid, child_pid);
             } else {
                 perror("Fork failed");
             }
             close(fd_chat);
             continue;
         }
       write(fd_chat, mensaje, strlen(mensaje));
      
   }
   close(fd_chat);
   unlink(fifo_path);
   return 0;
}