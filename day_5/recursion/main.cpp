#include <iostream>

using namespace std;

int factorial (int n)
{
  if (n == 1)
    return n;

  return n * factorial (n - 1);
}

// eg: f(x) = x
// f(f(x)) = x^2

int main ()
{
  int n;

  cout << "Enter a number to calculate factorial: ";
  cin >> n;

  cout << "The factorial of " << n << " is: " << factorial (n);

  return 0;
}
