#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string expression) 
{
  int len = expression.length();
  int i = 0;
  int count = 0;

  stack<char> b;

  // Check the redundant bracket using iterating through loop 

  while(i < len)
  {
    if(expression[i] != ')')
    {
      // Push useful information or opening bracket into stack 
      b.push(expression[i]);
    }
    else if(expression[i] == ')')
    {
      // Pop all the element from the stack till (
      // check the count value 

        while(b.top() != '(')
        {
          count++;
          b.pop();
        }

        // Opening bracket removed 
        b.pop();

        if(count <= 1) // (a)
        {
          return true; // redundant bracket is their 
        }
    }

    i++;
    count = 0;
  }

  return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}