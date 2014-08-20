/*************************************************************************
	> File Name: Configure2.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 07:27:35 AM PDT
 ************************************************************************/

#include "Configure2.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

MyConf::MyConf(const string& filename):fin(filename.c_str()){
       if(!fin){
          throw std::runtime_error("open fin error!\n");
	   }
      
	   string line;
	   while(getline(fin,line)!=NULL){
		   trim_dot(line);
           istringstream stream(line);
		   string key,value;
		   stream>>key>>value;
		   m_map.insert(make_pair(key,value));
	   }
}

map<string,string>& MyConf::get_map(){
	return m_map;
}

MyConf::~MyConf(){
	fin.close();
}

void MyConf::trim_dot(string& line){
    for(string::size_type ix=0;ix!=line.size();ix++){
		if(line[ix]=='='){
			line[ix]=' ';
			break;
		}
	}
}

void MyConf::print(){
	map<string,string>::iterator iter;
	for(iter=m_map.begin();iter!=m_map.end();iter++){
		cout<<iter->first<<"\t"<<iter->second<<endl;
	}
}
