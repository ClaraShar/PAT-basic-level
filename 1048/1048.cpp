#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string A,B,C="";
	cin>>A>>B;
	int lenA=A.length(),lenB=B.length(),i,flag=1;
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	if(lenA>lenB){
		i=lenA;
		B.append(lenA-lenB,'0');
	}
	else if(lenB>lenA){
		i=lenB;
		A.append(lenB-lenA,'0');
	}
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	while(i>0){
		i--;
		if(flag==1){
			int temp=(A[i]+B[i]-'0'-'0')%13;
			if(temp<10)
				C.append(to_string(temp));
			else if(temp==10)
				C.append("J");
			else if(temp==11)
				C.append("Q");
			else if(temp==12)
				C.append("K");
		}
		else if(flag==-1){
			int temp=B[i]-A[i];
			if(temp>=0)
				C.append(to_string(temp));
			else
				C.append(to_string(temp+10));
		}
		flag*=-1;
	}
	reverse(C.begin(),C.end());
	cout<<C;
	return 0;
}