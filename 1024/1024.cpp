#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int pos_e,pos_d,l=s.length(),index;
	char temp[l];

	for(int i=0;i<l;i++)
	{
		if(s[i]=='E')
			pos_e=i;
		else if(s[i]=='.')
			pos_d=i;
	}
	
	if(s[0]=='-')
		cout<<"-";
	
	for(int i=pos_e+2,j=0;i<l;i++)
		temp[j++]=s[i];
	index=atoi(temp);

	if(s[pos_e+1]=='-')
	{
		cout<<"0.";
		for(int i=0;i<index-1;i++)
			cout<<"0";
		cout<<s[1];
		for(int i=pos_d+1;i<pos_e;i++)
			cout<<s[i];
	}

	if(s[pos_e+1]=='+')
	{
		cout<<s[1];
		for(int i=pos_d+1;i<pos_e;i++)
			cout<<s[i];
		int num_0=index-pos_e+3;
		for(int i=0;i<num_0;i++)
			cout<<"0";
	}
	return 0;
}