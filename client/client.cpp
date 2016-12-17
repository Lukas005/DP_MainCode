#include "client.h"
#include <cstring>
#include <netdb.h>
#include <unistd.h>


using namespace std;

Client::Client(string s, int p)
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        cerr << "ERROR opening socket"<< endl;
    }

    server = gethostbyname(s.c_str());
    if (server == NULL) {
        cerr << "ERROR, no such host" << endl;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    serv_addr.sin_port = htons(p);


    if (connect(sock,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        cerr << "ERROR connecting" << endl;
}

int Client::SendMessageToServer(string s)
{
    int n = write(sock, s.c_str(), s.length());
    if (n < 0)
    {
        cerr << "ERROR writing to socket" << endl;
        return 1;
    }
    return 0;
}

string Client::ReadFromServer()
{
    char buffer[512];
    bzero(buffer, 512);
    int n = read(sock, buffer, 511);
    if (n < 0)
    {
        cerr << "ERROR reading from socket" << endl;
        return "err";
    }
    string s = buffer;
    return s;
}

Client::~Client()
{
    close(sock);
    sock = -1;
}
