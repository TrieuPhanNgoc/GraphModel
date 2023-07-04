#include "graph.h"

graph_api* graph_api::getInstance(const uint32_t& size) {
    return new graph_api(size);
}

graph_api::graph_api(const uint32_t& size) : m_size(size) {}

void graph_api::init() {
    for (uint32_t idex = 0; idex < m_size; ++idex) {
        m_listGraph.push_back(std::vector<int>());
    }
}

graph_api::RetCode graph_api::insertVertice(const uint32_t& u, const uint32_t& v) {
    return this->addVertices(u, v);
}

graph_api::RetCode graph_api::addVertices(const uint32_t& u, const uint32_t& v) {
    if (u < 0 || u > m_size) {
        return graph_api::RetCode::FAILED;
    }

    // Undirected graphic -> making reverse
    m_listGraph[u].push_back(v);
    m_listGraph[v].push_back(u);

    return graph_api::RetCode::SUCCESS;
}

void graph_api::printGraphic() {
    for (uint32_t i = 0; i < m_size; ++i) {
        std::cout << "Vertice " << i << ": head";
        for (int elem : m_listGraph[i]) {
            std::cout << " -> " << (elem);
        }
        std::cout << std::endl;
    }
}