//带 配额 的文件系统
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+10;
//目录配额 LD_d  针对 孩子 文件   ->目录的下一层
//后代配额 LR_d  针对 后代 文件   ->目录的所有子文件

//创建普通文件
//C <file path> <file size>

//移除文件
//R <file path>

//设置 目录文件 配额值
//Q <file path> <LD> <LR>

//观察题目，1，2，5，6，7操作是没有配额操作的，即使不实现配额操作也可以拿50'

struct FiLe{
    string name;
    vector <int> sons;  //后代的编号
    int father; //父节点的编号 假设根目录为0
    int is_file; //0代表为目录 1代表为文件
    ll size_file;  //如果是文件，那么他当前的大小  
    ll size_dic_ld; //如果是目录，孩子文件的总大小
    ll size_dic_lr; //如果是目录，后代文件的总大小
    ll ld_d;    //如果是目录，目录配额
    ll lr_d;    //如果是目录，后代配额
}file[maxn];

map<string,int>mp;  //把文件名字映射成为整形  mp[path]==0 代表不存在，否则代表编号
int tot=0;

inline int my_create(string path,int in_size){
    //3.当路径中的任何目录都不存在时，尝试创建这些目录
    //4.如果该指令会使配额系统不满足，则不能执行  ->目前未实现
    if(path=="/"){
        //处理一个特殊情况
        // cout<<"N"<<endl;
        return 0;
    }

    if(mp[path]){
        int id = mp[path];
        if(file[id].is_file){
            //1.若路径所指的文件已经存在，且也是普通文件的，则替换这个文件
            file[id].size_file = in_size;
            // cout<<"Y"<<endl;
            return 1;

            //这里之后要补充一个向上回溯的过程

        }else{
            //2.若路径所指文件已经存在，但是目录文件的，则该指令不能执行成功
            // cout<<"N"<<endl;
            return 0;
        }
    }

    int fa=0;
    for(int i=1;i<path.size();i++){
        if(path[i]=='/'){
            //此时进入分割线了
            string temp = path.substr(0,i); //找到了一个目录的名字
            if(mp[temp]==0){
                //如果这个目录原本不存在
                tot++;
                mp[temp] = tot;
                file[fa].sons.push_back(tot);
                file[tot].father=fa;
                file[tot].name = temp; 

                fa = tot;

            }else{
                //如果此时已经存在该文件或者目录
                int cur = mp[temp];
                if(file[cur].is_file){
                    //4.2若要创建目录与已有的同一双亲目录下的孩子文件中的普通文件名称重复，则不能执行
                    // cout<<'N'<<endl;
                    return 0;
                }
                fa = mp[temp];
            }
        }
    }
    //处理完毕 现在要处理最后一个文件了
    tot++;
    mp[path] = tot;
    file[fa].sons.push_back(tot);
    file[tot].father=fa;
    file[tot].is_file=1;
    file[tot].name=path;
    file[tot].size_file=in_size;

    // cout<<'Y'<<endl;
    return 1;
}

inline void my_delete(string path){
    //3.在上述过程中被移除的目录（如果有）上设置的配额值也被移除
    //4.该指令始终认为能执行成功

    //1.若该路径所指的文件不存在，则不进行任何操作
    if(mp[path]==0) return;

    //2.若该路径所指的文件是目录，则移除该目录及其所有后代文件
    
}

inline void my_q(string path,int ld,int lr){
    //1.若路径所指的文件不存在，或者不是目录文件，则该指令执行不成功
    //2.若在该目录上已经设置了配额，则将原配额值替换为指定的配额值
    //3.特别地，若配额值为0，则表示不对该项配额进行限制
    //4.若在应用新的配额值后，该文件系统配额变为不满足，那么该指令执行不成功
}

int count_of_commands;
int main(){
    file[0].name="/";
    cin>>count_of_commands;
    char comm;
    string path; 
    int in_size;
    int ld,lr;
    while(count_of_commands--){
        cin>>comm;
        if(comm=='C'){
            cin>>path>>in_size;
            if(my_create(path,in_size)) cout<<'Y'<<endl;
            else cout<<'N'<<endl;
        }else if(comm=='R'){
            cin>>path;
            my_delete(path);
            cout<<'Y'<<endl;
        }else if(comm=='Q'){
            cin>>path>>ld>>lr;
            my_q(path,ld,lr);
        }
    }
}
