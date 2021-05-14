#include<bits/stdc++.h>
using namespace std;
int isdanger(int x,int y,int xl,int yd,int xr,int yu){
    if((x>=xl)&&(x<=xr)&&(y>=yd)&&(y<=yu))  return 1;
    else return 0; 
}
typedef struct{
    int x=0,y=0;
}stu;
int main(){
    int n,k,t,xl,yd,xr,yu;
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    vector< vector<stu> >res(n,vector<stu>(t));
    //核心问题成了求连续个1的个数
    int count[n][t];    //记录第i个人第j个坐标是否危险
    int counta=0,countb=0;    // 经过高危区域人数和在高位区域逗留人数
    vector< vector<int> >tempcount(n,vector<int>(t,0));      //最大连续次数的计数
    for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
            cin>>res[i][j].x>>res[i][j].y;
            count[i][j]=isdanger(res[i][j].x,res[i][j].y,xl,yd,xr,yu);
        }
    }
    //for(int i=0;i<n;i++){
    //    for(int j=0;j<t;j++){
    //        cout<<count[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    for(int i=0;i<n;i++){
        //对n个人进行检查
        //tempcount[i][j] 记录到j时的连续天数
        int maxx=0;
        for(int j=0;j<t;j++){
            if(j==0) tempcount[i][j]=count[i][j];
            else{
                if(count[i][j]==1){
                    tempcount[i][j]=tempcount[i][j-1]+1;
                }else{
                    tempcount[i][j]=0;
                }
            }
            maxx=max(maxx,tempcount[i][j]);
        }
        if(maxx>=k) countb++;
        else if(maxx>0) counta++;
    }
    //for(int i=0;i<n;i++){
    //    for(int j=0;j<t;j++){
    //       cout<<tempcount[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    cout<<counta+countb<<endl<<countb;
    return 0;
}
