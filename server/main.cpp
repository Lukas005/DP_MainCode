#include "server.h"
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) {
         cerr << "ERROR, no port provided" << endl;
         return 1;
    }
	Server * s = new Server(atoi(argv[1]));
	s->Listen();
	s->ReadFromClient();
	s->WriteToClient("Test message.");
	s->CloseClientSocket();
	delete s;

	return 0;
}
