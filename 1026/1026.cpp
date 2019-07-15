#include <iostream>
using namespace std;

int main(){
	int C1,C2;
	cin>>C1>>C2;
	int second=(C2-C1+50)/100;
	int a=second/3600;
	int b=second%3600/60;
	int c=second%60;
	printf("%02d:%02d:%02d",a,b,c);
	cin>>C1;
	return 0;
}