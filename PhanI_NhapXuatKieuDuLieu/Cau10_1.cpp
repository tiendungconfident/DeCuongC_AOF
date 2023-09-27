/* Viết chương trình C, nhập vào 1 số nguyên N (0 < N < 2x10^9). 
Đếm và in ra màn hình số các ước của N. */

#include<stdio.h>
int main() 
{
	unsigned long N,i,count=0;
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
                printf("%lu\t",i);
                count=count+1;
            }
        }
	    printf("\nSo cac uoc cua %lu la: %lu",N,count);
    }
	return 0;
}