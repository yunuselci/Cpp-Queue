#include <iostream>
using namespace std;

class QueueNode{
public:
    int data;
    QueueNode* next;
    QueueNode (const int& data = 0, QueueNode* next = NULL) : data(data) , next(next){}
};
class Queue{
    QueueNode* root;
    int length;
    void makeEmpty(){
        while(!isEmpty())
            dequeue();
    }
public:
    Queue() : root(NULL),length(0){}
    ~Queue(){ makeEmpty(); }
    Queue& operator=(const Queue& rhs){ return assign(rhs); }
    Queue& assign(const Queue& rhs){
        makeEmpty();
        QueueNode* tmp = rhs.root;
        while(tmp != NULL){
            enqueue(tmp->data);
            tmp = tmp->next;
        }
        return *this;
    }
    bool isEmpty()const{ return root==NULL;}

    void enqueue(const int& value){
        if(isEmpty())
            root = new QueueNode(value);
        else{
            QueueNode* tmp = root;
            while(tmp-> next != NULL)
                tmp = tmp->next;
            tmp->next = new QueueNode(value);
        }
        ++length;
    }

    void dequeue(){
        if(isEmpty())
            cout << "Kuyruk bos oldugu icin eleman cikarması yapamadik.";
        QueueNode* tmp = root;
        root = root->next;
        delete tmp;
        --length;
    }

    int size()const{
        int counter = 0;
        QueueNode* tmp = root;
        if(isEmpty())
            cout << "Kuyruk Bos";
        while(tmp != NULL){
            tmp = tmp ->next;
            ++counter;
        }
        return counter;
    }

    int front()const{
        if(isEmpty())
            cout << "Error!";
        return root->data;
    }
/*
    int back()const{
        QueueNode* tmp = root->next;
        if(isEmpty())
            cout << "Error!";
        while(tmp!=NULL)
            tmp = tmp->next;
        return tmp->data;
    }
*/
    int Length()const{
        return length;
    }

    void print()const{
        QueueNode* tmp = root;
        while(tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp -> next;
        }
    }


};

int main() {

}