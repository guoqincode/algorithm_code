//单调队列的板子
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000001;
int n,k;
int head,tail;
int a[maxn],q[maxn],p[maxn];    //q记录数据 p记录下标
void min_queue(){
    head=1,tail=0;
    for(int i=1;i<=n;i++){
        while(head<=tail&&q[tail]>=a[i]) tail--;    //遇到更小的了，在前面的根本不可能成为队列中的最小值了
        q[++tail]=a[i];
        p[tail]=i;
        while(p[head]<=i-k) head++; //清除在窗口外的元素
        if(i>=k) printf("%d ",q[head]);
    }
    printf("\n");
}
void max_queue(){
    head=1,tail=0;
    for(int i=1;i<=n;i++){
        while(head<=tail&&q[tail]<=a[i]) tail--;    //遇到更大的了，在前面的根本不可能成为队列中的最大值了
        q[++tail]=a[i];
        p[tail]=i;
        while(p[head]<=i-k) head++; //清除在窗口外的元素
        if(i>=k) printf("%d ",q[head]);
    }
    printf("\n");
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    min_queue();
    max_queue();
    return 0;
}