#include<iostream>
using namespace std;

int main()
{
  int num = 10;
  int a = num / 10;
  int b = num % 10;
  num = num / 10;
  int c = num % 10;

  cout << a << " " <<  c << endl;
}