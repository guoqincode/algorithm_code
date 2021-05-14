//t2 大模拟
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+3,maxm=1e5+3;
int n,m,k,b;

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
    string s;                    //该文件目前存储的字符串
    vector<int>index_of_blocks;  //该文件目前使用的 块 的下标集合
}fILE[maxn];

int is_used[maxm];  //记录该块是否被使用

inline void op_a(int x,int off,string st){
    if(off>=fILE[x].s.size()){
        //如果off超过尾部 则直接从尾部写入新的数据
        
        if(fILE[x].index_of_blocks.empty()||fILE[x].s.size()%b==0){
            //如果一开始就是空的 或者一开始不为空且没有那种站一半的情况
            int need_blocks=st.size()/b;
            if(st.size()%b) need_blocks++;
            int cur_have=0;
            int flag=0;
            for(int i=1;i<=m;i++){
                if(is_used[i]==0){
                    is_used[i]=1;
                    fILE[x].index_of_blocks.push_back(i);
                    cur_have++;
                    if(cur_have==need_blocks){
                        break;
                        flag=1; //flag=1代表已经找完了
                    }
                }
            }
            if(flag==1){
                //可以全部放进去的情况
                fILE[x].s+=st;
            }else{
                //只能放进去一部分的情况
                //只有 cur_have 个剩余的块可以用
                int len=cur_have*b; //可以连进去的长度
                string temp=st.substr(0,len);
                fILE[x].s+=temp;
            }
        }
        
        else{
            //一开始不为空并且存在那种 "占一半" 的情况
            int lst_have=b-fILE[x].s.size()%b;  //最后一块还有剩下多少空间
            if(lst_have>=st.size()) fILE[x].s+=st;
            else{
                // fILE[x].s+=st.substr(0,lst_have);   //先把该块剩下的空间都给填满
                int need_blocks=(st.size()-lst_have)/b;
                if((st.size()-lst_have)%b) need_blocks++;
                
                int cur_have=0;
                int flag=0;
                for(int i=1;i<=m;i++){
                    if(is_used[i]==0){
                        is_used[i]=1;
                        fILE[x].index_of_blocks.push_back(i);
                        cur_have++;
                        if(cur_have==need_blocks){
                            break;
                            flag=1; //flag=1代表已经找完了
                        }
                    }
                }

                if(flag==1){
                    fILE[x].s+=st;
                }else{
                    int len=cur_have*b; //可以连进去的长度
                    string temp=st.substr(0,len+lst_have);
                    fILE[x].s+=temp;
                }
            }
        }

        return;
    }
    
    else{
        //off没有超过尾部 那么就开始覆盖
        string temp=fILE[x].s.substr(0,off)+st;    //这是新的字符串
        if(temp.size()==fILE[x].s.size()){
            //单纯的  等 量  替换后面几个字母的情况
            fILE[x].s=temp;
            return;
        }else if(temp.size()<fILE[x].s.size()){
            //没有覆盖完全 相当于单纯的替换了中间的某些
            for(int i=0;i<st.size();i++){
                fILE[x].s[i+off]=st[i];
            }
        }else if(temp.size()>fILE[x].s.size()){
            //覆盖完全了并且有超过的情况出现
            int temp_size=temp.size()/b;
            if(temp.size()%b) temp_size++;  //新的字符串需要的块的数量
            if(temp_size==fILE[x].index_of_blocks.size()){
                //如果不需要多出新的块
                fILE[x].s=temp;
            }else{
                int need_blocks=temp_size-fILE[x].index_of_blocks.size();
                
                int cur_have=0;
                int flag=0;
                for(int i=1;i<=m;i++){
                    if(is_used[i]==0){
                        is_used[i]=1;
                        fILE[x].index_of_blocks.push_back(i);
                        cur_have++;
                        if(cur_have==need_blocks){
                            break;
                            flag=1; //flag=1代表已经找完了
                        }
                    }
                }

                if(flag==1){
                    fILE[x].s=temp;
                    return;
                }else{
                    int len=(cur_have+fILE[x].index_of_blocks.size())*b; //可以连进去的长度
                    // string temp=st.substr(0,len+lst_have);
                    fILE[x].s=temp.substr(0,len);
                    return;
                }
            }

        }
    }
}

inline void op_b(int x){
    cout<<fILE[x].index_of_blocks.size()<<" ";
    for(int i=0;i<fILE[x].index_of_blocks.size();i++) cout<<fILE[x].index_of_blocks[i]<<" ";
    cout<<endl;
}

inline void op_c(int x,int off,int y){
    if(off>=fILE[x].s.size()){
        cout<<"-2"<<endl;
        return;
    }
    if(off+y-1>=fILE[x].s.size()){
        cout<<"-1"<<endl;
        return;
    }
    for(int i=off;i<=off+y-1;i++){
        cout<<fILE[x].s[i];
    }
    cout<<endl;
}

inline void op_d(int x,int off,int y){
    //D x off y   1.以off为起点删除y字节数据，off超过尾部，则无效，否则直到删除y字节或者已经没有字节剩余
    //删除后的空间清理是个难点 1.找出所有被删除的已占用块->未占用，文件容量也随之减小  
    //                     2. ！！！ 块中的文件前移  个人感觉是最难实现的一部分，最重要的是找到合适的数据结构or高效算法
    //                     3. 再次把没有用的文件块设置为未使用
    if(off>=fILE[x].s.size()) return;   //off 超过尾部,无效
    if(off+y-1>=fILE[x].s.size()){
        //删除的y字节超过尾部
        string temp=fILE[x].s.substr(0,off);
        fILE[x].s=temp;
        int need_blocks=off/b;
        if(off%b) need_blocks++;
        while(fILE[x].index_of_blocks.size()>need_blocks){
            int temp=fILE[x].index_of_blocks[fILE[x].index_of_blocks.size()-1];
            fILE[x].index_of_blocks.pop_back();
            is_used[temp]=0;
        }
        return;
    }

    //空间清理
    //删除的是中间的那一部分，所以我们可以先把中间那一部分删除，然后求出还能留下多少块，留下前面的那些块
    string temp=fILE[x].s.substr(0,off);
    //跳过off+y个
    temp+=fILE[x].s.substr(off+y);
    fILE[x].s=temp;
    int need_blocks=temp.size()/b;
    if(temp.size()%b) need_blocks++;
    while(fILE[x].index_of_blocks.size()>need_blocks){
            int temp=fILE[x].index_of_blocks[fILE[x].index_of_blocks.size()-1];
            fILE[x].index_of_blocks.pop_back();
            is_used[temp]=0;
    }
    return;
}

int main(){
    cin>>n>>m>>k>>b;
    char op;
    
    while(k--){
        cin>>op;
        int x,off,y;
        string st;
        if(op=='A'){
            cin>>x>>off>>st;
            op_a(x,off,st);
        }else if(op=='B'){
            cin>>x;
            op_b(x);
        }else if(op=='C'){
            cin>>x>>off>>y;
            op_c(x,off,y);
        }else if(op=='D'){
            cin>>x>>off>>y;
            op_d(x,off,y);
        }
    }

    return 0;
}
