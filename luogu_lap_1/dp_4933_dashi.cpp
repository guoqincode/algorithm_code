#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1009,V=20008;
#define mod 998244353
ll n,a[N],f[N][2*V],maxh=0,ans=0;
inline ll read(){
    ll x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		maxh=max(maxh,a[i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			f[i][a[i]-a[j]+maxh]=(f[i][a[i]-a[j]+maxh]+f[j][a[i]-a[j]+maxh]+1)%mod;
			//解释上式为何有+1：这个1指的是a[j]和a[i]这俩元素组成序列的情况，
			//在f[j][a[i]-a[j]]中仅有a[j]并不满足公差条件，所以要单独加上这个 
			ans=(ans+f[j][a[i]-a[j]+maxh]+1)%mod; 
			//我们不是用f[i][a[i]-a[j]+maxh]算的，而是直接加的f[j][a[i]-a[j]+maxh]+1
			//f数组仅用作dp，如果最后再算ans会慢 
		}
	}
	ans=(ans+n)%mod;
	printf("%lld\n",ans);
	return 0;
} 