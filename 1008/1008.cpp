#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    M%=N;//n倍数位的移动是多余的
    vector<int> a(N);
    for(int i=0;i<N;i++)
        cin>>a[i];
    reverse(a.begin(),a.begin()+N);
    reverse(a.begin(),a.begin()+M);
    reverse(a.begin()+M,a.end());//reverse是左闭右开区间
    for(int i=0;i<N-1;++i)
        cout<<a[i]<<" ";
    cout<<a[N-1];
    return 0;
}
