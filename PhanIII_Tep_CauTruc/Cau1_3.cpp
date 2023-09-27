#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct HangHoa 
{
    int MaHH;
    char TenHH[50];
    char NhaSX[50];
    int DonGia;
};
struct HoaDon 
{
    int MaHH;
    char MaKhach[6];
    int Soluong;
    int Ngaymua;
    int Thangmua;
    int Thanhtien;
};

void NhapHangHoa() 
{
    struct HangHoa hanghoa;
    printf("Nhap MaHH: ");
    scanf("%d", &hanghoa.MaHH);
    printf("Nhap TenHH: ");
    scanf(" %[^\n]s", hanghoa.TenHH);
    printf("Nhap NhaSX: ");
    scanf(" %[^\n]s", hanghoa.NhaSX);
    printf("Nhap DonGia: ");
    scanf("%d", &hanghoa.DonGia);

    FILE *file = fopen("HangHoa.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file HangHoa.bin\n");
        return;
    }

    fwrite(&hanghoa, sizeof(struct HangHoa), 1, file);

    fclose(file);
    printf("Hang hoa da duoc them vao file HangHoa.bin\n");
    printf("_____________________________________________\n");
}

void NhapHoaDon() 
{
    struct HoaDon hoadon;
    printf("Nhap MaHH: ");
    scanf("%d", &hoadon.MaHH);
    printf("Nhap MaKhach: ");
    scanf("%s", hoadon.MaKhach);
    printf("Nhap Soluong: ");
    scanf("%d", &hoadon.Soluong);
    printf("Nhap Ngaymua: ");
    scanf("%d", &hoadon.Ngaymua);
    printf("Nhap Thangmua: ");
    scanf("%d", &hoadon.Thangmua);

    // Tinh thanh tien
    FILE *hanghoaFile = fopen("HangHoa.bin", "rb");
    if (hanghoaFile == NULL) 
    {
        printf("Loi! Khong the mo file HangHoa.bin\n");
        return;
    }

    struct HangHoa hanghoa;
    int thanhtien = 0;
    while (fread(&hanghoa, sizeof(struct HangHoa), 1, hanghoaFile)) 
    {
        if (hanghoa.MaHH == hoadon.MaHH) 
        {
            thanhtien = hoadon.Soluong * hanghoa.DonGia;
            break;
        }
    }

    fclose(hanghoaFile);
    hoadon.Thanhtien = thanhtien;

    FILE *file = fopen("HoaDon.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file HoaDon.bin\n");
        return;
    }

    fwrite(&hoadon, sizeof(struct HoaDon), 1, file);

    fclose(file);
    printf("Thong tin hoa don da duoc them vao file HoaDon.bin\n");
    printf("_____________________________________________\n");
}

void TinhTongTien() 
{
    char MaKhach[6];
    printf("Nhap MaKhach: ");
    scanf("%s", MaKhach);

    FILE *hoadonFile = fopen("HoaDon.bin", "rb");
    if (hoadonFile == NULL) 
    {
        printf("Loi! Khong the mo file HoaDon.bin\n");
        return;
    }

    struct HoaDon hoadon;
    struct HangHoa hanghoa;
    int stt = 1;
    int tongTien = 0;

    printf("STT\tTenHH\t\t\tSoLuong\tDonGia\tThanhTien\n");

    while (fread(&hoadon, sizeof(struct HoaDon), 1, hoadonFile)) 
    {
        if (strcmp(hoadon.MaKhach, MaKhach) == 0)
        {
            FILE *hanghoaFile = fopen("HangHoa.bin", "rb");
            if (hanghoaFile == NULL) 
            {
                printf("Loi! Khong the mo file HangHoa.bin\n");
                fclose(hoadonFile);
                return;
            }

            while (fread(&hanghoa, sizeof(struct HangHoa), 1, hanghoaFile)) 
            {
                if (hanghoa.MaHH == hoadon.MaHH) 
                {
                    printf("%d\t%s\t\t\t%d\t%d\t%d\n", stt, hanghoa.TenHH, hoadon.Soluong, hanghoa.DonGia, hoadon.Thanhtien);
                    tongTien += hoadon.Thanhtien;
                    break;
                }
            }
            fclose(hanghoaFile);
            stt++;
        }
    }

    printf("Tong tien: %d\n", tongTien);
    fclose(hoadonFile);
}

int main()
{
    NhapHangHoa();
    NhapHoaDon();
    TinhTongTien();
    return 0;
}