#include<bits/stdc++.h>
using namespace std;
const int maxn=200001;
map<int,int>mp; //第一行存放数据 第二行存放出现的次数
int n,c;
int a[maxn];
long long ans=0;
int main(){
    scanf("%d%d",&n,&c);
    c=abs(c);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        a[i]-=c;
    }
    // for(auto it=mp.begin();it!=mp.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    for(int i=1;i<=n;i++) ans+=mp[a[i]];
    cout<<ans;
    return 0;
}