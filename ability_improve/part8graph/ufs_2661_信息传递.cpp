#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int f[maxn];
int n;
int ans=0x3f3f3f3f;
inline int findfather(int x,int& cnt){
    //加上引用!
    cnt++;
    if(f[x]==x) return x;
    else return findfather(f[x],cnt);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++){
        int cnt=0,ff;
        cin>>ff;
        if(findfather(ff,cnt)==i){
            ans=min(ans,cnt);
        }else{
            f[i]=ff;
        }
    }
    cout<<ans;
    return 0;
}