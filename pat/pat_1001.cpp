//pat1001
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,sum;
	scanf("%d %d",&a,&b);
	sum=a+b;
	if(abs(sum)<1000) printf("%d",sum);
	else if(abs(sum)<1000000) printf("%d,%03d",sum/1000,abs(sum%1000));
	else printf("%d,%03d,%03d",sum/1000000,abs(sum%1000000/1000),abs(sum%1000));
	return 0;
}
