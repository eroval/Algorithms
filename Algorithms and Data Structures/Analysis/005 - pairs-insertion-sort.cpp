/* Подреждане на двойки от низове и числа във вектор в ненамаляващ ред.  Обособено е в
   процедура, подобна на тази за подреждане на числа чрез същия алгоритъм (виж файла
   insertion-sort.cpp).
   Сравняването на двойки става лексикографски (като думи в речник): ако първите членове
   на двойките са различни, сравняването между тях определя предшестването между двойките,
   а ако са равни, сравняват се вторите членове. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

using SIpair = pair<string,int>;

bool compare(SIpair & p, SIpair & q) {
  return (p.first < q.first || (p.first == q.first && p.second < q.second));
}

void insertionSort(vector<SIpair> & a) {
  int n = a.size();
  for (int i=1; i<n; ++i) {
    int j;
    auto x = a[i];
    for (j=i-1; j >= 0 && compare(x,a[j]); --j)
      a[j+1] = a[j];
    a[j+1] = x;
  }
}


int main() {
  vector<SIpair> a;
  string s; int i;
  while (cin >> s >> i)      // четене на числата по двойки
    a.emplace_back(s,i);     // образуване на двойка на място – в края на вектора
  insertionSort(a);
  for (auto x : a)
    cout << x.first << ' ' << x.second << endl;
  cout << endl;
}
