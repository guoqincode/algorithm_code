#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
struct Node{
    int v;
    int layer;
};
vector<Node>Adj[maxn];
bool vis[maxn]={false};
int bfs(int s,int k){
    int num_forward=0;
    queue<Node>q;
    Node start;
    start.v=s;
    start.layer=0;

    q.push(start);
    vis[start.v]=true;

    while(!q.empty()){
        for(int j=0;j<q.size();j++){
            auto temp=q.front();
            q.pop();
            int u=temp.v;
            for(int i=0;i<Adj[u].size();i++){
                Node next=Adj[u][i];
                next.layer=temp.layer+1;
                if(vis[next.v]==false&&next.layer<=k){

                    q.push(next);
                    vis[next.v]=true;
                    num_forward++;
                }
            }
        }
    }
    return num_forward;
}
int n,k;
int main(){
    cin>>n>>k;
    int numfollow,idfollow;
    for(int i=1;i<=n;i++){
        Node user;
        user.v=i;
        cin>>numfollow;
        for(int j=1;j<=numfollow;j++){
            cin>>idfollow;
            Adj[idfollow].push_back(user);
            //转化成了被关注的邻接表
        }
    }
    int query;
    cin>>query;
    for(int i=0;i<query;i++){
        int temp_s;
        for(int i=1;i<=n;i++) vis[i]=false;
        cin>>temp_s;
        cout<<bfs(temp_s,k)<<endl;
    }
    return 0;
}