/* DANG NGOC MINH
   6251071063
   CNTT - K62
*/
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

struct Queue{
    public:
        Queue();
        Node *createNode(int x);
        int getSize();
        bool isEmpty();
        void enqueue(int x);
        void dequeue();
        void show();
    private:
        Node *head;
        Node *tail;
        int size;
};

Queue::Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

int Queue::getSize(){
    return size;
}

bool Queue::isEmpty(){
    if(size == 0)
        return true;
    else 
        return false;
}

Node *Queue::createNode(int x){
    Node *p = new Node();
    p -> data = x;
    p -> next = NULL;
    return p;
}

void Queue::enqueue(int x){
    Node *p = createNode(x);
    if(head == NULL)
        head = p; 
    else{
        Node *tmp = head;
        while(tmp -> next != NULL)
            tmp = tmp -> next;
        tmp -> next = p;
    }
}

void Queue::dequeue(){
    if(head != NULL){
        Node *p = head;
       head = head -> next;
        p -> next = NULL;
        delete p;
    }
}

void Queue::show(){
    for(Node *i = head; i != NULL; i = i -> next){
        cout << i -> data << " ";
    }
}

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(6);
    q.show();

    cout << endl;
    q.dequeue();
    q.dequeue();
    q.show();
}