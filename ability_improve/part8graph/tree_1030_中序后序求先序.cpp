//由二叉树的中序和先序遍历序列求先序遍历序列
//后序序列的最后一个一定是根
#include<bits/stdc++.h>
using namespace std;
int len=0;
char inord[9],afterord[9];

inline void preord(int inleft, int inright, int afterleft, int afterright){
    //根节点一定是后序遍历的最后一个
    cout<<afterord[afterright];
    //在中序遍历中以根节点为界 左边是左子树 右边是右子树
    int i;
    for(i=inleft;i<=inright;i++) if(inord[i]==afterord[afterright]) break;
    // if(i>inright) return;   //找不到相同的了
    //左子树一共有i-inleft个数 右子树一共有inright-i个数
    if(i>inleft) preord(inleft,i-1,afterleft,afterright-(inright-i)-1);   //具有用右子树的个数确定左子树的最右边界
    if(i<inright) preord(i+1,inright,afterleft+(i-inleft),afterright-1);
}

int main(){
    scanf("%s %s",inord+1,afterord+1);
    len=strlen(inord+1);
    preord(1,len,1,len);
    return 0;
}