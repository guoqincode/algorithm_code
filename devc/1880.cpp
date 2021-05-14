//����ͻ���dp ʯ�Ӻϲ�
//���ǻ���ʱ�� dp[i][j]=max(dp[i][k],dp[k+1][j])+sum[i]-sum[j-1]
//�����ǻ��Σ�
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){ if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){ x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
const int maxn=210; //��Ϊ��Բ�βٳ� ����dp ����Ҫ������������ռ�
const int inf=0x3f3f3f3f;
int n;
int maxans=0,minans=inf;
int a[maxn],sum[maxn];  //sum ǰ׺����
int dpmax[maxn][maxn],dpmin[maxn][maxn];
int main(){
    n=read();
    fill(dpmin,dpmin+maxn*maxn,inf);
    for(int i=1;i<=n;i++){ a[i]=read(); a[i+n]=a[i];}
    for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];   //���ǰ׺��
    for(int len=1;len<n;len++){
        for(int i=1;i+len<=2*n;i++){
            int j=i+len;
            dpmin[i][j]=inf;
            for(int k=i;k<j;k++){
                dpmax[i][j]=max(dpmax[i][j],dpmax[i][k]+dpmax[k+1][j]+sum[j]-sum[i-1]);
                dpmin[i][j]=min(dpmin[i][j],dpmin[i][k]+dpmin[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        maxans=max(maxans,dpmax[i][i+n-1]);
        minans=min(minans,dpmin[i][i+n-1]);
    }
    cout<<minans<<endl<<maxans;
    return 0;
}
