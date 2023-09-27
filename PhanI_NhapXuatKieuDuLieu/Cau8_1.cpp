/* Viết chương trình C, nhập vào 1 số nguyên N (0 < N < 2x10^9). 
Tính và in ra màn hình tổng các ước của N */

#include<stdio.h>
int main()
{
    unsigned long N,i,sum=0;
    printf("Nhap so nguyen N (0 < N < 2x10^9): ");
    scanf("%lu",&N);
    if(N<=0 || N>=2e9)
        printf("So N khong hop le.");
    else
    {
        printf("\nCac uoc cua %lu la: ",N);
        for(i=1;i<=N;i++)
        {
            if(N%i==0)
            {
                printf("%lu\t",i); //\t để nhảy 1 tab
                sum=sum+i;
            }
        }
        printf("\nTong cac uoc cua %lu la: %lu",N,sum);
    }
    return 0;
}