#include <iostream>
#include "../include/node.h"
#include "../include/edge.h"
#include "../include/graph.h"
#include <vector>
#include <tuple>


int main(){

    std::cout << "Welcome to grapher" << std::endl;

    Graph g("g", std::vector<std::tuple<int32_t, int32_t>>{
                               std::make_tuple(1, 2),
                               std::make_tuple(1, 3),
                               std::make_tuple(1, 4),
                               std::make_tuple(2, 5),
                               std::make_tuple(2, 6),
                               std::make_tuple(4, 6),
                               std::make_tuple(3, 7)});

    auto all_nodes = [](Graph& gr){
        std::cout << "Graph " << gr.name() << " has these nodes : ";
        for (Node n : gr.nodes())
        {
            std::cout << n.value() << ',';
        }
        std::cout << std::endl;
    };

    std::cout << "Depth first search of " << g.name() << " : " << g.depthFirstSearch() << std::endl;

    all_nodes(g);
    return 0;
}
