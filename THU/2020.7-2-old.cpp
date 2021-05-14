//写麻了  我为什么非要真实的把这些数据存储在每个block里边呢？
//尝试失败第一次

//接下来的两个月重点练习大模拟  clang不能用万能头文件好难受

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;
int n,m,k,b;
const int maxn=1e3+5,maxm=1e5+5,maxb=101,max_st=1e6+3;
//A x off st  1.如果off超过文件尾部则直接从文件尾部开始写入数据 2.如果off及其后面有数据则覆盖 
//            3.如果写入过程中容量不足，则从小到大分配未占用的块，并将这些块标记为已占用，如果未占用块不足，操作终止

//D x off y   1.以off为起点删除y字节数据，off超过尾部，则无效，否则直到删除y字节或者已经没有字节剩余
//删除后的空间清理是个难点 1.找出所有被删除的已占用块->未占用，文件容量也随之减小  
//                     2. ！！！ 块中的文件前移  个人感觉是最难实现的一部分，最重要的是找到合适的数据结构or高效算法
//                     3. 再次把没有用的文件块设置为未使用

//B x         查询第x号文件拥有的块数 先返回块数，再依次输出已占用的块的编号

//C x off y   以第x号文件的off位置为起点查询y字节数据 1.如果off超过文件尾部则返回-2 2.如果不足y字节则返回-1

//观察测试电可以发现 1.2 6.7分别只有ab操作和ac操作，所以即使只实现了最简单的abc，仍然可以拿到40‘

struct FiLe{
    //fIlE[x] -> 第x号文件
    int nums_of_blocks;             //拥有的块数
    vector <int> index_of_blocks;   //拥有的块数分别是多少编号
    int index_of_end;            //最后一个字节的位置 没有数据时候默认是-1
}fIlE[maxn];

struct BloCk{
    int is_used;    //0 未使用      1 已使用
    char block_str[maxb];   //可能有点浪费空间。。  mark一下，这种数据结构不是最好的  应该可以用链式的。。等用这种的数据结构解决掉这个问题再换成链式的
}bLoCk[maxm];

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch-'0'); ch=getchar();}
    return x*f;
}

inline void op_a(int x,int off,char In[]){
    //1.如果off超过文件尾部则直接从文件尾部开始写入数据 2.如果off及其后面有数据则覆盖 
    //3.如果写入过程中容量不足，则从小到大分配未占用的块，并将这些块标记为已占用，如果未占用块不足，操作终止
    int flag=1;     //flag=1 第一次写入   flag=0 超过了文件尾要从尾部开始写入    flag=2 覆盖的情况
    if(fIlE[x].index_of_end==-1) off=0; //第一次写入
    else if(off>=fIlE[x].index_of_end+1){
        off=fIlE[x].index_of_end+1; //这里实现了1和2 从尾部写入或者从off处开始覆盖
        flag=0;
    }else flag=2;


    int In_len=strlen(In);  //要输入的字符串的长度
    int st_in=0;
    int new_end=off+In_len-1;   //新的结束点 （如果能到达的话）
    
    
    //flag=1时 即第一次写入时  ->未完成
    if(flag==1){
        int need_blocks=In_len/b;
        if(In_len%b) need_blocks++;
        //need_blocks 为需要的块数
        int point_blocks=1;
        int i;
        int mm=need_blocks;
        while(mm){
            if(point_blocks==n+1) break;    //即使查询完最后一块的时候仍然没有填满 那么就跳出
            if(bLoCk[point_blocks].is_used==0){
                //找到了一块没有使用的
                fIlE[x].index_of_blocks.push_back(point_blocks);
                fIlE[x].nums_of_blocks++;
                bLoCk[point_blocks].is_used=1;
                for(i=0;i<b&&st_in<In_len;i++){
                    bLoCk[point_blocks].block_str[i]=In[st_in];
                    st_in++;
                }
                bLoCk[point_blocks].block_str[i]='\0';  //字符串的结束  这里不能一直用b位置写0 因为最后一次的时候可能不是完整的字符串
                mm--;
            }
            point_blocks++;
        }

        if(mm==0) fIlE[x].index_of_end=new_end;
        else fIlE[x].index_of_end=off+st_in-1;
    }

    //从尾部开始写 还未写一般情况
    else if(flag==0){
        //从最后开始写
        if(fIlE[x].index_of_blocks.empty()){
            int need_blocks=In_len/b;
            if(In_len%b) need_blocks++;
            //need_blocks 为需要的块数
            int point_blocks=1;
            int i;
            int mm=need_blocks;
            while(mm){
                if(point_blocks==n+1) break;    //即使查询完最后一块的时候仍然没有填满 那么就跳出
                if(bLoCk[point_blocks].is_used==0){
                    //找到了一块没有使用的
                    fIlE[x].index_of_blocks.push_back(point_blocks);
                    fIlE[x].nums_of_blocks++;
                    bLoCk[point_blocks].is_used=1;
                    for(i=0;i<b&&st_in<In_len;i++){
                        bLoCk[point_blocks].block_str[i]=In[st_in];
                        st_in++;
                    }
                    bLoCk[point_blocks].block_str[i]='\0';  //字符串的结束  这里不能一直用b位置写0 因为最后一次的时候可能不是完整的字符串
                    mm--;
                }
                point_blocks++;
            }

            if(mm==0) fIlE[x].index_of_end=new_end;
            else fIlE[x].index_of_end=off+st_in-1;
        }

        else{
            //首先定位到最后一个块
            int lst_block=fIlE[x].index_of_blocks[fIlE[x].index_of_blocks.size()-1];
            int lst_len=strlen(bLoCk[lst_block].block_str);
            //就从lst_len开始写
            int st_point=(fIlE[x].index_of_end+1)%b;
            //从最后一个块向后补还是 最后一个块已经满了要从新块开始取决于st_point是不是0
            int st_block;
            if(st_point==0) int st_block=lst_block+1;
            else st_block=lst_block;
            //要从st_block 开始写入 In_len 个字符

            if(st_point==0){
                
            }else{

            }

        }
    }


    //覆盖的情况 -> 还未写一般情况
    else if(flag==2){
        if(fIlE[x].index_of_blocks.empty()){
            int need_blocks=In_len/b;
            if(In_len%b) need_blocks++;
            //need_blocks 为需要的块数
            int point_blocks=1;
            int i;
            int mm=need_blocks;
            while(mm){
                if(point_blocks==n+1) break;    //即使查询完最后一块的时候仍然没有填满 那么就跳出
                if(bLoCk[point_blocks].is_used==0){
                    //找到了一块没有使用的
                    fIlE[x].index_of_blocks.push_back(point_blocks);
                    fIlE[x].nums_of_blocks++;
                    bLoCk[point_blocks].is_used=1;
                    for(i=0;i<b&&st_in<In_len;i++){
                        bLoCk[point_blocks].block_str[i]=In[st_in];
                        st_in++;
                    }
                    bLoCk[point_blocks].block_str[i]='\0';  //字符串的结束  这里不能一直用b位置写0 因为最后一次的时候可能不是完整的字符串
                    mm--;
                }
                point_blocks++;
            }

            if(mm==0) fIlE[x].index_of_end=new_end;
            else fIlE[x].index_of_end=off+st_in-1;
        }

        else{


        }
    }

}

inline void op_b(int x){
    //查询第x号文件拥有的块数 先返回块数，再依次输出已占用的块的编号
    printf("%d ",fIlE[x].nums_of_blocks);
    for(int i=0;i<fIlE[x].index_of_blocks.size();i++) printf("%d ",fIlE[x].index_of_blocks[i]);
    printf("\n");
}

inline void op_c(int x,int off,int y){
    //第x号文件的off位置为起点查询y字节数据 1.如果off超过文件尾部则返回-2 2.如果不足y字节则返回-1
    if(off>fIlE[x].index_of_end){
        printf("-2\n");
        return;
    }
    int end_c=off+y-1;  //查询的最后一个字节的编号
    if(end_c>fIlE[x].index_of_end){
        //不足y字节
        printf("-1\n");
        return;
    }

    //两种特殊情况都跳过了 , 开始查找从off开始的y个字节
    while(off<=end_c){
        int cur_block=off/b;    //当前是第几块
        int cur_off=off%b;      //在当前查找的块中是第几个数据
        printf("%c",bLoCk[fIlE[x].index_of_blocks[cur_block]].block_str[cur_off]);
        off++;
    }
    printf("\n");

}

inline void op_d(int x,int off,int y){

}

int main(){
    n=read(); m=read(); k=read(); b=read();
    for(int i=1;i<=n;i++) fIlE[i].index_of_end=-1;
    char op;
    while(k--){
        cin>>op;
        if(op=='A'){
            int x=read(),f=read();
            char ss[max_st];
            cin>>ss;
            op_a(x,f,ss);
        }else if(op=='B'){
            int x=read();
            op_b(x);
        }else if(op=='C'){
            int x=read(),f=read(),y=read();
            op_c(x,f,y);
        }else if(op=='D'){
            int x=read(),f=read(),y=read();
            op_d(x,f,y);
        }
    }

    return 0;

}