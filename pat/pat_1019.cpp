//pat 1019
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,base;
    scanf("%d %d",&n,&base);
    vector<int>res;
    while(n){
        res.push_back(n%base);
        n/=base;
    }
    int flag=1;
    for(int i=0;i<res.size()/2;i++){
        if(res[i]!=res[res.size()-1-i]){
            flag=0;
            break;
        }
    }
    if(flag){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    for(int i=res.size()-1;i>=0;i--){
        printf("%d",res[i]);
        if(i) printf(" ");
    }
    return 0;
}
