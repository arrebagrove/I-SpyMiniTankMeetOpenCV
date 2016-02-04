// ISpyMiniTank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SpyMini.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	SpyMini robot;

	robot.connectToTank();
	robot.forward();
	robot.backward();
	robot.turnLeft();
	getchar();
	return 0;
}

