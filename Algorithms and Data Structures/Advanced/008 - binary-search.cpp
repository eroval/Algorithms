/* Двоично търсене в ненамаляващ отрязък от вектор от 0 или повече стойности.
   Извежда се отместването спрямо началото на отрязъка или на първото срещане на търсената
   стойност (ако се среща), или на мястото, което може да заеме стойността, спазвайки 
   наредбата. (Намира се или къде за пръв път я има стойността, или къде я няма!)
   Отрязъкът, в който става търсенето, се задава като полуотворен интервал чрез двойка
   указатели (итератори) за начало и край.
   Търсенето е обособено във функция и се извършва на стъпки, на всяка от които отрязъкът,
   в който се търси, се разполовява.  На всяка стъпка текущият отрязък е [p,q) и
   разполовяването става, променяйки или p, или q.  Търсенето завършва, когато дължината
   на отрязъка (т.е. q–p) стане 1.  Възможно е и отрязъкът да е изначално празен (p=q) –
   тогава търсенето завършва веднага.
   Ако в реда (x > *m ? p : q) = m сравнението се направи чрез >= вместо >, ще се търси
   последното вместо първото срещане на x.
   Броят действия при търсене сред n стойности е пропорционален на log n. */

#include <iostream>
#include <vector>

using namespace std;

// Определяне на името I като синоним на „итератор към елемент на вектор от стойности T“.
// По-нататък I се използва като име на тип, еквивалентно на израза отдясно на знака =.
template <typename T>
using I = typename vector<T>::iterator;

// Функция за двоично търсене в отрязък [p,q).  Търси се стойността x.
// Резултатът е итератор към първото срещане на x или, ако такова няма,
// към мястото, което би могло да заема x.
template <typename T>
I<T> bsearch(I<T> p, I<T> q, T x) {
  for (;;) {
    unsigned n = q-p;        // брой елементи в отрязъка
    if (n >= 2) {            // отрязъкът съдържа >1 члена, трябва да се раздели
      I<T> m = p+n/2;        //    итератор към среден по ред член
      (x > *m ? p : q) = m;  //    стойността на m се дава или на p, или на q (съотв. се избира дясна или лява половина)
    } else {                 // броят членове е ≤1, търсенето завършва
      if (n == 1 && *p < x)  //    ако е останала единствена стойност и тя е по-малка от x,
        ++p;                 //    мястото на x е непосредствено вдясно
      return p;
    }
  }
}

int main() {
  vector<int> v{10,20,30,40,40,40,50,60,70,70,80,90};
  int z;                     // търсеното число
  cin >> z;
  I<int> a = v.begin(), b = v.end();
  I<int> i = bsearch(a,b,z);      // в този случай търсенето е в целия вектор
  cout << i-a;               // отместването на получения итератор спрямо началото на отрязъка
// Търсенето е успешно, ако i не е извън края на отрязъка и сочената от него стойност е търсената:
  cout << (i != b && *i == z ? " успех\n" : " неуспех\n");
}
