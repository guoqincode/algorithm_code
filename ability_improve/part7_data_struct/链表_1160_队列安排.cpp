#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

struct Node{
    int lf;
    int rh;
}node[maxn];

int n,m;
int vis[maxn];
int main(){
    n=read();
    node[1].lf=node[1].rh=-1;
    for(int i=2;i<=n;i++){
        int temp=read(),p=read();
        //注意插入的时候不能只顾一边 左右两半都要照顾到
        if(p==0){
            //插入到temp的左边
            if(node[temp].lf==-1){
                //如果temp左边没有元素
                node[i].rh=temp;
                node[i].lf=node[temp].lf;
                node[temp].lf=i;
            }else{
                node[i].rh=temp;
                node[i].lf=node[temp].lf;
                int kk=node[temp].lf;
                node[kk].rh=i;
                node[temp].lf=i;
            }
            
        }else{
            if(node[temp].rh==-1){
                node[i].lf=temp;
                node[i].rh=node[temp].rh;
                node[temp].rh=i;
            }else{
                node[i].lf=temp;
                node[i].rh=node[temp].rh;
                int kk=node[temp].rh;
                node[kk].lf=i;
                node[temp].rh=i;
            }
        }

        // cout<<endl;
        //  for(int i=1;i<=n;i++){
        //     cout<<i<<"  "<<node[i].lf<<"  "<<node[i].rh<<endl;
        // }
        // cout<<endl;
    }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<"  "<<node[i].lf<<"  "<<node[i].rh<<endl;
    // }
    // cout<<endl;
    m=read();
    for(int i=1;i<=m;i++){
        int temp=read();
        if(!vis[temp]) vis[temp]=1;
    }
    int st=1;
    for(int i=1;i<=n;i++){
        if(node[i].lf==-1){
            st=i;
            break;
        }
    }
    int temp=st;
    while(true){
        if(temp==-1) break;
        if(!vis[temp]){
            //如果没有删除
            cout<<temp<<" ";
        }
        temp=node[temp].rh;
    }
    return 0;
}