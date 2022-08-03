#include<iostream>
using namespace std;
#include "StackUsingLL.h"

int main()
{
  Stack<int> s;

  s.Push(10);
  s.Push(20);
  s.Push(30);

  cout << s.Pop() << endl;

}
