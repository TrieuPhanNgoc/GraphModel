#include "graph.h"


int main() {
    // Demo for undirected graph -> we don't need to make reverse
    auto graph = undirected_graph_api::getInstance(3);
    graph->init();
    graph->insertVertice(0, 1);
    graph->insertVertice(0, 2);
    graph->insertVertice(1, 2);
    graph->printGraphic();

    return 0;
}