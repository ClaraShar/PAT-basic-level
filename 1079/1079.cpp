#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string add(string a,string b){
	string temp=a;
	int c=0;
	for(int i=a.size()-1;i>=0;--i){
		temp[i]=(a[i]-'0'+b[i]-'0'+c)%10+'0';
        c=(a[i]-'0'+b[i]-'0'+c)/10;
    }
    if(c>0)
    	temp="1"+temp;
    return temp;
}

int main(){
	string a,b;
	cin>>a;
	int cnt=10;
	while(cnt--){
		b=a;
		reverse(b.begin(),b.end());
		if(a==b){
			cout<<a<<" is a palindromic number."<<endl;
			return 0;
		}
		else{
			string sum=add(a,b);
			cout<<a<<" + "<<b<<" = "<<sum<<endl;
			a=sum;
		}
	}
	cout<<"Not found in 10 iterations.";
	cin>>a;
	return 0;
}