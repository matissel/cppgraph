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
    : name_(name), nodes_(nodes), edges_(edges) {}

std::vector<Edge> Graph::fromTuples(std::vector<std::tuple<int32_t, int32_t>> connections)
{
    std::vector<Edge> edges = {};
    for (const auto &tp : connections)
    {
        edges.push_back(Edge(Node(std::get<0>(tp)), Node(std::get<1>(tp))));
    }
    return edges;
}

// Constructor using list of tuple to create connections
Graph::Graph(std::string name, std::vector<std::tuple<int32_t, int32_t>> connections) : Graph::Graph(name, fromTuples(connections)) {}

Graph::Graph(std::string name, std::vector<Edge> edges) : name_(name), edges_(edges)
{
    std::vector<int> node_values = {};
    std::vector<Node> nodes_tmp;
    for (Edge e : edges)
    {
        if (find(node_values.begin(), node_values.end(), e.fromValue()) == node_values.end())
        {
            node_values.push_back(e.fromValue());
            nodes_tmp.push_back(Node(e.fromValue()));
        }
        if (find(node_values.begin(), node_values.end(), e.toValue()) == node_values.end())
        {
            node_values.push_back(e.toValue());
            nodes_tmp.push_back(Node(e.toValue()));
        }
    }
    nodes_ = nodes_tmp;
}

std::vector<Edge> Graph::getEdges()
{
    return edges_;
}

std::vector<Node> Graph::getNodes()
{
    return nodes_;
}


void Graph::removeDuplicateEdges()
{
    //TODO
}

void Graph::addNode(Node node)
{
    for(Node n: nodes_){
        if(n.value() == node.value())
        {
            std::cout << "Can't add node with value " << n.value() << ", already in the graph" << std::endl;
            return;
        }
    }
    nodes_.push_back(node);
}

void Graph::addEdge(Edge e)
{
    //TODO
}
