//本文件夹为复旦大学计算机学院2020年机试题目
//t1 拓扑排序裸题
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;      //题目没有给数据范围 假设n=1e5
int in[maxn],head[maxn];    //入度 
int n;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch-'0'); ch=getchar();}
    return x*f;
}

struct Edge{
    int from;
    int to;
    int next;
}edge[maxn<<2]; //假设边的数量为4*maxn

int tot=0;

inline void addedge(int from,int to){
    tot++;
    in[to]++;
    edge[tot].from=from;
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}

queue<int>q;

inline void bfs(){
    for(int i=1;i<=n;i++){
        if(!in[i]) q.push(i);   
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u-1<<" ";
        for(int i=head[u];i;i=edge[i].next){
            int to=edge[i].to;
            in[to]--;
            if(!in[to]) q.push(to);
        }
    }
}


int main(){
    // n=read();
    cin>>n;
    //nt输入输出 输入时候加上1 输出时候减去1
    int tto,ffrom;
    // while(cin>>tto>>ffrom){
    //     //题目中没给究竟要输入多少组
    //     addedge(ffrom+1,tto+1);
    // }
    for(int i=1;i<=n;i++){
        cin>>tto>>ffrom;
        addedge(ffrom+1,tto+1);
    }
    //tot现在就是输入的关系的数量
    bfs();
    return 0;
}

