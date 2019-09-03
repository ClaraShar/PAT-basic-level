#include <iostream>
#include <string>
using namespace std;

int main(){
	string A;
	cin>>A;
	int B,lenA=A.length(),chu=0,Q,R=0;
	cin>>B;
	if(lenA==1&&(A[0]-'0')/B==0)
		cout<<"0";
	for(int i=0;i<lenA;++i){
		chu=R*10+A[i]-'0';
		Q=chu/B;
		R=chu%B;
		if(!Q&&!i)
			continue;
		cout<<Q;
	}
	cout<<" "<<R;
	cin>>A;
	return 0;
}