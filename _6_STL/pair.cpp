#include<bits/stdc++.h>
using namespace std;
int main(){
    //三种初始化方式
    pair<string,int>p;
    p.first="haha";
    p.second=5;
    cout<<p.first<<"  "<<p.second<<endl;
    p=make_pair("xixi",55);
    cout<<p.first<<"  "<<p.second<<endl;
    p=pair<string,int>("heihei",555);
    cout<<p.first<<"  "<<p.second<<endl;

    map<string,int>mp;
    mp.insert(make_pair("haha",5555));
    mp.insert(pair<string,int>("hehe",55555));
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}