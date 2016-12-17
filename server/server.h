#ifndef _SERVER_H_
#define _SERVER_H_

#include <iostream>
// #include <cstring>
#include <netinet/in.h>

class Server{
private:
    int sock, sockclient;
	struct sockaddr_in serv_addr, cli_addr;
    char buffer[512];
public:
    Server(int );
    int Listen();
    int ReadFromClient();
    int WriteToClient(std::string );
    void CloseClientSocket();
    ~Server();
};

#endif
