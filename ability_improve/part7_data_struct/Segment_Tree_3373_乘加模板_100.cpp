#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m,a[1000005],mod;
struct node{
	ll sum,l,r,mu,add;
}t[1000005];
ll read(){
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
void build(ll p,ll l,ll r){
	t[p].l=l,t[p].r=r;t[p].mu=1;
	if(l==r){t[p].sum=a[l]%mod;return ;}
	ll mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].sum=(t[p*2].sum+t[p*2+1].sum)%mod;
}
void spread(ll p){
    t[p*2].sum=(ll)(t[p].mu*t[p*2].sum+((t[p*2].r-t[p*2].l+1)*t[p].add)%mod)%mod;
    t[p*2+1].sum=(ll)(t[p].mu*t[p*2+1].sum+(t[p].add*(t[p*2+1].r-t[p*2+1].l+1))%mod)%mod;//add已经乘过mu啦
	
    t[p*2].mu=(ll)(t[p*2].mu*t[p].mu)%mod;
    t[p*2+1].mu=(ll)(t[p*2+1].mu*t[p].mu)%mod;

	t[p*2].add=(ll)(t[p*2].add*t[p].mu+t[p].add)%mod;
    t[p*2+1].add=(ll)(t[p*2+1].add*t[p].mu+t[p].add)%mod;
    
    t[p].mu=1,t[p].add=0;
}
void add(ll p,ll l,ll r,ll k){
	if(t[p].l>=l&&t[p].r<=r){
		t[p].add=(t[p].add+k)%mod;
		t[p].sum=(ll)(t[p].sum+k*(t[p].r-t[p].l+1))%mod;//只要加上增加的就好
		return ;
	}
	spread(p);
	t[p].sum=(t[p*2].sum+t[p*2+1].sum)%mod;
	ll mid=(t[p].l+t[p].r)>>1;
	if(l<=mid)add(p*2,l,r,k);
	if(mid<r)add(p*2+1,l,r,k);
	t[p].sum=(t[p*2].sum+t[p*2+1].sum)%mod;
	
}
void mu(ll p,ll l,ll r,ll k){
	if(t[p].l>=l&&t[p].r<=r){
		t[p].add=(t[p].add*k)%mod;//比较重要的一步,add要在这里乘上k,因为后面可能要加其他的数而那些数其实是不用乘k的
		t[p].mu=(t[p].mu*k)%mod;
		t[p].sum=(t[p].sum*k)%mod;
		return ;
	}
	spread(p);
    t[p].sum=t[p*2].sum+t[p*2+1].sum;
	ll mid=(t[p].l+t[p].r)>>1;
	if(l<=mid)mu(p*2,l,r,k);
	if(mid<r)mu(p*2+1,l,r,k);
	t[p].sum=(t[p*2].sum+t[p*2+1].sum)%mod;
}
ll ask(ll p,ll l,ll r){
	if(t[p].l>=l&&t[p].r<=r){
		return t[p].sum;
	}
	spread(p);
	ll val=0;
	ll mid=(t[p].l+t[p].r)>>1;
	if(l<=mid)val=(val+ask(p*2,l,r))%mod;
	if(mid<r)val=(val+ask(p*2+1,l,r))%mod;
	return val;
}
int main(){
	cin>>n>>m>>mod;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int ty=read();
		if(ty==1){
			ll cn=read(),cm=read(),cw=read();
			mu(1,cn,cm,cw);
		}else if(ty==2){
			ll cn=read(),cm=read(),cw=read();
			add(1,cn,cm,cw);
		}else {
			ll cn=read(),cm=read();
			cout<<ask(1,cn,cm)<<endl;
		}
    }
}