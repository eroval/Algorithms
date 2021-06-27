// Обхождане на посадено дърво по няколко начина.

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Съставна стойност за представяне на възел на двоично дърво.
// Възелът съдържа „данна“ и множество от указатели към възли-наследници.
// Данната също може да бъде указател към същинската стойност на възела.
template <typename T>
struct RTnode {T data; unordered_set<RTnode<T> *> * heirs;};

// Обхождане в ред корен–наследници (префиксно).  Резултатът е вектор от възлите.
template <typename T>
void rt_preorder(RTnode<T> * & n, vector<T> & ns) {
  ns.push_back(n->data);
  if (n->heirs != nullptr)
    for (auto p : *n->heirs) rt_preorder(p,ns);
}

// Обхождане в ред наследници–корен (суфиксно).  Резултатът е вектор от възлите.
template <typename T>
void rt_postorder(RTnode<T> * & n, vector<char> & ns) {
  if (n->heirs != nullptr)
    for (auto p : *n->heirs) rt_postorder(p,ns);
  ns.push_back(n->data);
}

// Обхождане на листата.  Резултатът е вектор от възлите-листа.
template <typename T>
void rt_leaves(RTnode<T> * & n, vector<char> & ns) {
  if (n->heirs == nullptr)
    ns.push_back(n->data);
  else
    for (auto p : *n->heirs) rt_leaves(p,ns);
}

// Обхождане по слоеве.  Резултатът е вектор от вектори от възлите по слоеве.
template <typename T>
void rt_levels(RTnode<T> * & n, vector<vector<T>> & ns, unsigned i) {
  if (i == ns.size())
    ns.push_back(*new vector<T>());
  ns[i].push_back(n->data);
  if (n->heirs != nullptr) {
    ++i;
    for (auto p : *n->heirs) rt_levels(p,ns,i);
  }
}

// Помощна процедура за построяване на посадено дърво от стойности char по зададен низ.
// В низа, ако даден възел е поставен в скоби, той има наследници, зададени в скобите след него.
RTnode<char> * mk_tree(string::iterator & si) {
  RTnode<char> * n = new RTnode<char>();
  bool par = *si == '(';
  if (par) ++si;
  n->data = *si++;
  if (!par)
    n->heirs = nullptr;
  else {
    n->heirs = new unordered_set<RTnode<char> *>();
    while (*si != ')')
      n->heirs->insert(mk_tree(si));
    ++si;
  }
  return n;
}

// Пример за построяване и обхождане.
int main() {
  string s("(a (b e (f j)) c (d g h i))");  // построяване на           a
  remove(s.begin(),s.end(),' ');            // зададеното чрез     b    c    d
  string::iterator si = s.begin();          // s дърво (същото   e   f     g h i
  RTnode<char> * tr = mk_tree(si);          // и на фигурата)        j
//
  vector<char> nodes;
  rt_preorder(tr,nodes);                    // обхождане и записване на възлите
  for (auto x : nodes) cout << x << ' ';    // печатане на редицата резултат
  cout << endl;
//
  nodes.clear();
  rt_postorder(tr,nodes);                   // обхождане и записване на възлите
  for (auto x : nodes) cout << x << ' ';    // печатане на редицата резултат
  cout << endl;
//
  nodes.clear();
  rt_leaves(tr,nodes);                      // обхождане и записване на възлите
  for (auto x : nodes) cout << x << ' ';    // печатане на редицата резултат
  cout << endl;
//
  vector<vector<char>> levels;
  rt_levels(tr,levels,0);                   // обхождане и записване на възлите
  for (auto & xs : levels) {                // печатане на слоевете
    for (auto x : xs) cout << x << ' ';
    cout << "| ";
  }
  cout << endl;
}
