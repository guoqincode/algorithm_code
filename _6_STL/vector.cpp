#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>vi;
    for(int i=1;i<=5;i++){
        vi.push_back(i);
    }
    for(int i=0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }
    vi.pop_back();
    for(vector<int>::iterator it=vi.begin();it!=vi.end();it++){
        cout<<*it<<" ";
    }

    vi.clear();
    cout<<vi.size()<<" ";
    for(int i=1;i<=5;i++){
        vi.push_back(i);
    }
    vi.insert(vi.begin()+2,-1);
    for(vector<int>::iterator it=vi.begin();it!=vi.end();it++){
        cout<<*it<<" ";
    }
    vi.erase(vi.begin());
    vi.insert(vi.begin()+2,-1);
    for(vector<int>::iterator it=vi.begin();it!=vi.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}