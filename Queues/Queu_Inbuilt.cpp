#include<iostream>
using namespace std;
#include <queue>

int main()
{
  queue<int> q;

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);

  cout << q.front() << endl; // 10
  
  q.pop(); // 10
  q.pop(); // 20

  cout << q.size() << endl; // 2
  cout << q.empty() << endl;
}