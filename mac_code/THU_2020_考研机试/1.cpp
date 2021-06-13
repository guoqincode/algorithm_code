//数字统计  顺便提交一下洛谷1179
#include<bits/stdc++.h>
using namespace std;
int n,k=2;

int check(int n){
    int res=0;
    while(n){
        if(n%10==k) res++;
        n/=10;
    }
    return res;
}
int main(){
    // cin>>n>>k;
    int l,r;
    cin>>l>>r;
    int ans=0;
    for(int i=l;i<=r;i++){
        ans+=check(i);
    }
    cout<<ans;
}