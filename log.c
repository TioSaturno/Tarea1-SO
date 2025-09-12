#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h> 
#include <sys/stat.h>
#include <string.h>
#define BUFFER 256
int main()
{ 
  const char *fifo_path= "fifo_path"; 
  int fd_chat;
  mkfifo(fifo_path, 0666);
  printf("Iniciando chat...\n");
  fd_chat = open(fifo_path, O_RDONLY);
    while(1){
        char msg[BUFFER];
        memset(msg, 0, BUFFER);  
        int n = read(fd_chat, msg, BUFFER - 1);
        if(n > 0){
            msg[n] = '\0';  
            printf("Mensaje recibido: %s", msg);
        } else if(n == 0){
            close(fd_chat);
            fd_chat = open(fifo_path, O_RDONLY);
        }
    }
    unlink(fifo_path);
    return 0;
}