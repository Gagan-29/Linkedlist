#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data= data;
        this -> next= NULL; 
    }
};
void insertAtHead(Node* &head,int d){

    Node* temp=new Node(d);
    temp -> next = head;
    head=temp;
}
void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail -> next= temp;
    tail = temp;  
}
void insertAtPosition(Node* &tail,Node* &head,int pos,int d){
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    int cnt=1;
    Node* temp = head;

    while(cnt<pos-1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert= new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}
void deletenode(Node* &head,Node* &tail,int pos){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        free(temp);
    }
    else{
        int cnt = 1;
        Node* prev = NULL;
        Node* curr = head;
        while(cnt < pos){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr -> next == NULL){
            prev -> next = curr -> next;
            tail = prev;
            free(curr);
            return;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        free(curr);
    }
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<< temp -> data<< " ";
        temp=temp -> next;
    }
    cout<<endl;
}
int main(){
    Node* node1 = new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,15);
    print(head);
    insertAtTail(tail,17);
    print(head);
    insertAtPosition(tail,head,3,20);
    print(head);
    insertAtPosition(tail,head,1,22);
    print(head);
    insertAtPosition(tail,head,7,29);
    print(head);
    deletenode(head,tail,5);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
}