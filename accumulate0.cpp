#include <iostream>
#include <numeric>		// accumulate

using namespace std;

int main() {
  int sample[] = {1,2,3,4};
  cout << accumulate(sample,sample+4,5) << '\n';
  
  return 0;
}
