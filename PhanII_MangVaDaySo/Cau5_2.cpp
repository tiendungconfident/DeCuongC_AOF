/* Viết chương trình C, nhập vào 1 dãy gồm N số nguyên (N nhập từ bàn phím, 0 < N < 2x109). 
Sắp xếp dãy theo thứ tự giảm dần của giá trị. In ra màn hình dãy trước và sau khi sắp xếp */
// Ngược lại câu 1, chỉ khác dòng 30, 36.
#include<stdio.h>
#define MAX 200000
int main()
{
    long n,i,j,a[MAX],trung_gian;
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
        printf("\nDay so truoc khi sap xep: ");
        for(i=1;i<=n;i++)
        {
            printf("%ld\t",a[i]);
        }

        //Tiến hành sắp xếp
        for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
        if(a[i]<a[j])
        {
            trung_gian=a[i];
            a[i]=a[j];
            a[j]=trung_gian;
        }
        printf("\nDay so da sap xep theo thu tu giam dan: ");
        for(i=1;i<=n;i++)
        {
            printf("%ld\t",a[i]);
        }
    }
    return 0;
}