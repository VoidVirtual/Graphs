#include <iostream>
#include <fstream>
#include "RouteStand.h"
int main(int argc, char** argv)
{
    RouteStand routes;
    std::ifstream in("input.txt");
    routes.Parse(in);
    routes.AddRoute("Moscow", "Denver", 1);
    std::cout<<routes.getMinDistance("Moscow", "Denver");
    return 0;
}
