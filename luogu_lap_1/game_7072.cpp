#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n_nums_of_input,rate;
void dytest(vector< int >&nums){
    //动态检测
    int n_rate = ((nums.size()-1)*rate)/100;    //实现了向下取整
    n_rate=max(n_rate,1);
    sort(nums.begin()+1,nums.end(),cmp);
    cout<<nums[n_rate]<<" ";
}
int main(){
    cin>>n_nums_of_input>>rate;
    //n rate->int
    vector< int >nums;
    nums.push_back(0);
    for(int i=1;i<=n_nums_of_input;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
        dytest(nums);
    }
    return 0;
}