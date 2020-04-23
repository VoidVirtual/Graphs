#include "Graph.h"
#include "Graph.cpp"
#include <string>
template struct Edge<int, int>;
template class Node<int, int>;
template class Graph<int, int>;
template struct Edge<int, std::string>;
template class Node<int, std::string>;
template class Graph<int, std::string>;
template struct Edge<long long unsigned int, std::string>;
template class Node<long long unsigned int, std::string>;
template class Graph<long long unsigned int, std::string>;

