#include<bits/stdc++.h>
using namespace std;
const int maxn=151;
const int INF=(int)(pow(2,31)-1);
double dis[maxn][maxn];
int n;
double ldis[maxn];
double l_1,l_2=INF,ans;
struct Node
{
    int x;
    int y;
}node[maxn];

double point_dis_with_another(int a,int b){
    return sqrt((node[a].x-node[b].x)*(node[a].x-node[b].x)+(node[a].y-node[b].y)*(node[a].y-node[b].y));
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        // cin>>node[i].x>>node[i].y;
        scanf("%d%d",&node[i].x,&node[i].y);
    }
    // for(int i=1;i<=n;i++){
    //     // cin>>node[i].x>>node[i].y;
    //     printf("%d %d\n",node[i].x,node[i].y);
    // }
    // cout<<point_dis_with_another(1,2)<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp;
            scanf("%1d",&temp); //每次只输入个位数
            // cout<<"he ";
            if(temp) dis[i][j]=point_dis_with_another(i,j);
            else if(i!=j) dis[i][j]=INF;
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%12lf ",dis[i][j]);
    //     }
    //     printf("\n");
    // }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%12lf ",dis[i][j]);
    //     }
    //     printf("\n");
    // }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]!=INF) ldis[i]=max(dis[i][j],ldis[i]);
            l_1=max(l_1,ldis[i]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]==INF){
                l_2=min(ldis[i]+point_dis_with_another(i,j)+ldis[j],l_2);
            }
        }
    }
    ans=max(l_1,l_2);
    printf("%.6f",ans);
    return 0;
}