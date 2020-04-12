#include <iostream>
#include "../include/node.h"
#include "../include/edge.h"
#include "../include/graph.h"
#include <vector>
#include <tuple>


int main(){

    std::cout << "Welcome to grapher" << std::endl;

    Graph g("My graph", std::vector<std::tuple<int32_t, int32_t>>{
                               std::make_tuple(1, 2),
                               std::make_tuple(1, 4),
                               std::make_tuple(2, 5),
                               std::make_tuple(4, 1)});

    auto all_nodes = [](Graph& gr){
        for (Node n : gr.getNodes())
        {
            std::cout << n.value() << std::endl;
        }
    };

    all_nodes(g);
    return 0;
}
