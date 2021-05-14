#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    string str1,str2;
    cin>>str1>>str2;
    for(int i=0;i<str1.size();i++){
        for(int j=1;j<str2.size();j++){
            if(str1[i]==str2[j]&&str1[i+1]==str2[j-1]){
                ans++;
            }
        }
    }
    cout<<(1<<ans);
    return 0;
}