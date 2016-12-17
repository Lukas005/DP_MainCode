#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <netinet/in.h>

class Client{
private:
    int sock, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;
public:
    Client(std::string s, int p);
    int SendMessageToServer(std::string s);
    std::string ReadFromServer();
    ~Client();
};

#endif // CLIENT_H
