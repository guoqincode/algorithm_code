#include<bits/stdc++.h>
using namespace std;
struct student{
    char id[15];
    int score;
    int lo_number;
    int lo_rk;
}stu[30010];
bool cmp(student a,student b){
    if(a.score!=b.score) return a.score>b.score;    //先按分数从高到低排序
    else return strcmp(a.id,b.id)<0;    //分数相同按照准考证从小到大排序
}

int main(){
    int n,k,num=0;
    cin>>n; //n 考场总数
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>stu[num].id>>stu[num].score;
            stu[num].lo_number=i;
            num++;
        }
        sort(stu+num-k,stu+num,cmp);
        stu[num-k].lo_rk=1;
        for(int j=num-k+1;j<num;j++){
            if(stu[j].score==stu[j-1].score) stu[j].lo_rk=stu[j-1].lo_rk;
            else stu[j].lo_rk=j+1-(num-k);
        }
    }
    //lo_rk已经排序完毕
    cout<<num<<endl;
    sort(stu,stu+num,cmp);
    int rk=1;
    for(int i=0;i<num;i++){
        if(i>0&&stu[i].score!=stu[i-1].score) rk=i+1;
        cout<<stu[i].id<<" "<<rk<<" "<<stu[i].lo_number<<" "<<stu[i].lo_rk<<endl;
    }
    return 0;
}