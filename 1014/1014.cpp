#include <iostream>
#include <cctype>
using namespace std;

void express_week(int week)
{
	string result;
	switch(week)
	{
		case 'A':
		{
			result = "MON";
			break;
		}
		case 'B':
		{
			result = "TUE";
			break;
		}
		case 'C':
		{
			result = "WED";
			break;
		}
		case 'D':
		{
			result = "THU";
			break;
		}
		case 'E':
		{
			result = "FRI";
			break;
		}
		case 'F':
		{
			result = "SAT";
			break;
		}
		case 'G':
		{
			result = "SUN";
			break;
		}	
	}
	cout<<result<<" ";

}


int main()
{
	string s1,s2,s3,s4;
	int week,i,hour;
	cin>>s1>>s2>>s3>>s4;
	int max1=s1.length(),max2=s3.length();
	if (s2.length()>s1.length())
		max1=s2.length();
	if(s4.length()>s3.length())
		max2=s4.length();
	for(i=0;i<max1;i++)
	{
		if((s1[i]==s2[i])&&isupper(s1[i]))
		{
			week = s1[i];
			express_week(week);
			break;
		}

	}
	for(int j=i+1;j<max1;j++)
	{
		if(s1[j]==s2[j])
		{
			hour = s1[j];
			if(isdigit(s1[j]))
			{
				cout<<"0"<<hour<<":";
			}
			else
			{
				hour = hour-65+10;
				cout<<hour<<":";
			}
			break;
		}
	}
	for(int w=0;w<max2;w++)
	{
		if(s3[w]==s4[w]&&isalpha(s3[w]))
		{
			if(w<10)
				cout<<"0"<<w;
			else
				cout<<w;
			break;
		}
	}
	return 0;
}