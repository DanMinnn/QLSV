// #pragma once
// #include <bits/stdc++.h>
// using namespace std;
// #define M 11
// static int cnt;

// struct Student{
//     string name, genDer, date, nativePlace;
//     string ID, faculty;
//     float gpa = 0;
//     int pointTraining = 0;
// };

// struct nodeSV{	
//     Student value;
//     nodeSV *next;
// };

// void init(nodeSV *&head);
// istream& operator >> (istream &is, Student &s);
// nodeSV* createNode(Student x);
// void addSV(nodeSV *&head, Student x);
// void insv(Student s);
// void inSet();
// void inds(nodeSV *head);
// void readFile(nodeSV *&head);
// void writeFile(nodeSV *&head);

// nodeSV* SortedMerge(nodeSV* a, nodeSV* b);
// void FrontBackSplit(nodeSV* source, nodeSV** frontRef, nodeSV** backRef);
// void deleteID(nodeSV *&head);
// void ascendingOrderName(nodeSV *&head);
// void fix_SV(nodeSV *&head);
// void gpaEst(nodeSV *&head);
// void wonScholarShip(nodeSV *&head);
// nodeSV *middle(nodeSV *start, nodeSV *last);
// void SearchID(nodeSV *&head);
// void MergeSort(nodeSV** headRef);
// nodeSV* SortedMerge(nodeSV* a, nodeSV* b);
// void FrontBackSplit(nodeSV* source, nodeSV** frontRef, nodeSV** backRef);
// void initHash(nodeSV *heads[]);
// int hashFunc(string s);
// void addToHashTable(nodeSV *heads[], Student x);
// void inFaculty(nodeSV *heads[]);
// nodeSV *lastNode(nodeSV *head);
// nodeSV *partition(nodeSV *first, nodeSV *last);
// void quickSort(nodeSV *first, nodeSV *last);
