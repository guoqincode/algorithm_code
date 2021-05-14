#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int n,m;
struct Node{
    int next;
    int vis;
}node[maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        node[i].next=(i+1)%(n+1);
    }
    node[n].next=1;
    int cnt=n;
    int index=0;
    int curcnt=0;
        //cnt为0的时候就结束
     while(true){
        index=(index+1)%(n+1);
        if(index==0) index++;   //要从1开始
        if(node[index].vis==0){
            curcnt++; 
            if(curcnt==m){
                cout<<index<<" ";
                node[index].vis=1;
                cnt--;
                curcnt=0;
                if(cnt==0) break;
            }
        }
    }
    return 0;
}