#include <stdio.h>
#include <string.h>
void ValidIp(char arr[1000]) {
    int len=strlen(arr), count=0;
   arr[len]='.'; arr[len+1]='\0';
    int i=0, q=0; char ans[1000];
    for(int x=0; x<4; x++)
    {
        while((arr[q]!='.' && arr[q]!=' ') && (arr[q]!='\t' && arr[q]!='\0') && arr[q]!='\n')
        {
            
            ans[q-i]=arr[q]; q++;
        }
        if((q-i)>3 || (q-i)==0) { printf("Not Valid\n"); return; }
        if((q-i)==3)
        {
            int z = (ans[0]-'0')*100 +(ans[1]-'0')*10 +(ans[2]-'0');
            if(z>255)
            {
                printf("Not Valid\n"); return;
            }
            if((z-100)<0) { printf("Not Valid\n"); return; }
            else count +=z;
        }
        if((q-i)==2)
        {
            int z= (ans[0]-'0')*10 +(ans[1]-'0');
            if((z-10)<0) { printf("Not Valid\n"); return; }
            count +=z;
        }
        if((q-i)==1)
        {
            int z= (ans[0]-'0');
            count +=z;
        }
        q=q+1; i=q;
    }
            while((arr[q]!='.' && arr[q]!=' ') && (arr[q]!='\t' && arr[q]!='\0') && arr[q]!='\n')
        {
            
            printf("Not Valid\n"); return;
        }
    printf("%d\n",count); return;
}
int main(){
    int t;
    scanf("%d", &t);
    char s[101];
    while(t--){
        scanf("%s", s);
        ValidIp(s); // print the desired ouput for string s
    }
    return 0;
}
