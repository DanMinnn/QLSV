#include "funcSort.hpp"

void deleteID(nodeSV *&head);
void fix_SV(nodeSV *&head);
void gpaEst(nodeSV *&head);
void wonScholarShip(nodeSV *&head);
nodeSV *middle(nodeSV *start, nodeSV *last);
void SearchID(nodeSV *&head);
void initHash(nodeSV *heads[]);
int hashFunc(string s);
void addToHashTable(nodeSV *heads[], Student x);
void inFaculty(nodeSV *heads[]);

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

void gpaEst(nodeSV *&head){//
	double res = 0;
	for(nodeSV *p = head; p != NULL; p = p -> next){
		if(p -> value.gpa > res){
			res = p -> value.gpa;
		}
	}
	cout << "List of students with the highest gpa score: \n";
	for(nodeSV *p = head; p != NULL; p = p -> next){
		if(res == p -> value.gpa){
			inSet();
			insv(p -> value);	
		}
	}
}

void wonScholarShip(nodeSV *&head){
	cout << "List of student who won the scholarship: \n";
    int tag = 0;
	for(nodeSV *p = head; p != NULL; p = p -> next){
		if(p -> value.gpa >= 3.7 && p-> value.gpa <= 4.0 && p -> value.pointTraining >= 80 && p -> value.pointTraining <= 100){
            tag = 1;
			inSet();
			insv(p -> value);
		}
	}
    if(tag == 0){
        cout << "\nNo student won the scholarship!";
    }
}

nodeSV *middle(nodeSV *start, nodeSV *last){
	if (start == NULL)
		return NULL;

	nodeSV* slow = start;
	nodeSV* fast = start -> next;

	while (fast != last)
	{
		fast = fast -> next;
		if (fast != last)
		{
			slow = slow -> next;
			fast = fast -> next;
		}
	}

	return slow;
}

void SearchID(nodeSV *&head){
	nodeSV *start = head;
	nodeSV *last = NULL;
	int flag = 0;
	string id;
    cout << "Enter ID to find: ";
    cin >> id;

	do{
		// Find middle
		nodeSV* mid = middle(start, last);

		// If middle is empty
		if (mid == NULL){
			cout << "No ID to search! ";
			//system("pause");
			break;	
		}
		// If value is present at middle
		if (mid -> value.ID == id){
			inSet();
			insv(start -> value);
			break;
		}

		// If value is more than mid
		else if (mid -> value.ID < id)
			start = mid -> next;

		// If the value is less than mid.
		else
			last = mid;

	} while (last == NULL || last != start);
}

/* void initHash(nodeSV *heads[]){
	for(int i = 0; i < M; i++){
		heads[i] = NULL;
	}
}

int hashFunc(string s){
	int h = 0;
	for(int i = 0; i < s.length(); i++){
		h += ((int)s[i]) * (i + 1);
	}
	return h % M; 
}

void addToHashTable(nodeSV *heads[], Student x){
	int hash = hashFunc(x.faculty);
	addSV(heads[hash], x);		
}
 */
void inFaculty(nodeSV *heads[]){
	for(int i = 0; i < M; i++)
		if(heads[i] != NULL){
			int cnt = 0;
			string kq = "";
			nodeSV *p = heads[i];

			while(p != NULL){
				cnt++;
				kq += "Name: " + p -> value.name + "\n";
				p = p -> next;
			}

			p = heads[i];
			cout << "====" << p -> value.faculty << ": " << cnt << "SV" << endl;
			cout << kq;
		}
}
