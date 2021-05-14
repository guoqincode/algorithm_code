#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100001,N = 17;
int n, m, tot_money, ans = 2147483647;
int dp[1 << N], f[1 << N], sum[MAXN], pay[MAXN], coin[MAXN];

inline int read() {
    int f = 1, x = 0; char ch = getchar();
    for(; ! isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    return x * f;
}
inline int check(int x, int cha) {
	int l = cha, r = n, mid;
	while(l <= r) {
	  mid = (l + r) >> 1;
	  if(sum[mid] - sum[cha - 1] == x) return mid;
	  if(sum[mid] - sum[cha - 1] < x) l = mid + 1;
	  else r = mid - 1;
	}
	return r;
}

int main() {
	m = read(), n = read();
	for(int i = 1; i <= m; i ++) coin[i] = read(), tot_money += coin[i];
	for(int i = 1; i <= n; i ++) pay[i] = read(), sum[i] = sum[i - 1] + pay[i];
	for(int i = 1; i < (1 << m); i ++) {
	  for(int j = 0; j < m; j ++) if(i & (1 << j)) {
	    int x = (i ^ (1 << j)), sum;
      if((sum = check(coin[j + 1], dp[x] + 1)) > dp[i]) 
        dp[i] = sum, f[i] = f[x] + coin[j + 1];
		  if(dp[i] == n) ans = min(f[i], ans);
	  } 
	}
	printf("%d", (tot_money - ans) < 0 ? -1 : tot_money - ans);
	return 0;
} 