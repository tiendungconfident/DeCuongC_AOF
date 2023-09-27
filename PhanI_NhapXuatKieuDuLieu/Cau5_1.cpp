/* Viết chương trình nhập vào một xâu ký tự S, kiểm tra xem xâu vừa nhập có là xâu đối xứng không. 
Xâu đối xứng là xâu khi viết theo thứ tự ngược lại ta vẫn được xâu ban đâu. Ví dụ: “DAD”, “MOM” */
// Bài này có phân biệt chữ hoa và chữ thường nên không dùng tolower() hoặc toupper()

#include<stdio.h>
#include<string.h> //Để dùng hàm strlen()
int main()
{
    char S[255];
    int i,j;
    int isPalindrome=1;
    printf("Nhap vao xau ky tu S: ");
    gets(S);

    for(i=0,j=strlen(S)-1 ; i<j ; i++,j--)
    {
        if(S[i]!=S[j])
        {
            isPalindrome=0;
            break;
        }
    }

    if(isPalindrome)
    {
        printf("Xau vua nhap la xau doi xung.");
    }
    else
    {
        printf("Khong phai xau doi xung.");
    }
    return 0;
}