#include <iostream>
#include <vector>
#include <typeinfo>

#define ARRAY_SIZE 5

using namespace std;

// all <class T> type of stuff has been replaced with <typename T> for reasons of logic

//the simplest stuff
template<typename T>
void Show(const T nData)
{
  cout << nData << endl;
}

//simple template class
template<typename TYPE>
void PrintTwice(const TYPE& data)
{
  cout<<"PrintTwice: " << data << data << endl;
}

//simple template typename
template<typename TYPE>
TYPE Twice(const TYPE& data)
{
   return data * 2;
}

/*******************************************************************************
 * Prerequisites for type T:
 * 
 *   Must have an accessible default constructor.
 *   Must have += operator callable.
 *   Must be able to convert itself to double (or equivalent).
 *
 ******************************************************************************/

//with side-effect
template<typename T>
void TwiceIt(T& tData)
{
    tData *= 2;    
    // tData = tData + tData;
}

//two input values (same type)
template<typename T>
T Add(const T& n1, const T& n2)
{
    return n1 + n2;
}

//reference as returned value
template<typename T>
const T& GetMax(const T& t1, const T& t2) // if return type is not a reference, the constant cannot be returned.
{
    if (t1 > t2)
    {
        return t1;
    }
    // else 
    return t2;
}

//input from a container
template<typename T>
double GetAverage(const vector<T>& av)	// not to duplicate possibly huge structure in stack
{
  // calling the default constructor
  T tSum = T(); // tSum = 0 or equivalent
  
  // need ‘typename’ before ‘std::vector<T>::iterator’ because ‘std::vector<T>’ is a dependent scope
  typename vector<T>::const_iterator avi; // const_ needed because of const vector
  for (avi = av.begin(); avi != av.end(); ++avi)
    {
      tSum += *avi;
    }
  
  // Whatever type of T is, convert to double
  return double(tSum) / av.size();
}

//two input values of possibly different types
template<typename T1, typename T2>
void PrintTwo(const T1& t1Data, const T2& t2Data)
{
  cout << "First value: " << t1Data << endl;
  cout << "Second value: " << t2Data << endl;
}

//type T needs to be specified at function call
template<class T>
void PrintSize()
{
  cout << "Size of this type: " << sizeof(T) << endl;
}

//type T needs to be specified at function call
template<typename T>
T SumOfNumbers(const int a, const int b)
{
   T t = T(); // Call default CTOR for T

   t = T(a)+b;
 
   return t;
}

//if default value is used
template<typename T>
void PrintNumbers(const vector<T> vs, const T filter = T()) // initilised to zero
{
  typename vector<T>::const_iterator vsi;
  for(vsi = vs.begin(); vsi != vs.end(); ++vsi)
   {
       if ( *vsi != filter) // Print if not filtered
	 cout << *vsi;
       else
	 cout << ".";
       cout << " ";
   }
  cout << endl;
}

int main()
{
  const char* a = "one";
  const int b = 123;
  const float c = 1.23456;
  const char d = 'a';
  const string s1 = "one";
  const string s2 = "two";


  PrintTwice(a);
  PrintTwice(b);
  PrintTwice(c);
  PrintTwice(d);
  PrintTwice(s1);

  cout << "Twice: " << Twice(b) << endl;
  cout << "Twice: " << Twice(c) << endl;
  cout << "Twice: " << Twice(d) << endl;
  cout << "Twice: " << Twice(Twice(b)) << endl;
  //cout << "Twice: " << Twice(s1) << endl; // not implemented either for char* or for string, only in Perl

  int b2 = b;
  cout << "Original: " << b2 << endl;
  TwiceIt(b2);
  cout << "TwiceIt: " << b2 << endl;

  int c3 = c;
  cout << "Original: " << c3 << endl;
  TwiceIt(c3);
  cout << "TwiceIt: " << c3 << endl;

  const int b1 = 357;
  const float c1 = 8.13264;
  const float c2 = 9.6431;
  const char d1 = 'b';
  cout << "Add: " << Add(b,b1) << endl;
  cout << "Add: " << Add(c,c1) << endl;
  cout << "Add: " << Add(d,d1) << endl;
  cout << "Add: " << Add(Add(c,c1),c2) << endl;
  cout << "Add: " << Add(s1,s2) << endl;  

  int tia[] = {100, 200, 300, 500, 1000};
  float tfa[] = {1.23, 4.56, 7.89, 1.47, 9.63};
  vector<int> vints(tia,tia+5);
  vector<float> vfloats(tfa,tfa+5);
  cout << "GetAverage: " << GetAverage(vints) << endl;
  cout << "GetAverage: " << GetAverage(vfloats) << endl;
  
  cout << "PrintTwo(a,b)\n";
  PrintTwo(a,b);
  cout << "PrintTwo(b,d)\n";
  PrintTwo(b,d);
  cout << "PrintTwo<double,double>(b,d)\n";
  PrintTwo<double,short>(b,d);
  cout << "PrintTwo<double>(b,d)\n"; // if one, only the first is determined
  PrintTwo<double>(b,d);


  cout << "Show<double>( 120 ): ";
  Show<double>( 120 );    // 120
  cout << "Show<short>( 'X' ): ";
  Show<short>( 'X' );    // 88
  cout << "Show<int>( 55.64 ): ";
  Show<int>( 55.64 );  // 55

  float ref_max = GetMax(c1,c2);
  cout << "GetMax (of " << c1 << "," << c2 << "): " << ref_max << endl;
  //ref_max += 1.0;
  //cout << ref_max << endl;

  // to avoid:  no matching function for call to ‘GetMax(const int&, const float&)’
  cout << "GetMax<double>(b,c): " << GetMax<double>(b,c) << endl;

  //PrintSize(); //would be invalid:  no matching function for call to ‘PrintSize()’
  PrintSize<double>();
  PrintSize<char>();

  double nSum;
  nSum = SumOfNumbers<double>(120,200);
  cout << "SumOfNumbers<double>(120,200): " << nSum << " (" << typeid(nSum).name() << ")" << endl;

  int Array[10] = {1,2,0,3,4,2,5,6,0,7};
  vector<int> iv(Array,Array+10);
  cout << "Leaving default as is:\n";
  PrintNumbers(iv);
  int filter = 2;
  cout << "Default as " << filter << ":\n";
  PrintNumbers(iv,filter);

  return 0;
}
