#include <bits/stdc++.h>
//#include "mylib.h"
using namespace std;
#define M 11
static int cnt;

struct Student{
    string name, genDer, date, nativePlace;
    string ID, faculty;
    float gpa = 0;
    int pointTraining = 0;
};

struct nodeSV{	
    Student value;
    nodeSV *next;
};

nodeSV* SortedMerge(nodeSV* a, nodeSV* b);
void FrontBackSplit(nodeSV* source, nodeSV** frontRef, nodeSV** backRef);

void init(nodeSV *&head){
	head = NULL;
}

istream& operator >> (istream &is, Student &s)
{
    ++cnt;
    s.ID = "SV" + string(3-to_string(cnt).length(), '0') + to_string(cnt);
	cout << "\t\t\t\tEnter student name: ";
    getline(is,s.name);
    cout << "\t\t\t\tEnter student gender: ";
    is >> s.genDer;
    cout << "\t\t\t\tEnter student date: ";
    is.ignore();
    getline(is,s.date);
    cout << "\t\t\t\tEnter student native place: ";
    getline(is,s.nativePlace);
    cout << "\t\t\t\tEnter faculty: ";
    getline(is,s.faculty); 
    cout << "\t\t\t\tEnter gpa out of 4: ";
    is >> s.gpa;
	is.ignore();
    cout << "\t\t\t\tEnter ponit training: ";
    is >> s.pointTraining;
	is.ignore(); 
	//----
	return is;
}

nodeSV* createNode(Student x){
    nodeSV *p = new nodeSV;
    p -> value = x;
    p -> next = NULL;
    return p;
}
// b?t d?u c?a Sang 
void deleteID(nodeSV *&head){
	string sID;
	cin.ignore();
	cout << "Enter ID to delete: ";
	cin >> sID;
	nodeSV *p = NULL;
	for(nodeSV *q = head; q != NULL; ){
		if (_stricmp(q->value.ID.c_str(), sID.c_str()) == 0 && q == head){
			head = head -> next;
            delete q;
            q = head;
		}
		else{
			if(_stricmp(q -> value.ID.c_str(), sID.c_str()) == 0){
				p -> next = q -> next;
				delete q;
				q = p;
				if(p -> next == NULL){
					nodeSV *k;
					k = p;
					return;
				}
			}
			p = q;
			q = q -> next;
		}
	}
}

void ascendingOrderName(nodeSV *&head){
	for(nodeSV *p = head; p != NULL; p = p -> next){
		nodeSV *min = p;
		for(nodeSV *q = p -> next; q != NULL; q = q -> next){
			if(q -> value.name < min -> value.name){
				min = q;
			}
		}
		Student tmp = min -> value;
		min -> value = p -> value;
		p -> value = tmp;
	}
}

void fix_SV(nodeSV *&head){
	string posID;
	cout << "Enter ID to fix: ";
	cin >> posID;
	for(nodeSV *p = head; p != NULL; p = p -> next){
		if(p -> value.ID == posID){
			int info;
			cout << "\t\t=======================" << endl;
			cout << "\t\t1. Name " << endl;
			cout << "\t\t2. Gender " << endl;
			cout << "\t\t3. Date " << endl;
			cout << "\t\t4. Native place " << endl;
			cout << "\t\t5. Faculty " << endl;
			cout << "\t\t6. Gpa " << endl;
			cout << "\t\t7. Point Training " << endl;
			cout << "\t\t=======================" << endl;

			cout << "Enter info u wanna fix: ";
			cin >> info;

			switch(info){
				case 1:
				    cout << "New name: ";
					cin.ignore();
					getline(cin, p -> value.name);
					break;
				case 2:
				    cout << "New Gender: ";
					cin >> p -> value.genDer;
					break;
				case 3:
				    cout << "New Date: ";
					cin.ignore();
					getline(cin, p -> value.date);
					break;
				case 4: 
				    cout << "New Native Place: ";
					cin.ignore();
					getline(cin, p -> value.nativePlace);
					break;
				case 5:
				    cout << "New Faculty: ";
					getline(cin, p -> value.faculty);
					break;
				case 6:
				    cout << "New Gpa: ";
					cin >> p -> value.gpa;
					break;
				case 7:
				    cout << "New Point Training: ";
					cin >> p -> value.pointTraining;
					break;
				case 8:
				    cout << "Choose wrong: ";
					break;
			}
		}
	}
}
int main(){
	nodeSV *head;
	init(head);
	nodeSV *hashTable[M];
//	initHash(hashTable);
	nodeSV *p = head;
	while(1){
		//SetColor(7);
		cout << "\n\t\t\t\t-----------------MENU---------------\n";
		cout << "\t\t\t\t1. Nhap sinh vien\n";
		cout << "\t\t\t\t2. Xuat danh sach sinh vien\n";
		cout << "\t\t\t\t3. delete sinh vien theo sID\n";
		cout << "\t\t\t\t4. Tim kiem sinh vien theo sID\n";
		cout << "\t\t\t\t5. Sap xep diem trung binh\n";
		cout << "\t\t\t\t6. Diem gpa cao nhat\n";
		cout << "\t\t\t\t7. Xet hoc bong\n";
		cout << "\t\t\t\t8. HashTable\n";
		cout << "\t\t\t\t9. Doc file\n";
		cout << "\t\t\t\t10. Ghi file\n";
		cout << "\t\t\t\t11. Sort by pointTraining\n";
		cout << "\t\t\t\t12. Sort by name\n";
		cout << "\t\t\t\t13. Fix \n";
		cout << "\t\t\t\t0. Thoat !\n";
		cout << "\t\t\t\t-------------------------------------\n";
		cout << "\t\t\t\tNhap lua chon :";
	int opt;  
		cin >> opt;
		switch(opt){
			case 1:
			    int amount;
                cout << "Enter the number of student: ";
                cin >> amount;
                cin.ignore();
                for(int i = 1; i <= amount; i++){
                    cout << "\n\t\t\t\t---------- Student: " << i << " -----------" << endl;
                    Student a;
                    cin >> a;
                    //addSV(head, a);
					system("pause");
                }
			case 3:
			    deleteID(head);
				system("pause");
				break;
			case 4:
			    //SearchID(head);
				system("pause");
				break;
			case 5: 
			    ascendingOrderName(head);
				system("pause");
				break;
				}
		system("cls");
	}
	return 0;
}

