// 生成树计数
// 对于情况1  m<=18的话 可以用暴力骗13'
// 对于情况2  m=n-1的话 要么是0 要么是1 因为生成树的边数就是n-1 
// 感觉情况2最简单 可以放到一开始来判断

//感觉是做出来了的 时间空间复杂度都不高  苦于无测试数据
//mark 考虑的太单纯了


#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
const int maxm=4e5+5;
const ll mod=998244353;
int n,m;

struct Edge{
    int x,y;
}edge[maxm];

int father[maxn];
inline int find_father(int x){
    if(x==father[x]) return x;
    else return father[x]=find_father(father[x]);
}

map<pair<int,int>,ll>mm;     //注意一下map和make_pair(x,y)的使用  85-89行

ll ans=1;
int main(){
    scanf("%d%d",&n,&m);


    if(m==n-1){
        //生成树的情况  用并查集来做
        //最最特殊的情况2 骗了15'
        int ans=n-1;
        for(int i=1;i<=n;i++) father[i]=i;
        for(int i=1;i<=m;i++){
            int a,b,z;
            scanf("%d%d%d",&a,&b,&z);
            if(find_father(a)!=find_father(b)){
                father[find_father(a)]=find_father(b);
                ans--;
            }
        }
        if(ans==0) printf("1");
        else printf("0");
        return 0;
    }

    else{
        //情况1 m<=18 m很小 可以用dfs遍历？
        //我的想法是 把每个强连通分量独立出来
        //每个强连通分量里边的边假设是n  则这里贡献了  *(1<<n)
        //每两个强连通分量之间的边假设是m 则这里贡献了  *(1<<m)-1
        //tarjan求强连通分量? 感觉不太好实现  用并查集应该更好一点?
        //个人感觉 先快排再一次遍历不如遍历两次

        //z=0表示该条边已经加入 z=1表示该条边等待加入
        for(int i=1;i<=n;i++) father[i]=i;
        int tot=0;
        for(int i=1;i<=m;i++){
            int a,b,z;
            scanf("%d%d%d",&a,&b,&z);
            if(z==0){
                //这条边加入的情况 合并强连通分量
                if(find_father(a)!=find_father(b)){
                    father[find_father(a)]=find_father(b);
                }
            }else if(z==1){
                //只存下来那些
                tot++;
                edge[tot].x=a;
                edge[tot].y=b;
            }
        }
        //tot是目前所有待加边的数量
        if(tot==0) ans=0;
        for(int i=1;i<=tot;i++){
            int a=edge[i].x,b=edge[i].y;
            int fa=find_father(a),fb=find_father(b);
            if(fa==fb) ans=(ans*2)%mod;
            else{
                //把它所连接的强连通分量记录下来
                //用二维矩阵存储肯定会爆炸 所以考虑用map存储

                // 第一次尝试的时候只是单纯的考虑了每两个强连通分量之间能相连的都要相连
                // 但是只要这些强连通分量能够构成生成树就行，没必要能连的都要连起来
                // mark一下，忙完最近的事情考虑一下这个问题

                auto tt=make_pair(fa,fb);
                mm[tt]++;          
            }
            for(auto kk=mm.begin();kk!=mm.end();kk++){
                ll temp=((1<<kk->second)-1)%mod;
                ans=(ans*temp)%mod;
            }
        }
        printf("%lld",ans);
        return 0;        
    }

    return 0;
}
