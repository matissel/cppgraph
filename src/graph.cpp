#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include "stdint.h"

#include "../include/node.h"
#include "../include/edge.h"
#include "../include/graph.h"

Graph::Graph(std::string name, std::vector<Node> nodes, std::vector<Edge> edges)
    : name(name), nodes(nodes), edges(edges) {}

std::vector<Edge> Graph::from_tuples(std::vector<std::tuple<int32_t, int32_t>> connections)
{
    std::vector<Edge> edges = {};
    for (const auto &tp : connections)
    {
        edges.push_back(Edge(Node(std::get<0>(tp)), Node(std::get<1>(tp))));
    }
    return edges;
}

// Constructor using list of tuple to create connections
Graph::Graph(std::string name, std::vector<std::tuple<int32_t, int32_t>> connections) : Graph::Graph(name, from_tuples(connections)) {}

Graph::Graph(std::string name, std::vector<Edge> edges) : name(name), edges(edges)
{
    std::vector<int> node_values = {};
    std::vector<Node> nodes_tmp;
    for (Edge e : edges)
    {

        if (find(node_values.begin(), node_values.end(), e.getFromValue()) == node_values.end())
        {
            node_values.push_back(e.getFromValue());
            nodes_tmp.push_back(Node(e.getFromValue()));
        }
        if (find(node_values.begin(), node_values.end(), e.getToValue()) == node_values.end())
        {
            node_values.push_back(e.getToValue());
            nodes_tmp.push_back(Node(e.getToValue()));
        }
    }
    nodes = nodes_tmp;
}

std::vector<Edge> Graph::getEdges()
{
    return edges;
}

std::vector<Node> Graph::getNodes()
{
    return nodes;
}
