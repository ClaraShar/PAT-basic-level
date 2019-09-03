#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    int n,arr[10000]={0},flag=0;
    cin>>n;
    int num[n];
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        num[i]=temp;
        while(temp!=1){
            if(temp%2)
                temp=3*temp+1;
            temp/=2;
            if(arr[temp]==1)
                break;
            arr[temp]=1;
        }
    }
    sort(num,num+n,cmp);
    for(int i=0;i<n;++i){
        if(arr[num[i]]==0){
            if(flag==1){
                cout<<" ";
            }
            cout<<num[i];
            flag=1;
        }
    }
    cin>>n;
    return 0;
}
