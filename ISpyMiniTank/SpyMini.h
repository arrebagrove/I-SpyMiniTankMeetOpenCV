#if !defined SPYMINI
#define SPYMINI
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")


class SpyMini
{
private:
	SOCKET sock;
	char *msg;
	char* getMsg();

	void moveIt();

public:
	SpyMini();
	SOCKET getSocket();
	void setMsg(char *msg);
	void connectToTank();
	void setSocket(SOCKET s);
	void forward();
	void backward();
	void turnRigt();
	void turnLeft();
	void stop();
};
#endif