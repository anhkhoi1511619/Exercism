// Client side C program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#define PORT 51111

char *init_text(char *input);
 
int main(int argc, char const* argv[])
{
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    int function = 0;
    printf("Please choose a function:\n>>");
    scanf("%d", &function);

    char *text = init_text(text);

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
 
    if ((status
         = connect(client_fd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    do
    {
        if(strlen(text) != 0) {
            send(client_fd, text, strlen(text), 0);
            printf("Message sent: %s\n", text);
            valread = read(client_fd, buffer,1024 - 1); // subtract 1 for the null
                                                        // terminator at the end
            printf("Message received: %s\n", buffer);
            
            free(text);
        } else{
            text = init_text(text);
        }
    } while (function != -1);
    // closing the connected socket
    close(client_fd);
    return 0;
}

char *init_text(char *text) {
    text = (char *)malloc(100 * sizeof(char)); // Allo`cate memory for the input string
    if (text == NULL) {
        printf("Memory allocation failed\n");
    }

    printf("Please type message to send to server:\n>> ");
    scanf("%99s", text); // Use %99s to avoid buffer overflow
    return text;
}