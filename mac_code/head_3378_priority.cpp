//使用优先队列模拟小顶堆
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int> >q;
    int op;
    int n;
    cin>>n;
    while(n--){
        cin>>op;
        if(op==1){
            cin>>op;
            q.push(op);
        }else if(op==2){
            cout<<q.top()<<endl;
        }else q.pop();
    }
    return 0;
}