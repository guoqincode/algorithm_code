//p1896 状压dp  互不侵犯
#include <bits/stdc++.h>
using namespace std;
// const int maxn=9;
// int dp[maxn+1][(1<<maxn)+10]; //？怎么设很重要
int n, kk;
// int dp[maxn+1][(1<<maxn)+10][maxn*maxn+2];
long long dp[10][2010][100];
//dp[i][j][k] 第i行 该行摆放国王的情况(从又往左) 此时一共放了多少国王
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

int si[2000], gs[2000], cnt = 0; // 2^9=512  cnt记录这是第几个状态

void dfs(int he, int sum, int node)
{
    //枚举 单独一行的所有放置状态
    if (node >= n)
    {
        //如果已经处理完毕
        si[++cnt] = he; //记录1010..
        gs[cnt] = sum;  //记录此时一共有多少1
        return;         //新建一个状态
    }
    dfs(he, sum, node + 1);                   //不用第node个
    dfs(he + (1 << node), sum + 1, node + 2); //用第node个 此时node要+2 跳过下一个格子
}

int main()
{
    n = read();
    kk = read();
    dfs(0, 0, 0);
    // cout<<cnt;
    for (int i = 1; i <= cnt; i++)
        dp[1][i][gs[i]] = 1; //第一层的所有状态均是只有一种情况的
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            for (int k = 1; k <= cnt; k++)
            {
                if (si[j] & si[k])
                    continue;
                if ((si[j] << 1) & si[k])
                    continue;
                if (si[j] & (si[k] << 1))
                    continue;
                for (int s = kk; s >= gs[j]; s--)
                    dp[i][j][s] += dp[i - 1][k][s - gs[j]];
            }
        }
    }
    long long ans = 0;
    // for (int i = 1; i <= cnt; i++) cout << dp[n][i][kk] << endl;
    for (int i = 1; i <= cnt; i++)
        ans += dp[n][i][kk];
    printf("%lld", ans);
    return 0;
}