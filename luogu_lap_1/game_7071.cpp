#include<bits/stdc++.h>
using namespace std;
void test(int n){
    if(n%2){
        cout<<-1;
        return;
    }
    vector< int >res;
    for(int i=24;i>=1;i--){
        if(n>=(1<<i)){
            res.push_back(1<<i);
            n-=(1<<i);
        }
        if(n==0) break;
    }
    if(n!=0){
        cout<<-1;
        return;
    }else{
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        return;
    }
}
int main(){
    int n;
    cin>>n;
    test(n);
    return 0;
}