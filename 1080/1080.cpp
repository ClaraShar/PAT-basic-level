#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct total_sort
{
	string id;
	int total;
};

bool cmp(total_sort a,total_sort b){
	if(a.total!=b.total)
		return a.total>b.total;
	return a.id<b.id;
}

struct pass
{
	double pg_score;
	double mid_score;
	double final_score;
	double total;
};

int main(){
	int p,m,n;
	cin>>p>>m>>n;
	map<string,pass> table;
	vector<string> v;
	vector<total_sort> ts;
	for(int i=0;i<p;++i){
		string id;
		double p_score;
		cin>>id>>p_score;
		if(p_score<200)
			continue;
		else{
			pass stu={p_score,-1,-1,0};
			v.push_back(id);
			table[id]=stu;
		}
	}
	for(int i=0;i<m;++i){
		string id;
		double m_score;
		cin>>id>>m_score;
		if(table.find(id)==table.end())//编程不合格
			continue;
		else
			table[id].mid_score=m_score;
	}
	for(int i=0;i<n;++i){
		string id;
		double f_score;
		cin>>id>>f_score;
		if(table.find(id)==table.end())//编程不合格
			continue;
		else
			table[id].final_score=f_score;
	}
	for(int i=0;i<v.size();++i){
		if(table[v[i]].mid_score>table[v[i]].final_score){
			table[v[i]].total=int(table[v[i]].mid_score*0.4+table[v[i]].final_score*0.6+0.5);//这里就要四舍五入
		}
		else
			table[v[i]].total=table[v[i]].final_score;
		if(table[v[i]].total>=60){
			total_sort temp;
			temp.id=v[i];
			temp.total=table[v[i]].total;//如果这里才四舍五入就要出错
			ts.push_back(temp);
		}
	}
	sort(ts.begin(),ts.end(),cmp);
	for(int i=0;i<ts.size();++i)
		cout<<ts[i].id<<" "<<table[ts[i].id].pg_score<<" "<<table[ts[i].id].mid_score<<" "<<table[ts[i].id].final_score<<" "<<ts[i].total<<endl;
	cin>>p;
	return 0;
}