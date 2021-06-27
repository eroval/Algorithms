// Обхождане на граф в ширина и дълбочина.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Множество от възли (със стойност от тип N във всеки) – синоним на ненаредено множество.
template<typename N> using Nodes = unordered_set<N>;
// Граф: съответствие между множество от възли и множество от множества от възли (множествата от съседите на всеки възел).
template<typename N> using Graph = unordered_map<N,Nodes<N>>;

// Проверява дали x е в множеството s
template<typename N>
bool contains(const Nodes<N> * s, N x) {
  return s->find(x) != s->end();
}

// Обхождане на граф g в ширина, започвайки от възела x.
// Резултатът е редицата nodes от възлите на графа.
// Като помощна структура се образува и използва опашката nq, която накрая се унищожава.
template<typename N>
void bft_graph_do(Graph<N> & g, N x, vector<N> * nodes, Nodes<N> * vis) {
  auto nq = new queue<N>();
  vis->insert(x);               // посещаване на x и
  nq->push(x);                  // поставяне в опашката
  while (!nq->empty()) {        // докато опашката е непразна
    x = nq->front();            //   извличане от опашката на възел x,
    nq->pop();                  //   премахване от опашката и
    nodes->push_back(x);        //   записване в редицата резултат
    for (auto n : g[x])         //   за всеки съсед
      if (!contains(vis,n)) {   //     ако е непосетен,
        vis->insert(n);         //     посещава се и
        nq->push(n);            //     се поставя в опашката
      }
  }
  delete nq;
}

// Тази процедура служи като „главна“ за повикване на горната.
// Тя образува редицата-резултат и множеството vis за посетени възли,
// предава ги за ползване на bft_graph и накрая унищожава vis.
template<typename N>
vector<N> * bft_graph(Graph<N> & g, N x) {
  auto n = g.size();    // брой възли в графа
  auto nodes = new vector<N>();
  nodes->reserve(n);
  auto vis = new Nodes<N>();
  vis->reserve(n);
  bft_graph_do(g,x,nodes,vis);
  delete vis;
  return nodes;
}

// Обхождане на граф g в дълбочина, започвайки от възела x.
// Резултатът е редицата nodes от възлите на графа.
template<typename N>
void dft_graph_do(Graph<N> & g, N x, vector<N> * nodes, Nodes<N> * vis) {
  vis->insert(x);                    // посещаване на x и
  nodes->push_back(x);               // записване на x в редицата резултат
  for (auto n : g[x])                // за всеки съсед
    if (!contains(vis,n))            //   ако е непосетен,
      dft_graph_do(g,n,nodes,vis);   //   повиква се процедурата с този начален възел
}

// Тази процедура служи като „главна“ за повикване на горната.
// Тя образува редицата-резултат и множеството vis за посетени възли,
// предава ги за ползване на dft_graph_do и накрая унищожава vis.
template<typename N>
vector<N> * dft_graph(Graph<N> & g, N x) {
  auto n = g.size();    // брой възли в графа
  auto nodes = new vector<N>();
  nodes->reserve(n);
  auto vis = new Nodes<N>();
  vis->reserve(n);
  dft_graph_do(g,x,nodes,vis);
  delete vis;
  return nodes;
}

// Пример за построяване и обхождане на граф.
int main() {
// За всеки възел на графа са посочени съседите.
  Graph<char> g{{'A',{'B','C','D'}}, {'B',{'A','D'}}, {'C',{'A','D','E','F'}}, {'D',{'A','B','C','G','K'}},
                {'E',{'C','F'}}, {'F',{'C','E'}}, {'G',{'D','H','I','K','M'}}, {'H',{'G','I','J'}},
                {'I',{'G','H','J'}}, {'J',{'H','I'}}, {'K',{'D','G','L'}}, {'L',{'K'}}, {'M',{'G'}}};
  auto v = bft_graph(g,'A');            // обхождане в ширина
  for (auto x : *v) cout << x << ' ';   // отпечатване на редицата от възли
  cout << endl;
  v = dft_graph(g,'A');                 // обхождане в дълбочина
  for (auto x : *v) cout << x << ' ';   // отпечатване на редицата от възли
  cout << endl;
}
