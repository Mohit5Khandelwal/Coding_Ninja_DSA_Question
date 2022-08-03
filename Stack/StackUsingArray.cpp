#include<climits>
#include<iostream>
using namespace std;

template<typename T>

class StackUsingArray
{
  T *data;
  int nextIndex;
  int capacity;

  public:

  /*// Making an constructor which takes an size of an array 
  StackUsingArray(int total_size)
  {
    // Dynamically create an array 
    data = new int[total_size];
    nextIndex = 0;
    capacity = total_size;
  }*/

  // Make certain changes in the default constructor 
  StackUsingArray()
  {
    capacity = 4;
    data = new T[capacity];
    nextIndex = 0;
  }



  // Finding the size of an stack 
  int size()
  {
    return nextIndex;
  }

  // Checking that if my stack is empty or not 
  bool isempty()
  {
    return nextIndex == 0;
  }

  // Inserting an element in a stack 
  void push(T element)
  {
    // Checking that if my stack is full or not 
    if(nextIndex == capacity)
    {
      /*cout << "Stack is full" << endl;
      return;*/

      // When my array is full then we dynamically make a new twice size array 
      T *new_data = new T[2 * capacity];

      // Copying the element from pre array 
      for(int i = 0; i < capacity; i++)
      {
        new_data[i] = data[i];
      }

      // Certain Manuplations 
      capacity = capacity * 2;
      delete[] data;

      data = new_data;
    }
    data[nextIndex] = element;
    nextIndex++;
  }

  // Deleting an element from the stack 
  T pop()
  {
    // Condition if my stack is empty 
    if(isempty())
    {
      cout << "Stack is empty" << endl;
      return 0;
    }

    nextIndex--;
    return data[nextIndex];
  }

  // Find the data of top element in the stack 
  T top()
  {
    if(isempty())
    {
      cout << "Stack is empty" << endl;
      return 0;
    }

    return data[nextIndex - 1];
  }

};
