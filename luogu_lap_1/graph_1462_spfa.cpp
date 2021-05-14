#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
const int mx=10010;
const int mm=100010;
const int inf=0x3f3f3f3f;
//边储存 
struct e{
    int t,nxt,w;
}edge[mm];
int cnt;
int head[mx];
int n,m,hp;
int f[mx];
//点权集合 
int u[mx];
int dist[mx];
bool v[mx];
bool check(int top)
{
    //标准spfa  
    memset(dist,inf,sizeof(dist));
    memset(v,0,sizeof(v));
    queue<int> q;
    v[1]=true;dist[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int temp=q.front();q.pop();
        v[temp]=false;
        for(int i=head[temp];i!=0;i=edge[i].nxt)
        {
            int to=edge[i].t;
            int wr=edge[i].w;
            if(dist[to]>dist[temp]+wr&&f[to]<=top/*过滤掉点权过大的点*/)
            {
                dist[to]=dist[temp]+wr;
                if(v[to]==false)
                {
                    v[to]=true;
                    q.push(to);
                }
            }
        }
    }
    //此时的dist[n]即为从暴风城到奥格瑞玛的最小损血
    if(dist[n]<=hp)
    {
        return true;
    }else{
        return false;
    } 
}
int main()
{
    scanf("%d%d%d",&n,&m,&hp);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
        u[i]=f[i]; 
    }
    for(int i=1;i<=m;i++)
    {
        static int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        cnt++;
        edge[cnt].t=b;
        edge[cnt].w=c;
        edge[cnt].nxt=head[a];
        head[a]=cnt;
        cnt++;
        edge[cnt].t=a;
        edge[cnt].w=c;
        edge[cnt].nxt=head[b];
        head[b]=cnt;
    }
    //开始二分 
    sort(u+1,u+n+1);
    //这里做一个判断：如果点权大小在不受限制的情况下，依然无法出现损血量小于hp的路径，直接结束程序
    if(check(inf)==false)
    {
        printf("AFK\n");
        return 0;
    } 
    int l=1,r=n;//得到点权集合的区间
    int mid;
    int ans=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(u[mid])==true)
        {
            ans=u[mid];
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    //二分完成后所得的就是我们需要的min(  f(a1)  f(a2)  f(a3) ... )
    printf("%d\n",ans);
    return 0;
}