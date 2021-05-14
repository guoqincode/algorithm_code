#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    for(int i=0;i<11;i++){
        q.push(i);
    }
    cout<<q.front()<<" "<<q.back()<<endl;
    q.pop();
    cout<<q.front()<<" "<<q.back()<<endl;
    //还有 size() empty()
    return 0;
}