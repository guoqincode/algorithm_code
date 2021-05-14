#include<bits/stdc++.h>
using namespace std;
//用优先级队列去模拟大顶堆小顶堆
int main(){
    priority_queue<int,vector<int>,greater<int> >q; //小顶堆
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }
    for(int i=0;i<n-1;i++){
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        sum+=(a+b);
        q.push(a+b);
    }
    cout<<sum;
    return 0;
}