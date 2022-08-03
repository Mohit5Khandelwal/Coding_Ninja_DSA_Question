#include<iostream>
using namespace std;
#include "Pair.cpp"

int main()
{
  // Making an triplet 
  Pair< Pair<int , int> , int> p1;

  p1.setY(16);
  
  Pair<int , int> p2;
  p2.setX(10);
  p2.setY(15);

  p1.setX(p2);

  cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;
}