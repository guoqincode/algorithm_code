#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<float>>input(3,vector<float>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%f",&input[i][j]);
        }
    }
    vector<char>select(3,'W');
    vector<float>res(3);
    res[0]=input[0][0]; res[1]=input[1][0]; res[2]==input[2][0];
    for(int i=0;i<3;i++){
        float maxi=input[i][0];
        if(input[i][1]>maxi){
            maxi=input[i][1];
            select[i]='T';
        }
        if(input[i][2]>maxi){
            maxi=input[i][2];
            select[i]='L';
        }
        res[i]=maxi;
    }
    float result=(res[0]*res[1]*res[2]*0.65-1)*2;
    printf("%c %c %c %.2f",select[0],select[1],select[2],result);
    return 0;
}
