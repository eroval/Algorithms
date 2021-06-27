/* Подреждане по „бързия“ метод (quicksort).
   Редицата се разделя на две части, така че всички стойности в едната да са ≤, а в другата – ≥
   от дадена стойност. Тази разделяща стойност е член на редицата и след разделянето остава между
   двете части, с които след това се постъпва по същия начин – разделят се на още по-малки части
   и т.н. Подразделянето спира, когато дължината на текущо разглеждания участък стане по-малка от
   определен праг. След като по този начин редицата се разбие на къси участъци, тя окончателно се
   подрежда чрез алгоритъма с пряко вмъкване. Тъй като стойностите в кой да е участък са ≤ на тези
   в следващите участъци, прякото вмъкване има линейна скорост.
   За да е бърз алгоритъмът като цяло, важно е при разбиването на всеки участък получаващите се две
   части да са близки по дължина. За да се увеличи шансът за това, разделящата стойност се избира
   като медиана (средно по големина) от началната, крайната и стоящата по средата в участъка стойности. */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Тип – итератор, в случая за елементите на вектор.
template <typename T> using I = typename vector<T>::iterator;

// Подреждане по „бързия“ метод.
template <typename T>
void quicksort(I<T> p, I<T> q) {
  const int Threshold = 10;    // праг за дължината при подразделяне
  I<T> pe = p, qe = q, i, j;
  T t, t1, t2;
// Образуване на стек от граници на интервали – двойки итератори.
  vector<pair<I<T>,I<T>>> * rng = new vector<pair<I<T>,I<T>>>();
  if (q-p > Threshold) {
    for (;;) {
      i = p+(q-p)/2;
      I<T> p1 = p+1, q1 = q-1;
      swap(*i,*p1);
// Подреждане на тройката *(p+1), *p, *(q-1).
      t = *p1; t1 = *p; t2 = *q1;
      if (t > t1)
        if (t2 >= t) {*p1 = t1; *p = t;}
        else
          if (t2 > t1) {*p1 = t1; *p = t2; *q1 = t;}
          else {*p1 = t2; *q1 = t;}
      else
        if (t1 > t2) {
          if (t2 >= t) {*p = t2; *q1 = t1;}
          else {*p1 = t2; *p = t; *q1 = t1;}
        }
// Изпълнено е *(p+1) <= *p <= *(q-1), като това са изходните стойности на *p, *(q-1) и *i
// в нужния ред.  Разделящата стойност за следващата фаза (разделянето по големина) е *p.
      for (i = p1, j = q1, t = *p;;) {     // сега разделящата стойност е t
        do ++i; while (*i < t);
        do --j; while (*j > t);
        if (i > j) break;
        swap(*i,*j);
      }
      *p = *j; *j = t;
// Образуване на два подинтервала, при това позицията j, където се намира разделящата стойност, не
// се включва в никой от тях.  Ако дължините и на двата интервала са под прага и стекът е непразен,
// от него се взима следващият текущ за подразделяне.  Ако дължината на само единия интервал е над
// прага, той става следващия текущ за подразделяне, а ако и двата интервала имат надпрагови дължини,
// по-дългият се записва в стека, а по-късият става следващия текущ за подразделяне.
      unsigned n1 = j-p, n2 = q-i;
      bool c = n1 > n2;
      if (c) swap(n1,n2);
      if (n2 <= Threshold) {
        if (rng->empty()) break;    // разбиването на къси части на цялата редица е завършено
        tie(p,q) = rng->back();     // извличане от стека на участък за подразделяне
        rng->pop_back();
      } else
        if (n1 <= Threshold)
          if (c) q = j; else p = i;
        else {
          if (c) {rng->emplace_back(p,j); p = i;}
          else   {rng->emplace_back(i,q); q = j;}
        }
    }
  }
// Подреждане с пряко вмъкване.
  for (i = pe+1; i != qe; ++i) {
    t = *i;
    for (j = i-1;; --j) {
      if (*j <= t) {++j; break;}
      *(j+1) = *j;
      if (j == pe) break;
    }
    *j = t;
  }
}

// Проверяване дали интервалът [p,q) съдържа ненамаляваща редица.
template <typename T>
bool isordered(I<T> p, I<T> q) {
  for (++p; p != q; ++p)
    if (*(p-1) > *p) return false;
  return true;
}

vector<unsigned> a;

// Пример за подреждане на вектор чрез метода на бързото подреждане.
int main() {
  for (int x; cin >> x;) a.push_back(x);
// Подреждане и измерване на времето, за което става това.
  auto t = time(nullptr);
  quicksort<unsigned>(a.begin(),a.end());
  cout << (time(nullptr)-t) << " sec" << endl;
#if 0     // ако трябва да се печата подредената редица, 0 се заменя с 1
  for (auto x : a) cout << x << ' ';
  cout << endl;
#endif
}
