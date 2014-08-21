/*************************************************************************
	> File Name: main.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Sat 16 Aug 2014 08:24:53 AM PDT
 ************************************************************************/

#include "ChatServer.h"
using namespace std;

int main(int argc,char *argv[]){
	ChatServer server(InetAddress(8989));
	server.start();
	return 0;
}

