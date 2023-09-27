/* Viết chương trình nhập vào một xâu ký tự, in ra màn hình xâu đảo ngược của xâu vừa nhập. 
Ví dụ: Nhập vào “Hello world!” thì in ra màn hình “!dlrow olleH” */

#include<stdio.h>
#include<string.h> //Để dùng hàm strlen()
int main()
{
    char xkt[255];
    int i;
    printf("Nhap vao mot xau ky tu: ");
    gets(xkt);
    printf("Xau vua nhap: %s\n",xkt);
    printf("Sau khi dao nguoc: ");
        for(i=strlen(xkt)-1;i>=0;i=i-1)
        printf("%c",xkt[i]);
    return 0;
}