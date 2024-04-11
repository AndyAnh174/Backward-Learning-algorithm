#include "network.h"

int main() {
    Network network;
    Node A('A'), B('B'), C('C'), D('D'), E('E');
    
    network.receivePacket(&A, &B);
    network.receivePacket(&A, &B);
    network.receivePacket(&B, &C);

    return 0;
}
