#include<bits/stdc++.h>
using namespace std;
const int maxn=2000001;
int n,m;
int a[maxn],q[maxn],p[maxn],minq[maxn];    //q存放数据 p存放位置

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int head=1,tail=0;
    minq[0]=0;
    for(int i=1;i<n;i++){
        while(head<=tail&&q[tail]>=a[i]) tail--;
        q[++tail]=a[i];
        p[tail]=i;
        while(head<=tail&&p[head]<=i-m) head++;
        minq[i]=q[head];
        // printf("&d\n",q[head]);
    }
    for(int i=0;i<n;i++) printf("%d\n",minq[i]);
    return 0;
}