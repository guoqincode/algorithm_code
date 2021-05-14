#include<bits/stdc++.h>
using namespace std;
struct fruit{
    string name;
    int price;

    //对小于号的重载
    friend bool operator <(fruit f1,fruit f2){
        return f1.price>f2.price;
    }

}f1,f2,f3;
int main(){
    priority_queue<int>q;  
    //-> priority_queue<int,vector<int>,less<int>>q;  大的优先级高
    // priority_queue<int,vector<int>,greater<int>>q  小的优先级高
    q.push(1);
    q.push(6);
    q.push(3);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    //push() top() pop()
    //empty()  size()

    priority_queue< int,vector<int>,greater<int> >_q;
    _q.push(1);
    _q.push(6);
    _q.push(3);
    cout<<_q.top()<<endl;
    _q.pop();
    cout<<_q.top()<<endl;

    priority_queue<fruit>__q;
    f1.name="taozi";
    f1.price=3;
    f2.name="lizi";
    f2.price=4;
    f3.name="pingguo";
    f3.price=1;
    __q.push(f1);
    __q.push(f2);
    __q.push(f3);
    cout<<__q.top().name<<"  "<<__q.top().price<<endl;


    return 0;
}