#include <iostream>
#include <vector>
using namespace std;
bool isprime(int a) {
    for (int i = 2; i * i <= a; i++)
        if(a % i == 0)
        	return false;
    return true;
}

int main(){
	int m,n,cnt_ten=1,cnt_prime=0,num=2;//cnt_prime用来数素数的个数
	cin>>m>>n;
	vector<int> v;//将Pm到Pn的所有素数存入vector中
	while(cnt_prime<n){
		if (isprime(num)) {
            cnt_prime++;
            if (cnt_prime >= m)//在m-n的范围内才存入
            	v.push_back(num);
        }
		num++;
	}
	for(int i=0;i<v.size();++i){
		if(cnt_ten==1){
			cout<<v[i];
			cnt_ten++;
		}
		else{
			cout<<" "<<v[i];
			if(cnt_ten==10){
				cout<<endl;//每输出10个就输出一个空行
				cnt_ten=1;
			}
			else{
				cnt_ten++;
			}
		}
	}
	cin>>m;
	return 0;
}