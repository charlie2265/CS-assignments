/******************************************************************************

Charlie Ritter
cs161 Priestley Spring 2024
Week 10 lab1 cpp DLL 
Double Linked List program,
Permission granted to only the instructor to use this code for weekly program.
sources: Text (Gaddis) and charliewk9.cpp/cs161 
*******************************************************************************/
#include <iostream>

using namespace std;

class Node {
    protected:
        int data;
        Node* next, *prev;
    public:
        Node(): data{0}, next{nullptr}, prev{nullptr} {}
        // parameterized constructor
        Node(int a_data): data{a_data}, next{nullptr}, prev{nullptr} {}
        // getters accessors
        int getData() const {return data;}
        Node* getNext() const {return next;}
        Node* getPrev() const {return prev;}
        // setters mutators
        void set_next(Node* a_next) {next = a_next;}
        void set_prev(Node* a_prev) {prev = a_prev;}
        void set_data(int a_data) {data = a_data;}

};

// add comments
class DLL {
    protected:
        Node* head, *tail;

    public:
    DLL(): head{nullptr}, tail{nullptr} {}
    void append (Node*);
    void display(int direction = 1);
    bool insert_after(Node*,int);

        
};
//
//
//
void DLL::append(Node* target){

    if (target == nullptr) 
        return;   // Client should have sent a pointer to a node to be appended

    target -> set_next(nullptr); // end of list

    if(tail == nullptr){
        head = target;
        target -> set_prev(nullptr); // first

    }
    else {
        tail -> set_next(target);
        target -> set_prev(tail);
    }

    tail = target;

    
}


void DLL::display(int direction){

    Node *curr {}; // current node

    if(direction == -1)
        cout << "Displaying the list in reverse: " << endl;
    else
        cout << "Displaying the list: " << endl;

    if(direction == 1){
        curr = head;
        while(curr != nullptr){
            cout << curr -> getData() << endl;
            curr = curr -> getNext();
        }
    }
    else{
        curr = tail;
        while (curr != nullptr){
            cout << curr -> getData() << endl;
            curr = curr -> getPrev();
        }
    }
    cout << endl;


}


bool DLL::insert_after(Node* node_ptr, int value){
    Node *curr = head;

    while(curr != nullptr && curr -> getData() != value)
        curr = curr -> getNext();
    
    if(curr == nullptr)
        return false;
    
    if(curr-> getNext() == nullptr)
        append(node_ptr);
    else{
        node_ptr -> set_prev(curr);
        node_ptr -> set_next(curr -> getNext());
        curr -> set_next(node_ptr);

    return true;
    
    }
}

int main() {
    DLL dll;
    Node *node_ptr;

    // this is all testing code
    cout << "Linked List Program" << endl;
    dll.display(); 
    node_ptr = new Node(15);
    dll.append(node_ptr);
    dll.display();
    dll.append(new Node(25));
    dll.display();
    dll.display(-1); // reverse
    dll.append(new Node(35));
    dll.display();
    dll.display(-1); // reverse

    node_ptr = new Node(5);

    if(!dll.insert_after(node_ptr, 15))
        cout << "Insert failed" << endl;
    dll.display();
    return 0;
}