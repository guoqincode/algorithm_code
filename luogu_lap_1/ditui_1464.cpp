#include<bits/stdc++.h>
using namespace std;
long long res[25][25][25]= {-1};
long long dfs(long long a,long long b,long long c) {
	if(a<=0||b<=0||c<=0) return 1;
	else if(res[a][b][c]!=-1) return res[a][b][c];
	else if(a>20||b>20||c>20) res[a][b][c]=dfs(20,20,20);
	else if(a<b&&b<c) res[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
	else res[a][b][c]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
	return res[a][b][c];
}
int main() {
	long long a,b,c;
	scanf("%ld %ld %ld",&a,&b,&c);
	while(!(a==-1&&b==-1&&c==-1)) {
		if (a>20) a=21;
		if (b>20) b=21;
		if (b>20) b=21;
		long long temp=dfs(a,b,c);
		//cout<<"w("<<a<<','<<b<<','<<c<<")="<<temp<<endl;
		printf("%ld",temp);
		cin>>a>>b>>c;
	}
}
