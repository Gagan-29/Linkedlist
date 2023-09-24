#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
void insert(Node* &tail,int element,int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp -> next = temp;
    }
    else{
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void deletenode(Node* &tail,int value){
    if(tail == NULL ){
        cout<<"The list is empty ";
        return;
    }
    else{
        Node* prev = tail; 
        Node* curr = prev -> next;
        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        if(curr == prev){
            tail = NULL;
        }
        else if(tail == curr){
            tail = prev;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        free(curr);
    }
    
}
void print(Node* &tail){
    Node* temp = tail;
    do{
        cout << tail -> data<<" ";
        tail = tail -> next;
    }
    while(tail != temp);
    cout<<"\n";
}
int main(){
    Node* tail =NULL;
    insert(tail,3,3);
    print(tail);
    insert(tail,3,5);
    print(tail);
    insert(tail,5,6);
    print(tail);
    insert(tail,5,10);
    print(tail);
    deletenode(tail,5);
    print(tail);
}