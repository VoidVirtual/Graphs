#pragma once
#include "Graph.h"
class RouteStand: private Graph<int, std::string>
{
    public:
        void Parse(std::string& filename)
        {
            std::ifstream in(filename);
            Parse(in);
        }
        void Parse(std::ifstream& in)
        {
            std::string first, second;
            int distance;
            while(!in.eof())
            {
                in>>first>>second>>distance;
                AddPath(first, second, distance);
            }
        }
        void AddRoute(const std::string& first, const std::string& second, int distance)
        {
            AddPath(first, second, distance);
        }
        int getMinDistance(const std::string& first, const std::string& second)
        {
            return Dijkstra(first, second);
        }
};
