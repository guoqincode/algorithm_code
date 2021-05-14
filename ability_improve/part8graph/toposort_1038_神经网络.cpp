#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int n,p;
int C[maxn],U[maxn],IN[maxn],OUT[maxn];
int W[maxn][maxn];
vector<int>TO[maxn];
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

void toposort(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        //首先找出所有入度为0的节点
        if(IN[i]==0) q.push(i);
    }
    while(!q.empty()){
        int size=q.size();
        for(int j=1;j<=size;j++){
            //分层计算
            int from=q.front();
            q.pop();
            //首先计算temp给后续节点造成的伤害
            if(C[from]<=0) continue;
            for(int k=0;k<TO[from].size();k++){
                int to=TO[from][k];
                C[to]+=W[from][to]*C[from];
                IN[to]--;
                if(IN[to]==0) q.push(to);
            }
        }
    }
}

int main(){
    n=read(); p=read();
    for(int i=1;i<=n;i++){
        C[i]=read();
        U[i]=read();
    }
    for(int i=1;i<=p;i++){
        int temps,tempd;
        temps=read(); tempd=read();
        W[temps][tempd]=read();
        OUT[temps]++;
        IN[tempd]++;
        TO[temps].push_back(tempd); //记录下来每条出边
    }
    for(int i=1;i<=n;i++){
        //初始非输入层节点的权值先减去U[i]
        if(IN[i]) C[i]-=U[i];
    }
    toposort();
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(OUT[i]==0&&C[i]>0){
            cout<<i<<" "<<C[i]<<endl;
            flag=false;
        }
    }
    if(flag) cout<<"NULL";
    return 0;
}
