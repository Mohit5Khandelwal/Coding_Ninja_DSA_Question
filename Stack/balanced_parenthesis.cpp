#include <iostream>
#include <string>
#include<strings.h>
#include <stack>
using namespace std;


bool isCheck(char open, char closed)
{
  if(open == '(' && closed == ')')
  {
    return true;
  }
  else if(open == '[' && closed == ']')
  {
    return true;
  }
  else if(open == '{' && closed == '}')
  {
    return true;
  }
  else
  {
    return false;
  }
}


bool isBalanced(string expression) 
{
  int len = expression.length();
  int i = 0;
  char check;
  stack<char> s;

  // Checking each parenthesis through loop 
  while(i < len)
  {
    if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
    {
      s.push(expression[i]);
    }
    else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
    {
      // Check that if pair is forming or not 
      if(s.size() != 0)
      {
        check = s.top();
      }
      
      if( isCheck(check , expression[i]))
      {
        s.pop();
      }
      else
      {
        return false;
      }
    }

    i++;
  }

  if(s.empty())
  {
    return true;
  }
  else
  {
    return false;
  }

}


int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}