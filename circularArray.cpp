#include<iostream>
using namespace std;
#define MaxLength 100

struct Buffe{
    int Elements[MaxLength];
    int Write, Read;
};

void makeQueue(Buffe *q){
    q -> Write = -1;
    q -> Read = -1;
}

bool isEmpty(Buffe q){
    return q.Write == -1;
}

bool isFull(Buffe q){
    return (q.Read - q.Write + 1) % MaxLength == 0;
}

int front(Buffe q){
    return q.Elements[q.Write];
}
void enQueue(Buffe *q, int x){
    if(isFull(*q))
        cout << "Mang day !\n";
    else{
        if(isEmpty(*q))
            q -> Write = 0;
        q -> Read = (q -> Read + 1) % MaxLength;
        q -> Elements[q -> Read] = x;
    }
}

void deQueue(Buffe *q){
    if(isEmpty(*q))
        cout << "Mang rong !\n";
    else if(q -> Write == q -> Read)
        makeQueue(q);
    else   
        q -> Write = (q -> Write + 1) % MaxLength;
}

void readQueue(Buffe *q){
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Nhap phan tu thu " << i << ":";
        cin >> x;
        enQueue(q, x);
    }
}

void show(Buffe q){
    cout << "Phan tu trong mang: \n";
    while(!isEmpty(q)){
        cout << front(q) <<  " ";
        deQueue(&q);
    }
}

int main(){
    Buffe Q;
    makeQueue(&Q);
    readQueue(&Q);
    show(Q);
}
