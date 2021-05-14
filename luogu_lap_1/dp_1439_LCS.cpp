//最长公共子序列  //编译失败是因为maxn开太大了 但是开小之后只能50'
//洛谷会卡O(n^2)的朴素算法   考虑O(nlogn)的做法-->转化成LIS问题
//考虑到全排列的性质 可以把问题转化为最长上升子序列
//关于为什么可以转化成LCS问题，这里提供一个解释。
// A:3 2 1 4 5
// B:1 2 3 4 5
// 我们不妨给它们重新标个号：把3标成a,把2标成b，把1标成c……于是变成：
// A: a b c d e
// B: c b a d e
// 这样标号之后，LCS长度显然不会改变。但是出现了一个性质：
// 两个序列的子序列，一定是A的子序列。而A本身就是单调递增的。
// 因此这个子序列是单调递增的。
// 换句话说，只要这个子序列在B中单调递增，它就是A的子序列。
// 哪个最长呢？当然是B的LCS最长。
// 自此完成转化。

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
const int inf=0x3f3f3f3f;
int a[maxn],b[maxn],m[maxn],f[maxn];
int n;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int main(){
    n=read();
    for(int i=1;i<=n;i++) {a[i]=read(); m[a[i]]=i;}
    for(int i=1;i<=n;i++){b[i]=read(); f[i]=inf;}
    int len=0;
    f[0]=0;
    for(int i=1;i<=n;i++){
        int left=0,right=len,mid;
        if(m[b[i]]>f[len]) f[++len]=m[b[i]];
        else{
            while(left<right){
                mid=(left+right)>>1;
                if(f[mid]>m[b[i]]) right=mid;
                else left=mid+1;
            }
            f[left]=min(m[b[i]],f[left]);
        }
    }
    printf("%d",len);
    return 0;
}