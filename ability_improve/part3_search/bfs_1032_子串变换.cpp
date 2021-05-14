#include<bits/stdc++.h>
using namespace std;
const int maxn=7;
string a,b,orignal_strs[maxn],transform_strs[maxn];
int cnt=0,ans=0;

struct node{
    string ss;
    int v;
};

string trans(string str,int i,int j){
    //返回转化后的字符串
    string trans_ans="";
    // if(i+orignal_strs[j].length()>str.length()) return trans_ans;
    // for(int k=0;k<orignal_strs[j].length();k++){
    //     if(str[i+k]!=orignal_strs[j][k]) return trans_ans;
    // }
    // trans_ans=str.substr(0,i);
    // trans_ans+=transform_strs[j];
    // trans_ans+=str.substr(i+orignal_strs[j].length());
    // return trans_ans;
    //这样是找到了字符串所有出现的次数

    //这样是只找到了字符串第一次出现的时候
    // if(str.find(orignal_strs[j])==string::npos) return trans_ans;
    // int posk=str.find(orignal_strs[j]);

    if(str.find(orignal_strs[j],i)==string::npos) return trans_ans;     //从第i个开始找!!!
    int posk=str.find(orignal_strs[j],i);
    trans_ans=str.substr(0,posk);
    trans_ans+=transform_strs[j];
    trans_ans+=str.substr(posk+orignal_strs[j].length());
    return trans_ans;
}

queue<node>q;
map<string,int>m;
inline void bfs(){
    node nn; nn.ss=a,nn.v=0;
    q.push(nn);

    while(!q.empty()){
        node u=q.front(); q.pop();
        string temp;
        if(m[u.ss]) continue;   //剪枝 判断重复的路径
        if(u.ss==b){
            //出现了答案 跳出
            ans=u.v;
            break;
        }
        m[u.ss]=1;
        for(int i=0;i<u.ss.length();i++){
            //枚举所有可能出现的位置
            for(int j=0;j<cnt;j++){
                temp=trans(u.ss,i,j);
                if(temp=="") continue;
                node vv;
                vv.ss=temp;
                vv.v=u.v+1;
                q.push(vv);
            }
        }
    }
    if(ans>=10||ans==0) cout<<"NO ANSWER!";
    else cout<<ans;
}

int main(){
    cin>>a>>b;
    while(cin>>orignal_strs[cnt]>>transform_strs[cnt]) cnt++; //cnt-1最后的值就是最后一个匹配的下标
    bfs();
    return 0;
}