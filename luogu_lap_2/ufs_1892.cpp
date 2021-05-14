#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int n,m;
int father[maxn],first_diren[maxn]={0};

int find_father(int x){
    if(x==father[x]) return x;
    else return find_father(father[x]);
}
void Union(int a,int b){
    int fa=find_father(a),fb=find_father(b);
    if(fa!=fb) father[fb]=fa;
    return;
}
void init(){
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
}

int main(){
    cin>>n>>m;
    init();
    char ch;
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>ch>>a>>b;
        if(ch=='F') Union(a,b);
        else{
            if(first_diren[a]==0) first_diren[a]=find_father(b);
            else Union(first_diren[a],b);
            if(first_diren[b]==0) first_diren[b]=find_father(a);
            else Union(first_diren[b],a);
        }
    }
    int count[maxn]={0};
    for(int i=1;i<=n;i++) count[find_father(i)]++;
    int count_set=0;
    for(int i=1;i<=n;i++){
        if(count[i]) count_set++;
    }
    cout<<count_set;
    return 0;
}