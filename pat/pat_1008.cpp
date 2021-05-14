//pat1008
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>dp(n);
    for(int i=0;i<n;i++)
        scanf("%d",&dp[i]);
    int sum=n*5;    
    if(n==1) printf("%d",sum+dp[0]*6);
    else{
        sum+=dp[0]*6;
        for(int i=1;i<n;i++){
            if(dp[i]>dp[i-1]) sum+=(dp[i]-dp[i-1])*6;
            else sum+=(dp[i-1]-dp[i])*4;
        }
        printf("%d",sum);
    }
    return 0;
}
