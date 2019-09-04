#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	string bad,c;
	getline(cin,bad);
	getline(cin,c);
	for(int i=0;i<c.length();++i){
		if(bad.find(toupper(c[i]))!=string::npos)//找到了
			continue;
		if(isupper(c[i])&&bad.find('+')!=string::npos)
			continue;
		cout<<c[i];
	}
	cin>>bad;
	return 0;
}