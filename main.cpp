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
    graph_api_interface* graph = nullptr;
    graph = graph_api_interface::getInstance(graph_api_interface::TypeOfGraph::UNDIRECTED, 3);
    if (graph != nullptr) {
        graph->insertVertice(0, 1); // Worked
        graph->insertVertice(0, 2); // Worked
        graph->insertVertice(1, 2); // Worked
        graph->insertVertice(3, 2); // Could not be inserted due to out range
        graph->printGraphic();
    }
}

/**
 *      0 ------> 1
 *      |        /
 *      |       /
 *      |      /
 *      |     /
 *     \ /   /
 *      .   .
 *        2  <------------ 3
*/
void RunDirectedTest() {
    // Generating undireted graph with 3 vertices
    graph_api_interface* graph = nullptr;
    graph = graph_api_interface::getInstance(graph_api_interface::TypeOfGraph::DIRECTED, 3);
    if (graph != nullptr) {
        graph->insertVertice(0, 1); // Worked
        graph->insertVertice(0, 2); // Worked
        graph->insertVertice(1, 2); // Worked
        graph->insertVertice(3, 2); // Could not be inserted due to out range
        graph->printGraphic();
    }
}

int main() {
    RunUndirectedTest();
    RunDirectedTest();
    return 0;
}