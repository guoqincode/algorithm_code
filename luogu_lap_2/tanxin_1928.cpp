#include<bits/stdc++.h>
using namespace std;
typedef struct{
    double m=0,v=0,ave=0;
}stu;
bool cmp(stu one,stu two){
    return one.ave>two.ave;
}
int main(){
    int n;
    double t,ans=0;
    scanf("%d %lf",&n,&t);
    vector< stu >res(n);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&res[i].m,&res[i].v);
        res[i].ave=res[i].v/res[i].m;
    }
    sort(res.begin(),res.end(),cmp);
    for(int i=0;i<n;i++){
        if(t>=res[i].m){
            t-=res[i].m;
            ans+=res[i].v;
        }else{
            ans+=res[i].ave*t;
            break;
        }
    }
    printf("%.2lf",ans);
    return 0;
}
