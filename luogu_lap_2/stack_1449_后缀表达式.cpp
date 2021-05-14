#include<bits/stdc++.h>
using namespace std;
#define ll long long
int p=-1;
ll now=0;   //作为存进位的用的
const int maxn=1001;
ll str[maxn];
char op;
int main(){
    // char ch=getchar();
    // while(ch!='@'){
    //     str[++p]=ch;
    //     ch=getchar();
    // }
    while((op=getchar())!='@'){
        if(op>='0'&&op<='9') now=now*10+(op-'0');
        else if(op=='.'){
            str[++p]=now;
            now=0;  //清除当前进位数
        }else if(op=='+'){
            str[p-1]+=str[p];
            str[p]=0;
            p--;
        }else if(op=='-'){
            str[p-1]-=str[p];
            str[p]=0;
            p--;
        }else if(op=='*'){
            str[p-1]*=str[p];
            str[p]=0;
            p--;
        }else if(op=='/'){
            str[p-1]/=str[p];
            str[p]=0;
            p--;
        }
    }
    cout<<str[0];
    return 0;
}