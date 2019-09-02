#include <stdio.h>
#include <stdlib.h>

struct question{
	int score;//分值
	int total;//选项个数
	int cor;//正确选项数
	int opt[5];//下标代表选项
};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	question ques[m];
	//初始化选项
	for(int i=0;i<m;++i)
		for(int j=0;j<5;++j)
			ques[i].opt[j]=0;
	for(int i=0;i<m;++i){
		scanf("%d %d %d",&ques[i].score,&ques[i].total,&ques[i].cor);
		char temp;
		for(int j=0;j<ques[i].cor;++j){
			scanf(" %c",&temp);
			ques[i].opt[temp-'a']++;//记录答案
		}
	}
	int error[m][5],max_error=0;//error是错题记录error[i][j]代表第i道题的第j个选项的错误次数，max_error错误次数最多
	for(int i=0;i<m;++i)
		for(int j=0;j<5;++j)
			error[i][j]=0;//初始化错误次数
	for(int i=0;i<n;++i){//学生答题情况
		double grade=0.0;
		for(int j=0;j<m;++j){//每一道题的情况
			int opt_cnt,isright=1,isallright=1;//选项数，是否正确
			int opt_stu[5]={0};
			char temp;
			getchar();
			scanf("(%d",&opt_cnt);
	        for(int k=0;k<opt_cnt;k++){
	            scanf(" %c)",&temp);
	            opt_stu[temp-'a']=1;//选择了该选项
	        }
	        for(int k=0;k<5;++k){
	        	if(opt_stu[k]==0&&ques[j].opt[k]==1){//漏选
	        		isallright=0;
	        		error[j][k]++;
	        	}
	        	else if(opt_stu[k]==1&&ques[j].opt[k]==0){//错选
	        		isright=0;
	        		error[j][k]++;
	        	}
	        	if(max_error<error[j][k])
	        		max_error=error[j][k];
	        }
	        if(isright){
	        	if(isallright)
	        		grade+=ques[j].score;
	        	else
	        		grade+=ques[j].score/2.0;
	        }
		}
		printf("%.1f\n",grade);
	}
	if(max_error==0)
		printf("Too simple\n");
	else{
		for(int i=0;i<m;++i){
			for(int j=0;j<5;++j){
				if(error[i][j]==max_error){
					printf("%d %d-%c\n",error[i][j],i+1,j+'a');
				}
			}
		}
	}
	return 0;
}