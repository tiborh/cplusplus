#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int main() {
  const int N = 10;
  const int MAXNUM = 100;
  int a[N], *p;

  cout << "Max num: " << MAXNUM << endl;
  
  srand((unsigned)time(0));
  for (int i = 0; i < N; ++i) {
    a[i] = (rand()%MAXNUM)+1;
    cout << i << ": " << a[i] << endl;
  }
  
  int sum = 0;
  for (p = a; p < &a[N]; ++p)
    sum += *p;

  cout << "Sum: " << sum << endl;

  return 0;
}
