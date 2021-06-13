//首先有一个允许重复的集合S，第一行输入指令行数n，
//接下来n行代表不同的指令操作，一共只有两种指令“ADD”和“QUERY”，
//系统保证大写输入，若是ADD，该行第二个输入是待录入字符串
//第三个代表分割后的字串的长度，如“ADD aaab 2”分割后的子串结果为{aa,aa,ab}
//然后将分割后的子串全部存进S中。如果是QUERY，该行第二个输入是起始查询字符串，
//第三个输入是终止查询字符串，该指令对应一个输出，
//代表集合S中字典序在起始字符串和终止字符串之间（包括起始和终止的字符串）的字符串个数。

#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
string str[maxn];
string add="ADD";
string query="QUERY";
int tot=0;
int n;

int main(){
    cin>>n;
    string comm,instr,from,to;
    int len;
    while (n--){
        cin>>comm;
        if(comm==add){
            cin>>instr>>len;
            int instr_size=instr.size();
            for(int i=0;i<=instr_size-len;i++){
                tot++;
                str[tot]=instr.substr(i,len);
            }
        }else if(comm==query){
            cin>>from>>to;
            sort(str+1,str+1+tot);  //排成了字典序
            int left=1,right=tot;
            while(from!=str[left]) left++;
            while(to!=str[right]) right--;
            cout<<right-left+1<<endl;
        }
    }
    return 0;
}