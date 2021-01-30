#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <netinet/in.h>
#include <time.h>
#define PORT 5000

int sockfd = 0,acceptfd = 0 ,serv_send;
char sent[1024];
char *serv_msg = "Hi from the server";
struct sockaddr_in serv_env;
//time_t ticks;
int val;

int main(int argc,char *argv[]){

// creating socket
sockfd = socket(AF_INET,SOCK_STREAM,0);
if (sockfd < 0) {
   /* code here */ 
   perror("Error:");
   exit(1);
}else {
   /* code here */ 
   puts("----------Socket created --------");
}

// set memmory locations values
 memset(&serv_env,'0',sizeof(serv_env));
bzero(sent,strlen(sent));

// establish server port and address
serv_env.sin_family = AF_INET;
serv_env.sin_port = htons(PORT);
serv_env.sin_addr.s_addr = htonl(INADDR_ANY);
// binding the connection
bind(sockfd,(struct sockaddr*)&serv_env,sizeof(serv_env));

// listening to the clients
int lisen = listen(sockfd,10);// listening to 10 clients maximum
 if (lisen < 0) {
   /* code here */ 
   perror("listen() failed:");
   exit(1);
 } else {
   /* code here */ 
   puts("*********Handshake was sucessful*******");
 }

while (1) { // Infinite loop to keep the server running
int len = sizeof(serv_env);
    acceptfd = accept(sockfd,(struct sockaddr*)&serv_env, &len);
   // snprintf(sent,sizeof(sent),"%.24s\r\n",ctime(&ticks));// storing the time in the data variable.
      serv_send = send(acceptfd,serv_msg,strlen(serv_msg),0);
      serv_send < 0 ? perror("send() failed") : puts("Message sent.....");
   close(acceptfd);
    sleep(1);// Sleep the server for 1 seconds to prevent it from over use the CPU processing.
   }
   
return 0;

}