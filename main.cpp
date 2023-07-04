#include "graph.h"


/**
 *      0 ------ 1
 *      |       /
 *      |     /
 *      |    /
 *      |  /
 *       2 
*/
void RunUndirectedTest() {
    // Generating undireted graph with 3 vertices
    auto graph = undirected_graph_api::getInstance(3);
    graph->init();              // Initilizing list
    graph->insertVertice(0, 1); // Worked
    graph->insertVertice(0, 2); // Worked
    graph->insertVertice(1, 2); // Worked
    graph->insertVertice(3, 2); // Could not be inserted due to out range
    graph->printGraphic();
}

int main() {
    RunUndirectedTest();
    return 0;
}