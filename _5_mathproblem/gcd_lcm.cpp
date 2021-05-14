#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    //cout<<a<<"  "<<b<<endl;
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    int a,b,res_gcd,res_lcm;
    cin>>a>>b;
    if(a>b){
        //保证 a>b
        res_gcd=gcd(a,b);
    }else{
        res_gcd=gcd(b,a);
    }
    res_lcm= (a/res_gcd)*b;     //防止溢出
    cout<<res_gcd<<"  "<<res_lcm;
    return 0;
}