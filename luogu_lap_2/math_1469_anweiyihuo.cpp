#include<bits/stdc++.h>
using namespace std;
int ans,n,temp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        ans^=temp;
    }
    printf("%d",ans);
    return 0;
}