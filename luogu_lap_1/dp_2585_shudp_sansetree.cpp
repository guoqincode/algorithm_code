//p2585 树上dp 三色二叉树  类似 没有上司的舞会
#include<bits/stdc++.h>
#include<string>
using namespace std;
const int maxn=5e5+10;
char str[maxn];
int fMax[maxn][2],fMin[maxn][2]; //f[i][0]表示以i为根节点 i不染绿色   f[i][1]代表i染绿色 
int tree[maxn][2];  //tree[i][0]为i左孩子编号 tree[i][1]为右节点编号
int tot=0;
inline void build(int root){
    tot++;
    if(str[root]=='0') return;  //叶子节点 返回
    else if(str[root]=='1'){
        tree[root][0]=root+1;
        build(root+1);
    }else if(str[root]=='2'){
        tree[root][0]=root+1;
        build(root+1);
        tree[root][1]=tot+1;    //右子树一定是所有访问过的节点个数+1
        build(tot+1);
    }
}

inline void dfs(int s){
    if(tree[s][0]==0&&tree[s][1]==0){
        fMax[s][0]=0; fMax[s][1]=1;
        fMin[s][0]=0; fMin[s][1]=1;
        return ;
    }
    if(tree[s][0]!=0) dfs(tree[s][0]);
    if(tree[s][1]!=0) dfs(tree[s][1]);
    fMax[s][0]=max(fMax[tree[s][0]][1]+fMax[tree[s][1]][0],fMax[tree[s][0]][0]+fMax[tree[s][1]][1]);
    fMax[s][1]=fMax[tree[s][0]][0]+fMax[tree[s][1]][0]+1;
    fMin[s][0]=min(fMin[tree[s][0]][1]+fMin[tree[s][1]][0],fMin[tree[s][0]][0]+fMin[tree[s][1]][1]);
    fMin[s][1]=fMin[tree[s][0]][0]+fMin[tree[s][1]][0]+1;
}

int main(){
    cin>>str+1;
    build(1);
    dfs(1);
    printf("%d %d",max(fMax[1][0],fMax[1][1]),min(fMin[1][0],fMin[1][1]));
    return 0;
}