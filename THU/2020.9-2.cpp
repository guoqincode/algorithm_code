//quorum机制
//任意一台机器更新数据时，广播，只要有w台机器更新完成就算成功提交的数据 w>n/2
//只有最新成功提交的数据才会在w台甚至更多机器上保存
//所以，用户需要访问[w,n]台机器才能取人数据的一致性，找到最近成功提交的数据
//提高了写效率，降低了读效率，是一种折中的办法

//具体地，有n台机器，[1...n],m个读写操作

//R t x1 x2 ... xw 表示在t时间访问了x1...xw
//如果不足w台数据相同，则从1号开始访问未访问过的，直到有w台 相同
//找到最新数据后，把本次访问的没有最新成功提交数据的机器更新为最新成功提交的数据
//-->读操作也可能产生更新操作
//输出：最新成功提交的数据版本t和访问的机器数目v,立刻输出

//W t k x1,x2 ... xk 表示在t时间更新了k台机器，k>=w
//  *写入数据需要d时长，所以R t，W t中的更新操作要在t+d时间内才能访问到
//  *如果同一时间对某节点写入不同数据，只有最新的才会被写入
//输出：输出该数据写入完成的时间和访问的机器数目，有d时长的执行延迟

//保证对于同一时间，可能会有多个读请求，但是只会有一个写请求

//n<=100 m<=3*1e4 n/2<w<=n d<=1000

#include<bits/stdc++.h>
using namespace std;
int n,m,w,d;
const int maxn=101,maxm=3*1e4+5;
char op;
int R_W[maxn],W_W[maxn];

struct Node{
    int cur_data_t;   //目前的数据是哪个时间点留下的  用来判断是否是相同的数据
    int is_writing;   //1 正在被写入 
    int writing_done_t; //如果正在被写入，那么写入完成的时间是多少
    int next_data;  //下一个要写入的值
}node[maxn];

int vis[maxn];
inline void Read(int t){


    memset(vis,0,sizeof(vis));
    //首先处理一下这个时间节点是否有节点被写入完成
    for(int i=1;i<=n;i++){
        if(node[i].is_writing){
            if(t>=node[i].writing_done_t){
                node[i].cur_data_t = node[i].next_data;
                node[i].is_writing=0;
            }
        }
    }
    //节点更新完成
    //首先确认这w个数据是否相同
    int flag=1;
    int temp = node[R_W[1]].cur_data_t;
    for(int i=1;i<=w;i++){
        temp = max(temp,node[R_W[i]].cur_data_t);   //找到最大的数据
    }
    // if(t==9) cout<<endl<<temp<<endl;
    int couunt=0;
    for(int i=1;i<=w;i++){
        vis[R_W[i]]=1;
        if(temp!=node[R_W[i]].cur_data_t){
            flag=0;
            //不是最新的话 就要修正
            if(node[R_W[i]].is_writing&&node[R_W[i]].next_data==temp) continue; //重复写入相同数据
            node[R_W[i]].is_writing=1;
            node[R_W[i]].writing_done_t=t+d;
            node[R_W[i]].next_data=temp;
        }else couunt++;
        
    }

    // if(t==9) cout<<endl<<couunt<<endl;
    if(flag==1){
        //w个数据全部相同
        cout<<couunt<<" "<<temp<<endl;
        return ;
    }
    //如果只有couunt(<w)个数据相同
    int has_visted=w;   //当前一共访问了has_visted个主机，有couunt个数据相同，当有w个数据相同时，跳出
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            has_visted++;
            //如果没有访问过的话
            if(temp==node[i].cur_data_t){
                couunt++;
                if(couunt==w){
                    cout<<has_visted<<" "<<temp<<endl;
                    return;
                }
            }else{
                if(node[R_W[i]].is_writing&&node[R_W[i]].next_data==temp) continue; //重复写入相同数据
                node[i].is_writing=1;
                node[i].writing_done_t=t+d;
                node[i].next_data=temp;
            }
        }
    }
    cout<<has_visted<<" "<<temp<<endl;
    return;
}

inline void Write(int t,int k){
    //在时间t下 更新k个数据
    //首先处理一下这个时间节点是否有节点被写入完成
    for(int i=1;i<=n;i++){
        if(node[i].is_writing){
            if(t>=node[i].writing_done_t){
                node[i].cur_data_t = node[i].next_data;
                node[i].is_writing=0;
            }
        }
    }
    //节点更新完成

    for(int i=1;i<=k;i++){
        node[W_W[i]].is_writing=1;
        node[W_W[i]].writing_done_t=t+d;
        node[W_W[i]].next_data=t+d;
    }
    // cout<<k<<" "<<t+d<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>w>>d;
    while(m--){
        cin>>op;
        int t;
        if(op=='R'){
            cin>>t;
            for(int i=1;i<=w;i++) cin>>R_W[i];
            //read fuction
            Read(t);
        }else if(op=='W'){
            cin>>t;
            int k;
            cin>>k;
            for(int i=1;i<=k;i++) cin>>W_W[i];
            Write(t,k);
            //write fuction
        }
    }
    return 0;
}
