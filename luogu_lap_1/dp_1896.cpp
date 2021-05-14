#include <bits/stdc++.h>
using namespace std;
int sit[2000], gs[2000];
int cnt = 0;
int n, yong;
long long f[10][2000][100] = {0};
void dfs(int he, int sum, int node) //预处理出每一个状态
{
    if (node >= n) //如果已经处理完毕（注意是大于等于）
    {
        sit[++cnt] = he;
        gs[cnt] = sum;
        return; //新建一个状态
    }
    dfs(he, sum, node + 1);                   //不用第node个
    dfs(he + (1 << node), sum + 1, node + 2); //用第node个，此时node要加2，及跳过下一个格子
}
int main()
{
    scanf("%d%d", &n, &yong);
    dfs(0, 0, 0);
    // cout<<cnt;
    for (int i = 1; i <= cnt; i++)
        f[1][i][gs[i]] = 1; //第一层的所有状态均是有1种情况的
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= cnt; j++)
            for (int k = 1; k <= cnt; k++) //枚举i、j、k
            {
                if (sit[j] & sit[k])
                    continue;
                if ((sit[j] << 1) & sit[k])
                    continue;
                if (sit[j] & (sit[k] << 1))
                    continue; //排除不合法国王情况
                for (int s = yong; s >= gs[j]; s--)
                    f[i][j][s] += f[i - 1][k][s - gs[j]]; //枚举s，计算f[i][j][s]
            }
    long long ans = 0;
    // for(int i=1;i<=cnt;i++) cout<<f[n][i][yong]<<endl;
    for (int i = 1; i <= cnt; i++)
        ans += f[n][i][yong]; //统计最终答案，记得用long long
    printf("%lld", ans);
    return 0;
}