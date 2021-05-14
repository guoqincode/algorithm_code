#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,step=0;
    cin>>n;
    while(n!=1){
        if(n%2) n=(3*n+1)/2;
        else n=n/2;
        step++;
    }
    cout<<step;
    return 0;
}