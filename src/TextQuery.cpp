/*************************************************************************
	> File Name: TextQuery.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Mon 18 Aug 2014 02:12:19 AM PDT
 ************************************************************************/

#include "TextQuery.h"
#include <stdexcept>
#include <string.h>
using namespace std;

TextQuery::TextQuery(WordIndex &word):vec_ptr(&word.m_vec),
index_ptr(&word.m_index){
     	
}

/*
void TextQuery::read_file(const string& filename){
	 infile_.open(filename.c_str());
	 if(!infile_){
		 throw std::runtime_error("open file error!\n");
	 }

	 string key,value;
	 while(infile_>>key>>value){
		 mp.insert(make_pair(key,atoi(value.c_str())));
	 }

	 infile_.close();
}


int TextQuery::editDistan(string& s){
	
    int dp[20][20];

	int len1=s.size(),len2=requery_.size();
	for(int i=0;i<=len1;i++){
		dp[i][0]=i;
	}

	for(int j=0;j<=len2;j++){
		dp[0][j]=j;
	}

	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			int cost=requery_[j]==s[i]?0:1;
			dp[i][j]=Min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+cost);
		}
	}

	return dp[len1][len2];
}
*/

int TextQuery::editDistan(const string& a){
	vector<uint32_t> w1,w2;
	parseUTF8String(a,w1);
	parseUTF8String(requery_,w2);
	return edit_distance_uint_32(w1,w2);
}


void TextQuery::statistic(set<int> &st){
	 for(set<int>::iterator iter=st.begin();iter!=st.end();iter++){
		 struct node tmp;
		 tmp.word=(*vec_ptr)[*iter].first;
		 tmp.frequency=atoi((*vec_ptr)[*iter].second.c_str());
		 tmp.editDistance=editDistan(tmp.word);

		 queue_.push(tmp);
	 }
}


string TextQuery::run_query(const string &s){
     while(!queue_.empty()){
		 queue_.pop();
	 }

	 requery_=s;

	/*
	 for(map<string,int>::iterator iter=mp.begin();iter!=mp.end();iter++){
		 struct node tmp;
		 tmp.word=iter->first;
		 tmp.frequency=iter->second;
		 tmp.editDistance=editDistan(tmp.word);

		 queue_.push(tmp);
	 }
	 */
	 size_t index=0;
	 string word;
	 for(;index!=requery_.size();index++){
         word=requery_.substr(index,1);
         statistic((*index_ptr)[word]);
	 }
	 return queue_.top().word;
} 


int TextQuery::getLenOfUTF8(unsigned char c){
	int cnt=0;
	while(c & (1<<(7-cnt))){
		++cnt;
	}
	return cnt;
}


void TextQuery::parseUTF8String(const string &s,vector<uint32_t> &vec){
	vec.clear();

	for(string::size_type ix=0;ix!=s.size();ix++){
		int len=getLenOfUTF8(s[ix]);
		uint32_t t=(unsigned char)s[ix];
		if(len>1){
			--len;
			//拼接剩余的字节
			while(len--){
				t=(t<<8)+(unsigned char)s[++ix];
			}
		}
		vec.push_back(t);
	}
}


int TextQuery::edit_distance_uint_32(const vector<uint32_t> &w1,const vector<uint32_t> &w2){
	int len_a=w1.size();
	int len_b=w2.size();

	int memo[100][100];
	memset(memo,0x00,100*100*sizeof(int));

	for(int i=1;i<=len_a;i++){
		memo[i][0]=i;
	}

	for(int j=1;j<=len_b;j++){
        memo[0][j]=j;
	}

	for(int i=1;i<=len_a;i++){
		for(int j=1;j<=len_b;j++){
			if(w1[i-1]==w2[j-1]){
				memo[i][j]=memo[i-1][j-1];
			}
			else{
				memo[i][j]=Min(memo[i-1][j-1],memo[i][j-1],
						memo[i-1][j])+1;
			}
		}
	}

	return memo[len_a][len_b];
}








