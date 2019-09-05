#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main(){
	int n,cnt=0;;
	cin>>n;
	double sum=0.0,temp;
	for(int i=0;i<n;++i){
		char a[50],b[50];//必须要是char*，string不行
		int flag=0;
		scanf("%s", a);
        sscanf(a, "%lf", &temp);//sscanf() – 从⼀一个字符串串中读进与指定格式相符的数据
        sprintf(b, "%.2f",temp);//sprintf() – 字符串串格式化命令，主要功能是把格式化的数据写⼊入某个字符串串中
        for(int j=0;j<strlen(a);++j){
        	if(a[j]!=b[j]){
        		flag=1;
        		break;
        	}
        }
        if(flag==1 || temp < -1000 || temp > 1000){
        	printf("ERROR: %s is not a legal number\n", a);
            continue;
        }
        else{
        	cnt++;
        	sum += temp;
        }
	}
    if(cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if(cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        cout<<"The average of 0 numbers is Undefined";
    cin>>n;
	return 0;
}