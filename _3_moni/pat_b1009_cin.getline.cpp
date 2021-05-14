#include<bits/stdc++.h>
using namespace std;
int main(){
    char str[90],ans[90][90];
    cin.getline(str,90);    //输入一整行
    int num=0,len=strlen(str),k=0;
    //num记录单词个数 k记录当前单词走到哪里了
    for(int j=0;j<len;j++){
        if(str[j]!=' '){
            ans[num][k++]=str[j];
        }else{
            ans[num][k]='\0';
            k=0;
            num++;
        }
    }
    for(int i=num;i>=0;i--){
        cout<<ans[i];
        if(i) cout<<" ";
    }
    return 0;
}