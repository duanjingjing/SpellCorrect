#include "Cache.h"

hash_map<string,string,MyHashFn>::iterator Cache::is_mapped(
	const string&word){
	return m_cache.find(word);
}

void Cache::map_to_cache(string& key,string& value){
	m_lock.lock();
	m_cache[key]=value;
	m_lock.unlock();
}

void Cache::write_to_file(ostream& fout){
	m_lock.lock();
	hash_map<string,string,MyHashFn>::iterator iter;
	for(iter=m_cache.begin();iter!=m_cache.end();iter++){
		fout<<iter->first<<'\t'<<iter->second<<endl;
	}
	m_lock.unlock();
}

void Cache::read_from_file(const string& filename){
    ifstream infile(filename.c_str());
	if(!infile){
		throw std::runtime_error("open read_file error!\n");
	}

    string key,value;
	while(infile>>key>>value){
        m_cache.insert(make_pair(key,value));
	}
	infile.close();

	hash_map<string,string,MyHashFn>::iterator iter;
	for(iter=m_cache.begin();iter!=m_cache.end();iter++){
		cout<<iter->first<<'\t'<<iter->second<<endl;
	}
}


