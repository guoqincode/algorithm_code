//pat1015
#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
    
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
void test(int n,int d){
    
    vector<int>nums;
    while(n){
        nums.push_back(n%d);	
        n=n/d;
    }
    int nn=0,re_n=0; 
    for(int i=0;i<nums.size();i++){
        re_n=re_n*d+nums[i];
        nn=nn*d+nums[nums.size()-1-i];
    }
    if(prime(nn)&&prime(re_n)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    while(n>0){
        int d;
        scanf("%d",&d);
        test(n,d);
        scanf("%d",&n);
    }
    return 0;
}
