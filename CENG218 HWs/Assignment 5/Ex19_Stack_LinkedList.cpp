#include <iostream>

using namespace std;

template<class T>
class LinkedList { 
private:
   struct LinkedNode {
      T elt;
      LinkedNode* next;
      LinkedNode(T elt, LinkedNode* next = nullptr) : elt(elt), next(next) {}
   };

   LinkedNode *first;
   LinkedNode *last;
   int cnt; // easily get the current # of items in the list

public:
   LinkedList() {first= last= 0; cnt=0;}
   bool isEmpty() { return cnt == 0; }
   int count() { return cnt; }
    
   void append(T elt) 
   {
      if (isEmpty()) 
      {
         first = last = new LinkedNode(elt);
      } 
        
      else 
      {
         last->next = new LinkedNode(elt);
         last = last->next;
      }
      
      cnt++;
   }
    
   void insert(T elt, int i = 0) // i=0 first
   {
      if (i < 0 || i > cnt) 
      {
         cout << "Out of range!" << endl;
         return;
      }

      if (i == 0) 
      {
         first = new LinkedNode(elt, first);
         
         if (cnt == 0) 
            last = first;
         
         else if (i == cnt) 
         {
            append(elt);
         } 
         
         else 
         {
            LinkedNode* curr = first;
            
            for (int j = 0; j < i - 1; j++) 
            {
               curr = curr->next;
            }
            
            curr->next = new LinkedNode(elt, curr->next);
         }
        
         cnt++;
      }
   } 
    
   void deleteFirst(T& elt)
   {
      if (isEmpty()) 
      {
         cout << "List is Empty!" << endl;
         return;
      }

      elt = first->elt;
      LinkedNode* temp = first;
      first = first->next;
      delete temp;
      cnt--;
      
      if (cnt == 0) 
      {
         last = nullptr;
      }
   }

   void deleteLast(T& elt)
   {
      if (isEmpty()) 
      {
         cout << "List is Empty!" << endl;
         return;
      }
        
      if (cnt == 1) 
         deleteFirst(elt);
            
      else 
      {
         LinkedNode* curr = first;
            
         while (curr->next != last) 
         {
            curr = curr->next;
         }
            
         elt = last->elt;
         delete last;
         last = curr;
         last->next = nullptr;
         cnt--;
      }
   }
   
   void deleteNth(T& elt, int n)
   {
      if (n < 0 || n >= cnt) 
      {
            cout << "Index is out of range!" << endl;
            return;
      }
        
      if (n == 0) 
         deleteFirst(elt);
      
      else if (n == cnt - 1) 
         deleteLast(elt);
      
      else 
      {
         LinkedNode* curr = first;
         
         for (int i = 0; i < n - 1; i++) 
         {
            curr = curr->next;
         }
            
         LinkedNode* temp = curr->next;
         elt = temp->elt;
         curr->next = temp->next;
         delete temp;
         cnt--;
      }
   }
};

template <class T>
class StackLL {
private:
   LinkedList<T> *data;
   int Top;
   int Capacity;

public:
   StackLL() 
   { 
      data = new LinkedList<T>;
      Top = -1;
      Capacity = 0;
   }

   bool isEmpty() { return data->isEmpty(); }
   int cntElts() { return data->count(); }
   
   void pop(T& x)
   {
      if (isEmpty()) 
      {
         cout << "Stack is Empty!" << endl;
         return;
      }

      data->deleteLast(x);
   }

   void push(T& x)
   {
      data->append(x);
   }
};

int main(int argc, char *argv[]) {
   StackLL<int> S;
   int choice, value;

   do {
      cout << "Stack Operations" << endl;
      cout << "1. Push Element" << endl;
      cout << "2. Pop Element" << endl;
      cout << "3. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;

      switch(choice) {
         case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            S.push(value);
            break;
         
         case 2:
            S.pop(value);
            cout << "Popped value: " << value << endl;
            break;
         
         case 3:
            break;
         
         default:
            cout << "Invalid choice. Please try again." << endl;
      }
   } while (choice != 3);

   return 0;
}