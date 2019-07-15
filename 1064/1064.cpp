#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;
	set<int> s;
	for(int i=0;i<N;++i){
		int num,id=0;
		cin>>num;
		while(num){
			id+=num%10;
			num/=10;
		}
		s.insert(id);
	}
	cout<<s.size()<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
        if(it!= s.begin())
        	cout<<" ";
        cout<<*it;
    }
	cin>>N;
	return 0;
}