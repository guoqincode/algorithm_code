#include<bits/stdc++.h>
using namespace std;
const int maxn=100000001;
const int maxq=1000001;
int n,q;
int isprime[maxn],prime[maxn];
int prime_no=0;
int query[maxq];
// void find_prime(){
//     //埃氏筛法在10^8以上时会超时，因为会出现重复筛的情况
//     for(int i=2;i<n+1;i++){
//         if(isprime[i]==0){
//             prime[prime_no++]=i;
//             for(int j=i+i;j<=n;j+=i){
//                 isprime[j]=1;
//             }
//         }
//     }
// }
void find_prime_oula(){
    for(int i=2;i<=n;i++){
        if(isprime[i]==0){
            prime[++prime_no]=i;
        }
        for(int j=1;j<=prime_no&&i*prime[j]<=n;j++){
            isprime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    return;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++)   scanf("%d",&query[i]);
    find_prime_oula();
    for(int i=1;i<=q;i++)   printf("%d\n",prime[query[i]]);
    return 0;
}