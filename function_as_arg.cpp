#include <iostream>

using namespace std;

int a(int num) { return num * num; }

int b(int num) { return num + num; }

void c(int func(int), int num) {
  cout << "x: " << num << ", f(x): "
       << func(num) << endl;
}

int main() {
  c(a,3);
  c(b,3);

  return 0;
}
