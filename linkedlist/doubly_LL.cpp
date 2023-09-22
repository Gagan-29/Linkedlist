#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }
};
void insertAtHead(Node* &tail,Node* &head,int d){
    if( head == NULL ){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node*temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
}
void insertAtTail(Node* &head,Node* &tail,int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}
void insertAtPos(Node* &head,Node* &tail,int pos,int d){
    Node* temp = head;
    if(pos == 1){
        insertAtHead(tail,head,d);
        return;
    }
    int cnt=1;
    while(cnt < pos-1){
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == NULL){
        insertAtTail(head,tail,d);
        return;
    }
    Node* nodeToInsert= new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
    
}
void deletion(Node* &tail,Node* &head,int pos){
    
    if( pos == 1 ){
        Node* temp =head;
        head = temp -> next;
        temp -> next -> prev = NULL;
        temp -> next = NULL;
        free(temp);
    }
    else{
        Node* curr = head;
        Node* previous =NULL;
        int cnt=1;
        while(cnt < pos){
            previous = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr -> next == NULL){
            curr -> prev =NULL;
            previous -> next = NULL ;
            tail = previous;
            free(curr);
        }
        else{
            curr -> prev = NULL;
            previous -> next = curr -> next ;
            curr -> next -> prev = previous;
            curr -> next = NULL;
            free(curr);
        }
        
    }
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main(){
    // Node* node1=new Node(10);
    // Node* head = node1;
    // Node* tail = node1;
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(tail,head,12);
    print(head);
    insertAtTail(head,tail,22);
    print(head);
    insertAtPos(head,tail,2,29);
    print(head);
    insertAtPos(head,tail,1,23);
    print(head);
    insertAtPos(head,tail,5,18);
    print(head);
    insertAtPos(head,tail,6,100);
    print(head);
    insertAtPos(head,tail,1,101);
    print(head);
    deletion(tail,head,3);
    print(head);
    deletion(tail,head,1);
    print(head);
    deletion(tail,head,2);
    print(head);

    cout << "head  " << head -> data << endl;
    cout<< "tail  "  << tail -> data <<endl;
}