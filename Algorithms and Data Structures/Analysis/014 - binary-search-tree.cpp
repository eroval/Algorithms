// Построяване и инфиксно обхождане на двоично подреждащо дърво (ДПД).
// Построяването става, като една по една се четат и добавят стойности
// в отначало празно дърво.  При обхождането възлите се записват във вектор.

#include <iostream>
#include <vector>

using namespace std;

// Съставна стойност за представяне на възел на двоично дърво.
// Възелът съдържа цяло число и два указателя към възли – ляв и десен наследници.
template <typename T>
struct BTnode {T data;  BTnode * left, * right;};

// Добавяне на стойност към двоично подреждащо дърво.
template <typename T, typename C = std::less<>>
void bt_insert(T x, BTnode<T> * & n, C less = C()) {
  BTnode<T> * p = new BTnode<T>{x,nullptr,nullptr};   // образуване и запълване на нов възел
  if (n == nullptr)                                   // празно дърво?
    n = p;                                            // новият възел се поставя като единствен в дървото
  else                                                // непразно дърво
    for (BTnode<T> * q = n;;)
      if (less(x,q->data))                            // включване наляво от q
        if (q->left == nullptr) {
          q->left = p; break;                         // поставяне на новия възел в дървото
        } else
          q = q->left;                                // спускане наляво
      else  /* x ≥ q->data */                         // включване надясно от q
        if (q->right == nullptr) {
          q->right = p; break;                        // поставяне на новия възел в дървото
        } else
          q = q->right;                               // спускане надясно
}

// Обхождане на двоично дърво в ред ляво–корен–дясно (инфиксно).
template <typename T>
void inorder(BTnode<T> * & n, vector<T> & ns) {
  if (n->left != nullptr) inorder(n->left,ns);        // ако лявото поддърво е непразно, обхожда се
  ns.push_back(n->data);                              // записване на стойността на текущия възел
  if (n->right != nullptr) inorder(n->right,ns);      // ако дясното поддърво е непразно, обхожда се
}

// Пример за построяване и обхождане на ДПД
int main() {
  BTnode<int> * tr = nullptr;
  int x;
  while (cin >> x) bt_insert(x,tr);        // четене на стойност x (ако има) и поставяне в дървото
  vector<int> trseq;
  inorder(tr,trseq);                       // обхождане на дървото, записване на възлите във вектор
  for (auto x : trseq) cout << x << ' ';   // отпечатване на резултата от обхождането
  cout << endl;
}
