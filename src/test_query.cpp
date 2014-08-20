/*************************************************************************
	> File Name: demo.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Wed 20 Aug 2014 05:24:28 AM PDT
 ************************************************************************/

#include "TextQuery.h"
#include "QueryServer.h"
#include<iostream>
using namespace std;

int main(int argc,const char* argv[]){
	MyConf conf("../conf/config.txt");
	WordIndex word(conf);
    QueryServer server(InetAddress(8989),word);
    
	server.start();
	
}

