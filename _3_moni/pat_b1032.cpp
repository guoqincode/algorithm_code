#include<bits/stdc++.h>
using namespace std;
int school[100010]={0};
int main(){
    int n,school_id,score,max=0,max_id=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>school_id>>score;
        school[school_id]+=score;
        if(school[school_id]>max){
            max=school[school_id];
            max_id=school_id;
        }
    }
    cout<<max_id<<" "<<max;
    return 0;
}