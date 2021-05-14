#include<bits/stdc++.h>
using namespace std;
const int maxn=1024;
struct node{
    int data;
    int lchild;
    int rchild;
}Node[maxn];

int _bst_indx=0;

int newNode(int x){
    Node[_bst_indx].data=x;
    Node[_bst_indx].lchild=-1;
    Node[_bst_indx].rchild=-1;
    return _bst_indx++;
}
void insert(int &root,int x){
    if(root==-1){
        root=newNode(x);
        return;
    }
    if(x<Node[root].data){
        insert(Node[root].lchild,x);
    }else{
        insert(Node[root].rchild,x);
    }
}

int n;  //等待输入的n


int create(vector<int>& data){
    int root=-1;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

vector<int>pre;
vector<int>mirrorpre;
vector<int>post;
void preorder(int root){
    if(root==-1) return;
    pre.push_back(Node[root].data);
    preorder(Node[root].lchild);
    preorder(Node[root].rchild);
}
void mirrorpreorder(int root){
    if(root==-1) return;
    mirrorpre.push_back(Node[root].data);
    //镜像相当于先访问右边再访问左边
    mirrorpreorder(Node[root].rchild);
    mirrorpreorder(Node[root].lchild);
}
void postorder(int root){
    if(root==-1) return;
    postorder(Node[root].lchild);
    postorder(Node[root].rchild);
    post.push_back(Node[root].data);
}
void mirrorpostorder(int root){
    if(root==-1) return;
    mirrorpostorder(Node[root].rchild);
    mirrorpostorder(Node[root].lchild);
    post.push_back(Node[root].data);
}
void pr_post(){
    for(int i=0;i<post.size();i++){
        cout<<post[i];
        if(i<post.size()-1) cout<<" ";
    }
}
void inorder(int root){
    if(root==-1) return;    //递推边界
    inorder(Node[root].lchild);
    cout<<Node[root].data<<" ";
    inorder(Node[root].rchild);
}
int main(){
    cin>>n;
    vector<int>data;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        data.push_back(temp);
    }
    int root=create(data);
    //inorder(root);
    preorder(root);
    //for(int i=0;i<n;i++) cout<<pre[i]<<" ";
    mirrorpreorder(root);
    //for(int i=0;i<n;i++) cout<<mirrorpre[i]<<" ";
    if(data==pre){
        cout<<"YES"<<endl;
        postorder(root);
        pr_post();
    }else if(data==mirrorpre){
        cout<<"YES"<<endl;
        mirrorpostorder(root);
        pr_post();
    }else{
        cout<<"NO";
    }
}
