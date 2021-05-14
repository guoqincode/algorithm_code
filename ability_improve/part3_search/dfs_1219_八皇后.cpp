//dfs 八皇后问题
#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int row[maxn],viscol[maxn],vismain[2*maxn+3],visvice[2*maxn+3];
int n;
int cnt=0;
inline void dfs(int x){
    if(x>n){
        //
        cnt++;
        if (cnt<=3){
            for(int i=1;i<=n;i++) printf("%d ",row[i]);
            printf("\n");
            return;
        }
        
    }else{
        for(int j=1;j<=n;j++){
            //遍历这一行中的所有可能
            if(viscol[j]==0&&vismain[x+j]==0&&visvice[x-j+n]==0){
                row[x]=j;
                viscol[j]=1;
                vismain[x+j]=1;
                visvice[x-j+n]=1;
                dfs(x+1);
                viscol[j]=0;
                vismain[x+j]=0;
                visvice[x-j+n]=0;
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    dfs(1);
    printf("%d",cnt);
    return 0;
}