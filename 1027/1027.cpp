#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int num,x;
	char c;
	cin>>num>>c;
	x = sqrt((num+1)/2);
	int w=2*x-1;
	for(int i=0;i<x;i++)
	{
		for(int q=0;q<i;q++)
			cout<<" ";
		for(int j=i;j<w;j++)
		{
			cout<<c;
		}
		w--;
		cout<<endl;
	}
	for(int i=x-2;i>=0;i--)
	{
		for(int q=i;q>0;q--)
			cout<<" ";
		for(int j=0;j<(x-i)*2-1;j++)
			cout<<c;
		cout<<endl;
	}
	int last=num-2*x*x+1;
	cout<<last;
	return 0;
}