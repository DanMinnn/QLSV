// #pragma once
// #include "funcprotoType.hpp"

#pragma once
#include <bits/stdc++.h>
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

void init(nodeSV *&head);
istream& operator >> (istream &is, Student &s);
nodeSV* createNode(Student x);
void addSV(nodeSV *&head, Student x);
void insv(Student s);
void inSet();
void inds(nodeSV *head);
void readFile(nodeSV *&head);
void writeFile(nodeSV *&head);

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

void addSV(nodeSV *&head, Student x){
	nodeSV *p = createNode(x);
	if (head == NULL)//rỗng: đầu cuối = p
		head = p;
	else//n pt => Thêm cuối
	{
        nodeSV *tmp = head;
		while(tmp -> next != NULL)
            tmp = tmp -> next;
        tmp -> next = p;
	}
}

void insv(Student s){ 
    cout << setw(5) << left << s.ID << "|" << "\t";
    cout << setw(30) << left << s.name << "|" << "\t";
    cout << setw(10) << left << s.genDer << "|" << "\t";
    cout << setw(15) << left << s.date << "|" << "\t";
    cout << setw(20) << left << s.nativePlace << "|" << "\t";
    cout << setw(20) << left << s.faculty << "|" << "\t";
    cout << setw(5) << left << s.gpa << "|" << "\t";
    cout << setw(16) << left << s.pointTraining << "|" << "\t" << endl;

} 

void inSet(){
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(5) << left << "ID" << "|" << "\t" << setw(30) << left << "Name" << "|" << "\t" << setw(10) << left << "Gender" << "|" << "\t" 
    << setw(15) << left << "Date" << "|" << "\t" << setw(20) << left << "Native place" << "|" << "\t" << setw(20) << left << "Faculty" << "|" << "\t" 
    << setw(5) << left << "Gpa" << "|" << "\t" << setw(16) << left << "Point Training" << "|" << "\t" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void inds(nodeSV *head){
	inSet();
    int i = 1;
	for (head; head != NULL; head = head -> next)
	{
	    insv(head -> value);
	}
}

void readFile(nodeSV *&head)
{
	ifstream f;
    f.open("qlsv.txt", ios::in);
	cout << "processing...\n";
	while (f.eof() == false)
	{
		Student a;//để lưu tạm dữ liệu load từ file
        f >> a.ID;
		string tmp;//luu bien tam de doc ki tu xuong dong o cuoi dong
		getline(f, tmp);
		getline(f, a.name);
		f >> a.genDer;
		getline(f, tmp);
		getline(f, a.date);
		getline(f, a.nativePlace);
        getline(f, a.faculty);
        f >> a.gpa;
        f >> a.pointTraining;
		addSV(head, a);	

	}
	f.close();
}

void writeFile(nodeSV *&head){
	ofstream f;
	f.open("sv.txt", ios::app);
	nodeSV *p = head;
	while (p != NULL){
		f << "ID: " << p -> value.ID << endl;
		f << "Name: " << p -> value.name << endl;
        f << "Gender: " << p -> value.genDer << endl;
        f << "Native place: " << p -> value.nativePlace << endl;
        f << "Faculty: " << p -> value.faculty << endl;
        f << "gpa score: " << p -> value.gpa << endl;
        f << "Point training: " << p -> value.pointTraining << endl;
		f << "==================" << endl;
		p = p -> next;
	}
	cout << "Wrote file !";
}
