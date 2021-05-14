//要考虑很多剪枝情况的题目
#include<bits/stdc++.h>
using namespace std;
const int maxn=66;
int a[maxn],cnt=0,N,maxa=0,suma,nexxt[maxn];
int len,m;
int ok=0;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

bool cmp(int a,int b){
    return a>b;
}
int vis[maxn];
inline void dfs(int k,int last,int rest){
    //k为正在拼的木棍的编号(即拼完成后的那个编号)  last为正在拼的前一节的编号 rest为剩下的未拼的编号
    int i;
    if(!rest){
        //rest==0 又一个小木棍拼完了
        if(k==m){
            //此时已经拼完了所有的m个小木棍
            ok=1;
            return ;
        }
        // int i;
        for(i=1;i<=cnt;i++){
            if(!vis[i]) break;
        }
        vis[i]=1;
        dfs(k+1,i,len-a[i]);
        vis[i]=0;
        if(ok) return;  //第一个找到的答案就是最小的 找到答案就可以一层一层的退出
    }
    int l=last+1,r=cnt,mid;
    while(l<r){
        //二分查找到一个不大于rest的最大长度
        mid=(l+r)>>1;
        if(a[mid]<=rest) r=mid;
        else l=mid+1;
    }
    for(int i=l;i<=cnt;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(k,i,rest-a[i]);
            vis[i]=0;
            if(ok) return;

            if(rest==a[i]||rest==len) return;
            i=nexxt[i];
            if(i==cnt) return ;
        }
    }
}

int main(){
    N=read();
    for(int i=1;i<=N;i++){
        int t=read();
        if(t>50) continue;  //过滤掉长度为50的木棍 cnt才是真正的被切后小木棍的数量
        a[++cnt]=t;
        suma+=t;    //suma记录下如果这些木棍合成一个后的长度
        maxa=max(maxa,t);   //用maxa记录下最长的被切后的木棍的长度
    }

    sort(a+1,a+cnt+1,cmp);     //1.从大到小排队 因为小的比大的"灵活"

    //初始化next数组 跳过连续的相同长度的小木棍   优化二分和dfs速度
    nexxt[cnt]=cnt;
    for(int i=cnt-1;i>=1;i--){
        if(a[i]==a[i+1]) nexxt[i]=nexxt[i+1];
        else nexxt[i]=i;
    }

    for(len=maxa;len<=suma/2;len++){
        //最小的长度肯定从最大的小木棍的长度开始
        //如果到了suma/2还不行 那就只能是suma了  所以临界条件从suma可以优化到suma/2
        if(suma%len) continue;  //优化:如果总长度不能整除要测试的长度 直接跳过
        m=suma/len;
        ok=0;
        vis[1]=1;
        dfs(1,1,len-a[1]);
        vis[1]=0;
        if(ok){
            printf("%d",len);
            return 0;
        }
    }
    printf("%d",suma);
    return 0;
}