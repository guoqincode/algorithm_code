#include<bits/stdc++.h>
using namespace std;
long long b,p,k;  // b^p mod k
// int pnum[33];
long long quickpower(long long a,long long b){
    //a^b
    long long ans=1,base=a;
    while(b>0){
        if(b&1) ans=ans*base%k;
        base=base*base%k;
        b=b>>1;
    }
    return ans;
}

int main(){
    cin>>b>>p>>k;
    // int tempp=p,cnt=0;
    // while(tempp){
    //     pnum[cnt++]=tempp%2;
    //     tempp/=2;
    // }
    // //p[cnt-1]-p[0] 对应着p的二进制
    // int tempb=b;
    // for(int i=cnt-1;i>=0;i--){
    //     tempb=(tempb*tempb)%k;
    //     if(p[i]) tempb=tempb*
    // }
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<quickpower(b,p)%k;
    // cout<<quickpower(b,p)%k;
    // printf("%d^%d mod %d=%d",b,p,k,quickpower(b,p));
    return 0;
}