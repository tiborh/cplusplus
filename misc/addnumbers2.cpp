#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
// The mess above is the price of generics: you cannot use:
//"using namespace std"

const int MAXNUM = 100;

template<class T>
T* get_numbers()
{
  T* numbers = new int[MAXNUM];
  string line;
  char const *filename = "addnumbers.txt";
  ifstream input (filename);
  if (input.is_open())
    {
      T i = 1;
      while ( getline(input,line) && i < 100)
	stringstream(line) >> *(numbers+i++);  // does not work:
      /*
	 error: there are no arguments to ‘stringstream’ that depend on a template parameter
       */
      input.close();
      *numbers = i;
    } else 
    {
      cout << "Cannot open " << filename << " for reading.\n";
      return NULL;
    }
  
  if (0 == *numbers)
    cout << "Nothing was read from the file " << filename << ".\n";

  return numbers;
}

int main()
{
  int* numbers = get_numbers();
  if (NULL == numbers)
    {
      cout << "NULL was returned. Exiting...\n";
      return 1;
    }
  
  cout << "The numbers read:\n";
  int sum = 0;
  for (int i = 1; i < *numbers; i++)
    {
      cout << *(numbers+i) << endl;
      sum += *(numbers+i);
    }

  cout << "The sum of the numbers: " << sum << ".\n";

  return 0;
}
