//Program to implement a circular linked list

#include <iostream>
using namespace std;
class list{
  private:
    struct node{
      int data;
      node* next;
      
    }*head;
    
  public:
    list(){
      head=nullptr;
    }
    void insert_begin(int);
    void insert_end(int);
    void display();
    void insert_position(int,int);
    void delete_begin();
    void delete_end();
    void delete_position(int);
    int search(int);
};

int main() {
    list list1;
    int choice, value, position,pos;

    do {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9 Exit\nEnter choice: ";
        cin >> choice;

        switch(choice){
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list1.insert_begin(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list1.insert_end(value);
            break;
        case 3:
            cout << "Enter position : ";
            cin >> position;
            cout<<"Enter value : ";
            cin>>value;
            list1.insert_position(position, value);
            break;
        case 4:
            list1.delete_begin();
            break;
        case 5:
            list1.delete_end();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> position;
            list1.delete_position(position);
            break;
        case 7:
            cout << "Enter value: ";
            cin >> value;
            pos=list1.search(value);
            if (position != -1)
                cout << "Found. " << endl;
            else
                cout << "Not found" << endl;
            break;
        case 8:
            list1.display();
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
            
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);
    
    return 0;
}

//Insert at the beginning
void list::insert_begin(int value){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    if(!head){
        newnode->next=newnode;
        head=newnode;
    }
    else{
        if(head->next==head){
            newnode->next=head;
            head->next=newnode;
            head=newnode;
        }
        else{
            node* temp= head;
            while (temp->next != head) {
            temp = temp->next;
            }
            newnode->next=head;
            head=newnode;
            temp->next=newnode;
        }
    }
}

//display the list
void list::display() {
    if (!head) {
        cout << "Empty list" << endl;
        return;
    }

    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); 

    cout << endl;
}

//Insert at the end
void list::insert_end(int value){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    if(!head){
        newnode->next=newnode;
        head=newnode;
        return;
    }
    if(head->next==head){
        newnode->next=head;
        head->next=newnode;
        return;
    }
    newnode->next=head;
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
}

//Insert at a certain position
void list::insert_position(int position, int value){
    node* newnode=(node*)malloc(sizeof(node));
    if(position==1){
        insert_begin(value);
        return;
    }
    if(position<1){
        cout<<"Invalid position";
    }
    node* temp=head;
    for(int i=1; temp && i<position-1;i++){
        temp=temp->next;
    }
    if(temp->next==head){
        insert_end(value);
        return;
    }
    else{
        newnode->data=value;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

//Delete at the beginning
void list::delete_begin(){
    if(!head){
        cout<<"Empty list";
        return;
    }
    node* temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    temp->next=head;
    temp=temp->next;
    cout<<temp->data<<endl;
    free(temp);
}

//Delete at end
void list::delete_end(){
    if(!head){
        cout<<"Empty list";
        return;
    }
    if(head->next == head){  
        cout << head->data;
        free(head);
        head = NULL; 
        return;
    }
    
    node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    
    node* last = temp->next;  
    temp->next = head;        
    cout << last->data;
    free(last);
}


//Delete a node from a certain position
void list::delete_position(int position){
    if(!head){
        cout<<"Empty list. \n";
        return;
    }
    node* temp=head;
    for(int i=1;temp && i< position-1;i++){
        temp=temp->next;
    }
    if(temp->next->next==head){
        node* delete_el=temp->next;
        temp->next=head;
        cout<<delete_el->data;
        free(delete_el);
    }
    else{
        node* delete_el=temp->next;
        temp->next=temp->next->next;
        cout<<delete_el->data;
        free(delete_el);
        return;
    }
}


//Searching for an element in the list
int list::search(int value){
    node* temp=head;
    if(!head){
        cout<<"Empty list. \n";
        return -1;
    }
    do{
        if(temp->data==value){
            return 1;
        }
        else{
            temp=temp->next;
        }
    }while(temp->next!=head);
    return -1;
    
}