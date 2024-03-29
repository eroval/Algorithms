/* Процедури за сливане и за подреждане чрез сливане.
   Процедурите са определени като шаблони за вектори от какъв да е тип,
   чиито стойности допускат сравняване за равенство, предшестване или следване. */

#include <iostream>
#include <vector>

using namespace std;

/* Слива подредените в ненамаляващ ред вектори a и b, записвайки резултата
   във вектора c.  Необходимото място е предварително заделено в c. */
template <typename T, typename C = std::less<>>
void merge(vector<T> & a, vector<T> & b, vector<T> & c, C less = C()) {
  unsigned m = a.size(), n = b.size(), i = 0, j = 0, k = 0;
  while (i < m && j < n)                        // докато и двете редици са непразни
    c[k++] = less(b[j],a[i]) ? b[j++] : a[i++];
  while (i < m) c[k++] = a[i++];                // копиране на остатъка от a, ако има такъв
  while (j < n) c[k++] = b[j++];                // копиране на остатъка от b, ако има такъв
}

/* Подреждане чрез сливане на участъка [p,q) на вектора a. Векторът b, със същия
   като на a размер, служи за буферна зона. Сливането не използва процедурата merge,
   а се извършва самостоятелно, като втората сливана половина се разполага в буфера
   в обратен ред. Така половините се срещат в краищата си и с това се избягва
   необходимостта от финално копиране на остатък, а и броят на проверките при
   сливането е по-малък: по две вместо три на всяка стъпка. */
template <typename T, typename C = std::less<>>
void mergesort(vector<T> & a, unsigned p, unsigned q, vector<T> & b, C less = C()) {
  unsigned i, j, k, m;
  if (q-p < 2) return;
  m = (p+q)/2;                                  // половините са [p,m) и [m,q), всяка е непразна
  mergesort(a,p,m,b,less);                      // подреждане на a[p,m)
  mergesort(a,m,q,b,less);                      // подреждане на a[m,q)
  for (i = p; i < m; ++i) b[i] = a[i];          // копиране в b[] на първата половина на a[]
  for (j = q; i < q;) b[--j] = a[i++];          // копиране в b[] на втората половина на a[], обърнато
  for (k = i = p, j = q-1; k < q; ++k)          // сливане на двете половини на b[] в a[]
    a[k] = less(b[j],b[i]) ? b[j--] : b[i++];
}

int main() {
  vector<int> u;
  for (int x; cin >> x;) u.push_back(x);        // четене на стойности във вектора u
  vector<int> z(u.size());
  mergesort(u,0,u.size(),z);                    // подреждане на вектора u, използвайки за буфер z
  for (auto x : u) cout << x << ' ';            // извеждане на резултата
  cout << endl;
  mergesort(u,0,u.size(),z,greater<int>());     // подреждане на същия вектор в обратен ред
  for (auto x : u) cout << x << ' ';            // извеждане на резултата
  cout << endl;
}
