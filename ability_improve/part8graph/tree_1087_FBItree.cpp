//FBI树
#include<bits/stdc++.h>
using namespace std;
char str[1100];
int n;
char chh[1025][1025];
inline void build(int l,int r){
    int mid;
    if(l<r){
        mid=(l+r)>>1;
        build(l,mid);
        build(mid+1,r);
    }
    if(l==r){
        if(str[l]=='0'){
            chh[l][l]='B';
            printf("B");
        }else{
            chh[l][l]='I';
            printf("I");
        }
    }else{
        if(chh[l][mid]==chh[mid+1][r]){
            chh[l][r]=chh[l][mid];
            printf("%c",chh[l][r]);
        }else{
            chh[l][r]='F';
            printf("F");
        }
    }
}

int main(){
    cin>>n;
    scanf("%s",str+1);

    build(1,1<<n);
    // for(int i=1;i<=(1<<n);i++){
    //     for(int j=1;j<=(1<<n);j++){
    //         printf("%c ",chh[i][j]);
    //     }
    //     cout<<endl;
    // }
    return 0;
}