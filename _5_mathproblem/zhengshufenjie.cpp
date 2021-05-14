/*算数基本定理*/
#include<bits/stdc++.h>
using namespace std;
struct div{
    int divsor; //素因子
    int count;  //素因子的指数
};
struct div fac[11];
int isprimer(int n){
    if(n<=1) return 0;
    else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return 0;
        }
    }
    return 1;
}
int main(){
    int n,num=0;
    cin>>n;
    if(n==1) cout<<"1=1";
    else{
        cout<<n<<"=";
        //cout<<isprimer(n)<<endl;
        for(int i=2;i*i<=n;i++){
            if(isprimer(i)&&n%i==0){
                fac[num].divsor=i;
                fac[num].count=0;
                while(n%i==0){
                    fac[num].count++;
                    n=n/i;
                }
                num++;
            }
            if(n==1) break; //及时跳出循环
        }
        //for(int i=0;i<=num;i++){
            //cout<<fac[i].divsor<<"  "<<fac[i].count<<endl;
        //}
        if(n!=1){
            fac[num].divsor=n;
            fac[num].count=1;
            //for(int i=0;i<=num;i++){
            //cout<<fac[i].divsor<<"  "<<fac[i].count<<endl;
        //}
            for(int i=0;i<=num;i++){
                if(i>0) cout<<'*';
                cout<<fac[i].divsor;
                if(fac[i].count>1) cout<<'^'<<fac[i].count;
            }
        }else{
            for(int i=0;i<num;i++){
                if(i>0) cout<<'*';
                cout<<fac[i].divsor;
                if(fac[i].count>1) cout<<'^'<<fac[i].count;
            }
        }
        
    }
    
    return 0;
}