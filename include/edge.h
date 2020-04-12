
class Edge
{
    Node from;
    Node to;

    public:
        Node getFrom();
        Node getTo();
        int32_t getFromValue();
        int32_t getToValue();
        Edge(Node from, Node to);
};
