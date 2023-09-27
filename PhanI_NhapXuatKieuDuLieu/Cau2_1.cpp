/* Viết chương trình nhập vào một xâu ký tự S, và 1 ký tự KT, 
đếm xem trong xâu S có bao nhiêu ký tự KT không phân biệt hoa thường. 
Nếu không có ký tự KT trong S thì in ra chữ “Khong co”. */

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
        count=count+1;
    }

    if(count>0)
    {
        printf("So lan xuat hien cua ky tu KT khong phan biet hoa thuong trong xau S: %d\n",count);
    }
    else
    {
        printf("Khong co.\n");
    }
    return 0;
}