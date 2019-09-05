#include <iostream>
using namespace std;

int main(){
	int n,D,maybe=0,must=0;
	float e;
	cin>>n>>e>>D;
	for(int i=0;i<n;++i){
		int k,cnt_e=0;
		cin>>k;
		for(int j=0;j<k;++j){
			float Ei;
			cin>>Ei;
			if(Ei<e)
				cnt_e++;
		}
		if(cnt_e>(k/2)){//这个地方的逻辑是关键，先判断是否空置，如果观察期大于阈值，那么为绝对空置，否则就是可能空置
			if(k>D)
				must++;
			else
				maybe++;
		}
	}
	printf("%.1f", maybe*100.0/n);//注意输出格式
	cout<<"% ";//printf中要使⽤用两个百分号%%表示输出⼀一个百分号，所以我选择用cout
	printf("%.1f", must*100.0/n);
	cout<<"%";
	cin>>n;
	return 0;
}