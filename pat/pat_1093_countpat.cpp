#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const int mod=1000000007;
int leftnumsp[maxn]={0};
int righnumst=0;
char str[maxn];
int main(){
    cin>>str;
    int len=strlen(str);
    int res=0;
    for(int i=1;i<len;i++){
        if(str[i-1]=='P') leftnumsp[i]=leftnumsp[i-1]+1;
        else leftnumsp[i]=leftnumsp[i-1];
    }
    for(int i=len-1;i>=0;i--){
        if(str[i]=='T') righnumst++;
        else if(str[i]=='A') res=(res+righnumst*leftnumsp[i])%mod;
    }
    cout<<res;
    return 0;
}