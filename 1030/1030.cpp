#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	long long p;
	cin>>n>>p;
	int a[n],max=0,res=0;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;++i){
		long long bound=a[i]*p;//用int型测试点5会报错
		for(int j=i+max;j<n;++j){//不用从头遍历，直接从之前的最大结果遍历，否则测试点4会超时
			if(a[j]>bound){
				break;
			}
			res=j-i+1;
			if(max<res)
				max=res;
		}
	}
	cout<<max;
	cin>>n;
	return 0;
}