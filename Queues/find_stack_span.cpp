#include <iostream>
using namespace std;

int check_stock(int *price,int index)
{
  int count = 0;
  int temp = price[index];

  if(index == 0)
  {
    return 0;
  }
  else
  {
    for(int j = index - 1; j >= 0; j--)
    {
      if(price[j] >= temp)
      {
        break;
      }
      else
      {
        count++;
      }
    }
  }

  return count;
}


int* stockSpan(int *price, int size)  
{
  // Dynamically create ans array 
  int *ans = new int[size];
  int i = 0;
  int j = 0;
  int stock_span;

  while(i < size)
  {
    stock_span = check_stock(price , i)  + 1;
    ans[j] = stock_span;
    i++;
    j++;
  }

  return ans;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}