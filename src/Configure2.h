/*************************************************************************
	> File Name: Configure2.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 07:23:26 AM PDT
 ************************************************************************/

#ifndef CONFIGURE2_H
#define CONFIGURE2_H

#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class MyConf{
public:
    MyConf(const std::string& name);
	~MyConf();
	std::map<std::string,std::string>& get_map();
	void print();
	
private:
	std::map<std::string,std::string> m_map;//存放配置文件内容
	void trim_dot(std::string&);
	std::ifstream fin;
};





#endif
