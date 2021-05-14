#include<bits/stdc++.h>
using namespace std;
const int maxn=1024;
struct node{
    int data;
    int lchild;
    int rchild;
}Node[maxn];

int index=0;

int newNode(int x){
    Node[index].data=x;
    Node[index].lchild=-1;
    Node[index].rchild=-1;
    return index++;
}

int create(int preleft,int preright,int inleft,int inright,int pre[],int in[]){
    if(preleft>preright) return -1;
    //preleft位置的一定是根节点
    int temproot=newNode(pre[preleft]);
    int i;
    for(i=inleft;i<=inright;i++){
        if(in[i]==pre[preleft]){
            break;
        }
    }
    int numleft=i-inleft;   //numleft->左子树的节点个数
    //左子树preleft=preleft+1 preright=preleft+numleft inleft=inleft inright=i-1
    Node[temproot].lchild=create(preleft+1,preleft+numleft,inleft,i-1,pre,in);
    Node[temproot].rchild=create(preleft+numleft+1,preright,i+1,inright,pre,in);
    return temproot;
}
void layerorder(int x){
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<Node[temp].data<<" ";
        if(Node[temp].lchild!=-1) q.push(Node[temp].lchild);
        if(Node[temp].rchild!=-1) q.push(Node[temp].rchild);
    }
}
int main(){
    int pre[]={3,9,20,15,7};
    int in[]={9,3,15,20,7};
    int root=create(0,4,0,4,pre,in);
    layerorder(root);
    return 0;
}