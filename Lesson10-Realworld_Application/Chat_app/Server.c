#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdint.h>

//typedef uint32_t u_int32_t;

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc , char * argv[])
{
    if (argc < 2)
    {
        fprintf(stderr , "Port No not provided. Program terminated\n");
        exit(1);
    }
    
    int sockfd , newsockdf , portno;
    char buffer[255];

    struct sockaddr_in serv_addr , cli_addr; 
    socklen_t clilen; 

    int sockdf = socket(AF_INET , SOCK_STREAM , 0); 
    
    if (sockdf <0)
    {
        error("Error opening Socket.");
    }
    
    bzero( (char * ) &serv_addr , sizeof(serv_addr) );
    int protno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockdf , (struct sockaddr *) &serv_addr , sizeof(serv_addr))< 0)
    {
        error("Binding Failed");
    }

    listen(sockdf , 4);
    clilen = sizeof(cli_addr);
    newsockdf = accept(sockdf , (struct sockaddr*) &cli_addr , &clilen);
    if (newsockdf <0)
    {
        error("Error on Accept");
    }
    
    while(1)
    {
        bzero(buffer , 255);
        int n = read(newsockdf , buffer , 255);
        if (n<0)
        {
            error("Error on reading");
        }
        printf("Client: %s\n" , buffer);
        bzero(buffer , 255);
        fgets(buffer , 255 , stdin);
        int w = write(newsockdf , buffer , strlen(buffer));
        if (w <0)
        {
            error("Error on writing");
        }
        int i = strncmp("Bye" , buffer , 3);
        if (i == 0)
        {
            break ; 
        }
    }
close(newsockdf);
close(sockdf);
return 0;

}