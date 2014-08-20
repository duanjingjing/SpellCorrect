/*************************************************************************
	> File Name: ProcessDictEn.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 11:21:58 PM PDT
 ************************************************************************/

#ifndef PROCESSDICTEN_H
#define PROCESSDICTEN_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>

class ProcessDictEn{
public:
	void read_file(const std::string& filename);

private:
	void store_file(const std::string& filename);
	std::fstream infile_;
	void trim_dot(std::string&);
	std::map<std::string,int> mp;
};



#endif

