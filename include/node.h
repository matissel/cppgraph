#include <stdint.h>

class Node
{
    bool isolated_;
    int32_t value_;
    public:
        int32_t value();
        void setValue(int32_t);
        Node(int32_t value);
        Node(int32_t value, bool isolated);
};
