//单词接龙  dfs
#include<bits/stdc++.h>
using namespace std;
const int maxn=21;
string str[maxn];
int com[maxn][maxn];    //com[i][j]为字符串i和字符串j的重合部分(i在前j在后)
int vis[maxn];
char st;
int n;
inline int findcom(int a,int b){
    //这个函数的目的是找到两个字符串的  重叠部分的*长度*
    bool find=true;
    int j=0;
    for(int i=str[a].size()-1;i>=0;i--){
        for(int ii=i;ii<str[a].size();ii++){
            if(str[a][ii]!=str[b][j++]){
                find=false;
                break;
            }
        }
        if(find==true) return str[a].size()-i;   //返回重叠部分的长度
        j=0;
        find=true;
    }
    return 0;
}

int anslen=0,curlen=0;
inline void dfs(int p){
    bool find=false;
    for(int j=1;j<=n;j++){
        // if(p==j) continue;
        if(vis[j]>=2) continue;     //访问次数超过两次的情况
        if(com[p][j]==0) continue;  //不相交的情况
        if(com[p][j]==str[p].size()||com[p][j]==str[j].size()) continue;    //一个包含一个的情况
        vis[j]++;
        curlen+=(str[j].size()-com[p][j]);
        find=true;
        dfs(j);
        
        //回溯
        curlen-=(str[j].size()-com[p][j]);
        vis[j]--;
    }
    if(!find) anslen=max(anslen,curlen);    //find==false 说明找不到任何一个相连的了
    return;
}


int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>str[i];
    cin>>st;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // if(i==j) continue;
            com[i][j]=findcom(i,j);

        }
    }
    
    for(int i=1;i<=n;i++){
        if(str[i][0]==st){
            vis[i]++;
            curlen=str[i].size();
            dfs(i);
            curlen=0;
            vis[i]--;
        }
    }
    cout<<anslen;
    return 0;
}