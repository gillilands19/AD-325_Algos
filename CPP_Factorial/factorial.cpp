#include<iostream>
using namespace std;

long long recursiveFactorial(int n);
long long factorialLoop(int n);

int main()
{
  int n;
  int x;

  cout << "Please enter a number: " << endl;
  cin >> n;
  cout << "Please enter another number: " << endl;
  cin >> x;

  cout << "The Factorial of " << n << " is " << recursiveFactorial(n) << endl;

  cout << "The Factorial of " << x << " is " << factorialLoop(x) << endl;

  return 0;
}

long long recursiveFactorial(int n)
{
  if(n > 1)
  {
    return n * recursiveFactorial(n - 1);
  }
  else if(n == 1)
  {
    return 1;
  }
  else
  {
    cout << "Not a Positive Number ";
    return 0;
  }
}

long long factorialLoop(int n)
{
  long long factorial = 1;
  for(int i = 1; i <= n; ++i)
  {
    factorial *= i;
  }
  if(n == 1)
  {
    return 1;
  }
  else if(n < 1)
  {
    cout << " Not a Positive Number ";
    return 0;
  }
  else
  {
  return factorial;
  }
}