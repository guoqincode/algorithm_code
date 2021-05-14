#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int a[maxn][maxn];
int ans=0,most=-1;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
int u=0;
int s[3][maxn][maxn];   //s[0][i][j]=1代表行i已经有j  s[1][i][j]=1代表列i已经有j s[2][i][j]=1代表小数独已经有j 
int ss[maxn*maxn][4];   //s[i][0] x s[i][1] y s[i][2] 分数 s[i][3]小数独编号
struct f{
    //记录该行0的个数
    int rank;
    int sum;
}cou[maxn];

inline int score(int i,int j){
    //返回这个节点的分数值
    if(i==1||i==9||j==1||j==9) return 6;
    if(i==2||i==8||j==2||j==8) return 7;
    if(i==3||i==7||j==3||j==7) return 8;
    if(i==4||i==6||j==4||j==6) return 9;
    return 10;
}

inline int which(int i,int j){
    //返回这个节点位于几号小数独里边
    if(i<=3){
        if(j<=3) return 1;
        else if(j<=6) return 2;
        else return 3;
    }else if(i<=6){
        if(j<=3) return 4;
        else if(j<=6) return 5;
        else return 6;
    }else{
        if(j<=3) return 7;
        else if(j<=6) return 8;
        else return 9;
    }
}

bool cmp(f a,f b){
    //按照0的数量升序排序  优先搜0少的
    return a.sum<b.sum;
}

//  dfs   模板
// void dfs(答案,搜索层数,其他参数){
//     if(层数==maxdeep){
//         更新答案;
//         return; 
//     }
//     (剪枝) 
//     for(枚举下一层可能的状态){
//         更新全局变量表示状态的变量;
//         dfs(答案+新状态增加的价值,层数+1,其他参数);
//         还原全局变量表示状态的变量;
//     }
// }

inline void dfs(int p,int curscore){
    if(p==u){
        if(curscore>most) most=curscore;
        return;
    }
    for(int i=1;i<=9;i++){
        if(!s[0][ss[p][0]][i]&&!s[1][ss[p][1]][i]&&!s[2][ss[p][3]][i]){
            s[0][ss[p][0]][i]=1;
            s[1][ss[p][1]][i]=1;
            s[2][ss[p][3]][i]=1;
            dfs(p+1,curscore+(ss[p][2]*i));
            s[0][ss[p][0]][i]=0;
            s[1][ss[p][1]][i]=0;
            s[2][ss[p][3]][i]=0;
        }
    }
    return;
}

int main(){
    for(int i=1;i<=9;i++) cou[i].rank=i;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            a[i][j]=read();
            if(a[i][j]){
                //如果不为0 则给该行 该列 该小数独打上存在a[i][j]的标记
                s[0][i][a[i][j]]=1;
                s[1][j][a[i][j]]=1;
                s[2][which(i,j)][a[i][j]]=1;
                ans+=score(i,j)*a[i][j];    //计算初始化的总分数
            }else cou[i].sum++; 
        }
    }

    sort(cou+1,cou+10,cmp); //按照0的数量升序排序  优先搜0少的 这样耗时会少一点

    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            //记录下了总的0的个数作为dfs的返回条件
            if(a[cou[i].rank][j]==0){
                ss[u][0]=cou[i].rank;
                ss[u][1]=j;
                ss[u][2]=score(cou[i].rank,j);
                ss[u][3]=which(cou[i].rank,j);
                u++;
            }
        }
    }

    dfs(0,ans);
    printf("%d",most);
    return 0;
}