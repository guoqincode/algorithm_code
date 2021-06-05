//kmp算法的模板
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int kmp[maxn];
int la,lb,j;
char a[maxn],b[maxn];

int main(){
    cin>>a+1>>b+1;
    la = strlen(a+1);
    lb = strlen(b+1);
    for(int i=2;i<=lb;i++){
        while(j&&b[i]!=b[j+1]) j = kmp[j];
        if(b[j+1]==b[i]) j++;
        kmp[i] = j;
    }
    j = 0;
    for(int i=1;i<=la;i++){
        while(j>0&&b[j+1]!=a[i]) j = kmp[j];
        if(b[j+1]==a[i]) j++;
        if(j==lb){
            cout<<i-lb+1<<endl;
            j = kmp[j];
        } 
    }
    for(int i=1;i<=lb;i++) cout<<kmp[i]<<" ";
    return 0;
}