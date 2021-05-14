//p3811 求乘法逆元  模板
//定义：若 a*x=1(mod p) 且(a,p)=1  则x为a的逆元 即x=a^-1(mod p)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e6 + 10;

//前置 求最大公因数的gcd算法
int gcd(int a,int b){
    return !b ? a : gcd(b ,a%b);
}

//算法1 拓展的欧几里得算法
//a*x=1(mod p)-->  a*x+p*y=1
void Exgcd(ll a,ll p,ll &x,ll &y){  //这个算法优点 当a、p互质但是p不是素数时候，也可以使用
    if(!p) x=1,y=0;
    else Exgcd(p, a%p, y, x),y-= a/p * x;   //每一步x变成y y变成x- a/p(向下取整) *y
}
//Exgcd(a,p,x,y); x=(x%p+p)%p  x就是a在mod p下的逆元


//算法2 快速幂
//a^(p-1) =1 (mod p) p为素数且a、p互质  -->x=a^(p-2) (mod p)

ll fpm(ll x,ll power,ll mod){
    x%=mod;
    ll ans=1;
    for(;power;power>>=1,(x*=x)%=mod){
        if(power & 1) (ans *= x) %= mod;
    }
    return ans;
}
// ll x = fpm(a,p-2,p);  x就是a在(mod p)下的逆元


//算法3 线性算法
//用于求一连串数字对一个 (mod p)的逆元  只能用这种方法，其他方法慢一些
//inv[1]=1   inv[i]=(p - p/i) * inv[p%i] % p
// inv[1]=1;
// for(int i=2;i<=n;i++) inv[i]=(p - p/i) * inv[p%i] % p;

inline ll read(){
    ll x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

ll n,p,inv[maxn];   //全是int 32' 全是ll 100'
int main(){
    n=read(); p=read();
    inv[1]=1; printf("1\n");
    for(int i=2;i<=n;i++){
        inv[i]=(p - p/i)*inv[p%i]%p;
        printf("%lld\n",inv[i]);    //-->100'

        // printf("%lld\n",fpm(i,p-2,p));  ->64' 最后两个tle
        // ll x,y;
        // Exgcd(i,p,x,y);
        // printf("%lld\n",x=(x%p+p)%p);  ->80分 最后一个tle
    }
    return 0;
}

