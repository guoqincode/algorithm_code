#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a,b;
        cin>>a>>b;
        ans+=(a*b);
    }
    long long zero=0;
    cout<<max(zero,ans);
    return 0;
}