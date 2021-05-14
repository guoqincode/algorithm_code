// 最佳阈值仅在Yi 中选取，即与某位同学的安全指数相同；
// 按照该阈值对这 m 位同学上学期的挂科情况进行预测，预测正确的次数最多（即准确率最高）；
// 多个阈值均可以达到最高准确率时，选取其中最大的。

//n==1e5  暴力法只能拿到70分
#include<bits/stdc++.h>
using namespace std;
const int maxn=200001;
typedef struct{
    int seita;
    int result;
    int vote;
}Stu;
int n;
Stu stu[maxn];
bool cmp(Stu a,Stu b){
    if(a.seita==b.seita) return a.result>=b.result;
    else return a.seita>=b.seita;
    //1.seita降序排列 2.result 10序排列 
    //遇到投票下降的情况直接输出上一个
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&stu[i].seita,&stu[i].result);
        stu[i].vote=0;
    }
    sort(stu+1,stu+n+1,cmp);
    int ans=stu[1].seita;
    for(int j=1;j<=n;j++){
        if(stu[j].seita==stu[1].seita&&stu[j].result) stu[1].vote++;
        else if(!stu[j].result) stu[1].vote++;
    }
    int maxvote=stu[1].vote;
    for(int i=2;i<=n;i++){
        if(stu[i].seita==stu[i-1].seita){
            stu[i].vote=stu[i-1].vote;
            continue;
        }
        for(int j=1;j<=n;j++){
            if(stu[j].seita>=stu[i].seita&&stu[j].result) stu[i].vote++;
            else if(stu[j].seita<stu[i].seita&&!stu[j].result) stu[i].vote++;
        }
        // if(stu[i].vote<=stu[i-1].vote){
        //     ans=stu[i-1].seita;
        //     break;
        // }
        if(stu[i].vote>maxvote){
            maxvote=stu[i].vote;
            ans=stu[i].seita;
        }
    }
    // cout<<maxvote<<"  "<<ans<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<stu[i].seita<<" "<<stu[i].result<<" "<<stu[i].vote<<endl;
    // }
    printf("%d",ans);
    return 0;
}