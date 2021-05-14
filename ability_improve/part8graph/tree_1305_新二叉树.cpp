#include<bits/stdc++.h>
using namespace std;
struct Node{
    char lc;
    char rc;
}node[200];
int n;
char h,h1;
inline void preord(char x){
    if(x=='*') return;
    cout<<x;
    preord(node[x].lc);
    preord(node[x].rc);
}
int main(){
    cin>>n;
    cin>>h;
    cin>>node[h].lc;
    cin>>node[h].rc;
    for(int i=2;i<=n;i++){
        cin>>h1;
        cin>>node[h1].lc;
        cin>>node[h1].rc;
    }
    preord(h);
    return 0;
}