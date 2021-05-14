#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int start,end;
}game;
bool cmp(game one,game two){
    return one.end<two.end;
}
int main(){
    int n;
    cin>>n;
    vector< game >gam(n);
    for(int i=0;i<n;i++){
        cin>>gam[i].start>>gam[i].end;
    }
    sort(gam.begin(),gam.end(),cmp);
    int tempend=0,count=0;
    for(int i=0;i<n;i++){
        if(gam[i].start>=tempend){
            tempend=gam[i].end;
            count++;
        }
    }
    //for(int i=0;i<n;i++) cout<<gam[i].start<<gam[i].end<<endl;
    cout<<count;
    return 0;
}
