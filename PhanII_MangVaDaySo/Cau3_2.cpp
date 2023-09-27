/* Viết chương trình C, nhập vào 1 dãy gồm N số nguyên (N nhập từ bàn phím, 0 < N < 2x10^9). 
Tìm và in ra màn hình các số là số nguyên tố trong dãy vừa nhập */

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

        printf("Cac so nguyen trong day la so nguyen to:");
        for(i=1;i<=n;i++)
        if(isPrime(a[i]))
        {
            printf("%ld, ",a[i]);
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