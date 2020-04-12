#include "../include/node.h"
#include "../include/edge.h"

Node Edge::getFrom(){
    return from;
}
Node Edge::getTo(){
    return to;
}

int32_t Edge::getFromValue(){
    return from.getValue();
}

int32_t Edge::getToValue(){
    return to.getValue();
}

Edge::Edge(Node from, Node to):from(from), to(to){}
