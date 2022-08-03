#include <iostream>
#include <string>
using namespace std;

#include<stack>

int countBracketReversals(string input) 
{
  
  int i = 0;
  int count = 0;
  int len = input.size();
  char c1 , c2;

  // Base Case

  if(len % 2 != 0) // Odd length 
  {
    return -1;
  }

  // Even length 
  // From the string first remove balanced parenthesis 

  // Creating stack 
  stack<char> b;

  while(i < len)
  {
    if(input[i] == '{')
    {
      b.push(input[i]);
    }
    else if(input[i] == '}')
    {
      // If closing bracket is come 
      
      // If stack is empty 
      if(b.empty())
      {
        b.push(input[i]);
      }
      else if(b.top() == '{')
      {
        // It makes an balanced pair {}
        b.pop();
      }
      else if(b.top() == '}')
      {
        // Push into stack 
        b.push(input[i]);
      }
    }

    i++;
  }

  // Operation On stack 
  // Till now we removed all balanced parenthesis 
  // Now we are balacing the unbalanced parenthesis 

  while(!b.empty())
  {
    // Pop two char from stack and then check 
    c1 = b.top(); b.pop();
    c2 = b.top(); b.pop();

    if(c1 == c2)
    {
      // When both are same {{ }}
      count++;
    }
    else if(c1 != c2)
    {
      // when both are disimilar }{ }{}
      count += 2; 
    }
  }

  return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}