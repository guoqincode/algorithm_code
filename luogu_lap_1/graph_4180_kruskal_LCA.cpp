#include<bits/stdc++.h>
const int N=400010,M=900010;
#define INF 2147483647000000
#define ll long long
using namespace std;
struct edge{
	ll u,v,d;
	ll next;
}G[N<<1];
ll tot=0;
ll head[N];
inline void addedge(ll u,ll v,ll d)
{
	G[++tot].u=u,G[tot].v=v,G[tot].d=d,G[tot].next=head[u],head[u]=tot;
	G[++tot].u=v,G[tot].v=u,G[tot].d=d,G[tot].next=head[v],head[v]=tot;
}

ll bz[N][19];
ll maxi[N][19];
ll mini[N][19];
ll deep[N];
inline void dfs(ll u,ll fa)
{
    bz[u][0]=fa;
	for(ll i=head[u];i;i=G[i].next)
	{
		ll v=G[i].v;
		if(v==fa)continue;
		deep[v]=deep[u]+1ll;
		maxi[v][0]=G[i].d;
		mini[v][0]=-INF;
		dfs(v,u);
	}
}

ll n;
inline void cal()
{
	for(ll i=1;i<=18;++i)
		for(ll j=1;j<=n;++j)
		{
			bz[j][i]=bz[bz[j][i-1]][i-1];
			maxi[j][i]=max(maxi[j][i-1],maxi[bz[j][i-1]][i-1]);
			mini[j][i]=max(mini[j][i-1],mini[bz[j][i-1]][i-1]);
			if(maxi[j][i-1]>maxi[bz[j][i-1]][i-1])mini[j][i]=max(mini[j][i],maxi[bz[j][i-1]][i-1]);
            else if(maxi[j][i-1]<maxi[bz[j][i-1]][i-1])mini[j][i]=max(mini[j][i],maxi[j][i-1]);
		}
}

inline ll LCA(ll x,ll y)
{
	if(deep[x]<deep[y])swap(x,y);
	for(ll i=18;i>=0;--i)
		if(deep[bz[x][i]]>=deep[y])
			x=bz[x][i];
	if(x==y)return x;
	for(ll i=18;i>=0;--i)
		if(bz[x][i]^bz[y][i])
			x=bz[x][i],y=bz[y][i];
	return bz[x][0];
}

inline ll qmax(ll u,ll v,ll maxx)
{
	ll Ans=-INF;
	for(ll i=18;i>=0;--i)
	{
		if(deep[bz[u][i]]>=deep[v])
		{
			if(maxx!=maxi[u][i])Ans=max(Ans,maxi[u][i]);
			else Ans=max(Ans,mini[u][i]);
			u=bz[u][i];
		}
	}
	return Ans;
}

inline void read(ll &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+(ch^48),ch=getchar();
}

ll m;

edge A[M<<1];

inline bool cmp(edge x,edge y)
{
	return x.d<y.d;
}

ll Father[N];
inline ll Get_Father(ll x)
{
	return (x==Father[x]) ? x : Father[x]=Get_Father(Father[x]);
}

bool B[M<<1];

int main()
{
	read(n),read(m);
	for(ll i=1;i<=m;++i)
	{
		read(A[i].u),read(A[i].v),read(A[i].d);
	}
	
	sort(A+1,A+m+1,cmp);
	
	for(ll i=1;i<=n;++i)
		Father[i]=i;
	
	ll Cnt=0ll;
	for(ll i=1;i<=m;++i)
	{
		ll Father_u=Get_Father(A[i].u);
		ll Father_v=Get_Father(A[i].v);
		if(Father_u!=Father_v)
		{
			Cnt+=A[i].d;
			Father[Father_u]=Father_v;
			addedge(A[i].u,A[i].v,A[i].d);
			B[i]=true;
		}
	}
	
	mini[1][0]=-INF;
	deep[1]=1;
	dfs(1,-1);
	cal();
	
	ll Ans=INF;
	
	for(ll i=1;i<=m;++i)
	{
		if(!B[i])
		{
			ll u=A[i].u;
			ll v=A[i].v;
			ll d=A[i].d;
			ll lca=LCA(u,v);
			ll maxu=qmax(u,lca,d);
			ll maxv=qmax(v,lca,d);
			Ans=min(Ans,Cnt-max(maxu,maxv)+d);
		}
	}
	
	printf("%lld",Ans);
	
	return 0;
}