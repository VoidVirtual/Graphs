#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include "Infinity.h"
/**forward declaration**/
template<typename W, typename V> class Node;
template<typename W, typename V> struct Edge;
template<typename W, typename V> class Path;
template<typename W, typename V> class Graph;

template<typename W, typename V>
struct Edge
{
    W weight;
    Node<W,V>* targetNode;
    Edge(W _weight, Node<W,V>* _target)
    {
        weight = _weight;
        targetNode = _target;
    }
};
template<typename W, typename V>
class Node
{
public:
    Node<W,V>();
    Node<W,V>(const V& value);
    void addTarget(const W& weight, Node<W,V>* target);
    void setMark(const W&);
    Node<W,V>* DFS_recursive(const V& value);
    Node<W,V>* DFS(const V& value);
    Node<W,V>* BFS(const V& value);
    V getValue()const{return m_value;}
    virtual ~Node();
    friend class Graph<W,V>;
private:
    std::vector<Edge<W,V>> edges;
    W mark;
    V m_value;
    bool visited = false;
};
template<typename W, typename V>
class Graph
{
public:
    W Dijkstra(Node<W,V>*, Node<W,V>*);
    W Dijkstra(const V&, const V&);
    void AddNode();
    void AddNode(const V&);
    void AddNode(Node<W,V>*);
    void AddTarget(const V&,const V&,const W&);
    void AddPath(const V&,const V&,const W&);
    bool DFS(Node<W,V>&,Node<W,V>&);
    bool BFS(Node<W,V>&,Node<W,V>&);
private:
    std::unordered_map<V, Node <W,V>*> m_nodes;
};
