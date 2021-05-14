#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    long long sum=0;
    cin>>n>>x;
    vector< long long >res(n);
    for(int i=0;i<n;i++) cin>>res[i];
    if(res[0]>x){
        sum+=(res[0]-x);
        res[0]=x;
    }
    for(int i=1;i<n;i++){
        if(res[i]+res[i-1]>x){
            //res[0]已经提前处理了
            sum+=(res[i]+res[i-1]-x);
            res[i]-=(res[i]+res[i-1]-x);
        }
    }
    cout<<sum;
    return 0;
}