#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int id;
    int ascore,cscore,mscore,escore;
    int arank,crank,mrank,erank;
    int minrank;
    char subject;
}student;
bool cmp_a(student one,student two){
	return one.ascore>two.ascore;
}
bool cmp_c(student one,student two){
	return one.cscore>two.cscore;
}
bool cmp_m(student one,student two){
	return one.mscore>two.mscore;
}
bool cmp_e(student one,student two){
	return one.escore>two.escore;
}
int main(){
    int n,m;
	scanf("%d %d",&n,&m);
	vector<student>stu(n);
	vector<int>find(m);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&stu[i].id,&stu[i].cscore,&stu[i].mscore,&stu[i].escore);
		stu[i].ascore=(stu[i].cscore+stu[i].mscore+stu[i].escore)/3;
		//printf("\n%d %d %d %d %d\n",stu[0].id,stu[0].ascore,stu[0].cscore,stu[0].mscore,stu[0].escore);
	}
	//for(int i=0;i<n;i++){
	//	printf("%d %d %d %d %d %d %d %d %d\n",stu[i].id,stu[i].ascore,stu[i].arank,stu[i].cscore,stu[i].crank,stu[i].mscore,stu[i].mrank,stu[i].escore,stu[i].erank);
	//}
	int count;
	sort(stu.begin(),stu.end(),cmp_a);
	count=1;
	for(int i=0;i<n;i++){
		if(i==0) stu[i].arank=count;
		else{
			if(stu[i].ascore==stu[i-1].ascore){
				stu[i].arank=stu[i-1].arank;
			}else{
				stu[i].arank=count;
			}
		}
		count++;
	}
	sort(stu.begin(),stu.end(),cmp_c);
	count=1;
	for(int i=0;i<n;i++){
		if(i==0) stu[i].crank=count;
		else{
			if(stu[i].cscore==stu[i-1].cscore){
				stu[i].crank=stu[i-1].crank;
			}else{
				stu[i].crank=count;
			}
		}
		count++;
	}
	sort(stu.begin(),stu.end(),cmp_m);
	count=1;
	for(int i=0;i<n;i++){
		if(i==0) stu[i].mrank=count;
		else{
			if(stu[i].mscore==stu[i-1].mscore){
				stu[i].mrank=stu[i-1].mrank;
			}else{
				stu[i].mrank=count;
			}
		}
		count++;
	}
	sort(stu.begin(),stu.end(),cmp_e);
	count=1;
	for(int i=0;i<n;i++){
		if(i==0) stu[i].erank=count;
		else{
			if(stu[i].escore==stu[i-1].escore){
				stu[i].erank=stu[i-1].erank;
			}else{
				stu[i].erank=count;
			}
		}
		count++;
	}
	//for(int i=0;i<n;i++){
	//	printf("%d %d %d %d %d %d %d %d %d\n",stu[i].id,stu[i].ascore,stu[i].arank,stu[i].cscore,stu[i].crank,stu[i].mscore,stu[i].mrank,stu[i].escore,stu[i].erank);
	//}
	for(int i=0;i<n;i++){
		stu[i].minrank=stu[i].arank;
		stu[i].subject='A';
		if(stu[i].crank<stu[i].minrank){
			stu[i].minrank=stu[i].crank;
			stu[i].subject='C';
		}
		if(stu[i].mrank<stu[i].minrank){
			stu[i].minrank=stu[i].mrank;
			stu[i].subject='M';
		}
		if(stu[i].erank<stu[i].minrank){
			stu[i].minrank=stu[i].erank;
			stu[i].subject='E';
		}
	}
	//for(int i=0;i<n;i++){
	//	printf("%d %d %d %d %d %d %d %d %d %d %c\n",stu[i].id,stu[i].ascore,stu[i].arank,stu[i].cscore,stu[i].crank,stu[i].mscore,stu[i].mrank,stu[i].escore,stu[i].erank,stu[i].minrank,stu[i].subject);
	//}
	for(int i=0;i<m;i++){
		scanf("%d",&find[i]);
	}
	for(int i=0;i<m;i++){
		
		int j;
		for(j=0;j<n;j++){
			if(find[i]==stu[j].id){
				printf("%d %c\n",stu[j].minrank,stu[j].subject);
				break;
			}
		}
		if(j==n) printf("N/A\n");
	}
	return 0;
}
