/*************************************************************************
	> File Name: WordIndex.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 11:05:07 PM PDT
 ************************************************************************/

#ifndef WORDINDEX_H
#define WORDINDEX_H

#include "Configure2.h"
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <fstream>

class WordIndex{
	friend class TextQuery;
public:
   WordIndex(MyConf &conf);
   ~WordIndex();
   void read_file(const  std::string& filename);
   void index_to_map(int i,std::map<std::string,std::set<int> >& m_map);

   void print();
private:
	   std:: map<std::string,std::set<int> > m_index;//存放一个字符或者汉字的词在m_vec中的位置
	   std::vector<std::pair<std::string,std::string> >m_vec;//存放词典文件的内容
       MyConf & myConf_;
	   std::ifstream fin_;
};

#endif
