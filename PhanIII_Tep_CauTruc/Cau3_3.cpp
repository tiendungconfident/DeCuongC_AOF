#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct Kho 
{
    int Makho;
    char Tenkho[50];
    char Diachi[100];
};

struct Vattu 
{
    int Makho;
    char MaVT[6];
    int Soluong;
    char Donvitinh[20];
    int Dongia;
    long Thanhtien;
};

void NhapKho() 
{
    struct Kho kho;
    printf("Nhap Makho: ");
    scanf("%d", &kho.Makho);
    printf("Nhap Tenkho: ");
    scanf(" %[^\n]s", kho.Tenkho);
    printf("Nhap Diachi: ");
    scanf(" %[^\n]s", kho.Diachi);

    FILE *file = fopen("Kho.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file Kho.bin\n");
        return;
    }

    fwrite(&kho, sizeof(struct Kho), 1, file);

    fclose(file);
    printf("Kho da duoc them vao file Kho.bin\n");
    printf("_____________________________________________\n");
}

void NhapVattu() 
{
    struct Vattu vattu;
    printf("Nhap Makho: ");
    scanf("%d", &vattu.Makho);
    printf("Nhap MaVT: ");
    scanf("%s", vattu.MaVT);
    printf("Nhap Soluong: ");
    scanf("%d", &vattu.Soluong);
    printf("Nhap Donvitinh: ");
    scanf(" %[^\n]s", vattu.Donvitinh);
    printf("Nhap Dongia: ");
    scanf("%d", &vattu.Dongia);

    vattu.Thanhtien = (long)vattu.Soluong * vattu.Dongia;

    FILE *file = fopen("Vattu.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file Vattu.bin\n");
        return;
    }

    fwrite(&vattu, sizeof(struct Vattu), 1, file);

    fclose(file);
    printf("Vat tu da duoc them vao file Vattu.bin\n");
    printf("_____________________________________________\n");
}

void GhiVattuTheoMaVT() 
{
    char MaVT[6];
    printf("Nhap MaVT: ");
    scanf("%s", MaVT);

    FILE *vattuFile = fopen("Vattu.bin", "rb");
    if (vattuFile == NULL) 
    {
        printf("Loi! Khong the mo file Vattu.bin\n");
        return;
    }

    struct Vattu vattu;
    struct Kho kho;
    int stt = 1;
    int tongSoluong = 0;

    printf("Danh sach cac kho chua vat tu MaVT %s:\n", MaVT);
    printf("STT\tTenkho\t\tDiachi\t\tSoluong\t\tDongia\t\tThanhtien\n");

    while (fread(&vattu, sizeof(struct Vattu), 1, vattuFile)) 
    {
        if (strcmp(vattu.MaVT, MaVT) == 0) 
        {
            FILE *khoFile = fopen("Kho.bin", "rb");
            if (khoFile == NULL) 
            {
                printf("Loi! Khong the mo file Kho.bin\n");
                fclose(vattuFile);
                return;
            }

            while (fread(&kho, sizeof(struct Kho), 1, khoFile)) 
            {
                if (kho.Makho == vattu.Makho) 
                {
                    printf("%d\t%s\t\t%s\t\t%d\t\t%d\t\t%ld\n", stt, kho.Tenkho, kho.Diachi, vattu.Soluong, vattu.Dongia, vattu.Thanhtien);
                    tongSoluong += vattu.Soluong;
                    break;
                }
            }

            fclose(khoFile);
            stt++;
        }
    }

    printf("Tong so luong vat tu: %d\n", tongSoluong);
    fclose(vattuFile);
}

int main() 
{
    NhapKho();
    NhapVattu();
    GhiVattuTheoMaVT();
    return 0;
}