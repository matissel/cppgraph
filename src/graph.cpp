#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include "stdint.h"
#include <functional>

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

std::vector<Edge> Graph::edges()
{
    return edges_;
}

std::vector<Node> Graph::nodes()
{
    return nodes_;
}

void Graph::setName(std::string name)
{
    name_ = name;
}

std::string Graph::name()
{
    return name_;
}

void Graph::removeDuplicateEdges()
{
    //TODO
}

void Graph::addNode(Node node)
{
    for(Node &n: nodes_){
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

std::vector<Node> Graph::neighbors(Node &n)
{
    std::vector<Node> neighbors={};
    for(Edge e: edges_)
    {
        if(e.fromValue() == n.value())
        {
            neighbors.push_back(e.to());
        }else if(e.toValue() == n.value())
        {
            neighbors.push_back(e.from());
        }
    }
    return neighbors;
}

std::string Graph::depthFirstSearch()
{
    std::string search = "";
    std::vector<int32_t> marqued={};

    std::function<void(Node &n)> explore = [this,&marqued, &explore, &search](Node &n)  -> void
    {
        search.append(std::to_string(n.value()));
        marqued.push_back(n.value());
        for(Node neighbor : neighbors(n))
        {
            if( std::find(std::begin(marqued),std::end(marqued), neighbor.value()) == std::end(marqued) )
            {
                explore(neighbor);
            }
        }
    };

    for(Node &n: nodes_)
    {
        // Unmarked node
        if( std::find(std::begin(marqued),std::end(marqued), n.value()) == std::end(marqued) )
            explore(n);
    }

    return search;
}

int32_t Graph::size()
{
    return nodes_.size();
}
