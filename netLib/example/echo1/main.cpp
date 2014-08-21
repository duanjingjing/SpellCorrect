/*************************************************************************
	> File Name: main.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Sat 16 Aug 2014 08:07:57 AM PDT
 ************************************************************************/

#include "EchoServer.h"
using namespace std;

int main(int argc,char *argv[]){
	EchoServer server(InetAddress(8989));
	server.start();
	return 0;
}

