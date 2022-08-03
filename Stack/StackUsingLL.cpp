// Making an generalize stack which store any data type 

template<typename T>
// Class for linked list 
class Node
{
  public:

  T data;
  Node<T> *next;

  // Constructor of LL 
  Node(T data)
  {
    this->data = data;
    next = NULL;
  }
};

// Class for Stack 
template<typename T>
class Stack
{
  Node<T> *head;
  int size;

  public:
  // Constructor of stack 
  Stack()
  {
    head = NULL;
    this->size = 0;
  }

  /* ----------->>>>>>>>  Function on stack >>>>>>>>>>> -------------- */

  // 1.  Size() Fun 
  int getSize()
  {
    return size;
  }

  // 2.  isEmpty() Fun 
  bool isEmpty()
  {
    if(head == NULL)
    {
      return true;
    }

    return false;
  }

  // 3. Push() the element 
  void Push(T element)
  {
    Node<T> *newNode = new Node<T>(element);

    if(isEmpty())
    {
      head = newNode;
    }
    else
    {
      head->next = newNode;
      head = newNode;
    }

    size++;
  }

  // 4. POP() the element 
  T Pop()
  {
    if(head == NULL)
    {
      return 0;
    }

    T ans;
    ans = head->data;

    Node<T> *temp = head;
    head = temp->next;

    delete temp;
    size--;

    return ans;
  }

  // 5. Top() the element 
  T Top()
  {
    if(isEmpty())
    {
      return 0;
    }

    return head->data;
  }


};