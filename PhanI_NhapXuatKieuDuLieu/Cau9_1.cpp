/* Viết chương trình C, nhập vào 2 số nguyên N, M (0 < N, M < 2x10^9). 
Tìm và in ra màn hình ước chung lớn nhất của N và M */

#include<stdio.h>
int main()
{
    unsigned long N,M,u,r;
    printf("Nhap so nguyen N: ");
    scanf("%lu",&N);
    printf("Nhap so nguyen M: ");
    scanf("%lu",&M);
    if(N<=0 || N>=2e9 || M<=0 || M>=2e9)
        printf("So N hoac M khong hop le.");
    else
    {
        do
        {
            r=N%M;
            N=M;
            M=r;
        } while (r!=0);
        u=N;
        printf("Uoc chung lon nhat cua hai so nguyen vua nhap la: %lu",u);
    }
    return 0;
}