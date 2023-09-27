/* Viết chương trình C, nhập vào 1 số nguyên N (0 < N < 2x10^9). 
In ra màn hình dãy nhị phân tương ứng N */

/* Bước 1: Chia số đó cho 2 với toán tử % và lưu phần dư vào trong mảng
Bước 2: Chia số cho 2 với toán tử /
Bước 3: Lặp lại bước 2 tới khi số là lớn hơn 0 */

#include<stdio.h>
int main()
{
    unsigned long N;
    int a[32],i;
    printf("Nhap so nguyen N (0 < N < 2x10^9):");
    scanf("%lu",&N);
    if(N<=0 || N>=2e9)
        printf("So N khong hop le.");
    else
    {
        for(i=0;N>0;i++)
        {
            a[i]=N%2;
            N=N/2;
        }
        printf("\nDang nhi phan cua so N vua nhap la:");
        for(i=i-1;i>=0;i--)
        {
            printf("%lu",a[i]);
        }
    }
    return 0;
}