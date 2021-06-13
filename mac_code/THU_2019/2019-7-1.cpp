//现定义一种字符串加密方式：将字符串每个字符的值在字母表上向右移一位
//右移的规则是’a’ -> ‘b’, ‘b’ -> ‘c’, …, ‘y’ -> ‘z’, ‘z’->‘a’
//例如"afju"加密后为"bgkv"。
//现给定正整数 n ( n ≤ 1 e 18 )  和一个长度不超过1e6的只含小写字母的字符串s 
//已知s被加密了n次
#include<bits/stdc++.h>
using namespace std;
#define ll long long
string str;
ll n;
int main(){
    cin>>n>>str;
    n = n % 26;   
    for(int i=0;i<str.size();i++){
        str[i] = 'a' + (str[i] - 'a' - n + 26) % 26;
    }
    cout<<str<<endl;
    return 0;
}