#include <bits/stdc++.h>
using namespace std;

struct SinhVien{
    string hoTen, gioiTinh, ngaySinh, queQuan;
    string maSV, monHoc;
    float Gpa;
    int soTC, DRL;
};

struct SV{	
    SinhVien value;
    SV *next;
};

typedef struct SV* sv;

sv createNode(){
    SinhVien s; 
    cout << "\nNhap ho ten sinh vien: ";
    cin.ignore();
    getline(cin,s.hoTen);
    cout << "\nNhap gioi tinh sinh vien: ";
    getline(cin,s.gioiTinh);
    cout << "\nNhap ngay sinh: ";
    getline(cin,s.ngaySinh);
    cout << "\nNhap que quan sinh vien: ";
    getline(cin,s.queQuan);
    cout << "\nNhap ma sinh vien: ";
    getline(cin,s.maSV);
    cout << "\nNhap mon hoc: ";
    getline(cin,s.monHoc);
    cout << "\nNhap so tin chi: ";
    cin >> s.soTC;
    cout << "\nNhap diem: ";
    cin >> s.Gpa;
    cout << "\nNhap diem ren luyen: ";
    cin >> s.DRL;
	// trung ten dcm
	sv tmp = new SV();
	tmp -> value = s;
	tmp -> next = NULL;
	return tmp;
}

bool empty(sv a){
	return a == NULL;
}

int Size(sv a){
	int cnt = 0;
	while(a != NULL){
		++cnt;
		a = a->next; // gan dia chi cua not tiep theo cho node hien tai
		//cho node hien tai nhay sang not tiep theo
	}
	return cnt;
}
 
//them 1 phan tu vao dau danh sach lien ket
void insertFirst(sv &a){
	sv tmp = createNode();
	if(a == NULL){
		a = tmp;
	}
	else{
		tmp -> next = a;
		a = tmp;
	}
}
 
//Them 1 phan tu vao cuoi dslk
void insertLast(sv &a){
	sv tmp = createNode();
	if(a == NULL){
		a = tmp;
	}
	else{
		sv p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}
 
//Them 1 phan tu vao giua
void insertMiddle(sv &a,int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n + 1){
		cout << "Vi tri chen khong hop le !\n"; return;
	}
	if(pos == 1){
		insertFirst(a); return;
	}
	else if(pos == n + 1 ){
		insertLast(a); return;
	}
	sv p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p->next;
	}
	sv tmp = createNode();
	tmp->next = p->next;
	p->next = tmp;
}
 
//xoa phan tu o dau
void deleteFirst(sv &a){
	if(a == NULL) return;
	a = a->next;
}
 
//xoa phan tu o cuoi
void deleteLast(sv &a){
	if(a == NULL) return;
	sv truoc = NULL, sau = a;
	while(sau->next != NULL){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = NULL;
	}
	else{
		truoc->next = NULL;
	}
}
 
//Xoa o giua
void deleteMiddle(sv &a, int pos){
	if(pos <=0 || pos > Size(a)) return;
	sv truoc = NULL, sau = a;
	for(int i = 1; i < pos; i++){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = a->next;
	}
	else{
		truoc->next = sau->next;
	}
}
 
void in(SinhVien s){
	cout << "--------------------------------\n";
	cout << "Ho ten :" << s.hoTen << endl;
    cout << "Gioi tinh: " << s.gioiTinh << endl;
    cout << "Ngay sinh: " << s.ngaySinh << endl;
    cout << "Que quan: " << s.queQuan << endl;
	cout << "ID : " << s.maSV << endl;
	cout << "GPA : " << s.Gpa << endl; 
    cout << "Mon hoc: " << s.monHoc << endl;
    cout << "Diem ren luyen: " << s.DRL;
	cout << "--------------------------------\n";
}
 
void inds(sv a){
	cout << "Danh sach sinh vien :\n";
	while(a != NULL){
		in(a -> value);
		a = a -> next;
	}
	cout << endl;
}
 
void sapxep(sv &a){
	for(sv p = a; p->next != NULL; p = p->next){
		sv min = p;
		for(sv q = p->next; q != NULL; q = q->next){
			if(q -> value.Gpa < min -> value.Gpa){
				min = q;
			}
		}
		SinhVien tmp = min -> value;
		min -> value = p -> value;
		p -> value = tmp;
	}
}
/*void sapxepTheoGpa(sv &a) {
    SV tmp;
    for(sv p = a; p->next != NULL; p = p->next){
		sv max = p;
		for(sv q = p->next; q != NULL; q = q->next){
			if(q -> value.Gpa < max -> value.Gpa){
				max = q;
				}
			}
		}
	}*/
//Tim kiem trong dslk
//Tim phan tu lon nhat, nho nhat
//Tim kiem sinh vien theo ten, theo ma, id ...
 
 
int main(){
	sv head = NULL;
	while(1){
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen sinh vien vao dau danh sach\n";
		cout << "2. Chen sinh vien vao cuoi danh sach\n";
		cout << "3. Chen sinh vien vao giua danh sach\n";
		cout << "4. Xoa phan tu o dau\n";
		cout << "5. Xoa phan tu o cuoi\n";
		cout << "6. Xoa phan tu o giua\n";
		cout << "7. Duyet danh sach lien ket\n";
		cout << "8. Sap xep cac sinh vien trong dslk\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
		if(lc == 1){
			insertFirst(head);
		}
		else if(lc == 2){
			insertLast(head);
		}
		else if(lc == 3){
			int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
			insertMiddle(head, pos);
		}
		else if(lc == 4){
			deleteFirst(head);
		}
		else if(lc == 5){
			deleteLast(head);
		}
		else if(lc == 6){
			int pos; cout << "Nhap vi tri can xoa:"; cin >> pos;
			deleteMiddle(head, pos);
		}
		else if(lc == 7){
			inds(head);
		}
		else if(lc == 8){
			sapxep(head);
		}
		else if(lc == 0){
			break;
		}
	}
	return 0;
}
