#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;

map<int,string>intTostring; //编号->姓名
map<string,int>stringToint; //姓名->编号
map<string,int>gang_and_nums;  //head->人数

int G[maxn][maxn]={0};  //邻接矩阵
int weight[maxn]={0};   //点权
int n,k,numperson=0;    //边数n 下限k 总输入numperson
bool vis[maxn]={false};

void dfs(int nowvisit,int& head,int& nummember,int& total){
    nummember++;
    vis[nowvisit]=true;
    if(weight[nowvisit]>weight[head]){
        head=nowvisit;
    }
    for(int i=0;i<numperson;i++){
        if(G[nowvisit][i]>0){
            total+=G[nowvisit][i];
            G[nowvisit][i]=G[i][nowvisit]=0;    //防止回头
            if(vis[i]==false){
                dfs(i,head,nummember,total);
            }
        }
    }
}
void dfstrave(){
    for(int i=0;i<numperson;i++){
        if(vis[i]==false){
            int head=i,nummember=0,total=0;
            dfs(i,head,nummember,total);
            if(nummember>2&&total>k){
                gang_and_nums[intTostring[head]]=nummember;
            }
        }
    }
}

int change(string str){
    //插入一个姓名时返回编号
    if(stringToint.find(str)!=stringToint.end()){
        //str 已经出现过
        return stringToint[str];
    }else{
        stringToint[str]=numperson;
        intTostring[numperson]=str;
        return numperson++;    //总人数+1
    }
}
int main(){
    int w;  //边权
    string str1,str2;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>str1>>str2>>w;
        int id1=change(str1);
        int id2=change(str2);
        weight[id1]+=w;
        weight[id2]+=w;
        G[id1][id2]+=w;
        G[id2][id1]+=w;
    }
    dfstrave();
    cout<<gang_and_nums.size()<<endl;
    for(map<string,int>::iterator it=gang_and_nums.begin();it!=gang_and_nums.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}
