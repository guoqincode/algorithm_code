//拓展欧几里得算法的板子题目
//求ax=1(mod b)的最小整数解
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Exgcd(ll a,ll p,ll& x,ll& y){
    if(!p) x=1,y=0;
    else Exgcd(p,a%p,y,x),y-=a/p*x;
}

ll a,p;

int main(){
    cin>>a>>p;
    ll x,y;
    Exgcd(a,p,x,y);
    x=(x%p+p)%p;
    cout<<x;
    return 0;
}