#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct MatHang 
{
    int MaHang;
    char TenHang[50];
    char Donvitinh[10];
    int DonGia;
};

struct PhieuBH 
{
    char MaNB[6];
    int MaHang;
    int Soluong;
    int Ngayban;
    int Thangban;
    int Namban;
    int Thanhtien;
};

void ThemMatHang() 
{
    struct MatHang matHang;
    printf("Nhap MaHang: ");
    scanf("%d", &matHang.MaHang);
    printf("Nhap TenHang: ");
    scanf(" %[^\n]s", matHang.TenHang);
    printf("Nhap Donvitinh: ");
    scanf(" %[^\n]s", matHang.Donvitinh);
    printf("Nhap DonGia: ");
    scanf("%d", &matHang.DonGia);

    FILE *file = fopen("MatHang.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file MatHang.bin\n");
        return;
    }

    fwrite(&matHang, sizeof(struct MatHang), 1, file);

    fclose(file);
    printf("Mat hang da duoc them vao file MatHang.bin\n");
    printf("_____________________________________________\n");
}

void ThemPhieuBH()
{
    struct PhieuBH phieuBH;
    printf("Nhap MaNB: ");
    scanf(" %[^\n]s", phieuBH.MaNB);
    printf("Nhap MaHang: ");
    scanf("%d", &phieuBH.MaHang);
    printf("Nhap Soluong: ");
    scanf("%d", &phieuBH.Soluong);
    printf("Nhap Ngayban: ");
    scanf("%d", &phieuBH.Ngayban);
    printf("Nhap Thangban: ");
    scanf("%d", &phieuBH.Thangban);
    printf("Nhap Namban: ");
    scanf("%d", &phieuBH.Namban);

    // Tinh thanh tien
    FILE *matHangFile = fopen("MatHang.bin", "rb");
    if (matHangFile == NULL)
    {
        printf("Loi! Khong the mo file MatHang.bin\n");
        return;
    }

    struct MatHang matHang;
    int thanhtien = 0;
    while (fread(&matHang, sizeof(struct MatHang), 1, matHangFile)) 
    {
        if (matHang.MaHang == phieuBH.MaHang) 
        {
            thanhtien = phieuBH.Soluong * matHang.DonGia;
            break;
        }
    }

    fclose(matHangFile);
    phieuBH.Thanhtien = thanhtien;

    FILE *file = fopen("PhieuBH.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file PhieuBH.bin\n");
        return;
    }

    fwrite(&phieuBH, sizeof(struct PhieuBH), 1, file);

    fclose(file);
    printf("Phieu ban hang da duoc them vao file PhieuBH.bin\n");
    printf("_____________________________________________\n");
}

void DanhSachMatHangTheoMaNB() 
{
    char MaNB[6];
    printf("Nhap MaNB: ");
    scanf(" %[^\n]s", MaNB);

    FILE *phieuBHFile = fopen("PhieuBH.bin", "rb");
    if (phieuBHFile == NULL) 
    {
        printf("Loi! Khong the mo file PhieuBH.bin\n");
        return;
    }

    struct MatHang matHang;
    struct PhieuBH phieuBH;
    int stt = 1;
    int tongTien = 0;

    printf("Danh sach mat hang ban cua MaNB %s:\n", MaNB);
    printf("STT\tTenHang\t\tSo luong\tDon gia\t\tThanh tien\n");

    while (fread(&phieuBH, sizeof(struct PhieuBH), 1, phieuBHFile))
    {
        if (strcmp(phieuBH.MaNB, MaNB) == 0) 
        {
            FILE *matHangFile = fopen("MatHang.bin","rb");
            if(matHangFile == NULL)
            {
                printf("Loi! Khong the mo file MatHang.bin");
                fclose(phieuBHFile);
                return;
            }

            while(fread(&matHang, sizeof(struct MatHang), 1, matHangFile))
            {
                tongTien += phieuBH.Thanhtien;
                printf("%d\t%s\t\t%d\t\t%d\t\t%d\n", stt, matHang.TenHang, phieuBH.Soluong, matHang.DonGia, phieuBH.Thanhtien);
                stt++;
            }
            fclose(matHangFile);
        }
    }

    printf("Tong tien ban duoc: %d\n", tongTien);
    fclose(phieuBHFile);
}

int main() 
{
    ThemMatHang();
    ThemPhieuBH();
    DanhSachMatHangTheoMaNB();
    return 0;
}