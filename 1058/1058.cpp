#include <stdio.h>
#include <stdlib.h>

struct question
{
	int score;
	int opt_cnt;
	int right_cnt;
	int right_opt[5];//下标表示选项，值为1表示正确
};
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	question ques[M];
	for(int i=0;i<M;++i)
		for(int j=0;j<5;++j)
			ques[i].right_opt[j]=0;
	for(int i=0;i<M;++i){
		scanf("%d %d %d",&ques[i].score,&ques[i].opt_cnt,&ques[i].right_cnt);
		for(int j=0;j<ques[i].right_cnt;++j){
			char c;
			scanf(" %c",&c);
			ques[i].right_opt[c-'a']=1;
		}
	}
	int error[M],max_error=0;//记录第i道题错误次数
	for(int i=0;i<M;++i)
		error[i]=0;
	for(int i=0;i<N;++i){//学生答题情况
		int grade=0;
		for(int j=0;j<M;++j){
			int cnt,isright=1;//cnt记录学生选了几个选项
			int opt_stu[5]={0};
			getchar();
			scanf("(%d",&cnt);
			for(int k=0;k<cnt;++k){
				char c;
				scanf(" %c)",&c);
				opt_stu[c-'a']=1;
			}
			for(int k=0;k<5;++k){
				if((opt_stu[k]==0&&ques[j].right_opt[k]==1) || (opt_stu[k]==1&&ques[j].right_opt[k]==0)){
					isright=0;
					break;
				}
			}
			if(isright){
				grade+=ques[j].score;
			}
			else{
				error[j]++;
				if(max_error<error[j])
					max_error=error[j];
			}
		}
		printf("%d\n", grade);
	}
	if(!max_error)
		printf("Too simple\n");
	else{
		printf("%d",max_error);
		for(int i=0;i<M;++i){
			if(error[i]==max_error)
				printf(" %d",i+1);
		}
	}
	scanf("%d",&N);
	return 0;
}