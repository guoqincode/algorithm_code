#include<bits/stdc++.h>
using namespace std;
typedef struct{
    char lc;
    char rc;
}Node;
const int maxn=140;
Node node[maxn];
int n;
char rot,root;
void dfs(char rot){
    if(rot=='*') return;
    cout<<rot;
    dfs(node[rot].lc);
    dfs(node[rot].rc);
}
int main(){
    scanf("%d",&n);
    cin>>rot;
    cin>>node[rot].lc;
    cin>>node[rot].rc;
    for(int i=2;i<=n;i++){
        cin>>root;
        cin>>node[root].lc;
        cin>>node[root].rc;
    }
    dfs(rot);
    return 0;
}
