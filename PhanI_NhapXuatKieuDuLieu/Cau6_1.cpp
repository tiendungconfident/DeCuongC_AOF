/* Viết chương trình nhập vào một xâu ký tự, đếm xem trong xâu vừa nhập 
có bao nhiêu ký tự là chữ cái in hoa, chữ cái in thường, chữ số */

#include<stdio.h>
#include<string.h>
#include<ctype.h> //Để dùng hàm isupper() islower() isdigit()
int main()
{
    char S[255];
    int i;
    int uppercaseCount=0;
    int lowercaseCount=0;
    int digitCount=0;

    printf("Nhap vao xau ki tu: ");
    gets(S);

    for(i=0;i<strlen(S);i++)
    {
        if(isupper(S[i]))
            uppercaseCount=uppercaseCount+1;
        else if(islower(S[i]))
            lowercaseCount=lowercaseCount+1;
        else if(isdigit(S[i]))
            digitCount=digitCount+1;
    }

    printf("\nTrong xau vua nhap:");
    printf("\nSo chu cai in hoa: %d",uppercaseCount);
    printf("\nSo chu cai in thuong: %d",lowercaseCount);
    printf("\nSo chu so: %d",digitCount);
    return 0;
}