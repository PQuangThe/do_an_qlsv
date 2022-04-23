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
void nhapdate(date &x)
{
	printf("dd/mm/yyyy: "); scanf("%d%*c%d%*c%d",&x.ngay,&x.thang,&x.nam);
}
struct sv
{ char mssv[10];
  char hoten[20];
  char gioitinh[3];
  date ngaysinh;
  char lop[10];
  float dtb;
};
void nhap1sv(sv &x)
{
	printf("Mssv: ");scanf("%s",&x.mssv);
	fflush(stdin); printf("Ho va ten: "),gets(x.hoten);
	fflush(stdin);
	printf("Gioi tinh (nam)(nu): "); gets(x.gioitinh);
	nhapdate(x.ngaysinh);
	fflush(stdin);printf("Lop: "); scanf("%s",&x.lop);
	do{ printf("DTB:"); scanf("%f",&x.dtb);
	} while(x.dtb<0 || x.dtb>10);
}   
void nhapSLSV(int &n){
	do{
		printf("Nhap so luong sinh vien: "); scanf("%d",&n);
	} while(n<=0 || n>=100);
}
void nhapDSSV(sv x[],int n){
	for(int i=0;i<n;i++)
	{ 
	   printf("\tNhap sinh vien thu %d:\n",i+1);
	   nhap1sv(x[i]);
	}
}
void xuatDSSV(sv x[],int n)
{
	printf("\n\t============================================================================================================");
	printf("\n\t %-5s \t %-20s \t %-15s \t %-10s \t %-6s \t %-10s \t %-6s", "STT", "Hoten", "MSSV", "Ngaysinh", "gioitinh", "lop", "DTB");
	printf("\n\t============================================================================================================");
	for(int i=0;i<n;i++)
	    printf("\n\t%-5d \t %-20s \t %-15s \t  %02d/%02d/%04d  \t %-6s \t %-10s \t %-6.1f",i+1, x[i].hoten,x[i].mssv, x[i].ngaysinh.ngay, x[i].ngaysinh.thang, x[i].ngaysinh.nam, x[i].gioitinh, x[i].lop, x[i].dtb);
}
void xuatSVdtblonhon8(sv x[],int n)
{
	for(int i=0;i<n;i++)
	 if(x[i].dtb>8) xuat1sv(x[i]);
}
int main()
{   sv a[MAX];
	int n;
	nhapSLSV(n);
	nhapDSSV(a,n);
	printf("\n\tDanh sach sinh vien vua nhap:");
	xuatDSSV(a,n);  
	printf("\n\tDanh sach sinh vien co DTB lon hon 8: ");
	xuatSVdtblonhon8(a,n);
}

