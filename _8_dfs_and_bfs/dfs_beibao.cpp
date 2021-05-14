#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
int n,w,maxValue=0;
int _w[maxn],_v[maxn];

void dfs(int index,int sumw,int sumv){
    if(index==n) return ;
    dfs(index+1,sumw,sumv);
    if(sumw+_w[index]<=w){
        if(sumv+_v[index]>maxValue){
            maxValue=sumv+_v[index];
        }
        dfs(index+1,sumw+_w[index],sumv+_v[index]);
    }
}

int main(){
    cin>>n>>w;
    for(int i=0;i<n;i++) cin>>_w[i];
    for(int i=0;i<n;i++) cin>>_w[i];
    dfs(0,0,0);
    cout<<maxValue;
    return 0;
}