#include <iostream>
#include<queue>
using namespace std;

class Node
{
  public:
  int data;
  Node *next;

  // Defining the constructor of LL
  Node(int element)
  {
    this->data = element;
    next = NULL;
  }

};

void reverseQueue(queue<int> &input) 
{
  Node *head = NULL;

  // From queue to LL 
  
  while(!input.empty())
  {
    // Create an new node 
    Node *new_node = new Node(input.front());

    if(head == NULL)
    {
      head = new_node;
    }
    else
    {
      new_node->next = head;
      head = new_node;
    }

    input.pop();
  }

  // Storing the element from LL to queue 

  while(head != NULL)
  {
    input.push(head->data);

    Node *a = head;
    head = a->next;

    delete a;
  }

}


int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}