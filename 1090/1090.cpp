#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	map<int,vector<int> > incompatible;
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		incompatible[a].push_back(b);
		incompatible[b].push_back(a);
	}
	for(int i=0;i<M;++i){
		int total,flag=1,a[100000]={0};//用数组a来存储每一单有哪些物体
		cin>>total;
		vector<int> v;
		for(int j=0;j<total;++j){
			int temp;
			cin>>temp;
			v.push_back(temp);
			a[temp]=1;
		}
		//下面的双重循环稍微有点晕
		for(int j=0;j<total;++j){
			for(int k=0;k<incompatible[v[j]].size();++k){//k对map[int]的vector计数遍历
				if(a[incompatible[v[j]][k]]==1){//对于每一样物品v[j]在与其不相容的名单incompatible[v[j]]内，如果a[]==1,证明在这一单有物品存在在该不相容名单内
					flag=0;
					break;
				}
			}
		}
		if(flag==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}