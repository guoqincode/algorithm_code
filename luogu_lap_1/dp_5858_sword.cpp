//p5858 dp golden sword
//35'
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e3+15;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll n,w,s;
ll dp[maxn][maxn],a[maxn];
// dp[i][j]为放入i原料，且当时正有j个原料所得到的最大耐久度
// 所以 dp[i][j]=max{dp[i-1][k]+a[i]*j}  j-1<=k<=min(w,j-1+s) 
// 对应当前一个也不拿出到拿出s个，这里注意边界问题
inline ll read(){
    ll x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int main(){
    // n=read(); w=read(); s=read();
    scanf("%lld %lld %lld",&n,&w,&s);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=w;j++){
            dp[i][j]=inf;
        }
    }
    dp[0][0]=0;
    // for(ll i=1;i<=n;i++){
    //     for(ll j=w;j;j--){
    //         for(ll k=min(w,j+s-1);k>=j-1;k--){
    //             dp[i][j]=max(dp[i][j],dp[i-1][k]+j*a[i]);
    //         }
    //     }
    // }
    int q[maxn],pos[maxn];
    for(long long i=1;i<=n;++i){
		int l=1,r=1;
		q[l]=dp[i-1][w];
		pos[l]=w;
		for(long long j=w;j;--j)
		{
			while(pos[l]>j+s-1 && l<=r)	++l;
			while(q[r]<dp[i-1][j-1] && l<=r)	--r;
			pos[++r]=j-1;
			q[r]=dp[i-1][j-1];
			dp[i][j]=q[l]+j*a[i];
		}
	}
    ll ans=inf;
    for(ll i=0;i<=w;i++) ans=max(ans,dp[n][i]);
    // cout<<ans;
    printf("%lld",ans);
    return 0;
}