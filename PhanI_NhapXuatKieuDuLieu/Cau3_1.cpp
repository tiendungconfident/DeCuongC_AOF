/* Viết chương trình nhập vào một xâu ký tự S, và 1 ký tự KT. 
In ra màn hình các vị trí xuất hiện ký tự KT trong xâu S không phân biệt hoa thường. 
Nếu không có ký tự KT trong S thì in ra chữ “Khong co”. Ví dụ:
S: “Nguyen Van Teo”; KT=”N” thì in ra: 1 6 10
S: “Nguyen Van Teo”; KT=”K” thì in ra: Khong co */

#include<stdio.h>
#include<string.h> //Để dùng hàm strlen()
#include<ctype.h> //Để dùng hàm toupper() hoặc có thể dùng tolower()
int main() 
{
    char S[255],KT;
    int i, count=0;
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
        printf("Cac vi tri xuat hien ky tu KT trong xau S: ");
        for(i=0;i<strlen(S);i++)
        if(toupper(S[i])==toupper(KT))
        {
            printf("%d\t",i+1);
        }
    }
    else
    {
        printf("Khong co.");
    }
    return 0;
}