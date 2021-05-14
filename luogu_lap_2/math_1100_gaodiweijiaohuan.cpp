#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long x;
    cin>>x;
    cout<<((x&0x0000ffff)<<16|(x&0xffff0000)>>16);
    return 0;
}