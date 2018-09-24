#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct score
{
	string id;
	int de;
	int cai;
	int sum;
}score;

bool cmp(score A,score B)   
{
	if(A.sum>B.sum)
		return true;
	else if(A.sum==B.sum)
	{
		if(A.de>B.de)
			return true;
		else if(A.de==B.de)
		{
			if(A.id<B.id)
				return true;
		}
	}
	return false;
}

int main()
{
	int students,low,high,enroll=0;
	string id;
	int de,cai;
	cin>>students>>low>>high;
	if(students==0)
		exit(0);
	score s[students];
	int z=0;
	for(int i=0;i<students;i++)
	{
		cin>>id>>de>>cai;
		if(de<low&&cai<low)
			continue;
		if(de>=low&&cai>=low)
		{
			enroll+=1;
			s[z].id=id;
			s[z].de=de;
			s[z].cai=cai;
			s[z].sum=s[z].de+s[z].cai;
			z++;
		}
	}
	cout<<enroll<<endl;
	score first[enroll];
	score second[enroll];
	score third[enroll];
	score fourth[enroll];
	int j=0,w=0,q=0,a=0;
	for(int i=0;i<enroll;i++)
	{
		if(s[i].de>=high&&s[i].cai>=high)
		{
			first[j].id=s[i].id;
			first[j].de=s[i].de;
			first[j].cai=s[i].cai;
			first[j].sum=s[i].sum;
			j++;
		}
		else if(s[i].de>=high&&s[i].cai<high)
		{
			second[w].id=s[i].id;
			second[w].de=s[i].de;
			second[w].cai=s[i].cai;
			second[w].sum=s[i].sum;
			w++;
		}
		else if(s[i].de<high&&s[i].cai<high&&s[i].de>=s[i].cai)
		{
			third[q].id=s[i].id;
			third[q].de=s[i].de;
			third[q].cai=s[i].cai;
			third[q].sum=s[i].sum;
			q++;
		}
		else
		{
			fourth[a].id=s[i].id;
			fourth[a].de=s[i].de;
			fourth[a].cai=s[i].cai;
			fourth[a].sum=s[i].sum;
			a++;
		}
	}
	sort(first,first+j,cmp);
	sort(second,second+w,cmp);
	sort(third,third+q,cmp);
	sort(fourth,fourth+a,cmp);
	for(int i=0;i<j;i++)
		cout<<first[i].id<<" "<<first[i].de<<" "<<first[i].cai<<endl;
	for(int i=0;i<w;i++)
		cout<<second[i].id<<" "<<second[i].de<<" "<<second[i].cai<<endl;
	for(int i=0;i<q;i++)
		cout<<third[i].id<<" "<<third[i].de<<" "<<third[i].cai<<endl;
	for(int i=0;i<a;i++)
		cout<<fourth[i].id<<" "<<fourth[i].de<<" "<<fourth[i].cai<<endl;
	return 0;
}