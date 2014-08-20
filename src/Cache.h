#ifndef CACHE_H
#define CACHE_H

#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include "MutexLock.h"
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;
//#define HashMap __gnu_cxx

struct MyHashFn{
public:
	size_t operator()(const string& str) const{
		return __stl_hash_string(str.c_str());
	}
};

class Cache{
public:
	void foobar(){cout<<"hello"<<endl;}
	hash_map<string,string,MyHashFn>::iterator is_mapped(const string& word);
	void map_to_cache(string& key,string& value);
	void write_to_file(ostream& fout);
	void read_from_file(const string& filename);
	hash_map<string,string,MyHashFn> m_cache;
private:
	MutexLock m_lock;
};

#endif
