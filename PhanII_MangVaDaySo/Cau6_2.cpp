/* Viết chương trình C, nhập vào 1 dãy gồm N số nguyên (N nhập từ bàn phím, 0 < N < 2x10^9). 
Tìm và in ra vị trí các số nguyên trong dãy là số nguyên tố */
// Cơ bản cũng không khác gì câu 3, khác dòng 28
#include<stdio.h>
#include<math.h>
#define MAX 200000
int isPrime(long x);
int main()
{
    long n,i,a[MAX];
    printf("Nhap so so nguyen N (0 < N < 2x10^9): ");
	scanf("%ld",&n);
    if(n<=0 || n>=2e9)
        printf("Vui long nhap lai.");
    else
    {
        printf("Nhap tung phan tu:\n");
        for(i=1;i<=n;i++)
        {
            printf("a[%ld]=",i);
            scanf("%ld",&a[i]);
        }

        printf("Vi tri cac so nguyen trong day la so nguyen to:");
        for(i=1;i<=n;i++)
        if(isPrime(a[i]))
        {
            printf("%ld\t",i);
        }
    }
    return 0;
}
int isPrime(long x)
{
    long i;
    if(x<2)
        return 0;
    else
    {
        for(i=2;i<=sqrt(x);i++)
        if(x%i==0)
        {
            return 0;
            break;
        }
    }
    return 1;
}