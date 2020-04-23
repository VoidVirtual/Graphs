#include "Graph.h"
template<typename W, typename V>
Node<W,V>::Node()
{

}
template<typename W, typename V>
Node<W,V>::Node(const V& value)
{
    m_value = value;
}
template<typename W, typename V>
Node<W,V>::~Node()
{

}
template<typename W, typename V>
void Node<W,V>::addTarget(const W& weight, Node<W,V>* targetNode)
{
    edges.push_back(Edge<W,V>(weight, targetNode));
}
template<typename W, typename V>
Node<W,V>* Node<W,V>::DFS_recursive(const V& value)
{
    visited = true;
    Node<W,V>* res = nullptr;
    if(m_value==value)
        return this;
    for(auto edge: edges)
    {
        if(!edge.targetNode->visited)
        {
            res = edge.targetNode->DFS_recursive(value);
            if(res!=nullptr)
                break;
        }
    }
    return res;
}
template<typename W, typename V>
Node<W,V>* Node<W,V>::DFS(const V& value)
{
    std::stack<Node<W,V>*> nodeStack;
    visited = true;
    nodeStack.push(this);
    while(!nodeStack.empty())
    {
        auto current = nodeStack.top(); nodeStack.pop();
        current->visited = true;
        if(current->m_value==value)
            return current;
        else
            for(auto edge: current->edges)
                if(!edge.targetNode->visited)
                    nodeStack.push(edge.targetNode);
    }
    return nullptr;
}
template<typename W, typename V>
Node<W,V>* Node<W,V>::BFS(const V& value)
{
    std::queue<Node<W,V>*> nodeQueue;
    visited = true;
    nodeQueue.push(this);
    while(!nodeQueue.empty())
    {
        auto current = nodeQueue.back(); nodeQueue.pop();
        current->visited = true;
        if(current->m_value == value)
            return current;
        for(auto edge: current->edges)
            if(!edge.targetNode->visited)
                nodeQueue.push(edge.targetNode);
    }
    return nullptr;
}

template<typename W, typename V>
void Node<W,V>::setMark(const W& weight)
{
    mark = weight;
}
template<typename W, typename V>
W Graph<W,V>::Dijkstra(Node<W,V>* startNode, Node<W,V>* targetNode)
{
    for(auto it: m_nodes)
        it.second->setMark(inf<W>);
    startNode->setMark(0);
    using namespace std;
    priority_queue<W, vector<pair<W,Node<W,V>*> >, greater<pair<W, Node<W,V>*>> > unvisited;
    for(auto it: m_nodes)
        unvisited.push(std::make_pair(it.second->mark, it.second));
    while(!unvisited.empty())
    {
        auto it = unvisited.top();
        Node<W,V>* current = it.second;
        unvisited.pop();
        current->visited = true;
        for(auto edge: current->edges)
        {
            if(edge.targetNode->visited && edge.targetNode!=targetNode)
                continue;
            if(edge.targetNode->mark > current->mark + edge.weight)
            {
                edge.targetNode->mark  = current->mark + edge.weight;
            }
        }
    }
   return targetNode->mark;
}
template<typename W, typename V>
W Graph<W,V>::Dijkstra(const V& startValue,const  V& targetValue)
{
    auto it1 = m_nodes.find(startValue);
    auto it2 = m_nodes.find(targetValue);
    if(it1==m_nodes.end()||it2==m_nodes.end())
        return inf<W>;
    auto startNode = it1->second;
    auto targetNode = it2->second;
    return Dijkstra(startNode, targetNode);
}
template<typename W, typename V>
void Graph<W,V>::AddNode(Node<W,V>* node)
{
    m_nodes.insert(std::make_pair(node->m_value,node));
}
template<typename W, typename V>
void Graph<W,V>::AddNode(const V& value)
{
    m_nodes.insert(std::make_pair(value,new Node<W,V>(value)));
}
template<typename W, typename V>
void Graph<W,V>::AddTarget(const V& startValue, const V& targetValue,const W& weight)
{
    auto startNode = m_nodes.find(startValue)->second;
    auto targetNode = m_nodes.find(targetValue)->second;
    startNode->addTarget(weight, targetNode);
}
template<typename W, typename V>
void Graph<W,V>::AddPath(const V& startValue, const V& targetValue, const W& weight)
{
    AddNode(startValue);
    AddNode(targetValue);
    auto startNode = m_nodes.find(startValue)->second;
    auto targetNode = m_nodes.find(targetValue)->second;
    startNode->addTarget(weight, targetNode);
}
template<typename W, typename V>
bool Graph<W,V>::DFS(Node<W,V>& start, Node<W,V>& target)
{
    if(start.DFS(target.m_value))
        return true;
    return false;
}
template<typename W, typename V>
bool Graph<W,V>::BFS(Node<W,V>& start, Node<W,V>& target)
{
    if(start.BFS(target.m_value))
        return true;
    return false;
}
