#include<bits/stdc++.h>
using namespace std;
typedef struct{
	char id[16];
	char sign[9];
	char out[9];
	int signsecond;
	int outsecond;
}stu;
bool cmp_sign(stu one,stu two){
	return one.signsecond<two.signsecond;
}
bool cmp_out(stu one,stu two){
	return one.outsecond>two.outsecond;
}
int main(){
	vector<stu>res;
	int m;
	scanf("%d",&m);
	stu temp;
	while(m--){
		scanf("%s %s %s",&temp.id,&temp.sign,&temp.out);
		int signhour=(temp.sign[0]-'0')*10+temp.sign[1]-'0';
		int signmin=(temp.sign[3]-'0')*10+temp.sign[4]-'0';
		int signsec=(temp.sign[6]-'0')*10+temp.sign[7]-'0';
		temp.signsecond=signhour*3600+signmin*60+signsec;
		int outhour=(temp.out[0]-'0')*10+temp.out[1]-'0';
		int outmin=(temp.out[3]-'0')*10+temp.out[4]-'0';
		int outsec=(temp.out[6]-'0')*10+temp.out[7]-'0';
		temp.outsecond=outhour*3600+outmin*60+outsec;
		res.push_back(temp);
	}
	sort(res.begin(),res.end(),cmp_sign);
	printf("%s ",res[0].id);
	sort(res.begin(),res.end(),cmp_out);
	printf("%s",res[0].id);
	return 0;
}
