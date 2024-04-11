#include "network.h"

void Network::receivePacket(Node* src, Node* dest) {
    std::cout << "Node " << dest->id << " received packet from Node " << src->id << std::endl;

    if (src->id == dest->id) {
        std::cout << "Node " << dest->id << " is the destination. Packet processed." << std::endl;
        return;
    }

    if (table.count({src->id, dest->id}) || table.count({dest->id, src->id})) {
        std::cout << "Forwarding entry found in the table." << std::endl;
        Node* n1 = table[{src->id, dest->id}].first;
        Node* n2 = table[{src->id, dest->id}].second;

        Node* nextNode = (n1->id != src->id) ? n1 : n2;
        if (nextNode->id != src->id) {
            std::cout << "Sending packet to Node " << nextNode->id << std::endl;
            table[{src->id, dest->id}] = {src, nullptr};
            return;
        }
    }

    table[{src->id, dest->id}] = {src, nullptr};

    std::cout << "Broadcasting packet to all nodes except Node " << src->id << std::endl;

    for (auto& entry : table) {
        if (entry.second.second == nullptr) {
            entry.second.second = src;
        }
    }
}
