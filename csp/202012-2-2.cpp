//100分的做法 对所有的输入进行排序
//记录比自己大的1的个数，比自己小的0的个数
#include<bits/stdc++.h>
using namespace std;
const int maxn=200001;
struct Node{
    int seita;
    int result;
}node[maxn];
struct Node1
{
    int seita;
    int qian1;
    int hou0;
    int sum;
}node1[maxn];
int n;
bool cmp(Node a,Node b){
    return a.seita<b.seita;
}
bool cmp1(Node1 a,Node1 b){
    //注意最后的排序 要输出sum最大的里对应的最大的seita
    if(a.sum==b.sum) return a.seita<b.seita;
    else return a.sum<b.sum;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&node[i].seita,&node[i].result);
    }
    sort(node+1,node+n+1,cmp);
    int k=1;
    node1[k].seita=node[1].seita;
    if(node[1].result) node1[k].qian1++;
    else node1[k].hou0++;
    for(int i=2;i<=n;i++){
        if(node[i].seita==node1[k].seita){
            if(node[i].result==1) node1[k].qian1++;
            else node1[k].hou0++;
        }else{
            k++;
            node1[k].seita=node[i].seita;
            if(node[i].result==1) node1[k].qian1++;
            else node1[k].hou0++;
        }
    }
    //k-->不同的总数
    //qian1记录了当前位置1的个数  hou0记录了当前位置0的个数
    int sum=0;
    for(int i=k;i>=1;i--){
        sum+=node1[i].qian1;
        node1[i].qian1=sum;
    }
    sum=0;
    for(int i=1;i<=k;i++){
        sum+=node1[i].hou0;
        node1[i].hou0=sum;
    }
    node1[0].hou0=0;
    for(int i=1;i<=k;i++) node1[i].sum=node1[i-1].hou0+node1[i].qian1;
    sort(node1+1,node1+k+1,cmp1);
    cout<<node1[k].seita;
    return 0;
}