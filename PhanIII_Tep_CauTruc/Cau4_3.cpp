#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct HSCB 
{
    char MaCB[6];
    char TenCB[50];
    char Bophan[10];
};

struct TamUng 
{
    char MaCB[6];
    int MaCT;
    int NgayTU;
    int ThangTU;
    int NamTU;
    int Sotien;
};

void NhapHSCB() 
{
    struct HSCB hscb;
    printf("Nhap MaCB: ");
    scanf("%s", hscb.MaCB);
    printf("Nhap TenCB: ");
    scanf(" %[^\n]s", hscb.TenCB);
    printf("Nhap Bophan: ");
    scanf(" %[^\n]s", hscb.Bophan);

    FILE *file = fopen("HSCB.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file HSCB.bin\n");
        return;
    }

    fwrite(&hscb, sizeof(struct HSCB), 1, file);

    fclose(file);
    printf("HSCB da duoc them vao file HSCB.bin\n");
    printf("_____________________________________________\n");
}

void NhapTamUng() 
{
    struct TamUng tamUng;
    printf("Nhap MaCB: ");
    scanf("%s", tamUng.MaCB);
    printf("Nhap MaCT: ");
    scanf("%d", &tamUng.MaCT);
    printf("Nhap NgayTU: ");
    scanf("%d", &tamUng.NgayTU);
    printf("Nhap ThangTU: ");
    scanf("%d", &tamUng.ThangTU);
    printf("Nhap NamTU: ");
    scanf("%d", &tamUng.NamTU);
    printf("Nhap Sotien: ");
    scanf("%d", &tamUng.Sotien);

    FILE *file = fopen("TamUng.bin", "ab");
    if (file == NULL) 
    {
        printf("Loi! Khong the mo file TamUng.bin\n");
        return;
    }

    fwrite(&tamUng, sizeof(struct TamUng), 1, file);

    fclose(file);
    printf("Chung tu tam ung da duoc them vao file TamUng.bin\n");
    printf("_____________________________________________\n");
}

void GhiChungTuTheoMaCB() 
{
    char MaCB[6];
    printf("Nhap MaCB: ");
    scanf("%s", MaCB);

    FILE *tamUngFile = fopen("TamUng.bin", "rb");
    if (tamUngFile == NULL) 
    {
        printf("Loi! Khong the mo file TamUng.bin\n");
        return;
    }

    struct TamUng tamUng;
    struct HSCB hscb;
    int stt = 1;
    int tongTien = 0;

    printf("Danh sach chung tu tam ung cua MaCB %s:\n", MaCB);
    printf("STT\tTenCB\t\tNgayTU\t\tThangTU\t\tNamTU\t\tSotien\n");

    while (fread(&tamUng, sizeof(struct TamUng), 1, tamUngFile))
    {
        if (strcmp(tamUng.MaCB, MaCB) == 0)
        {
            FILE *hscbFile = fopen("HSCB.bin", "rb");
            if (hscbFile == NULL) 
            {
                printf("Loi! Khong the mo file HSCB.bin\n");
                fclose(tamUngFile);
                return;
            }

            while (fread(&hscb, sizeof(struct HSCB), 1, hscbFile)) 
            {
                if (strcmp(hscb.MaCB, MaCB) == 0) 
                {
                    printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\n", stt, hscb.TenCB, tamUng.NgayTU, tamUng.ThangTU, tamUng.NamTU, tamUng.Sotien);
                    break;
                }
            }

            fclose(hscbFile);

            tongTien += tamUng.Sotien;
            stt++;
        }
    }

    printf("Tong tien tam ung: %d\n", tongTien);
    fclose(tamUngFile);
}

int main() 
{
    NhapHSCB();
    NhapTamUng();
    GhiChungTuTheoMaCB();
    return 0;
}
