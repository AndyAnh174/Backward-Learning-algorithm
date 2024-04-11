#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include <unordered_map>

class Node {
public:
    char id;
    Node(char _id) : id(_id) {}
};

class Network {
private:
    std::unordered_map<std::pair<char, char>, std::pair<Node*, Node*>> table;

public:
    Network() {}
    void receivePacket(Node* src, Node* dest);
};

#endif // NETWORK_H
