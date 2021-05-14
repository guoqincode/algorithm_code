#include<bits/stdc++.h>
using namespace std;
const int maxn=101;

int father[maxn];
int n;
void init_father(){
    //初始化 father
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
}

int findfather(int x){
    if(x==father[x]) return x;
    else return findfather(father[x]);
}

void Union_ufs(int a,int b){
    int fa=findfather(a);
    int fb=findfather(b);
    if(fa!=fb){
        father[fb]=fa;
    }
}

int main(){
    int m;
    cin>>n>>m;
    init_father();
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        Union_ufs(a,b);
    }
    set<int>st;
    for(int i=1;i<=n;i++){
        st.insert(findfather(i));
    }
    for(set<int>::iterator it=st.begin();it!=st.end();it++){
        cout<<*it<<"  ";
    }
    cout<<endl<<st.size();
    return 0;
}