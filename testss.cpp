#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <string>
#include <windows.h>
#define MAX 100
struct date
{ int ngay, thang, nam;
};
typedef struct 
{ char mssv[10];
  char hoten[20];
  char gioitinh[3];
  date ngaysinh;
  char lop[10];
  float dtb;
}	SinhVien;
void nhapdate(date &x);
void nhap1sv(SinhVien &x);   
void nhapSLSV(int &n);
void nhapDSSV(SinhVien x[],int n);
void xuatDSSV(SinhVien x[],int n);
void xuatSVdtblonhon8(SinhVien x[],int n);
void TroVe();
int main()
{   SinhVien sv[MAX];
	int n=0, SoLuaChon;
	while(1)
	{	printf("\t\t*************************************************");
		printf("\n\t\t*%38s		*","CHUONG TRINH QUAN LY SINH VIEN");
		printf("\n\t\t*************************************************");
		printf("\n\t\t%26s", "MENU");
		printf("\n\t\t\t1. tao va nhap danh sach sinh vien");
		printf("\n\t\t\t2.them sinh vien");
		printf("\n\t\t\t3.in ds sinh vien");
		printf("\n\n\nnhap lua chon:");scanf("%d", &SoLuaChon);			//nhap lua chon chuc nang
		switch(SoLuaChon)
		{
			case 1:
				system("cls");
				nhapSLSV(n);
				nhapDSSV(sv,n);
				printf("\nban da nhap thanh cong");
				TroVe();
				break;
			case 3:
				system("cls");
				xuatDSSV(sv,n);
				TroVe();
				break;
				
		
		}
	}
}
void nhapdate(date &x)	//ham nhap ngay sinh
{
	printf("dd/mm/yyyy: "); scanf("%d%*c%d%*c%d",&x.ngay,&x.thang,&x.nam);
}
void nhap1sv(SinhVien &x)	//ham nhap thong tinh cua moi sv
{
	printf("Mssv: ");scanf("%s",&x.mssv);
	fflush(stdin); printf("Ho va ten: "),gets(x.hoten);
	fflush(stdin);
	do
	{	fflush(stdin);
		printf("Gioi tinh (nam)(nu): "); gets(x.gioitinh);
	}
	while (strcmp(x.gioitinh, "nam") && strcmp(x.gioitinh, "nu"));	//kiem tra dau vao,neu sai nhap lai
	nhapdate(x.ngaysinh);
	fflush(stdin);printf("Lop: "); scanf("%s",&x.lop);
	do{ printf("DTB:"); scanf("%f",&x.dtb);
	} while(x.dtb<0 || x.dtb>10);
}
 void nhapSLSV(int &n)		//ham nhap so luong sinh vien
{
	do{
		printf("\nNhap so luong sinh vien: "); scanf("%d",&n);
	} while(n<=0 || n>=100);
}
void nhapDSSV(SinhVien x[],int n)		//ham dung de nhap thong tin cua nhieu sinh vien
{
	for(int i=0;i<n;i++)
	{ 
	   printf("\tNhap sinh vien thu %d:\n",i+1);
	   nhap1sv(x[i]);
	}
}
void xuatDSSV(SinhVien x[],int n)		// ham in ra danh sach sinh vien
{
	printf("\n\t============================================================================================================");
	printf("\n\t %-5s \t %-20s \t %-15s \t %-10s \t %-6s \t %-10s \t %-6s", "STT", "Hoten", "MSSV", "Ngaysinh", "gioitinh", "lop", "DTB");
	printf("\n\t============================================================================================================");
	for(int i=0;i<n;i++)
	    printf("\n\t%-5d \t %-20s \t %-15s \t  %02d/%02d/%04d  \t %-6s \t %-10s \t %-6.1f",i+1, x[i].hoten,x[i].mssv, x[i].ngaysinh.ngay, x[i].ngaysinh.thang, x[i].ngaysinh.nam, x[i].gioitinh, x[i].lop, x[i].dtb);
}
void xuatSVdtblonhon8(SinhVien x[],int n)
{	SinhVien *arr=(SinhVien*)calloc(MAX, sizeof(SinhVien));
	int a=0;
	for(int i=0;i<n;i++)
	{	if(x[i].dtb>8) 
			{	*(arr+a)=x[i];
				a++;
			}
	}
	xuatDSSV(arr,a);
	free(arr);
}
void TroVe()			//ham tro ve giao dien chinh
{	printf("\n\nBam phim bat ky de tiep tuc...");
    getch();			//tam dung
    system("cls");		//xoa man hinh
}
