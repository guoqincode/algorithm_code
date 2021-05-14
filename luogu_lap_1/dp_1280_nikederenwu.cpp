//p1280 dp 尼克的任务
//本时刻无任务 dp[i]=dp[i+1]+1
//本时刻有任务 dp[i]=max(dp[i],dp[i+a[sum]])  a[sum]表示在这个时刻的任务的持续时间
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
struct Task{
    int p,t;
}task[maxn];
int n,k;
int sum[maxn];
int dp[maxn];
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

bool cmp(Task a,Task b){
    return a.p>b.p;
}

int main(){
    n=read(); k=read();
    for(int i=1;i<=k;i++){
        task[i].p=read(); task[i].t=read();
        sum[task[i].p]++;
    }
    sort(task+1,task+k+1,cmp);
    int num=1;
    for(int i=n;i>=1;i--){  //倒着搜
        if(sum[i]==0) dp[i]=dp[i+1]+1;  //本时刻无任务
        else{
            for(int j=1;j<=sum[i];j++){
                dp[i]=max(dp[i],dp[i+task[num].t]);
                num++;  //当前已经扫过的任务数
            }
        }
    }
    printf("%d",dp[1]);
    return 0;
}