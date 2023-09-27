/* Viết chương trình C, nhập vào 1 số nguyên N (0 < N < 2x10^9).
Tính và in ra màn hình tổng các ước lẻ của N */

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
        printf("\nCac uoc le cua %lu la: ",N);
        for(i=1;i<=N;i++)
        {
            if(N%i==0 && i%2==1)
            {
                printf("%lu\t",i);
                sum=sum+i;
            }
        }
        printf("\nTong cac uoc le cua %lu la: %lu",N,sum);
    }
    return 0;
}