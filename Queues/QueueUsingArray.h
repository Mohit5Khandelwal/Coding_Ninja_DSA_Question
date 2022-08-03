template <typename T>
class QueueUsingArray
{
  // Declaring an data variable for this class 
  T *data;
  int first_index;
  int next_index;
  int size;
  int capacity;

  public:

  // Declaring an constructor of an class 
  QueueUsingArray()
  {
    int s = 5;
    data = new T[s];
    first_index = -1;
    next_index = 0;
    size = 0;
    capacity = s;
  }

  /* ---------------------------------->>>>>>>>>>>>>>   Queues Functions >>>>>>>>>>>-------------------------------------------*/

  // 1. Finding the size of queue
  int getSize()
  {
    return size;
  }

  // 2. Check if my queue is empty or not 
  bool isEmpty()
  {
    return size == 0;
  }

  // 3. Inserting an element in a queue
  void enqueue(T element)
  {
    // Check that if my queue is full or not 
    if(size == capacity)
    {
      int j = 0;
      
      // Dynamically new array create 
      T *new_data = new T[2 * capacity];

      // Copying the element from the prvious array 

      // F_I -->> Cap.
      for(int i = first_index; i < capacity; i++)
      {
        new_data[j] = data[i];
        j++;
      }

      // 0th Index ---->> F_I
      for(int i = 0; i < first_index; i++)
      {
        new_data[j] = data[i];
        j++;
      }

      next_index = capacity;
      first_index = 0;

      capacity = capacity * 2;

      delete[] data;

      data = new_data;
      
      
      /*cout << "Queue is full" << endl;
      return;*/
    }

    data[next_index] = element;
    next_index = (next_index + 1) % capacity; // Circularly incre. the next

    // Initlize the first index 
    if(first_index == -1)
    {
      first_index = 0;
    }

    size++;
  }

  // 4. Deleting an element from a queue
  T dequeue()
  {
    // Check if queue is empty or not 
    if(isEmpty())
    {
      cout << "Queue is empty" << endl;
      return 0;
    }

    int ans = data[first_index];
    first_index = (first_index + 1) % 5;

    size--;

    // As my queue is empty then we reset the value of both pointer 
    if(first_index == next_index)
    {
      // Queue is empty
      first_index = -1;
      next_index  = 0;
    }

    return ans;
  }

  T front()
  {
        // Check if queue is empty or not 
    if(isEmpty())
    {
      cout << "Queue is empty" << endl;
      return 0;
    }

    return data[first_index];
  }
};