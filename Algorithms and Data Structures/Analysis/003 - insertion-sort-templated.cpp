/* Подреждане на двойки низ-число във вектор в ненамаляващ ред.
   Този вариант се различава от реализирания в pairs-insertion-sort.cpp (виж също
   insertion-sort.cpp) по това, че процедурата за подреждане е определена като шаблон –
   тя е приложима към вектори с елементи от какъв да е тип, който допуска сравнения
   между стойностите.  Параметърът на шаблона е типът на елементите на вектора.
   Сравняването между стойности се реализира от функция, параметър на процедурата за
   подреждане.  Ако за кои да е два аргумента тази функция дава истина, в подредбата
   първият от тях ще предшества втория.  В конкретния пример сравняването се извършва
   от същата функция, както в pairs-insertion-sort.cpp. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

using SIpair = pair<string,int>;

bool compare(SIpair p, SIpair q) {
  return (p.first < q.first || (p.first == q.first && p.second <= q.second));
}

template <typename T>
void insertionSort(vector<T> & a, bool cmp(T,T)) {
  int n = a.size();
  for (int i=1; i<n; ++i) {
    int j;
    auto x = a[i];
    for (j=i-1; j >= 0 && cmp(x,a[j]); --j)
      a[j+1] = a[j];
    a[j+1] = x;
  }
}

int main() {
  vector<SIpair> a;
  string s; int i;
  while (cin >> s >> i)      // четене на двойките
    a.emplace_back(s,i);     // образуване на двойка на място – в края на вектора
  insertionSort(a,compare);
  for (auto x : a)
    cout << x.first << ' ' << x.second << endl;
  cout << endl;
}
