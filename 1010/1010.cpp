#include <iostream>
using namespace std;

int main()
{
    int a,b,flag=0;
    while(cin>>a>>b)
    {
        if(b){
            if(flag==1)
                cout<<" ";
            cout<<a*b<<" "<<b-1;
            flag=1;
        }
    }
    if (flag == 0) cout << "0 0";
    cin>>a;
    return 0;
}
