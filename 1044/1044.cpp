#include <iostream>
#include <typeinfo>
#include <math.h>
#include <algorithm>
#include <regex>
using namespace std;

void to_mars(string s){
	int len=s.length(),i=len,num=0;
	string marsQ[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	string marsR[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	while(i){
		i--;
		num+=(s[i]-'0')*pow(10,len-i-1);
	}
	int Q=num/13,R=num%13;
	if(Q&&R)
		cout<<marsQ[Q]<<" "<<marsR[R]<<endl;
	else if(!Q&&R)
		cout<<marsR[R]<<endl;
	else if(Q&&!R)
		cout<<marsQ[Q]<<endl;
	else if(!Q&&!R)
		cout<<"tret"<<endl;
}

void to_earth(string s){
	string VQ[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	string VR[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};	
	int pos=s.find(' '),num=0;
	if(pos!=-1){
		string Q=s.substr(0,pos);
		string R=s.substr(pos+1,s.length()-pos-1);
		string *posQ=find(VQ,VQ+13,Q);
		string *posR=find(VR,VR+13,R);
		num=(posQ-VQ)*13+(posR-VR);
		cout<<num<<endl;
	}
	else{
		string *posQ=find(VQ,VQ+13,s);
		string *posR=find(VR,VR+13,s);
		if(posQ!=VQ+13){//找到了
			num=(posQ-VQ)*13;
			cout<<num<<endl;
		}
		else if(posR!=VR+13){
			num=posR-VR;
			cout<<num<<endl;
		}
	}
}

int main(){
	int n;
	cin>>n;
	cin.ignore();//cin和getline同时使用时需要清除缓冲区
	regex reg("[0-9]+");
	for(int i=0;i<n;++i){
		string s;
		getline(cin,s);//getline可以接受输入字符串带空格
		bool bValid=regex_match(s,reg);
		if(bValid)//全数字
			to_mars(s);
		else
			to_earth(s);
	}
	return 0;
}
