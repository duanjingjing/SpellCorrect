/*************************************************************************
	> File Name: WordIndex.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Wed 20 Aug 2014 12:45:08 AM PDT
 ************************************************************************/

#include "WordIndex.h"
#include <stdexcept>
using namespace std;

WordIndex::WordIndex(MyConf &conf):myConf_(conf){
	read_file(myConf_.get_map()["word_lib"]);
}

WordIndex::~WordIndex(){
	fin_.close();
}

void WordIndex::read_file(const string& filename){
	 fin_.open(filename.c_str());
	 if(!fin_){
		 throw std::runtime_error("open file error!\n");
	 }

	 string key,word;
	 while(fin_>>key>>word){
		 m_vec.push_back(make_pair(key,word));
	 }

	 for(size_t ix=0;ix!=m_vec.size();ix++){
		 index_to_map(ix,m_index);
	 }
}

void WordIndex::index_to_map(int i,map<string,set<int> >& m_map){
     size_t index=0;
	 string key,word;

	 key=m_vec[i].first;
	 for(;index!=key.size();index++){
		 word=key.substr(index,1);
		 m_map[word].insert(i);
	 }
}

void WordIndex::print(){
	for(vector<pair<string,string> >::size_type ix=0;ix!=m_vec.size();ix++){
		cout<<m_vec[ix].first<<"\t"<<m_vec[ix].second<<endl;
	}

	cout<<"====================================="<<endl;
	for(map<string,set<int> >::iterator iter=m_index.begin();iter!=m_index.end();iter++){
		cout<<iter->first<<" ";
		set<int> tmp=iter->second;

		for(set<int>::iterator it=tmp.begin();it!=tmp.end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}


