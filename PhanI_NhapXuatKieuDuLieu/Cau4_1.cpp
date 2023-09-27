/* Viết chương trình nhập vào một xâu ký tự S, và 1 ký tự KT. Thay thế tất cả các ký tự
KT (không phân biệt hoa thường) trong xâu S thành dấu cách. In ra màn hình kết quả
xâu sau khi thay thế. Nếu không có ký tự KT trong S thì in ra chữ “Khong co” */

#include<stdio.h>
#include<string.h> //Để dùng hàm strlen()
#include<ctype.h> //Để dùng hàm toupper() hoặc có thể dùng tolower()
int main()
{
    char S[255],KT;
    int i,count=0; 
    printf("Nhap vao xau ky tu S: ");
    gets(S);
    fflush(stdin);
    printf("Nhap vao ky tu KT: ");
    scanf("%c",&KT);

    for(i=0;i<strlen(S);i++)
    if(toupper(S[i])==toupper(KT))
    {
        S[i]=' ';
        count=count+1;
    }

    if(count>0)
    {
        printf("Xau sau khi thay the: %s",S);
    }
    else
    {
        printf("Khong co.");
    }
    return 0;
}