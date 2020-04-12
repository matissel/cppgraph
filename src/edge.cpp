#include "../include/node.h"
#include "../include/edge.h"

Node Edge::from(){
    return from_;
}
Node Edge::to(){
    return to_;
}

int32_t Edge::fromValue(){
    return from_.value();
}

int32_t Edge::toValue(){
    return to_.value();
}

Edge::Edge(Node from, Node to):from_(from), to_(to){}
