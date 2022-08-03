#include<iostream>
using namespace std;
#include "StackUsingArray.cpp"

int main()
{
  StackUsingArray<char> s;

  s.push(100);
  s.push(101);
  s.push(102);

  cout << s.pop() << endl;
  cout << s.pop() << endl;

  cout << s.size() << endl;

  cout << s.top() << endl;

  cout << s.isempty() << endl;


}

