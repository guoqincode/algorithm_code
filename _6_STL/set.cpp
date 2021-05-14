#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int>st;
    st.insert(2);
    st.insert(1);
    st.insert(7);
    st.insert(0);
    for(set<int>::iterator it=st.begin();it!=st.end();it++){
        cout<<*it<<" ";
    }

    auto it=st.find(7);
    cout<<endl<<*it;
    st.erase(it);
    cout<<endl;
    for(set<int>::iterator it=st.begin();it!=st.end();it++){
        cout<<*it<<" ";
    }
    st.erase(0);
    cout<<endl;
    for(set<int>::iterator it=st.begin();it!=st.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}