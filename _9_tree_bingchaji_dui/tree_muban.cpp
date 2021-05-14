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
    Node[index].lchild=-1;  //->初始时左右孩子都为NULL
    Node[index].rchild=-1;
    return index++;
}

void search(int root,int x,int newdata){
    if(root==-1) return;    //空树 递归边界
    if(Node[root].data==x) Node[root].data=x;
    search(Node[root].lchild,x,newdata);    //递归式
    search(Node[root].rchild,x,newdata);
}

void insert(int &root,int x){
    //root 前记得加引用
    if(root==-1){
        root=newNode(x);
        return;
    }
    if(x<=Node[root].data){
        //若插入要满足什么性质
        insert(Node[root].lchild,x);
    }else{
        insert(Node[root].rchild,x);
    }
}

int create(int data[],int n){
    int root=-1;    //line 28
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

void preorder(int root){
    if(root==-1) return;    //递推边界
    cout<<Node[root].data<<" ";
    preorder(Node[root].lchild);
    preorder(Node[root].rchild);
}
void inorder(int root){
    if(root==-1) return;    //递推边界
    inorder(Node[root].lchild);
    cout<<Node[root].data<<" ";
    inorder(Node[root].rchild);
}
void postorder(int root){
    if(root==-1) return;    //递推边界
    postorder(Node[root].lchild);
    postorder(Node[root].rchild);
    cout<<Node[root].data<<" ";
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
    int n=10;
    int data[10]={0,1,2,3,6,7,9,8,5,4};
    create(data,n);
    preorder(0);
    cout<<endl;
    inorder(0);
    cout<<endl;
    postorder(0);
    cout<<endl;
    layerorder(0);
    cout<<endl;
    return 0;
}
