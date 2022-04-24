#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <string>
#include <windows.h>
#define MAX 100
typedef struct
{ int ngay, thang, nam;
}	date;
typedef struct 
{ char mssv[10];
  char hoten[20];
  char gioitinh[3];
  date ngaysinh;
  char lop[10];
  float dtb;
}	SinhVien;
int SoLanThucThi();
void nhapdate(date &x);
void nhap1sv(SinhVien &x);   
void nhapSLSV(int &n);
void nhapDSSV(SinhVien x[],int n);
void xuatDSSV(SinhVien x[],int n);
void xuatSVdtblonhon8(SinhVien x[],int n);
void themSV(SinhVien x[], int &n);
void TroVe();
bool InDSvaoFile(SinhVien x[], int n, char name[]);
int main()
{   SinhVien sv[MAX];
	int n=0, SoLuaChon;
	char name[20];
	while(1)
	{	
		printf("\n\t\t\t[ chuong trinh thuc thi lan %d ]\n", SoLanThucThi());
		printf("\t\t*************************************************");
		printf("\n\t\t*%38s		*","CHUONG TRINH QUAN LY SINH VIEN");
		printf("\n\t\t*************************************************");
		
		printf("\n\t\t%26s", "MENU");
		printf("\n\t\t[\t1. Tao va nhap danh sach sinh vien\t]");
		printf("\n\t\t[\t2. Them sinh vien\t\t\t]");
		printf("\n\t\t[\t3. In ds sinh vien\t\t\t]");
		printf("\n\t\t[\t4. Luu ds sinh vien vao file\t\t]");
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
			case 2:
				system("cls");
				if(n==0)
				{	printf("hay tao va nhap 1 danh sach truoc");
					TroVe();
					break;
				}
				themSV(sv, n);
				printf("\nthem thanh cong");
				TroVe();
				break;
			case 3:
				system("cls");
				if(n==0)
				{	printf("chua co danh sach, hay tao mot danh sach truoc");
					TroVe();
					break;
				}
				xuatDSSV(sv,n);
				TroVe();
				break;
			case 4:
				system("cls");
				if(n==0)
				{	printf("chua co danh sach, hay tao mot danh sach truoc");
					TroVe();
					break;
				}
				printf("nhap ten danh sach: ");
				scanf("%s", name);
				strcat(name,".txt\0");
				if (InDSvaoFile(sv, n, name))
					printf("\nluu thanh cong");
				else
					printf("\nxuat hien loi, luu that bai");
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
	{    printf("\n\t%-5d \t %-20s \t %-15s \t%02d/%02d/%04d  \t %-6s \t %-10s \t %-6.1f",
		i+1, x[i].hoten,x[i].mssv, x[i].ngaysinh.ngay, x[i].ngaysinh.thang, x[i].ngaysinh.nam, x[i].gioitinh, x[i].lop, x[i].dtb);
	}
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
int SoLanThucThi()
{
	int dem=1;
	FILE *f1;
	f1 = fopen("dem.txt", "r");
	fscanf(f1, "%d", &dem);
	fclose(f1);
	f1=fopen("dem.txt", "w");
	fprintf(f1, "%d", dem+1);
	fclose(f1);
	return dem;
}
bool InDSvaoFile(SinhVien x[],int n, char name[])
{
	FILE *f2;
	f2 = fopen(name, "w+");
	if(f2==NULL)
		return false;
	else
	{	fputs("\n\t============================================================================================================", f2);
		fprintf(f2,"\n\t %-5s \t %-20s \t %-15s \t %-10s \t %-6s \t %-10s \t %-6s", "STT", "Hoten", "MSSV", "Ngaysinh", "gioitinh", "lop", "DTB");
		fputs("\n\t============================================================================================================", f2);
		for(int i=0;i<n;i++)
		{    fprintf(f2, "\n\t%-5d \t %-20s \t %-15s \t%02d/%02d/%04d  \t %-6s \t %-10s \t %-6.1f",
				i+1, x[i].hoten,x[i].mssv, x[i].ngaysinh.ngay, x[i].ngaysinh.thang, x[i].ngaysinh.nam, x[i].gioitinh, x[i].lop, x[i].dtb);
		}
		
	}
	fclose(f2);
	return true;
}
void themSV(SinhVien x[], int &n)
{	int add;
	printf("nhap so sinh vien can them vao: "); scanf("%d", &add);
	for (int i=n; i< n+add; i++)
	{	printf("\nnhap sinh vien thu %d",i+1);
		nhap1sv(x[i]);
	}
	n+=add;
}
void TroVe()			//ham tro ve giao dien chinh
{	printf("\n\nBam phim bat ky de tiep tuc...");
    getch();			//tam dung
    system("cls");		//xoa man hinh
}
