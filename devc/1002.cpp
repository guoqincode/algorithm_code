#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
    sscanf(str,"%d",&n);    ->���ַ�����str�е�������%d�ĸ�ʽд��n��
    sprintf(str,"%d",n);    ->��n�е�������%d�ĸ�ʽд��str�ַ�������
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
