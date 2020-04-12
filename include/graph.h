#include <vector>

class Graph {
    std::string name;
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    public:
        Graph(std::string name, std::vector<Node> nodes, std::vector<Edge> edges);

        std::vector<Edge> from_tuples(std::vector<std::tuple<int32_t, int32_t>> connections_);

        Graph(std::string name_, std::vector<std::tuple<int32_t, int32_t>> connections_);

        Graph(std::string name_, std::vector<Edge> edges_);

        std::vector<Node> getNodes();

        std::vector<Edge> getEdges();
};
