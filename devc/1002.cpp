#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
    sscanf(str,"%d",&n);    ->将字符数组str中的内容以%d的格式写到n中
    sprintf(str,"%d",n);    ->将n中的内容以%d的格式写道str字符数组中
    */
   int n;
   char str[100]="123";
   sscanf(str,"%d",n);
   printf("%d\n",n);
   cout<<n<<endl;
   char str2[100];
   sprintf(str2,"%d",n);
   printf("%s\n",str2);

   return 0;
}
