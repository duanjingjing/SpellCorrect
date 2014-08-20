#ifndef CONFIGURE_H
#define CONFIGURE_H

#include "MutexLock.h"
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>

class Configure{
public:
    static Configure *getInstance(){
		if(pInstance_==NULL){
			mutex_.lock();
			if(pInstance_==NULL){
				//业务逻辑
			//	ifstream infile("../conf/config.txt");
				if(!infile_){
					throw std::runtime_error("open file error!\n");
				}

				string line;
				while(getline(infile,line)!=NULL){
				   trim_dot(line);

				   string key,value;
				   infile>>key>>value;
                   std::cout<<key<<"\t"<<value<<std::endl;
				   m_map.insert(make_pair(key,value));
				}
				pInstance_=new Configure;
			}
			mutex_.unlock();
		}
		return pInstance_;
	}

	static void print(){
		std::map<std::string,std::string>::iterator iter;
		for(iter=m_map.begin();iter!=m_map.end();iter++){
			std::cout<<iter->first<<"\t"<<iter->second<<std::endl;
		}
	}

private:

   static  void trim_dot(std::string& s){
         for(std::string::size_type ix=0;ix!=s.size();ix++){
			 if(s[ix]=='=') {
				 s[ix]=' ';
				 break;
			 }
		 }
	}

	static std::map<std::string,std::string> m_map;//存放配置文件
    Configure(){}

	static Configure *pInstance_;
	static MutexLock mutex_;
	static ifstream infile_;
};

Configure *Configure::pInstance_=NULL;
MutexLock Configure::mutex_;
ifstream Configure::infile_("../conf/config.txt")
std::map<std::string,std::string> Configure::m_map;











#endif
