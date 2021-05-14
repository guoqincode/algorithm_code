#include<bits/stdc++.h>
using namespace std;
const int maxn=256;
int p=0;
int main(){
    char ch;
    while((ch=getchar())!='@'){
        if(ch=='(') p++;
        else if(ch==')'){
            p--;
            if(p<0){
                cout<<"NO";
                return 0;
            }
        }
    }
    if(p==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}