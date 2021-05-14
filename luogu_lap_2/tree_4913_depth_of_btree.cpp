#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int l,r;
}node;
int max_depth=-1;
void dfs(vector< node >& tree,int root,int step){
    if(root==0) return; //根节点
    max_depth=max(step,max_depth);
    dfs(tree,tree[root].l,step+1);
    dfs(tree,tree[root].r,step+1);
}
int main(){
    int n;
    cin>>n;
    vector< node >tree(n+1);
    for(int i=1;i<=n;i++){
        cin>>tree[i].l>>tree[i].r;
    }
    dfs(tree,1,1);
    cout<<max_depth;
    return 0;
}