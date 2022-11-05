#include <bits/stdc++.h>
#include "mylib.h"
using namespace std;

static int dem;

struct SinhVien{
    string hoTen, gioiTinh, ngaySinh, queQuan;
    string maSV, khoa;
    float Gpa;
    int DRL;
};

struct nodeSV{	
    SinhVien value;
    nodeSV *next;
};

typedef struct nodeSV sv;

typedef struct ds_sv{
    sv *head = NULL;
    sv *tail = NULL;
}ds_sv;

istream& operator >> (istream &is, SinhVien &s)
{
    ++dem;
    s.maSV = "SV" + string(3-to_string(dem).length(), '0') + to_string(dem);
	cout << "\t\t\t\tNhap ho ten sinh vien: ";
    is.ignore();
    getline(is,s.hoTen);
    cout << "\t\t\t\tNhap gioi tinh sinh vien: ";
    is >> s.gioiTinh;
    cout << "\t\t\t\tNhap ngay sinh: ";
    is.ignore();
    getline(is,s.ngaySinh);
    cout << "\t\t\t\tNhap que quan sinh vien: ";
    getline(is,s.queQuan);
    cout << "\t\t\t\tNhap lop hoc: ";
    getline(is,s.khoa);
    cout << "\t\t\t\tNhap diem he so 4: ";
    is >> s.Gpa;
    cout << "\t\t\t\tNhap diem ren luyen: ";
    is >> s.DRL;
	//----
	return is;
}

nodeSV* createNode(SinhVien x){
    nodeSV *p = new nodeSV;
    p -> value = x;
    p -> next = NULL;
    return p;
}

void addSV(ds_sv &ds_sv, SinhVien x){
	nodeSV *p = createNode(x);
	if (ds_sv.head == NULL)//rỗng: đầu cuối = p
	{
		ds_sv.head = ds_sv.tail = p;
	}
	else//n pt => Thêm cuối
	{
		ds_sv.tail -> next = p;
		ds_sv.tail = p;
	}
}

void insv(SinhVien s){// them khung mau 
	/* cout << "\t\t\t\tID : " << s.maSV << endl;
	cout << "\t\t\t\tHo ten :" << s.hoTen << endl;
    cout << "\t\t\t\tGioi tinh: " << s.gioiTinh << endl;
    cout << "\t\t\t\tNgay sinh: " << s.ngaySinh << endl;
    cout << "\t\t\t\tQue quan: " << s.queQuan << endl;
    cout << "\t\t\t\tLop hoc: " << s.khoa << endl;
	cout << "\t\t\t\tGPA : " << fixed << setprecision(2) << s.Gpa << endl; 
    cout << "\t\t\t\tDiem ren luyen: " << s.DRL << endl; */
    cout << setw(5) << left << s.maSV << "|" << "\t";
    cout << setw(30) << left << s.hoTen << "|" << "\t";
    cout << setw(10) << left << s.gioiTinh << "|" << "\t";
    cout << setw(15) << left << s.ngaySinh << "|" << "\t";
    cout << setw(20) << left << s.queQuan << "|" << "\t";
    cout << setw(10) << left << s.khoa << "|" << "\t";
    cout << setw(5) << left << s.Gpa << "|" << "\t";
    cout << setw(3) << left << s.DRL << "|" << "\t" << endl;

}

void inds(ds_sv ds_sv){
	SetColor(3);
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
	//cout << "\t\t\t\t---------- Sinh vien: " << i++ << "-----------"<< endl;
    cout << setw(5) << left << "ID" << "|" << "\t" << setw(30) << left << "Ho ten" << "|" << "\t" << setw(10) << left << "Gioi tinh" << "|" << "\t" 
    << setw(15) << left << "Ngay sinh" << "|" << "\t" << setw(20) << left << "Que quan" << "|" << "\t" << setw(10) << left << "Khoa" << "|" << "\t" 
    << setw(5) << left << "Gpa" << "|" << "\t" << setw(3) << left << "DRL" << "|" << "\t" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    int i = 1;
	for (nodeSV *k = ds_sv.head; k != NULL; k = k -> next)
	{
	    insv(k -> value);
	}
}

void xoaID(ds_sv &ds_sv){
	string ma;
	cin.ignore();
	cout << "Nhap ma can xoa: ";
	cin >> ma;
	nodeSV *p = NULL;
	for(nodeSV *q = ds_sv.head; q != NULL; ){
		if (_stricmp(q->value.maSV.c_str(), ma.c_str()) == 0 && q == ds_sv.head){
			ds_sv.head = ds_sv.head -> next;
            delete q;
            q = ds_sv.head;
		}
		else{
			if(_stricmp(q -> value.maSV.c_str(), ma.c_str()) == 0){
				p -> next = q -> next;
				delete q;
				q = p;
				if(p -> next == NULL){
					ds_sv.tail = p;
					return;
				}
			}
			p = q;
			q = q -> next;
		}
	}
}

void sapxepTangdan(ds_sv &ds_sv){
	for(nodeSV *p = ds_sv.head; p != NULL; p = p -> next){
		nodeSV *min = p;
		for(nodeSV *q = p -> next; q != NULL; q = q -> next){
			if(q -> value.Gpa < min -> value.Gpa){
				min = q;
			}
		}
		SinhVien tmp = min -> value;
		min -> value = p -> value;
		p -> value = tmp;
	}
}

void SearchID(ds_sv &ds_sv){
	string masv;
    cout << "Nhap ma can tim: ";
    cin >> masv;
    bool found = false;
    for(nodeSV *p = ds_sv.head; p != NULL; p = p -> next){
        if(p -> value.maSV.find(masv) != string::npos){
            insv(p -> value);
            found = true;
        }
    }
    if(!found)
        cout << "Khong tim thay sinh vien co ma vua nhap !\n";
}

void gpaest(ds_sv &ds_sv){//
	double res = 0;
	for(nodeSV *p = ds_sv.head; p != NULL; p = p -> next){
		if(p -> value.Gpa > res){
			res = p -> value.Gpa;
		}
	}
	cout << "Danh sach sinh vien co diem gpa cao nhat: \n";
	for(nodeSV *p = ds_sv.head; p != NULL; p = p -> next){
		if(res == p -> value.Gpa){
			insv(p -> value);	
		}
	}
}

void xethocBong(ds_sv &ds_sv){
	cout << "Danh sach sinh vien dat hoc bong: \n";
    int tag = 0;
	for(nodeSV *p = ds_sv.head; p != NULL; p = p -> next){
		if(p -> value.Gpa >= 3.7 && p-> value.Gpa <= 4.0 && p -> value.DRL >= 80 && p -> value.DRL <= 100){
            tag = 1;
			insv(p -> value);
		}
	}
    if(tag == 0){
        cout << "\nKhong co sinh vien dat hoc bong!";
    }
}


void docfile(ds_sv &ds_sv)
{
	ifstream f;
    f.open("qlsv.txt", ios::in);
	cout << "processing...";
	while (f.eof() == false)
	{
		SinhVien a;//để lưu tạm dữ liệu load từ file
        f >> a.maSV;
		string tmp;//luu bien tam de doc ki tu xuong dong o cuoi dong
		getline(f, tmp);
		getline(f, a.hoTen);
		f >> a.gioiTinh;
		getline(f, tmp);
		getline(f, a.ngaySinh);
		getline(f, a.queQuan);
        getline(f, a.khoa);
        f >> a.Gpa;
        f >> a.DRL;
		addSV(ds_sv, a);	

	}
	f.close();
}

void ghifile(ds_sv &ds_sv){
	ofstream f;
	f.open("sv.txt", ios::app);
	nodeSV *p = ds_sv.head;
	while (p != NULL){
		f << "ID: " << p -> value.maSV << endl;
		f << "Ho ten: " << p -> value.hoTen << endl;
        f << "Gioi tinh: " << p -> value.gioiTinh << endl;
        f << "Que quan: " << p -> value.queQuan << endl;
        f << "Lop hoc: " << p -> value.khoa << endl;
        f << "Diem gpa: " << p -> value.Gpa << endl;
        f << "Diem ren luyen: " << p -> value.DRL << endl;
		f << "==================" << endl;
		p = p -> next;
	}
	cout << "Da ghi file !";
}

/* string in_name(string fullName){
	int pos = 0;
	string name = ' ' + fullName;
	string merge;
	for(int i = name.length() - 1; i >= 0; i--){
		++pos;
		if(name[i] == ' '){
			merge += name.substr(i + 1, pos - 1);
			pos = 0;
		}
	}
	return merge;
}

nodeSV *partition(ds_sv &ds_sv){
	nodeSV *right = ds_sv.tail;
	SinhVien x = right -> value;//pivot ở đuôi
	nodeSV *prev = NULL;
	nodeSV *i = prev;
	nodeSV *left = ds_sv.head;
	nodeSV *j = left;
	while(j != right){
		if(in_name(j -> value.hoTen) <= in_name(x.hoTen)){
			i = (i == NULL) ? left : i = i -> next;
			swap(i, j);
		}
		j = j -> next;
	}
	i = (i == NULL)? left : i -> next;
	swap(i, right);
	return i;
}

void quickSort(ds_sv &ds_sv, nodeSV *left, nodeSV *right){
	if(right != NULL && left != right && left != right -> next){
		nodeSV *p = partition(ds_sv);
		quickSort(ds_sv, left, p -> next);
		quickSort(ds_sv, p -> next, right);
	}
} */

int main(){
    ds_sv ds_sv;
	nodeSV *head;
    //docfile(ds_sv);
	while(1){
		SetColor(7);
		cout << "\n\t\t\t\t-----------------MENU---------------\n";
		cout << "\t\t\t\t1. Nhap sinh vien\n";
		cout << "\t\t\t\t2. Xuat danh sach sinh vien\n";
		cout << "\t\t\t\t3. Xoa sinh vien theo ma\n";
		cout << "\t\t\t\t4. Tim kiem sinh vien theo ma\n";
		cout << "\t\t\t\t5. Sap xep diem trung binh\n";
		cout << "\t\t\t\t6. Diem gpa cao nhat\n";
		cout << "\t\t\t\t7. Xet hoc bong\n";
		//cout << "\t\t\t\t8. HashTable\n";
		cout << "\t\t\t\t8. Doc file\n";
		cout << "\t\t\t\t9. Ghi file\n";
		cout << "\t\t\t\t0. Thoat !\n";
		cout << "\t\t\t\t-------------------------------------\n";
		cout << "\t\t\t\tNhap lua chon :";
		int opt; 
		cin >> opt;
		switch(opt){
			case 1:
			    int amount;
                cout << "Nhap so luong sinh vien: ";
                cin >> amount;
                cin.ignore();
                for(int i = 1; i <= amount; i++){
                    cout << "\n\t\t\t\t---------- Sinh vien: " << i << " -----------" << endl;
                    SinhVien a;
                    cin >> a;
                    addSV(ds_sv, a);
					system("pause");
                }
				break;
			case 2:
                /* cout << setw(5) << left << "ID" << "\t" << setw(30) << left << "Ho ten" << "\t" << setw(10) << left << "Gioi tinh" << "\t" 
                << setw(15) << left << "Ngay sinh" << "\t" << setw(20) << left << "Que quan" << "\t" << setw(10) << left << "Khoa" << "\t" 
                << setw(5) << left << "Gpa" << "\t" << setw(3) << left << "DRL" << "\t" << endl; */
			    inds(ds_sv);
				system("pause");
				break;
			case 3:
			    xoaID(ds_sv);
				system("pause");
				break;
			case 4:
			    SearchID(ds_sv);
				system("pause");
				break;
			case 5: 
			    sapxepTangdan(ds_sv);
				system("pause");
				break;
			case 6:
			    gpaest(ds_sv);
				system("pause");
				break;
			case 7:
			    xethocBong(ds_sv);
				system("pause");
				break;
			/* case 8:
			    nodeSV *hashTable[M];
	            initHash(hashTable);
				nodeSV *p = head;
				while (p != NULL)
				{
					addHashTable(hashTable, p -> value);
					p = p -> next;
				}
				
			    exportFile(hashTable);
				cout << "done." << endl;
				break; */
			case 8:
			    docfile(ds_sv);
                inds(ds_sv);
				system("pause");
				break;
			case 9:
			    ghifile(ds_sv);
				system("pause");
				break;
			case 0:
			    return 0;
			    break;
		}
		system("cls");
	}
	return 0;
}

