#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(){
	char c;
	string s;
	cin>>c;
	getchar();
	int cnt;
	getline(cin,s);
	if(c=='C'&&s.length() != 0){//这里要判断一下字符串是否为空串
		char pre=s[0];
		cnt=1;
		for(int i=1;i<s.length();++i){
			if(s[i]==pre){
				cnt++;
			}
			else{
				if(cnt==1)
					cout<<pre;
				else
					cout<<cnt<<pre;
				cnt=1;
				pre=s[i];
			}
		}
		if(cnt==1)
			cout<<pre;
		else
			cout<<cnt<<pre;
	}
	else if(c=='D'){
		cnt=0;
		for(int i=0;i<s.length();++i){
			if(isdigit(s[i])){
				cnt=cnt*10+(s[i]-'0');
			}
			else{
				if(cnt){
					for(int j=0;j<cnt;++j)
						cout<<s[i];
				}
				else
					cout<<s[i];
				cnt=0;
			}
		}
	}
	cin>>c;
	return 0;
}