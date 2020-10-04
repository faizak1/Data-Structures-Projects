#include <iostream>
using namespace std;
class Node{
 public:
    int data;
    Node *next;
};
class LinkedList{
private:
    Node *first;
public:
    LinkedList(){first=NULL;}
    LinkedList(int arr[],int n);
    ~LinkedList();
    void Display();
    void Insert(int index,int x);
    int Delete(int index);
    void deleteAllOccurences(int key);
    void deletefirstOccurence(int key2);
    void reverseLinkedList();
    int Length();
};
LinkedList::LinkedList(int arr[],int n)
{
    Node *last,*t;
    int i=0;
    first=new Node;
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
LinkedList::~LinkedList()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}
void LinkedList::Display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int LinkedList::Length()
{
    Node *p=first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void LinkedList::Insert(int index,int x){
    Node *t,*p=first;
    
    if(index <0 || index > Length())
    return;
    t=new Node;
    t->data=x;
    t->next=NULL;
    
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
int LinkedList::Delete(int index){
    Node *p,*q=NULL;
    int x=-1;
    if(index < 0 || index > Length()-1)
    return -1;
    if(index==0)
    {
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else{
        p=first;
        //for(int i=0;i<index-1;i++)
        for(int i=0;i<index;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}
void LinkedList::deleteAllOccurences(int key) 
{ 
    Node *temp = first;
    Node *prev = first;
    while (temp != NULL) {
        if (temp->data == key) {
            if (temp == first) {
                first = temp->next;
                prev = first;
                delete temp;
                temp = first;
            }
            else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    return;
} 
void LinkedList::deletefirstOccurence(int key2) 
{ 
    Node *temp = first;
    Node *prev = first;
    bool found = false;
    while (temp != NULL && found ==false) {
        if (temp->data == key2) {
            found = true;
            if (temp == first) {
                first = temp->next;
                prev = first;
                delete temp;
                temp = first;
            }
            else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    return;
} 
void LinkedList::reverseLinkedList(){
    Node* current = first; 
    Node *prev = NULL, *next = NULL; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    first = prev;
}
int main()
{
    int arr[5], insertNum, insertPos, elem, key, key2;
    char rerun, reverseOrNot;
    cout << "Enter a list of 5 numbers to include in the linked list: ";
    for (int i=0; i<5; i++){
        cin>> arr[i];
    }
    LinkedList l(arr,5);
    cout << "Would you like to reverse this linked list?: (y/n)" <<endl;
    cin >> reverseOrNot;
    if (toupper(reverseOrNot)== 'Y'){
        l.reverseLinkedList();
        l.Display();
    }
    do {
        cout << "What number would you like to insert? : ";
        cin>> insertNum;
        cout << "What position would you like to insert this number? (list positions start from 0) : "; 
        cin>> insertPos;
        l.Insert(insertPos, insertNum);
        l.Display();
        cout <<"Would you like to insert another number in the linked list? : (y/n)";
        cin >> rerun;
    } while (toupper(rerun)== 'Y');
    cout << "Which element position would you like to delete (list positions start from 0): "; 
    cin >> elem;
    l.Delete(elem);
    l.Display();
    cout << "Which element key would you like to delete all occurrences of : "; 
    cin >> key;
    l.deleteAllOccurences(key);
    l.Display();
    cout << "Which element key would you like to delete the first occurrences of : "; 
    cin >> key2;
    l.deletefirstOccurence(key2);
    l.Display();
    cout <<"Thanks for interacting with my program!" <<endl;
    return 0;
}