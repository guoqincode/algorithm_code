// 并查集 1.初始化 2.寻找根节点 递推和递归两种方法 3.合并 4.路径压缩 递推和递归两种方法
#include<bits/stdc++.h>
using namespace std;
const int maxn=1025;
int father[maxn];
int findfather_ditui(int x){
    while(x!=father[x]){
        x=father[x];
    }
    return x;
}
int findfather_digui(int x){
    if(x==father[x]) return x;
    else return findfather_digui(father[x]);
}
void Union(int a,int b){
    int fa=findfather_digui(a);
    int fb=findfather_digui(b);
    if(fa!=fb){
        father[fb]=fa;  //fb连到fa上
    }
}
int yasuo(int x){
    int a=x;    //把x保存一下
    int root=findfather_ditui(x);   //得到根节点root
    while(a!=father[a]){
        int z=a;
        a=father[a];    //保存原父亲节点
        father[z]=root;    
    }
    return x;
}
int yasuo_digui(int v){
    if(v==father[v]) return v;
    else{
        int F=yasuo_digui(father[v]);
        father[v]=F;
        return F;
    }
}
int main(){
    //1 初始化
    for(int i=1;i<=1024;i++){
        father[i]=i;
    }
    father[1]=1;
    father[2]=1;
    father[3]=2;
    father[4]=3;
    father[5]=4;
    father[6]=5;
    //cout<<findfather_digui(2)<<findfather_digui(3)<<endl;
    for(int i=1;i<=6;i++){
        cout<<i<<"  "<<findfather_ditui(i)<<"  "<<findfather_digui(i)<<"  "<<father[i]<<endl;
    }
    // Union(3,6);
    // for(int i=1;i<=6;i++){
    //     cout<<i<<"  "<<findfather_ditui(i)<<"  "<<findfather_digui(i)<<endl;
    // }
    // int x=yasuo(6);
    // for(int i=1;i<=6;i++){
    //     cout<<i<<"  "<<findfather_ditui(i)<<"  "<<findfather_digui(i)<<"  "<<father[i]<<endl;
    // }
    int x=yasuo_digui(6);
    for(int i=1;i<=6;i++){
        cout<<i<<"  "<<findfather_ditui(i)<<"  "<<findfather_digui(i)<<"  "<<father[i]<<endl;
    }
    return 0;
}