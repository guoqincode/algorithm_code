#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main(){
    int a,b;
    cin>>a>>b;
    int ans=0;
    if(a==b) ans--;
    int n=a*b;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0&&gcd(i,n/i)==a) ans+=2;
    }
    cout<<ans;
    return 0;
}