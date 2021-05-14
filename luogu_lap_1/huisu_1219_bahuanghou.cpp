#include<bits/stdc++.h>
using namespace std;
void dfs(vector< vector<int> >&res,vector<int>& temp,vector<int>& viscol,vector<int>& vismaindis,vector<int>& visvicedis,int row,int n){
    //viscol[n] vismaindis[2*n-1] visvicedis[2*n-1] 分别代表列，主对角线，副对角线是否能够放置
    //
    if(temp.size()==n){
        res.push_back(temp);
        return;
    }
    for(int j=0;j<n;j++){
        //现在是第row+1行，从第0+1列开始测试是否可以放置
        if(viscol[j]==0&&vismaindis[row+j]==0&&visvicedis[row-j+n]==0){
            viscol[j]=1;
            vismaindis[row+j]=1;
            visvicedis[row-j+n]=1;
            temp.push_back(j+1);
            dfs(res,temp,viscol,vismaindis,visvicedis,row+1,n);
            temp.pop_back();
            viscol[j]=0;
            vismaindis[row+j]=0;
            visvicedis[row-j+n]=0;
        }
    }
}
int main(){
    //经典的八皇后问题
    int n;
    cin>>n;
    vector< vector<int> >res;
    vector<int>temp;
    vector<int>viscol(n,0);
    vector<int>vismaindis(2*n-1,0);
    vector<int>visvicedis(2*n-1,0);
    dfs(res,temp,viscol,vismaindis,visvicedis,0,n);
    for(int i=0;i<3;i++){
        int j;
        for(j=0;j<res[i].size()-1;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<res[i][j]<<endl;
    }
    cout<<res.size();
    return 0;
}