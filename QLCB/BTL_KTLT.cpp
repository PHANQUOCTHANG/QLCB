#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
typedef struct Phicong{
	int MPC;
	char TPC[20];
	int age;
	int height;
	float weight;
	char Nationality[20];
}PC;
typedef struct Chuyenbay{
	int MACB; // Mã chuyến bay.
	char MAMB[20]; // Mã máy bay.
	char ND[20]; // Ngày đi.
	char NV[20]; // Ngày về.
	PC MPC; // Mã phi công.
	char TH[20]; // Tên hãng.
	char rank[20]; // Hạng.
	char NXP[20]; // Nơi xuất phát.
	char NT[20]; // Nơi tới.
} CB;
void Input (CB *x){ // Nhập ra thông tin một chuyến bay.
	printf ("Ma chuyen bay: ");
	scanf ("%d",&x->MACB);
	fflush(stdin);
	printf ("Ma may bay:    ");
	gets(x->MAMB);
	strupr(x->MAMB);
	printf ("Ngay di:       ");
	gets(x->ND);
	printf("Ngay ve:       ");
	gets(x->NV);
	printf ("Ma Phi cong:   ");
	scanf ("%d",&x->MPC.MPC);
	fflush(stdin);
	printf ("Ten Phi cong:  ");
	gets(x->MPC.TPC);
	strupr(x->MPC.TPC);
	printf ("Tuoi        :  ");
	scanf ("%d",&x->MPC.age);
	fflush(stdin);
	printf ("Height      :  ");
	scanf ("%d",&x->MPC.height);
	fflush(stdin);
	printf ("Weight      :  ");
	scanf ("%f",&x->MPC.weight);
	fflush(stdin);
	printf ("Nationality :  ");
	gets(x->MPC.Nationality);
	strupr(x->MPC.Nationality);
	printf ("Ten hang:      ");
	gets(x->TH);
	strupr(x->TH);
	printf ("Hang:          ");
	gets(x->rank);
	strupr (x->rank);
	printf ("Dia diem di:   ");
	gets(x->NXP);
	strupr(x->NXP);
	printf ("Dia diem toi:  ");
	gets(x->NT);
	strupr(x->NT);
	printf ("\n\n");
	printf ("--------------------------*---------------------------\n");
}
void Input1 (CB *x){ // Nhập ra thông tin các chuyến bay.
	printf ("\n*Moi nhap thong tin cac chuyen bay:  \n\n\n");
	printf ("--------------------------*---------------------------\n");
	for (int i=0;i<n;i++){
		printf ("\n*STT: %d\n\n",i+1);
		Input((x+i));
	}	
}

void Output (CB *x){ // Xuất ra thông tin một chuyến bay.
	printf ("--------------------------*--------------------------\n");
	printf ("Ma chuyen bay : %d                                   \n",x->MACB);
	printf ("Ma may bay    : %s                                   \n",x->MAMB);
	printf ("Ngay di       : %s                                   \n",x->ND);
	printf("Ngay ve       : %s                                    \n",x->NV);
	printf ("Ma Phi cong   : %d                                  \n",x->MPC.MPC);
	printf ("Ten hang bay  : %s                                   \n",x->TH);
	printf ("Hang          : %s                                   \n",x->rank);
	printf ("Dia diem di   : %s                                   \n",x->NXP);
	printf ("Dia diem toi  : %s                                   \n",x->NT);
	printf ("--------------------------*--------------------------\n\n\n");
}
void Output1(CB *x){ // Xuất ra thông tin các chuyến bay.
	printf ("\n               **FLIGHT INFORMATION:**                 \n\n");
	for (int i=0;i<n;i++){
		printf ("           *     CHUYEN BAY THU:  %d    *            \n\n",i+1);
		Output((x+i));
	}
}
void Output2(CB *x){ // xuat thong tin phi cong.
	printf ("Ma phi cong : %d                                     \n",x->MPC.MPC);
	printf ("Ten phi cong: %s                                     \n",x->MPC.TPC);
	printf ("Age         : %d                                     \n",x->MPC.age);
	printf ("Height      : %dcm                                   \n",x->MPC.height);
	printf ("Weight      : %.2fkg                                   \n",x->MPC.weight);
	printf ("Nationality : %s                                     \n",x->MPC.Nationality);
	printf ("--------------------------*--------------------------\n\n\n");
}
void swap (CB *a,CB *b){
	CB t=*a;
	*a=*b;
	*b=t;
}
void Sapxep1(CB *x){ // sắp xếp tăng dần theo MACB.
	for (int i=0;i<n;i++){
		int min=i;
		for (int j=i+1;j<n;j++){
			if ((x+min)->MACB>(x+j)->MACB) min=j;
		}
		swap((x+i),(x+min));
	}
}
void Sapxep2(CB *x){ // sắp xếp giảm dần theo MACB.
	for (int i=0;i<n;i++){
		int max=i;
		for (int j=i+1;j<n;j++){
			if ((x+max)->MACB<(x+j)->MACB) max=j;
		}
		swap((x+i),(x+max));
	}
}
void Find (CB *x){ // Tìm kiếm thông tin chuyến bay.
	int index;
	int key,value;
	printf ("Nhap MACB can tim kiem:");
	scanf ("%d",&index);
	fflush(stdin);
	bool z=false;
	for (int i=0;i<n;i++){
		if ((x+i)->MACB==index) {
			z=true;
			key=i;
			break;
		}
	}
	printf ("\nResult: ");
	if (z==true) {
		printf (" Found\n");
		printf ("\n*Ban co muon xuat ra thong tin chuyen bay vua tim kiem?\n");
		printf ("1.YES\n");
		printf ("2.NO\n");
		printf ("*Moi nhap lua chon: ");
		scanf("%d",&value);
		fflush(stdin);
		printf ("\n");
		if (value==1){
			printf ("           *     CHUYEN BAY THU:  %d    *            \n\n",key+1);
			Output((x+key));
		}
		}
	else printf (" Not Found\n\n");
}
void erase(CB*x,int index){ // Xóa thông tin chuyến bay thứ index.
	for (int i=index;i<n;i++){
		*(x+i)=*(x+i+1); 
	}
	n--;
}
void Delete(CB *x){ // Xóa thông tin chuyến bay.
	bool key=false;
	int index;
	printf ("*Nhap MACB can xoa:");
	scanf ("%d",&index);
	fflush(stdin);
	for (int i=0;i<n;i++){
		if ((x+i)->MACB==index) {
			erase(x,i);
			printf ("\n*Result: \n");
			printf ("\n*Da xoa thanh cong!\n\n");
			key=true;
			break;
		}
	}
	if (key==false) printf ("*Khong ton tai MACB can xoa!\n");
	else {
		if (n==0) printf ("\n*Danh sach hien tai rong!\n");
		else {
			printf ("Danh sach da duoc update la: \n");
			Output1(x);
		}
	}
}

void Find1(CB *x){ //Tìm thông tin của phi công trong chuyến bay quản lí.
	int index;
	bool value=false;
	printf ("Nhap Ma phi cong can (MCP) tim kiem: ");
	scanf ("%d",&index);
	fflush(stdin);
	printf ("\nResult: ");
	for (int i=0;i<n;i++){
		if ((x+i)->MPC.MPC==index) {
			printf ("\n\n");
			Output2((x+i));
			value=true;
			printf ("\n\n");
			break;
		}
	}
	if (value==false) printf ("NOT FOUND\n\n");
	
}
void Listed (CB *x){ // Thống kê các chuyến bay địa điểm tới theo yêu cầu.
	char index[20];
	bool value=false;
	printf ("Nhap dia diem toi can thong ke: ");
	gets(index);
	strupr(index); // chuyển chuỗi chữ thường thành chữ hoa.
	printf ("\nResult: ");
	for (int i=0;i<n;i++){
		if (strcmp((x+i)->NT,index)==0) {
			printf ("\n\n");
			Output((x+i));
			value=true;
			printf ("\n\n");
		}
	}
	if (value==false) printf ("NOT FOUND!\n\n");
}
void ListedSL( CB *x){ // TThống kê số lượng chuyến bay theo ngày đi.
	char index[20];
	int count=0;
	printf ("Nhap ngay di can thong ke: ");
	gets(index);
	printf ("\nResult: ");
	for (int i=0;i<n;i++){
		if (strcmp((x+i)->ND,index)==0) count++;
	}
	if (count>0) printf ("So luong chuyen bay khoi hanh trong ngay %s la: %d\n",index,count);
	else printf ("Khong co chuyen bay nao khoi hanh vao ngay %s\n",index);
}
void xoaxuongdong(char x[]){ // 
	size_t len=strlen(x);
	if (x[len-1]=='\n'){
		x[len-1]='0';
	}
}
void OutputToFile(CB *x){  // Xuất vào File.
	char Ten_File[100];
	printf ("Nhap Ten File de ghi: ");
	fgets(Ten_File,sizeof(Ten_File),stdin);
	xoaxuongdong(Ten_File);
	FILE *f;
	f=fopen(Ten_File,"wb");
	if (f==NULL){
		printf ("Loi mo File de ghi.\n");
		return ;
	}
	fwrite(&n,sizeof(n),1,f);
	for (int i=0;i<n;i++){
		fwrite((x+i),sizeof(CB),1,f);
	}
	fclose(f);
}
void InputFromFile(CB *x){ // Nhập dữ liệu từ File.
	char Ten_File[100];
	printf ("Nhap Ten File de xuat: ");
	fgets(Ten_File,sizeof(Ten_File),stdin);
	xoaxuongdong(Ten_File);
	FILE *f;
	f=fopen(Ten_File,"rb");
	if (f==NULL){
		printf ("Loi mo File de doc.\n");
		return ;
	}
	fread(&n,sizeof(n),1,f);
	for (int i=0;i<n;i++){
		fread((x+i),sizeof(CB),1,f);
	}
	fclose(f);
}
void addCB (CB *x){ // them thong tin mot chuyen bay.
	int index;
	printf ("Nhap so thong tin chuyen bay ban muon them: ");
	scanf ("%d",&index);
	fflush(stdin);
	printf ("\n");
	for (int i=n;i<n+index;i++){
		Input(x+i);
	}
	n+=index;
	printf ("Them thanh cong!\n");
}
void Selectable(CB *a){
	int x,y;
	do{
		printf ("\n          *Moi chon 1 trong nhung chuc nang sau: \n\n");
		printf ("1.Xuat ra thong tin cac chuyen bay.\n");
		printf ("2.Sap xep cac chuyen bay tang dan theo MACB.\n");
		printf ("3.Sap xep cac chuyen bay giam dan theo MACB.\n");
		printf ("4.Tim kiem mot chuyen bay.\n");
		printf ("5.Xoa mot chuyen bay.\n");
		printf ("6.Tim thong tin cua mot Phi cong trong chuyen bay theo MPC.\n");
		printf ("7.Tim thong tin cac chuyen theo dia diem toi.\n");
		printf ("8.Thong ke so luong chuyen bay khoi hanh theo ngay di.\n");
		printf ("9.Xuat du lieu vao File\n");
		printf ("10.Nhap du lieu tu File\n");
		printf ("11.Them thong tin mot chuyen bay.\n");
		printf (" \n*Moi nhap lua chon:");
		scanf ("%d",&x);
		fflush(stdin);
		printf ("\n\n");
		switch(x){
			case 1:{
				printf ("*Result: \n");
				Output1(a);
				break;
			}
			case 2: {
				printf ("*Result: \n");
				Sapxep1(a);
				Output1(a);
				break;
			}
			case 3:{
				printf ("*Result: \n");
				Sapxep2(a);
				Output1(a);
				break;
			}
			case 4: {
				Find(a);
				break;
			}
			case 5:{
				Delete(a); 
				break;
			}
			case 6:{
				Find1(a);
				break;
			}
			case 7: {
				Listed(a);
				break;
			}
			case 8: {
				ListedSL(a);
				break;
			}
			case 9:{
				OutputToFile(a);
				break;
			}
			case 10:{
				InputFromFile(a);
				break;
			}
			case 11: {
				printf ("\n");
				addCB(a);
				break;
			}
		}
		printf ("\n*Ban co muon tiep tuc su dung Selectable khong ?\n");
		printf ("1.YES\n");
		printf ("2.NO\n");
		printf (" \n*Moi nhap lua chon:");
		scanf ("%d",&y);
		fflush(stdin);
		printf ("\n\n");
		printf ("--------------------------*---------------------------\n");
		if (y!=1) 	printf ("\n\n*-----------------------*END*------------------------*\n");
	}while(y==1);
}




int main(){
	CB *a;
	char value[20];
	printf ("*Nhap so chuyen bay quan li: ");
	scanf ("%d",&n);
	fflush(stdin);
	a=(struct Chuyenbay*)malloc(n*sizeof (struct Chuyenbay)); // cap phat dong.
	printf ("\nBan co muon nhap du lieu tu ban phim khong:YES/NO.\n");
	printf ("\nMoi nhap lua chon:");
	gets(value);
	strupr(value);
	if (strcmp(value,"YES")==0){
		Input1(a);
	}
	Selectable(a);
	return 0;
}