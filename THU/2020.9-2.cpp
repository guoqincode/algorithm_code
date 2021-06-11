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
const int maxn=101,maxm=3*1e4+5,maxw=3*1e4+5,maxd=1000;
char op;
int R_W[maxw],W_W[maxn];

struct Node{
    int cur_data;   //目前的数据是哪个时间点留下的
    
}node[maxn];

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

        }else if(op=='W'){
            cin>>t;
            int k;
            cin>>k;
            for(int i=1;i<=k;i++) cin>>W_W[i];

            //write fuction

        }
    }
}