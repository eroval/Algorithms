/* В редица от цели числа се намира отрязък, чийто сбор е възможно най-голям неотрицателен.
   Ако редицата е празна или съдържа само отрицателни числа, най-големият сбор се смята равен
   на 0 и се образува от празен отрязък. Ако сборът е положителен, освен него извеждаме и двойка
   цели числа j и k – поредните номера на прочетените числа, за които отрязъкът x_j, ..., x_k има
   най-голям сбор и е първият поред такъв отрязък. Например за редицата
        2 5 -10 3 2 1 0 3 -2 7 -6
   се извежда
        14
        4 10 .
   Виж също https://en.wikipedia.org/wiki/Maximum_subarray_problem */

#include <iostream>

using namespace std;

int main() {
  int sm = 0, sc = 0, j, jc, k, x;
  for (int i = 0; (cin >> x) && ++i;) {
// i  = брой въведени числа
// sc = най-голям сбор за отрязък, завършващ на i-то число
// sm = най-голям сбор изобщо за отрязък (sm ≥ sc)
// jc = номер на първия член на отрязъка със сбор sc
// j  = номер на първия член на отрязъка със сбор sm
// k  = номер на последния член на отрязъка със сбор sm
    if (sc == 0 && x > 0) jc = i;
    sc = max(0,sc+x);
    if (sc > sm) { sm = sc; k = i; j = jc; }
  }
  cout << sm << endl;
  if (sm) cout << j << ' ' << k << endl;
}