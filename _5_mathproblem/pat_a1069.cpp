#include<bits/stdc++.h>
using namespace std;
int n;

int sol(int n){
    int nums[4];
    for(int i=0;i<4;i++){
        nums[i]=n%10;
        n=n/10;
    }
    sort(nums,nums+4);
    int big=nums[3]*1000+nums[2]*100+nums[1]*10+nums[0];
    int small=nums[0]*1000+nums[1]*100+nums[2]*10+nums[3];
    int cha=big-small;
    //cout<<big<<"-"<<small<<"="<<cha<<endl;
    printf("%04d - %04d = %04d\n",big,small,cha);
    return cha;
}
int main(){
    cin>>n;
    while(1){
        int temp=sol(n);
        if(temp==0||temp==6174) break;
        else n=temp;
    }
    return 0;
}