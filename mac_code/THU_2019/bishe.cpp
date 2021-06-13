#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
const int maxk=101;

int A[maxn][maxn];
int F[maxk][maxn][maxn];    //F[k][i][j] == F^k (i,j)

int n;  //节点的数量

int main(){
    cin>>n;

    //初始化输入 A 初始化k=1的时候的F
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>A[i][j];
            F[1][i][j]=A[i][j];
        }
    }

    //计算k从2到100时候的F矩阵
    for(int k=2;k<maxk;k++){
        for(int i=1;i<=n;i++){
            //遍历n个节点

            //定义1中的F 递推式的实现
            for(int j=1;j<=n;j++){

                // if(F[k-1][i][j]!=0&&A[i][j]!=0){
                //     //
                //     F[k][i][j]+=(F[k-1][i][j]+A[i][j]);
                // }else if(F[k-1][i][j]!=0||)

                //现在是F[k][i][j]
                for(int t=1;t<=n;t++){
                    if(F[k-1][i][t]!=0&&A[i][j]!=0){
                        F[k][i][j]+=(F[k-1][i][t]+A[i][j]);
                    }else if(F[k-1][i][t]!=0||A[t][j]!=0){
                        F[k][i][j]=0;

                        break;
                    }
                }
            }

        }
    }

    for(int k=1;k<11;k++){
        cout<<"k=="<<k<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // cout<<F[k][i][j]<<" ";
                printf("%-5d ",F[k][i][j]);
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}