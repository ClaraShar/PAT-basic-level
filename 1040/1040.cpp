#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin>>s;
	int countt=0,countp=0,result=0;
	for(int i=0;i<s.length();++i)
		if(s[i]=='T')
			countt++;
	for(int i=0;i<s.length();++i){
		if(s[i]=='P')
			countp++;
		if(s[i]=='A')
			result=(result+countt*countp%1000000007)%1000000007;
		if(s[i]=='T')
			countt--;
	}
	cout<<result;
	cin>>s;
	return 0;
}