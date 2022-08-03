#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) 
{
  int size_extra; 
  int size1 , size2;
  int count1 = 0;
  int count2 = 0;

  // pop out all element input and store to extra 
  while(!input.empty())
  {
    extra.push(input.top());
    input.pop();
  }

  // Making an two new stack 
  stack<int> s1;
  stack<int> s2;

  size_extra = extra.size();

  // How many element go inside s1 and s2
  if(size_extra % 2 == 0)
  {
    size1 = size_extra / 2;
    size2 = size1;
  }
  else if(size_extra % 2 != 0)
  {
    size1 = (size_extra + 1) / 2;
    size2 = size_extra - size1;
  }

  // Storing element in stack s1 and s2

  // For s1
  while(count1 < size1)
  {
    s1.push(extra.top());
    extra.pop();
    count1++;
  }

    // For s2
  while(count2 < size2)
  {
    s2.push(extra.top());
    extra.pop();
    count2++;
  }

  // Storing the element's of stack s2 into input stack 
  while(!s2.empty())
  {
    input.push(s2.top());
    s2.pop();
  }

  // Storing the element's of stack s1 into input stack 
  while(!s1.empty())
  {
    input.push(s1.top());
    s1.pop();
  }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}