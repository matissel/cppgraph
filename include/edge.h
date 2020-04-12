
class Edge
{
    Node from_;
    Node to_;

    public:
        Node from();
        Node to();
        int32_t fromValue();
        int32_t toValue();
        Edge(Node from, Node to);

};
