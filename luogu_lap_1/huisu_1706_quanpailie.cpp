#include<bits/stdc++.h>
using namespace std;
void dfs(vector< vector<int> >&res,vector<int>& temp,vector<int>& vis,int len){
    if(temp.size()==len){
        res.push_back(temp);
        return;
    }
    for(int i=1;i<=len;i++){
        if(!vis[i-1]){
            temp.push_back(i);
            vis[i-1]=1;
            dfs(res,temp,vis,len);
            temp.pop_back();
            vis[i-1]=0;
        }
    }
}
int main(){
    //dfs＋回溯
    int n;
    cin>>n;
    vector< vector<int> >res;
    vector<int>temp;
    vector<int>vis(n,0);
    dfs(res,temp,vis,n);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            printf("%5d",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
