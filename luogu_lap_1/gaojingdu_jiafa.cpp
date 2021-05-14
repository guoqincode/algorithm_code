#include<bits/stdc++.h>
using namespace std;
string add(string str1,string str2){
    int len1=str1.size();
    int len2=str2.size();
    string res;
    if(len1<len2){
        for(int i=0;i<abs(len1-len2);i++){
            str1="0"+str1;
        }
        len1=str1.size();
    }else if(len1>len2){
        for(int i=0;i<abs(len1-len2);i++){
            str2="0"+str2;
        }
    }
    int cf=0,temp=0;   
    //cout<<str1<<endl<<str2<<endl;
    for(int i=len1-1;i>=0;i--){
        temp=str1[i]-'0'+str2[i]-'0'+cf;
        cf=temp/10;
        temp=temp%10;
        res=char(temp+'0')+res;
    }
    if(cf) res=char(cf+'0')+res;
    return res;
}
int main(){
    string str1,str2;
    cin>>str1>>str2;
    //cout<<str1<<endl;
    //cout<<str2<<endl;
    cout<<add(str1,str2);
    return 0;
}

