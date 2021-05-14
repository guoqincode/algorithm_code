#include<bits/stdc++.h>
using namespace std;
int main(){
    map<char,int>mp;
    mp['a']=1;
    mp['b']=2;
    mp['c']=3;
    //map 会按照键从小到大排序
    cout<<mp['a']<<" "<<mp['b']<<" "<<mp['c']<<endl;    //通过下标访问
    for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;     //通过迭代器访问 it->first it->second
    }

    //find(key)  返回迭代器
    map<char,int>::iterator it=mp.find('b');
    cout<<it->first<<" "<<it->second<<endl;
    return 0;
}