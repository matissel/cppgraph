#include "../include/node.h"

int32_t Node::value(){
    return value_;
}

Node::Node(int32_t value): value_(value){

}

Node::Node(int32_t value, bool isolated): value_(value), isolated_(isolated){
}

void Node::setValue(int32_t value){
    value = value;
}
