#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
struct Dp
{
    int value;
    int start,end;
}dp[maxn];
int n;
int nums[maxn];

int main(){
    cin>>n;
    int pos_nums=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i]>=0) pos_nums++;
    }
    if(pos_nums==0){
        cout<<"0 "<<nums[0]<<" "<<nums[n-1];
        return 0;
    }
    dp[0].value=nums[0];
    dp[0].start=0;
    dp[0].end=0;
    for(int i=1;i<n;i++){
        if(dp[i-1].value+nums[i]<nums[i]){
            dp[i].value=nums[i];
            dp[i].start=dp[i].end=i;
        }else{
            dp[i].start=dp[i-1].start;
            dp[i].end=i;
            dp[i].value=dp[i-1].value+nums[i];
        }
    }
    int maxv=-1000000000,startt=-1,endd=-1;
    for(int i=0;i<n;i++){
        if(dp[i].value>maxv){
            maxv=dp[i].value;
            startt=dp[i].start;
            endd=dp[i].end;
        }
    }
    cout<<maxv<<" "<<nums[startt]<<" "<<nums[endd]<<endl;
}
