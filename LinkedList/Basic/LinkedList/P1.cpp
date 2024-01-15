//Insert,Print,Delete,Revers,size,mid,loop
// Created by Sift Ali on 1/15/2024.
//

#include <iostream>

using  namespace std;

class LL{
    class  Node{
    public:
        string data;
        Node* next;
        Node(string data){
            this->data=data;
            this->next= nullptr;
        }
    };
public:
    Node* head;

    LL(){
        this->head= nullptr;
    }

//////////////Insert//////

    void Insert(string value) {
        Insert(head, value);
    }

    void Insert(Node*& current, string value) {
        if (current == nullptr) {
            current = new Node(value);
        } else {
            Insert(current->next, value);
        }
    }

///////size////

    void size(){
        if( head== nullptr) {
            cout<<"List is Empty";
            return;
        }
         else {
            cout << "Size: " << calculateSize(head) << endl;
         }
      }

    int calculateSize(Node* currentNode) {
        if (currentNode == nullptr) {
            return 0;
        } else {
            return 1 + calculateSize(currentNode->next);
        }
    }

///////////////Mid/////////////

   void mid() {
       if( head== nullptr) {
           cout<<"List is Empty";
           return;
       }
       else{
           Node* midNode = mid(head, head);
           cout << "Middle Node: " << midNode->data << endl;
       }
    }

   Node* mid(Node*& slow,Node*& fast) {
     //  if (fast==nullptr || fast->next== nullptr)
     if (!fast || !fast->next){
         return slow;
     }
     return mid(slow->next, fast->next->next);
   }

///////////////Loop detection////

    void LoopDetection() {
        if( head== nullptr) {
            cout<<"List is Empty";
            return;
        }
        bool result = Loop(head, head->next->next);
        if(result) cout<<"Loop Detected "<<endl;

        else cout<<"Loop Not Detected "<<endl;

    }

    bool Loop(Node*& slow,Node*& fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        if (slow == fast || slow == fast->next){
            return true;
        }

        return Loop(slow->next, fast->next->next);
    }

///////////////Revers/////////////

    void Revers( ) {
        if( head== nullptr) {
            cout<<"List is Empty";
            return;
        }
        cout<<"Revers LinkedList : ";
        ReversPrint(head);
        cout<<endl;
    }

    void ReversPrint(Node*& currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            ReversPrint(currentNode->next);
            if(currentNode->next!= nullptr) cout<<"->";
                cout<<currentNode->data;
        }
    }
/////////////// clear////////////////
 void clearList(){
        if( head== nullptr) {
            cout<<"List is Empty";
            return;
        }
        clearList(head);
        head = nullptr;
        cout << "Linked List Cleared" << endl;

    }
    void clearList(Node*& currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            Node* nextNode = currentNode->next;
            delete currentNode;
            clearList(nextNode);
        }
    }
///////////////PRINT//////////////////

    void PrintList( ) {
        if( head== nullptr) {
            cout<<"List is Empty";
            return;
        }
        cout<<"Print LinkeList : ";
        PrintList(head);
        cout<<endl;
    }

    void PrintList(Node*& currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            cout<<currentNode->data;
            if(currentNode->next!= nullptr) cout<<"->";
            PrintList(currentNode->next);
        }
    }
};

int main(){
    LL list;
    list.Insert("1");
    list.Insert("2");
    list.Insert("3");
    list.Insert("4");
    list.Insert("5");
    list.Insert("6");
    list.PrintList();
    list.Revers();
    list.mid();
    list.size();

    // Creating a loop from the last node to the second node
    //   list.head->next->next->next->next->next = list.head->next;
    list.LoopDetection();
  //  list.clearList();
   // list.PrintList();


}
