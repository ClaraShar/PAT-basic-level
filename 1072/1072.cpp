#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
	int N,M,cnt_peo=0,cnt_stuff=0;
	cin>>N>>M;
	set<int> check;
	for(int i=0;i<M;++i){
		int temp;
		cin>>temp;
		check.insert(temp);
	}
	string name;
	for(int i=0;i<N;++i){
		int cnt,flag=0;
		cin>>name>>cnt;
		for(int i=0;i<cnt;++i){
			int temp;
			cin>>temp;
			if(check.find(temp)!=check.end()){
				if(flag==0){
					flag=1;
					cout<<name<<":";
				}
				cnt_stuff++;
				printf(" %04d",temp);
			}
		}
		if(flag){
			cout<<endl;
			cnt_peo++;
		}
	}
	cout<<cnt_peo<<" "<<cnt_stuff;
	return 0;
}