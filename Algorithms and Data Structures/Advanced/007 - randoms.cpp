/* Програмата образува редица от случайни числа от един от два вида.
   Може да се използва за пораждане на входни данни за други програми. */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Образуване на редица от n случайни числа, всяко в интервала [p,q), във вектора a.
void randomSequence(vector<int> & a, int n, int p, int q) {
  a.resize(n);
  srand(time(nullptr));
  q -= p;
  for (int i=0; i<n; ++i)
    a[i] = p+rand()%q;
}

// Образуване на случайна пермутация от числата 1,...,n във вектора a.
void randomPermutation(vector<int> & a, int n) {
  a.resize(n);
  srand(time(nullptr));
  for (int i=0; i<n; ++i) a[i] = 1+i;
  for (int i; n>1; --n) {
    i = rand()%n;
    swap(a[i],a[n-1]);
  }
}

/* Програмата се повиква с едно или три числа на командния ред: ако е само едно,
   изпълнява се randomPermutation(), а ако са три – randomSequence().  Числата от
   образуваната редица се извеждат в един ред на стандартния изход. */


int main(int argc, char * argv[]) {
  vector<int> a;
  if (argc == 2)
    randomPermutation(a,atoi(argv[1]));
  else
    randomSequence(a,atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
  for (int x : a) cout << x << ' ';
  cout << endl;
}
