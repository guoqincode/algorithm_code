//区间贪心问题
#include<bits/stdc++.h>
using namespace std;
struct line{
    int left,right;
};
line I[100];
bool cmp(line a,line b){
    if(a.left!=b.left) return a.left>b.left;    //先按左端点从大到小排序
    else return a.right<b.right;    //再按右端点从小到大排序
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>I[i].left>>I[i].right;
    }
    sort(I,I+n,cmp);
    int ans=1,lastx=I[0].left;
    for(int i=1;i<n;i++){
        if(I[i].right<=lastx){
            lastx=I[i].left;
            ans++;
        }
    }
    cout<<ans;
}