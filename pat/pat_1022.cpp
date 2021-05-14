//pat1022
#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int id;
    vector<string>bookname;
    vector<string>author;
    vector<string>keyword;
    vector<string>publisher;
    int year;
}book;
bool cmp(book one,book two){
	return one.id<two.id;
}
int main(){
    int m;
    scanf("%d",&m);
    vector<book>lib;
    for(int i=0;i<m;i++){
        book temp;
        scanf("%d",&temp.id);
        fflush(stdin);
        string te;
        scanf("%s",&te);
        printf("%d ",temp.id);
        for(int i=0;te[i]!='\0';i++) printf("%c",te[i]);
    }
    return 0;
}
