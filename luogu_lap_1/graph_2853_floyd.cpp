#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int k,n,m;
int dis[maxn][maxn];
int niu[101];


void floyd(){
    for(int k=1;k<=n;k++){
        //k是中间点
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]&&dis[k][j]){
                    dis[i][j]=1;
                }
            }
        }
    }
}

int main(){
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++) cin>>niu[i];  //输入每个牛所在牧场的编号
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        dis[a][b]=1;
    }
    for(int i=0;i<=n;i++) dis[i][i]=1;  //初始化边界条件   自身到自身肯定是可达的
    floyd();
    int ans=0;
    for(int i=1;i<=n;i++){
        //测试每一个牧场
        int sum=0;
        for(int j=1;j<=k;j++){
            if(dis[niu[j]][i]) sum++;
        }
        if(sum==k) ans++;
    }
    cout<<ans;
}