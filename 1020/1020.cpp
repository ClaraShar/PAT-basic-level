#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct mooncake
{
	double stock;
	double sale;
	double each_sale;
} mooncake;
mooncake m[1000];

bool cmp(mooncake A,mooncake B)   
{
	if(A.each_sale!=B.each_sale)//让结构体按单位售价递减排序 
	{
		return A.each_sale>B.each_sale;
	}
	else//如果单位售价相同的话，按总售价递减排序 
	{
		return A.sale>B.sale;
	}
}

int main()
{
	int kind,max_demand;
	double result=0.0;
	cin>>kind>>max_demand;
	for(int i=0;i<kind;i++)
		cin>>m[i].stock;
	int sale[kind];
	for(int i=0;i<kind;i++)
		cin>>m[i].sale;
	for(int i=0;i<kind;i++)
		m[i].each_sale=m[i].sale/m[i].stock;
	sort(m,m+kind,cmp);//降序排序 
	for(int i=0;i<kind;i++)    
	{
		if(m[i].stock>=max_demand)      //库存数大于等于最大需求量k，直接售出k*单位售价 
		{
			result=result+(double)max_demand*m[i].each_sale;
			break;
		}
		else                 //库存数还不到k，将其总售价加起来 
		{
			result=result+(double)m[i].sale;
			max_demand=max_demand-m[i].stock;     // 相减得到剩下的需求量 
		}
	}
	cout<<fixed<<setprecision(2)<<result<<endl;
	return 0;
}