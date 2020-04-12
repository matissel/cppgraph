#include <vector>

class Graph {
    std::string name_;
    std::vector<Edge> edges_;
    std::vector<Node> nodes_;

    public:
        Graph(std::string name, std::vector<Node> nodes, std::vector<Edge> edges);

        std::vector<Edge> fromTuples(std::vector<std::tuple<int32_t, int32_t>> connections);

        Graph(std::string name, std::vector<std::tuple<int32_t, int32_t>> connections);

        Graph(std::string name, std::vector<Edge> edges);

        std::vector<Node> getNodes();

        std::vector<Edge> getEdges();

        void removeDuplicateEdges();

        void addEdge(Edge edge);

        void addNode(Node node);
};
