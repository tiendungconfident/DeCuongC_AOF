#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct Sach 
{
    int MaSach;
    char TenSach[50];
    char NhaXB[50];
    float Giabia;
};

struct Muon 
{
    int MaSach;
    char MaBanDoc[6];
    int Ngaymuon;
    int Thangmuon;
    float Tiencoc;
};

void NhapSach() 
{
    struct Sach sach;
    printf("Nhap MaSach: ");
    scanf("%d", &sach.MaSach);
    printf("Nhap TenSach: ");
    scanf(" %[^\n]s", sach.TenSach);
    printf("Nhap NhaXB: ");
    scanf(" %[^\n]s", sach.NhaXB);
    printf("Nhap Giabia: ");
    scanf("%f", &sach.Giabia);

    FILE *file = fopen("Sach.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file Sach.bin\n");
        return;
    }

    fwrite(&sach, sizeof(struct Sach), 1, file);

    fclose(file);
    printf("Sach da duoc them vao file Sach.bin\n");
    printf("_____________________________________________\n");
}

void NhapMuon() 
{
    struct Muon muon;
    printf("Nhap MaSach: ");
    scanf("%d", &muon.MaSach);
    printf("Nhap MaBanDoc: ");
    scanf("%s", muon.MaBanDoc);
    printf("Nhap Ngaymuon: ");
    scanf("%d", &muon.Ngaymuon);
    printf("Nhap Thangmuon: ");
    scanf("%d", &muon.Thangmuon);

    // Tinh tien coc
    FILE *sachFile = fopen("Sach.bin", "rb");
    if (sachFile == NULL) 
    {
        printf("Loi! Khong the mo file Sach.bin\n");
        return;
    }

    struct Sach sach;
    float tiencoc = 0;

    while (fread(&sach, sizeof(struct Sach), 1, sachFile)) 
    {
        if (sach.MaSach == muon.MaSach) 
        {
            tiencoc = 0.4 * sach.Giabia;
            break;
        }
    }

    fclose(sachFile);

    muon.Tiencoc = tiencoc;

    FILE *file = fopen("Muon.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file Muon.bin\n");
        return;
    }

    fwrite(&muon, sizeof(struct Muon), 1, file);

    fclose(file);
    printf("Thong tin muon sach da duoc them vao file Muon.bin\n");
    printf("_____________________________________________\n");
}

void TinhTienCoc() 
{
    char MaBanDoc[6];
    printf("Nhap MaBanDoc: ");
    scanf("%s", MaBanDoc);

    FILE *muonFile = fopen("Muon.bin", "rb");
    if (muonFile == NULL) 
    {
        printf("Loi! Khong the mo file Muon.bin\n");
        return;
    }

    struct Muon muon;
    struct Sach sach;
    float tongTiencoc = 0;
    int stt = 1;

    printf("STT\tTenSach\t\tNgaymuon\tThangmuon\tTiencoc\t\tGiabia\n");

    while (fread(&muon, sizeof(struct Muon), 1, muonFile)) 
    {
        if (strcmp(muon.MaBanDoc, MaBanDoc) == 0) 
        {
            FILE *sachFile = fopen("Sach.bin", "rb");
            if (sachFile == NULL) 
            {
                printf("Loi! Khong the mo file Sach.bin\n");
                fclose(muonFile);
                return;
            }

            while (fread(&sach, sizeof(struct Sach), 1, sachFile)) 
            {
                if (sach.MaSach == muon.MaSach) 
                {
                    printf("%d\t%s\t\t%d\t\t%d\t\t%.2f\t\t%.2f\n", stt, sach.TenSach, muon.Ngaymuon, muon.Thangmuon, muon.Tiencoc, sach.Giabia);
                    tongTiencoc += muon.Tiencoc;
                    break;
                }
            }

            fclose(sachFile);
            stt++;
        }
    }

    printf("Tong tien coc: %.2f\n", tongTiencoc);
    fclose(muonFile);
}

int main() 
{
    NhapSach();
    NhapMuon();
    TinhTienCoc();
    return 0;
}