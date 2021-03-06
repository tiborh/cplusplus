#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
//#include <algorithm>  // e.g. split
//#include <cassert> // assert()
//#include <climits> // e.g. INT_MAX
//#include <cmath>
//#include <cstdio>
//#include <cstdlib> // e.g. for srand(time(NULL)) and rand()
//#include <cstring> // e.g. for strlen
//#include <ctime>   // for time operation
//#include <deque>	       // double linked list
//#include <exception>
//#include <fstream> // file operations
//#include <functional> // for lambda
//#include <initializer_list> // for initializer_list<T>
//#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
//#include <map>
#include <sstream> // stringstream
//#include <stack>  // for single-linked lists
#include <string>
//#include <sys/types.h> // for stat
//#include <sys/stat.h> // for stat
//#include <typeinfo> // for typeid
//#include <unistd.h>
//#include <vector>


using namespace std;

int main(int argc, char** argv)
{
  stringstream ss = {};
  if (argc < 2)
    {
      string instr;
      getline(cin,instr,'\n');
      ss << instr;
    } else 
    {
      ss << argv[1];
    }

  do {
    string test;
    //ss >> test;
    getline(ss,test,'\t');
    cout << '\"' << test << "\" (" << test.length() << ")\n";
  } while(ss.good());

  return 0;
}
