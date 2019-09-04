#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n;
	cin>>n;
	if(n==6174){
		cout<<"7641 - 1467 = 6174";
		return 0;
	}
	int sub=n;
	while(sub!=6174){
		int num[4];
		num[0] = sub / 1000;
	    num[1] = sub / 100 % 10;
	    num[2] = sub / 10 % 10;
	    num[3] = sub % 10;
		sort(num,num+4,cmp);
		int a=0,b=0;
		for(int j=0;j<4;++j){
			a+=num[j]*pow(10,3-j);
			b+=num[3-j]*pow(10,3-j);
		}
		sub=a-b;
		if(!sub){
			printf("%04d - %04d = 0000", a, b);
			return 0;
		}
		printf("%04d - %04d = %04d\n", a, b, sub);
	}
	cin>>n;
	return 0;
}