#include <iostream>
using namespace std;

int main() {
  char    abc[27];
  char    *ptr = abc;
  strcpy(abc, "abcdefgxyz");
  cout << abc << endl;
  cout << &abc << endl;
  cout << *abc << endl;
  cout << abc+4 << endl;
  cout << abc[12] << endl;
  return 0;
}