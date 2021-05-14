//线段树板子
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int a[maxn+2];
struct tree{
    int left,right; //维护的左右区间
    long long pre;  //节点维护的值
    long long add;  //lazy标记
}t[4*maxn+2];   //通常开4*节点个数的空间
int n,m;

//建树
void build(int p,int left,int right){
    t[p].left=left,t[p].right=right;    //维护的区间为 [left,right]
    if(left==right){
        //这个区间只有一个数
        t[p].pre=a[left];
        return;
    }
    int mid=(left+right)>>1;
    build(2*p,left,mid);    //左孩子2*p维护[left,mid]
    build(2*p+1,mid+1,right);   //右孩子2*p+1 维护[mid+1,right]
    t[p].pre=t[2*p].pre+t[2*p+1].pre;
}

// 懒标记的精髓就是打标记和下传操作
// 由于我们要做的操作是区间加一个数
// 所以我们不妨在区间进行修改时为该区间打上一个标记
// 就不必再修改他的儿子所维护区间
// 等到要使用该节点的儿子节点维护的值时
// 再将懒标记下放即可，可以节省很多时间
// 对于每次区间修改和查询，将懒标记下传，可以节省很多时间
void spread(int p){
    //一层一层的向下传递
    if(t[p].add){   //如果lazy标记不为0，则下传，修改左右儿子维护的值
        t[2*p].pre+=(t[2*p].right-t[2*p].left+1)*t[p].add;
        t[2*p+1].pre+=(t[2*p+1].right-t[2*p+1].left+1)*t[p].add;
        t[2*p].add+=t[p].add;   //左右孩子打上标记
        t[2*p+1].add+=t[p].add; 
        t[p].add=0; //下传之后将该节点的lazy置为0
    }
}

//区间修改
//考虑将一个区间加上一个数
//我们可以从根节点不断向下查找
//当发现我们要修改的区间覆盖了当前节点时
//我们就把这个区间给修改，并打上懒标记
//（由于懒标记存在，我们就不必再修改他的儿子节点），否则下传懒标记，继续向下找
void change(int p,int x,int y,int z){
    if(x<=t[p].left&&y>=t[p].right){
        //如果被覆盖的话，就对其进行修改
        t[p].pre+=(long long)z*(t[p].right-t[p].left+1);
        t[p].add+=z;
        return;
    }

    spread(p);  //如果没有覆盖，就要向下寻找，考虑儿子所维护的区间可能因为懒标记存在而没有修改，所以将懒标记下放
    
    int mid=(t[p].left+t[p].right)>>1;
    if(x<=mid) change(p*2,x,y,z);   //如果修改的区间覆盖了左儿子，就修改左儿子
    if(y>mid) change(p*2+1,x,y,z);
    t[p].pre=t[2*p].pre+t[2*p+1].pre;
}

//区间查询
//考虑询问一个区间的和
//依旧是从根节点向下查找，当发现该节点被覆盖时，就返回维护的值
//否则下传懒标记，查询左右儿子，累加答案
long long query(int p,int x,int y){
    if(x<=t[p].left&&y>=t[p].right) return t[p].pre;   //如果被覆盖，就返回维护的值
    spread(p);  //下传懒标记，并查询左右儿子
    long long ans=0;
    int mid=(t[p].left+t[p].right)>>1;
    if(x<=mid) ans+=query(p*2,x,y);   
    if(y>mid) ans+=query(p*2+1,x,y);
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int q,x,y,k;
        scanf("%d",&q);
        if(q==1){
            scanf("%d%d%d",&x,&y,&k);
            change(1,x,y,k);
        }else if(q==2){
            scanf("%d%d",&x,&y);
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}