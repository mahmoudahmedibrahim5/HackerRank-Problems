#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache:Cache
{
public:
    LRUCache(int c)
    {
        cp = c;
        head = new Node(0 , 0);
        tail = new Node(0 , 0);
        head->prev = NULL;
        tail->next = NULL;
    }
    
    void set(int key, int value)
    {
        bool found = false;
        
        for(const auto& pair : mp)
        {
            if(pair.second->key == key){
                found = true;
                pair.second->value = value;
            }
        }
        if(!found){
            if((int)mp.size() == cp){
                auto last = tail->prev;
                last->key = key;
                last->value = value;
            }
            else if((int)mp.size() == 0){
                Node* n = new Node(key, value);
                head->next = n;
                n->prev = head;
                n->next = tail;
                tail->prev = n;
                mp.insert(make_pair(key, n));
            }
            else{
                Node* first = head->next;
                Node* n = new Node(key, value);
                head->next = n;
                n->prev = head;
                n->next = first;
                first->prev = n;
                mp.insert(make_pair(key, n));
            }
                
        }
    }
    
    int get(int key)
    {
        int result = -1;
        for(auto& pair : mp)
        {
            if(pair.second->key == key)
                result = pair.second->value;
        }
        return result;
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
