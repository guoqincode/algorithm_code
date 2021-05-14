#include<bits/stdc++.h>
using namespace std;
const int maxn=130;
typedef struct{
    int num;
    int ability;
}team;
team teams[maxn];
bool cmp(team a,team b){
    return a.ability>b.ability;
}
int n;
int main(){
    cin>>n;
    int size=(1<<n);    //这样求幂快一些
    for(int i=1;i<=size;i++){
        teams[i].num=i;
        cin>>teams[i].ability;
    }
    sort(teams+1,teams+(1<<n)/2+1,cmp);
    sort(teams+(1<<n)/2+1,teams+(1<<n)+1,cmp);
    if(teams[1].ability>teams[(1<<n)/2+1].ability){
        cout<<teams[(1<<n)/2+1].num;
    }else{
        cout<<teams[1].num;
    }
    return 0;
}