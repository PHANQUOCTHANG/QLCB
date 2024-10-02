#include <bits/stdc++.h>
using namespace std;
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
struct Node{
	CB data;
	Node *next;
};
struct linklist{
	Node *head;
	Node *tail;
};
Node *CreatNode(CB x){
	Node *node=new Node;
	node->data=x;
	node->next=NULL;
	return node;
}
void Creatlist(linklist &l){
	l.head=NULL;
	l.tail=NULL;
}
void addfinal(linklist &l,Node *node){
	if (l.head==NULL){
		l.head=node;
		l.tail=node;
	}
	else {
		l.tail->next=node;
		l.tail=node;
	}
}
void Input (linklist &l){ // Nhập ra thông tin một chuyến bay.
	CB x;
	
	printf ("Ma chuyen bay: ");
	scanf ("%d",&x.MACB);
	fflush(stdin);
	printf ("Ma may bay:    ");
	gets(x.MAMB);
	strupr(x.MAMB);
	printf ("Ngay di:       ");
	gets(x.ND);
	printf("Ngay ve:       ");
	gets(x.NV);
	printf ("Ma Phi cong:   ");
	scanf ("%d",&x.MPC.MPC);
	fflush(stdin);
	printf ("Ten Phi cong:  ");
	gets(x.MPC.TPC);
	strupr(x.MPC.TPC);
	printf ("Tuoi        :  ");
	scanf ("%d",&x.MPC.age);
	fflush(stdin);
	printf ("Height      :  ");
	scanf ("%d",&x.MPC.height);
	fflush(stdin);
	printf ("Weight      :  ");
	scanf ("%f",&x.MPC.weight);
	fflush(stdin);
	printf ("Nationality :  ");
	gets(x.MPC.Nationality);
	strupr(x.MPC.Nationality);
	printf ("Ten hang:      ");
	gets(x.TH);
	strupr(x.TH);
	printf ("Hang:          ");
	gets(x.rank);
	strupr (x.rank);
	printf ("Dia diem di:   ");
	gets(x.NXP);
	strupr(x.NXP);
	printf ("Dia diem toi:  ");
	gets(x.NT);
	strupr(x.NT);
	Node *node=new Node;
	node=CreatNode(x);
	addfinal(l,node);
	printf ("\n\n");
	printf ("--------------------------*---------------------------\n");
}
void Input1 (linklist &l){ // Nhập ra thông tin các chuyến bay.
	printf ("\n*Moi nhap thong tin cac chuyen bay:  \n\n\n");
	printf ("--------------------------*---------------------------\n");
	for (int i=0;i<n;i++){
		printf ("\n*STT: %d\n\n",i+1);
		Input(l);
	}	
}

void Output (Node *x){ // Xuất ra thông tin một chuyến bay.
	printf ("--------------------------*--------------------------\n");
	printf ("Ma chuyen bay : %d                                   \n",x->data.MACB);
	printf ("Ma may bay    : %s                                   \n",x->data.MAMB);
	printf ("Ngay di       : %s                                   \n",x->data.ND);
	printf("Ngay ve       : %s                                    \n",x->data.NV);
	printf ("Ma Phi cong   : %d                                  \n",x->data.MPC.MPC);
	printf ("Hang          : %s                                   \n",x->data.rank);
	printf ("Dia diem di   : %s                                   \n",x->data.NXP);
	printf ("Dia diem toi  : %s                                   \n",x->data.NT);
	printf ("--------------------------*--------------------------\n\n\n");
}
void Output1(linklist &l){ // Xuất ra thông tin các chuyến bay.
	int k=1;
	Node *p=l.head;
	if (p==NULL){
		printf ("\nDanh sach rong!\n");
	}
	else {
		printf ("\n               **FLIGHT INFORMATION:**                 \n\n");
	    for (Node *node=l.head;node!=NULL;node=node->next){
		printf ("           *     CHUYEN BAY THU:  %d    *            \n\n",k++);
		Output(node);
	}
	}
}
void Output2(Node *x){ // Xuất thông tin phi công.
	printf ("Ma Phi cong   : %d                                  \n",x->data.MPC.MPC);
	printf ("Ten phi cong: %s                                     \n",x->data.MPC.TPC);
	printf ("Age         : %d                                     \n",x->data.MPC.age);
	printf ("Height      : %dcm                                   \n",x->data.MPC.height);
	printf ("Weight      : %.2fkg                                   \n",x->data.MPC.weight);
	printf ("Nationality : %s                                     \n",x->data.MPC.Nationality);
	printf ("--------------------------*--------------------------\n\n\n");
}

void arrange1(linklist &l){ // sắp xếp tăng dần theo MACB.
	Node *p, *q;
    for(p = l.head; p != l.tail; p=p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->data.MACB > q->data.MACB){
                CB x = p->data;
                p->data = q->data;
                q->data = x; 
            }
        }
    }    
}
void arrange2(linklist &l){ // sắp xếp giảm dần theo MACB.
	Node *p, *q;
    for(p = l.head; p != l.tail; p=p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->data.MACB < q->data.MACB){
                CB x = p->data;
                p->data = q->data;
                q->data = x; 
            }
        }
    }    
}
void Find (linklist &l){ // Tìm kiếm chuyến bay theo mã chuyến bay.
	int index;
	int value;
	int k=1;
	printf ("Nhap MACB can tim kiem:");
	scanf ("%d",&index);
	fflush(stdin);
	Node *p=l.head;
	while (p!=NULL && p->data.MACB!=index){
		p=p->next;
	}
	printf ("\nResult: ");
	if (p==NULL) printf (" Not Found\n");
	else {
		printf ("Found\n");
		printf ("\n*Ban co muon xuat ra thong tin chuyen bay vua tim kiem?\n");
		printf ("1.YES\n");
		printf ("2.NO\n");
		printf ("*Moi nhap lua chon: ");
		scanf("%d",&value);
		fflush(stdin);
		printf ("\n");
		if (value==1){
			printf ("           *     CHUYEN BAY THU:  %d    *            \n\n",k++);
			Output(p);
		}
	}
}
void Delete(linklist &l){
	int index;
	printf ("Nhap MACB can Delete: ");
	scanf ("%d",&index);
	fflush(stdin);
	Node *check=l.head;
	if(check->data.MACB==index){
			if (l.head != NULL)
			{
				Node* node = l.head;
			
				l.head = node->next;
				delete node;         
				if (l.head == NULL){
					l.tail = NULL;
				}
				printf("Da xoa thanh cong!\n");
				return;
			}
		printf("!DANH SACH RONG!\n");
		return;
	}	
	else{
		while(check->next!=NULL && check->next->data.MACB!=index){
			check=check->next;
		}
		if(check!=NULL){
			Node *tam=check->next;
			if(tam!=NULL){
				if (l.tail == tam){
					l.tail = check;
				}
				check->next = tam->next;
				delete tam;
				printf("Da xoa thanh cong!\n");
				return;
				
			}
		}
		printf("MACB khong hop le!\n");
		return;
	}
}
void Find1(linklist &l){ //Tìm thông tin của phi công trong chuyến bay quản lí.
	int index;
	bool value=false;
	printf ("Nhap Ma phi cong can (MCP) tim kiem: ");
	scanf ("%d",&index);
	fflush(stdin);
	printf ("\nResult: ");
	for (Node *node=l.head;node!=NULL;node=node->next){
		if (node->data.MPC.MPC==index) {
			printf ("\n\n");
			Output2(node);
			value=true;
			printf ("\n\n");
			break;
		}
	}
	if (value==false) printf ("NOT FOUND\n\n");
	
}
void Listed (linklist &l){ // Thống kê các chuyến bay có địa điểm tới theo yêu cầu.
	char index[20];
	bool value=false;
	printf ("Nhap dia diem toi can thong ke: ");
	gets(index);
	strupr(index); // chuyển chuỗi chữ thường thành chữ hoa.
	printf ("\nResult: ");
	for (Node *node=l.head;node!=NULL;node=node->next){
		if (strcmp(node->data.NT,index)==0) {
			printf ("\n\n");
			Output(node);
			value=true;
			printf ("\n\n");
		}
	}
	if (value==false) printf ("NOT FOUND!\n\n");
}
void ListedSL(linklist &l){ // Thống kê số lượng chuyến bay khởi hành có ngày đi theo yêu cầu.
	char index[20];
	int count=0;
	printf ("Nhap ngay di can thong ke: ");
	gets(index);
	printf ("\nResult: ");
	for (Node *node=l.head;node!=NULL;node=node->next){
		if (strcmp(node->data.ND,index)==0) count++;
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
void OutputToFile(linklist &l) {  
    char Ten_File[100];
    printf("Nhap Ten File de ghi: ");
    fflush(stdin);
    fgets(Ten_File, sizeof(Ten_File), stdin);
    xoaxuongdong(Ten_File);
    FILE *f;
    f = fopen(Ten_File, "wb");
    if (f == NULL) {
        printf("ERROR! Khong mo duoc file de ghi.\n");
        return;
    }
    int count = 0;
    Node *current = l.head;
    // Đếm số lượng nút trong danh sách liên kết
    while (current != NULL) {
        count++;
        current = current->next;
    }
    // Ghi số lượng nút vào file
    fwrite(&count, sizeof(count), 1, f);
    // Duyệt qua từng nút và ghi thông tin vào file
    current = l.head;
    while (current != NULL) {
        fwrite(&(current->data), sizeof(CB), 1, f);
        current = current->next;
    }
    fclose(f);
}

void InputFromFile(linklist &l) { 
    char Ten_File[100];
    printf("Nhap Ten File de xuat: ");
    fflush(stdin);
    fgets(Ten_File, sizeof(Ten_File), stdin);
    xoaxuongdong(Ten_File);
    FILE *f;
    f = fopen(Ten_File, "rb");
    if (f == NULL) {
        printf("ERROR! Khong mo duoc file de doc.\n");
        return;
    }
    int count;
    // Đọc số lượng nút từ file
    fread(&count, sizeof(count), 1, f);
    CB data;
    // Duyệt qua từng nút được lưu trong file và thêm vào danh sách liên kết
    for (int i = 0; i < count; i++) {
        fread(&data, sizeof(CB), 1, f);
        Node *newNode = CreatNode(data);
        if (l.head == NULL) {
            l.head = newNode;
            l.tail = newNode;
        } else {
            l.tail->next = newNode;
            l.tail = newNode;
        }
    }
    fclose(f);
}
void addCB(linklist &l){
	int index;
	printf ("Nhap so thong tin chuyen bay ban muon them: ");
	scanf ("%d",&index);
	fflush(stdin);
	printf ("\n");
	for (int i=1;i<=index;i++){
		Input(l);
	}
}
void Selectable(linklist &l){
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
				Output1(l);
				break;
			}
			case 2: {
				printf ("*Result: \n");
				arrange1(l);
				Output1(l);
				break;
			}
			case 3:{
				printf ("*Result: \n");
				arrange2(l);
				Output1(l);
				break;
			}
			case 4: {
				Find(l);
				break;
			}
			case 5:{
				Delete(l); 
				break;
			}
			case 6:{
				Find1(l);
				break;
			}
			case 7: {
				Listed(l);
				break;
			}
			case 8: {
				ListedSL(l);
				break;
			}
			case 9:{
				OutputToFile(l);
				break;
			}
			case 10:{
				InputFromFile(l);
				break;
			}
			case 11: {
				addCB(l);
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
	linklist l;
	Creatlist(l);
	char value[20];
	printf ("Ban co muon nhap du lieu tu ban phim khong:YES/NO.\n");
	printf ("\nMoi nhap lua chon:");
	gets(value);
	strupr(value);
	if (strcmp(value,"YES")==0){
		printf ("\n*Nhap so chuyen bay quan li: ");
		scanf ("%d",&n);
		fflush(stdin);
		Input1(l);
	}
	Selectable(l);
	return 0;
}