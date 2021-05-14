//快排模板
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000001;
int n,a[maxn];
void myqsort(int l,int r){
    int mid=a[(l+r)/2];
    int i=l,j=r;
    do{
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(l<j) myqsort(l,j);
    if(i<r) myqsort(i,r);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    myqsort(1,n);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}