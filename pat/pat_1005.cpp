#include<bits/stdc++.h>
using namespace std;
int main(){
    int sum=0;
    while(1){
    	char ch;
    	scanf("%c",&ch);
    	if(ch=='\n'||ch=='\0') break;
    	sum+=ch-'0';
	}
	//printf("\n%d\n",sum);
    if(sum){
    	vector<int>res;
    	while(sum){
       		res.push_back(sum%10);
    			sum=sum/10;
    	}
    	int count=res.size();
    	while(count--){
        	switch(res[count]){
           		case 0:printf("zero");	break;
            	case 1:printf("one");	break;
            	case 2:printf("two");	break;
            	case 3:printf("three");	break;
            	case 4:printf("four");	break;
            	case 5:printf("five");	break;
            	case 6:printf("six");	break;
            	case 7:printf("seven");	break;
            	case 8:printf("eight");	break;
            	case 9:printf("nine");	break;
        	}
        	if(count) printf(" ");
    	}
	}else{
		printf("zero");
	}
    return 0;
}
