#include <iostream>
#include <string>
using namespace std;

int main(){
	string sell,hong;
	int result=0,arr[1000]={0};
	getline(cin,sell);
	getline(cin,hong);
	for(int i=0;i<sell.length();++i){//统计店主的各有多少珠子
		arr[sell[i]]++;
	}
	for(int i=0;i<hong.length();++i){
		if(arr[hong[i]]>0)
			arr[hong[i]]--;
		else
			result++;
	}
	if(!result)
		cout<<"Yes "<<sell.length()-hong.length();
	else
		cout<<"No "<<result;
	cin>>sell;
	return 0;
}