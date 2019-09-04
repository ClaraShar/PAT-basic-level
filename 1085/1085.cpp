#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

struct node
{
	string school;
	int score,cnt;//加权总分，考生人数
};

bool cmp(node a,node b){
	if(a.score!=b.score)
		return a.score>b.score;
	else if(a.cnt!=b.cnt)
		return a.cnt<b.cnt;
	else
		return a.school<b.school;
}

int main(){
	int n;
	cin>>n;
	unordered_map<string,double> school_mark;
	unordered_map<string,int> school_stu;//学校得分，学校参赛人数
	for(int i=0;i<n;++i){
		string id,school_name;
		double t;//分数
		cin>>id>>t>>school_name;
		for(int k=0;k<school_name.length();++k)
			school_name[k]=tolower(school_name[k]);
		if(id[0]=='B')
			t/=1.5;
		else if(id[0]=='T')
			t*=1.5;
		school_mark[school_name]+=t;
		school_stu[school_name]++;		
	}
	node r[school_mark.size()];
	int w=0;
	for(auto it=school_mark.begin();it!=school_mark.end();++it){
		r[w].school=it->first;
		r[w].score=it->second;
		r[w++].cnt=school_stu[it->first];
	}
	sort(r,r+school_mark.size(),cmp);
	cout<<school_mark.size()<<endl;
	int pre=-1,range=0;
	for(int j=0;j<school_mark.size();++j){
		if(r[j].score!=pre)
			range=j+1;
		pre=r[j].score;
		cout<<range<<" "<<r[j].school<<" "<<r[j].score<<" "<<r[j].cnt<<endl;
	}
	cin>>n;
	return 0;
}