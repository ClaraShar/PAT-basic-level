#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int N,M;
	cin>>N;
	map<string,string> m,att;
	for(int i=0;i<N;++i){
		string boy,girl;
		cin>>boy>>girl;
		m[boy]=girl;
		m[girl]=boy;
	}
	cin>>M;
	for(int i=0;i<M;++i){
		string no;
		cin>>no;
		att[no]=1;
	}
	int j=0;
	string single[M];
	for(auto it=att.begin();it!=att.end();++it){
		if(m.find(it->first)==m.end() || (m.find(it->first)!=m.end()&&att.find(m[it->first])==att.end())){//没有伴侣或伴侣没来
			single[j++]=it->first;
		}
	}
	sort(single,single+j);
	cout<<j<<endl;
	for(int i=0;i<j-1;++i){
		cout<<single[i]<<" ";
	}
	if(j>0)
		cout<<single[j-1];
	return 0;
}