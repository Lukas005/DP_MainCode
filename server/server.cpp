#include "server.h"
#include <iostream>
#include <cstring>

#include <unistd.h>
//#include <netinet/in.h>
// #include <sys/socket.h>
//#include <sys/types.h>
using namespace std;

Server::Server(int port)
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sockclient = -1;
    if (sock < 0)
        cerr<< "ERROR opening socket";

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);

    if (bind(sock,
        (struct sockaddr *) &serv_addr,
        sizeof(serv_addr)) < 0)
    {
         cerr << "ERROR on binding";
    }

    bzero(buffer,256);
}

int Server::Listen()
{
    socklen_t clilen = sizeof(cli_addr);
    cout << "Listening..." << endl;
    listen(sock, 5);

    sockclient = accept(sock,
        (struct sockaddr *) &cli_addr,
        &clilen);

    cout << "Accepted!" <<endl;
    if (sockclient < 0)
    {
        cerr << "ERROR on accept";
        return 1;
    }

    return 0;
}

int Server::ReadFromClient()
{
    int n;
    n = read(sockclient, buffer, 255);
    if (n < 0)
    {
        cerr<< "ERROR reading from client's socket"<< endl;
        return 1;
    }

    cout << "Received: " << buffer << endl;
}

int Server::WriteToClient(string s)
{
    int n;
    cout << "Sending to the client result" << endl;

    n = write(sockclient, s.c_str(), s.length());
	if (n < 0)
    {
        cerr << "ERROR writing to socket";
        return 1;
    }
    return 0;
}

void Server::CloseClientSocket()
{
    cout << "Closing client's socket." << endl;
    close(sockclient);
    sockclient = -1;
}

Server::~Server()
{
    close(sock);
}
