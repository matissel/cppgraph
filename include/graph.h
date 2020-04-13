#include <vector>

class Graph {
    std::string name_;
    std::vector<Edge> edges_;
    std::vector<Node> nodes_;
    std::vector<Edge> fromTuples(std::vector<std::tuple<int32_t, int32_t>> connections);

    public:
        Graph(std::string name, std::vector<Node> nodes, std::vector<Edge> edges);


        Graph(std::string name, std::vector<std::tuple<int32_t, int32_t>> connections);

        Graph(std::string name, std::vector<Edge> edges);

        std::vector<Node> nodes();

        std::vector<Edge> edges();

        std::string name();

        void setName(std::string name);

        void removeDuplicateEdges();

        void addEdge(Edge edge);

        void addNode(Node node);

        std::string depthFirstSearch();

        std::vector<Node> neighbors(Node &n);

        int32_t size();
};
