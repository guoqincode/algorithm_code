//导弹拦截 本质上是求一个最长不上升序列和一个最长上升序列 
//LIS问题 注意用O(nlgn)时间复杂度的算法
//!!LIS问题还没有完全理解  变一下就不会了
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5 + 15;
int a[maxn];
int f1[maxn],f2[maxn];
int main(){
    int temp,n=0;
    // while(cin>>temp){
    //     a[++n]=temp;
    //     // if(n==8) break;
    // }
    while(scanf("%d",&temp)==1) a[++n]=temp;
    int len1=0,len2=0;  //分别代表最长不上升子序列和最长上升子序列
    f1[0]=0,f2[0]=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=f1[len1]) f1[++len1]=a[i];
        else{
            int left=0,right=len1,mid;
            while(left<=right){
                mid=(left+right)>>1;
                if(f1[mid]>=a[i]) left=mid+1;
                else right=mid-1;
            }
            f1[left]=max(f1[left],a[i]);
        }
    }
    // for(int i=1;i<=n;i++) f2[i]=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(a[i]>f2[len2]) f2[++len2]=a[i];
        else{
            int left=0,right=len2,mid;
            while(left<right){
                mid=(left+right)>>1;
                if(f2[mid]>=a[i]) right=mid;
                else left=mid+1;
            }
            f2[left]=min(f2[left],a[i]);
        }
    }
    printf("%d\n",len1+1);
    printf("%d",len2);
    return 0;
}