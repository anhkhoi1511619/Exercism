// Client side C program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#define PORT 51111

char *init_text(char *input);
void *read_data_socket_func();
void *send_data_socket_func();

int function = 0;
int client_fd;
char* text;
 
int main(int argc, char const* argv[])
{
    int status, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    printf("Please choose a function:\n>>");
    scanf("%d", &function);

    text = init_text(text);

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

    pthread_t read_data_socket;
    pthread_t send_data_socket;

    pthread_create(&read_data_socket, NULL, read_data_socket_func, NULL);
    pthread_create(&send_data_socket, NULL, send_data_socket_func, NULL);

    pthread_exit(NULL);

    // closing the connected socket
    close(client_fd);
    return 0;
}

char *init_text(char *text) {
    text = (char *)malloc(100 * sizeof(char)); // Allo`cate memory for the input string
    if (text == NULL) {
        printf("Memory allocation failed\n");
    }
    printf("Please type message to send for server:\n>> ");
    scanf(" ");

    scanf("%99[^\n]s", text); // Use %99s to avoid buffer overflow
    printf("You entered: %s length: %lu\n", text, strlen(text));
    return text;
}

void* read_data_socket_func()
{
    do
    {
        char buffer[1024] = { 0 };
        int valread = read(client_fd, buffer,
                   1024 - 1); // subtract 1 for the null
                              // terminator at the end
        if(valread > 0) {
            printf("Message received: %s\n", buffer);
        } else{
            printf("Checking data from socket\n");
        }
    } while (function != -1);

}
void* send_data_socket_func()
{
    do
    {
        if(strlen(text) != 0) {
            send(client_fd, text, strlen(text), 0);
            printf("Message sent: %s\n", text);
            free(text);
        } else{
            text = init_text(text);
        }
    } while (function != -1);
}