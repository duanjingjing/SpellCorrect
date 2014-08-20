/*************************************************************************
	> File Name: TextQuery.h
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Mon 18 Aug 2014 01:59:31 AM PDT
 ************************************************************************/

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include "WordIndex.h"
#include "Configure2.h"
#include <algorithm>
#include <stdint.h>

struct node{
	std::string word;
	int  frequency;
	int editDistance;
};

struct cmp{
	bool operator()(const struct node&lhs,
			      const struct node&rhs)const{
         if(lhs.editDistance==rhs.editDistance){
			 return lhs.frequency<rhs.frequency;
		 }
		 else{
			 return rhs.editDistance<lhs.editDistance;
		 }
	}
};

class TextQuery{
public:
	TextQuery(WordIndex &word);
    std::string run_query(const std::string&);
    //void read_file(const std::string& filename);
private:
	std::map<std::string,int>  mp;
    std::priority_queue<node,std::vector<node>,cmp> queue_;
    int  editDistan(const std::string&);

	int Min(int a,int b,int c){
		int t=a<b?a:b;
		return t<c?t:c;
	}
    
	int getLenOfUTF8(unsigned char c);
	void parseUTF8String(const std::string& s,std::vector<uint32_t> &vec);
	int edit_distance_uint_32(const std::vector<uint32_t> &w1,const std::vector<uint32_t> &w2);
	std::ifstream infile_;
	std::string requery_;
	void statistic(std::set<int>&);
//	WordIndex &word_;
	std::vector<std::pair<std::string,std::string> >* vec_ptr;
	std::map<std::string,std::set<int> > * index_ptr;
};

#endif
