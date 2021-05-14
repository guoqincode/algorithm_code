//按照固定格式输出A+B
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int sum=a+b;
    if(abs(sum)<1000) cout<<sum;
    else if(abs(sum)<1000000) printf("%d,%03d",sum/1000,abs(sum%1000));
    else printf("%d,%03d,%03d",sum/1000000,abs((sum/1000)%1000),abs(sum%1000));
    return 0;
} 
