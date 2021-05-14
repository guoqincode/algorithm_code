//p4170 涂色 区间dp
#include<bits/stdc++.h>
using namespace std;
const int maxn=52,inf=0x3f3f3f3f;
int f[maxn][maxn];  //f[i][j]代表[i...j]涂色所需的最小次数
char s[maxn];
int n;
int main(){
    scanf("%s",s+1);    //从第一格开始输入
    n=strlen(s+1);
    // fill(f,f+maxn*maxn,inf);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) f[i][j]=inf;
    }
    for(int i=1;i<=n;i++) f[i][i]=1;
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(s[i]==s[j]) f[i][j]=min(f[i+1][j],f[i][j-1]);
            else{
                //从i j中找个最大值
                for(int k=i;k<j;k++) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            }
        }
    }
    printf("%d",f[1][n]);
    return 0;
}