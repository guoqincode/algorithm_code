#include<bits/stdc++.h>
using namespace std;
int n,k;
int count_of_primer=0;
int nums[25];
int isprimer(int n){
    if(n<=1) return 0;
    if(n==2) return 1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
void dfs(int cur_k,int cur_sum,int startx){
    //最重要的是去重，即“不降”原则
    if(cur_k==k){
        if(isprimer(cur_sum)){
            count_of_primer++;
        }
        return;
    }
    // 去重的循环，非常重要
    for(int i=startx;i<=n;i++){
        dfs(cur_k+1,cur_sum+nums[i],i+1);
    }
    //
    return;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>nums[i];
    dfs(0,0,1);
    cout<<count_of_primer;
    return 0;
}