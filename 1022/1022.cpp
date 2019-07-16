#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int A,B,D;
	cin>>A>>B>>D;
	int sum=A+B;
	if(sum==0)
		cout<<"0";
	else{
		string s="";
		while(sum){
			int b=sum%D;
			s.append(to_string(b));
			sum/=D;
		}
		reverse(s.begin(),s.end());
		cout<<s;
	}
	cin>>A;	
	return 0;
}