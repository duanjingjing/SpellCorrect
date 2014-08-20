/*************************************************************************
	> File Name: ProcessDictEn.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Tue 19 Aug 2014 11:26:43 PM PDT
 ************************************************************************/

#include "ProcessDictEn.h"
#include <stdexcept>
#include <sstream>
using namespace std;

void ProcessDictEn::read_file(const string& filename){
	infile_.open(filename.c_str());
	if(!infile_){
        throw std::runtime_error("open file error!\n");
	}
    
	string line;
	while(getline(infile_,line)!=NULL){
		trim_dot(line);
		istringstream stream(line);
		string word;
		while(stream>>word){
			mp[word]++;
		}
	} 
	
	infile_.close();
	store_file("../data/word_lib.dat");
}
        
void ProcessDictEn::store_file(const string& filename){	
	ofstream fout;
	fout.open(filename.c_str());
	if(!fout){
		throw std::runtime_error("open write file error");
	}

	for(map<string,int>::iterator iter=mp.begin();iter!=mp.end();iter++){
		fout<<iter->first<<"\t"<<iter->second<<endl;
	}

    fout.close();
}

void ProcessDictEn::trim_dot(string& s){
	for(string::iterator iter=s.begin();iter!=s.end();iter++){
       if(ispunct(*iter)){
		   *iter=' ';
	   }
	   else if(isupper(*iter)){
		   *iter=tolower(*iter);
	   }
	}
}

	


