#pragma once
#include "funcSearch.hpp"

int menu();

int menu(){
    nodeSV *head;
	init(head);
	nodeSV *hashTable[M];
	initHash(hashTable);
	nodeSV *p = head;
	while(1){
		// cout << "\n\t\t\t\t-----------------MENU---------------\n";
		// cout << "\t\t\t\t1. Nhap sinh vien\n";
		// cout << "\t\t\t\t2. Xuat danh sach sinh vien\n";
		// cout << "\t\t\t\t3. delete sinh vien theo ID\n";
		// cout << "\t\t\t\t4. Tim kiem sinh vien theo ID\n";
		// cout << "\t\t\t\t5. Sap xep diem trung binh\n";
		// cout << "\t\t\t\t6. Diem gpa cao nhat\n";
		// cout << "\t\t\t\t7. Xet hoc bong\n";
		// cout << "\t\t\t\t8. HashTable\n";
		// cout << "\t\t\t\t9. Doc file\n";
		// cout << "\t\t\t\t10. Ghi file\n";
		// cout << "\t\t\t\t11. Sort by pointTraining\n";
		// cout << "\t\t\t\t12. Sort by name\n";
		// cout << "\t\t\t\t13. Fix \n";
		// cout << "\t\t\t\t0. Thoat !\n";
		// cout << "\t\t\t\t-------------------------------------\n";
		// cout << "\t\t\t\tNhap lua chon :";
		//system("cls");
        cout << setw(135) <<"----------------------- MANAGEMENT STUDENT ----------------------"  << endl;
        cout << setw(135) <<"|================================================================|" << endl;
        cout << setw(135) <<"|-----               Class: CTDL K62 - GROUP 7              -----|" << endl;
        cout << setw(135) <<"|================================================================|" << endl;
        cout << setw(135) <<"|================================================================|" << endl;
        cout << setw(135) <<"| 1-Enter student                               7-Scholarship    |" << endl;
        cout << setw(135) <<"| 2-Print list of student                       8-Sort by pointT |" << endl;
        cout << setw(135) <<"| 3-Delete ID                                   9-Sort by gpa    |" << endl;
        cout << setw(135) <<"| 4-Search ID                                  10-Read file      |" << endl;                           
        cout << setw(135) <<"| 5-Ascending Order Name                       11-Write file     |" << endl; 
        cout << setw(135) <<"| 6-The highest gpa                            12-Fix info       |" << endl;
        cout << setw(135) <<"|-------                  0-Exit program                    -----|" << endl;    
        cout << setw(135) <<"|================================================================|" << endl;
        cout << setw(135) <<"------------------------------------------------------------------" << endl;
        cout << setw(90)  <<"What is your choice: ";
		
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
                    addSV(head, a);
					system("pause");
                }
				break;
			case 2:
			    inds(head);
				system("pause");
				break;
			case 3:
			    deleteID(head);
				system("pause");
				break;
			case 4:
			    SearchID(head);
				system("pause");
				break;
			case 5: 
			    ascendingOrderName(head);
				system("pause");
				break;
			case 6:
			    gpaEst(head);
				system("pause");
				break;
			case 7:
			    wonScholarShip(head);
				system("pause");
				break;
			case 8:
			    cout << "processing...\n";
				while (p != NULL)
				{
					addToHashTable(hashTable, p -> value);
					p = p -> next;
				}
				inFaculty(hashTable);
				cout << "done." << endl;
				system("pause"); 
				break;
			case 9:
			    MergeSort(&head);
				inds(head);
				system("pause");
				break;
			case 10:
			    cout << "Sort by name: \n";
				quickSort(head, lastNode(head));
				system("pause");
				break;
			case 11:
			    readFile(head);
                inds(head);
				system("pause");
				break;
			case 12:
			    writeFile(head);
				system("pause");
				break;
			case 13:
			    fix_SV(head);
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
