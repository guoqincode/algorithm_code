#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=100001;
const int mod=10007;
int nums[maxn],colors[maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>nums[i];
    for(int i=1;i<=n;i++) cin>>colors[i];

    //暴力法-->40'
    // int ans=0;
    // for(int x=1;x+2<=n;x++){
    //     for(int y=x+1;y+1<=n;y++){
    //         int z=2*y-x;
    //         if(z>n) break;
    //         if(z<=y) break;
    //         if(colors[x]==colors[z]){
    //             ans+=(x+z)*(nums[x]+nums[z]);
    //             ans%=mod;
    //         }
    //     }
    // }

    
}