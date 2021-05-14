#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    cout<<"cout<<"<<str<<endl;
    printf("printf:%s\n",str.c_str());
    cout<<"for:";
    for(int i=0;i<str.size();i++){
        cout<<str[i];
    }
    cout<<endl;

    string str2;
    cin>>str2;
    cout<<"str1:"<<str<<endl;
    cout<<"str2:"<<str2<<endl;
    cout<<"str1+str2=:"<<str+str2<<endl;

    //substr()
    string str3="thank you for your smile";
    cout<<str3.substr(0,10)<<endl;
    //str1.find(str2)返回str1中str2第一次出现的位置 未找到时 失配符 string::npos
    string str4="thank";
    string str5="hello";
    if(str3.find(str4)!=string::npos){
        cout<<str3.find(str4)<<endl;
    }
    if(str3.find(str5)!=string::npos){
        cout<<str3.find(str5)<<endl;
    }else{
        cout<<"string::npos"<<endl;
    }
    cout<<string::npos<<endl;
    
    return 0;
}