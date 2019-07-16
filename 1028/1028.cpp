#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct birth
{
	string name;
	int year;
	int month;
	int day;
};

bool cmp(birth a,birth b){
	if(a.year!=b.year)
		return a.year<b.year;
	else if(a.month!=b.month)
		return a.month<b.month;
	return a.day<b.day;
}

int main(){
	int N,j=0;
	cin>>N;
	birth birthday[N];
	for(int i=0;i<N;++i){
		int y,m,d;
		char a,b;
		string n;
		cin>>n;
		cin>>y>>a>>m>>b>>d;
		if( (y<2014||(y==2014&&m<9)||(y==2014&&m==9&&d<=6)) && (y>1814||(y==1814&&m>9)||(y==1814&&m==9&&d>=6)) ){
			birthday[j].name=n;
			birthday[j].year=y;
			birthday[j].month=m;
			birthday[j++].day=d;
		}
	}
	cout<<j;
	if(j!=0){
		sort(birthday,birthday+j,cmp);
		cout<<" "<<birthday[0].name<<" "<<birthday[j-1].name;
	}
	cin>>N;
	return 0;
}