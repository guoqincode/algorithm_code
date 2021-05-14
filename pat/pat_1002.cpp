//pat 1002
//2 1 2.4 0 3.2
//2 2 1.5 1 0.5
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<float>res(1001,0);
    int n1,n2;
    int exp;
    float coe;
    scanf("%d",&n1);
    while(n1--){
        scanf("%d %f",&exp,&coe);
        res[exp]+=coe;
    }
    scanf("%d",&n2);
    while(n2--){
        scanf("%d %f",&exp,&coe);
        res[exp]+=coe;
    }
    int count=0,a[20];
    float b[20];
    for(int i=0;i<=1000;i++){
        if(res[i]){
            a[count]=i;
            b[count]=res[i];
            count++;
        }
    }
    //count->size of result
    printf("%d",count);
    for(int i=count-1;i>=0;i--){
        printf(" %d %.1f",a[i],b[i]);
    }
    return 0;
}
