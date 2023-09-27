/* Viết chương trình nhập vào một xâu ký tự, in ra màn hình xâu đảo ngược của xâu vừa nhập. 
Ví dụ: Nhập vào “Hello world!” thì in ra màn hình “!dlrow olleH” */

#include<stdio.h>
#include<string.h> //Để dùng hàm strrev()
int main()
{
    char xkt[255];
    printf("Nhap vao mot xau ky tu: ");
    gets(xkt);
    printf("Xau vua nhap: %s\n",xkt);
    printf("Sau khi dao nguoc: %s",strrev(xkt));
    return 0;
}