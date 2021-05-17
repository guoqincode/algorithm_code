//DHCP服务器
#include<bits/stdc++.h>
using namespace std;
int size_of_pool,Tdef,Tmax,Tmin,size_of_command;
const int max_size_of_pool=10001;
string Server;  //服务器的名称
string all="*";
string REQ="REQ";
string DIS="DIS";
struct I_and_P{
    //初始化
    //所有ip地址状态为未分配，占用者为空，过期时刻请0
    //地址的状态有 未分配、待分配、占用、过期 四种。处于未分配状态的 IP 地址没有占用者，而其余三种状态的 IP 地址均有一名占用者
    //处于待分配和占用的ip有一个大于0的过期时刻。到达过期时刻时，若为待分配则变为未分配，占用者清0，过期时刻清0，否则占用->过期，过期时刻清0
    int stage;  //0未分配 1待分配 2占用 3过期 
    int is_belong;  //目前的占用者
    int expired_time;   //过期时刻
}IP[max_size_of_pool];

map<string,int>m;   //用来将字符串映射成一个整数
int tot=0;

// DHCP 数据报文格式 <发送主机> <接收主机> <报文类型> <IP 地址> <过期时刻>
// 发送主机 ~   接收主机 接收报文的主机名 or *
// 报文类型  DIS OFR REQ ACK NAK
// IP       对于DIS来说，发送为0，接收时候忽略  对其他报文来说是一个正整数
// 过期时刻  对于OFR、ACK是一个正整数，表示服务器授予客户端ip的过期时刻
//           对于DIS、REQ来说，若为正正整数表示客户端期望的过期时间   对于其他报文，发送时为0 接受时忽略


//DHCP服务器配置    地址池大小N   默认过期时间Tdef、过期时间的上限Tmax和下限Tmin  本机名称H


//分配策略   一个单独的函数实现如下要求:
//1.首先检查此前是否给该客户端分配过ip，且该ip之后没有分配给别人，否则
//2.分配给他最小的尚未  占用过(新的)  ip，否则
//3.分配给他 此时未被占用的IP，如果没有，则拒绝分配


//实现细节

//对于REQ报文
//1.检查接收主机是否为本机：
//若不是，则找到占用者为发送主机的所有 IP 地址，对于其中状态为 待分配的，将其状态设置为 未分配，并清空其占用者，清零其过期时刻，处理结束；
//2.检查报文中的 IP 地址是否在地址池内，且其占用者为发送主机，若不是，则向发送主机发送 Nak 报文，处理结束
//3.无论该 IP 地址的状态为何，将该 IP 地址的状态设置为占用；
//4.与 Discover 报文相同的方法，设置 IP 地址的过期时刻；
//5.向发送主机发送 Ack 报文

int main(){
    cin>>size_of_pool>>Tdef>>Tmax>>Tmin>>Server>>size_of_command;
    while(size_of_command--){
        //client只能向server发送DIS和REQ
        int t,ip_cur,T_cur;
        string from,to,comm;
        cin>>t>>from>>to>>comm>>ip_cur>>T_cur;
        //对于收到的报文
        //1.判断接收主机是否为本机，或者为 *，若不是，则判断类型是否为 Request，若不是，则不处理；
        //2.若类型不是 Discover、Request 之一，则不处理；
        //3.若接收主机为 *，但类型不是 Discover，或接收主机是本机(客户端本身?)，但类型是 Discover，则不处理。
        if(to==all||to==Server){

            if(comm==REQ||comm==DIS){
                if(to==all&&comm!=DIS) continue;
                if(to==Server&&comm==DIS) continue;
                //排除掉了所有不处理的情况
                if(comm==DIS){
                    //向所有的服务器发送DIS报文的情况

                    //对于DIS报文
                    //1.检查是否有占用者为发送主机的 IP 地址：
                    //若有，则选取该 IP 地址；
                    //若没有，则选取最小的状态为未分配的 IP 地址；
                    //若没有，则选取最小的状态为过期的 IP 地址；
                    //若没有，则不处理该报文，处理结束；
                    //2.将该 IP 地址状态设置为待分配，占用者设置为发送主机；
                    //3.设置过期时刻，详见题目
                    //4.向主机发送offer报文，ip、过期时刻
                    

                }
                
                else if(comm==REQ){
                    //向给客户端回应的服务器发送REQ的情况
                }

            }else continue;

        }
        


        else if(comm==REQ){

        }
        


        else continue;
    }
}