#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Node(){
    //     next = NULL;
    // }
};

class LinkedList
{
    Node *head = new Node();
    

public:
    void insert_at_begining(int data);
    void insert_at_end(int data);
    void insert_at_pos(int pos, int data);
    void delete_at_begining();
    void delete_at_end();
    void delete_at_pos();
    void print();
    bool check_empty();
    
    LinkedList(){
        if(head==NULL){
        cout<< "list is empty"<<endl;
        return;
        }
        Node *temp = new Node();
          temp = head;
        head=temp->next;
        delete(temp);

    }


};


//checking NULL List
bool LinkedList::check_empty(){
    if(head==NULL){
        cout<< "list is empty"<<endl;
        return 1;
    }
    return 0;
}

void LinkedList::print(){
    if(check_empty()) return;
    Node *temp  = new Node()  ;
    temp = head;
    while (temp!=NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }

    cout << endl;
    // delete(temp);
}

//Inserting a Node
void LinkedList::insert_at_begining(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;

    if (head==NULL)
    {
        head = temp;
        return;
    }
    head = temp;
    // free(temp);
}




void LinkedList::insert_at_end(int data)
{
    Node *temp = new Node();
    temp = head;
    if (head == NULL)
    {
                head->data = data;
                head->next = NULL;
                return;
     }
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
        Node *temp1 = new Node();

    
    temp1->data = data;
    temp1->next = NULL;
    temp->next= temp1;
    
    }


void LinkedList::insert_at_pos(int pos,int data){
         if(head==NULL) {
             cout << "list is empty" << endl;
         }
         Node *temp = new Node();
         temp = head;
         while(pos-1>1){
             temp = temp->next;
             pos--;
         }
         Node *tempdata = new Node();
         tempdata->data = data;
         tempdata->next = temp->next;
         temp->next = tempdata;
}


void LinkedList::delete_at_begining(){
    if(head==NULL){
        cout<< "list is empty"<<endl;
        return;
    }
    Node *temp = new Node();
          temp = head;
        head=temp->next;
        delete(temp);

}

void LinkedList::delete_at_end(){
    if(check_empty()){
        cout<<"List is empty"<<endl;
        return;
    }
    Node *temp = new Node();
    temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;

    }
    delete(temp);
    

}


int main(){

    LinkedList list ;
    list.print();

    list.insert_at_begining(5);
    list.insert_at_begining(7);
    list.insert_at_begining(6);
    list.print();

    list.insert_at_end(4);
    list.insert_at_end(9);
    list.insert_at_end(9);
    list.insert_at_end(9);
    list.insert_at_pos(2, 11);
    list.insert_at_begining(6);

    list.print();
    
    list.delete_at_begining();
    list.print();
    
    list.delete_at_end();
    list.print();

    return 0;
}
