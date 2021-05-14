#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int n,p[maxn],hashtable_[maxn]={false};

void generatep(int index){
    //index-->处理到第index位
    if(index==n+1){
        for(int i=1;i<=n;i++){
            cout<<p[i];
        }
        cout<<endl;
        return;
    }
    for(int x=1;x<=n;x++){
        if(hashtable_[x]==false){
            p[index]=x;
            hashtable_[x]=true;
            generatep(index+1);
            hashtable_[x]=false;
        }
    }
}

int main(){
    cin>>n;
    generatep(1);   //从第一位开始产生
    return 0;
}