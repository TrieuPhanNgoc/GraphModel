#include "graph.h"

graph_api_interface* graph_api_interface::getInstance(const TypeOfGraph& type, const uint32_t& size) {
    switch (type)
    {
        case graph_api_interface::TypeOfGraph::UNDIRECTED: {
            return new undirected_graph_api(size);
        }

        case graph_api_interface::TypeOfGraph::DIRECTED: {
            return new directed_graph_api(size);
        }
        default: {
            return nullptr;
        }
    }
}

undirected_graph_api::undirected_graph_api(const uint32_t& size) 
    : m_size(size), m_type(TypeOfGraph::UNDIRECTED) {
        this->init();
    }

void undirected_graph_api::init() {
    for (uint32_t idex = 0; idex < m_size; ++idex) {
        m_listGraph.push_back(std::vector<int>());
    }
}

graph_api_interface::RetCode undirected_graph_api::insertVertice(const uint32_t& u, const uint32_t& v) {
    return this->addVertices(u, v);
}

graph_api_interface::RetCode undirected_graph_api::addVertices(const uint32_t& u, const uint32_t& v) {
    if ((u < 0 || u >= m_size)
    || (v < 0 || v >= m_size)) {
        return graph_api_interface::RetCode::FAILED;
    }

    // Undirected graphic -> making reverse
    m_listGraph[u].push_back(v);
    m_listGraph[v].push_back(u);

    return graph_api_interface::RetCode::SUCCESS;
}

void undirected_graph_api::printGraphic() {
    for (uint32_t i = 0; i < m_size; ++i) {
        std::cout << "Vertice " << i << ": head";
        for (int elem : m_listGraph[i]) {
            std::cout << " -> " << (elem);
        }
        std::cout << std::endl;
    }
}

directed_graph_api::directed_graph_api(const uint32_t& size) 
    : m_size(size), m_type(TypeOfGraph::DIRECTED) {
        this->init();
    }

void directed_graph_api::init() {
    for (uint32_t idex = 0; idex < m_size; ++idex) {
        m_listGraph.push_back(std::vector<int>());
    }
}

graph_api_interface::RetCode directed_graph_api::insertVertice(const uint32_t& u, const uint32_t& v) {
    return this->addVertices(u, v);
}

graph_api_interface::RetCode directed_graph_api::addVertices(const uint32_t& u, const uint32_t& v) {
    if ((u < 0 || u >= m_size)
    || (v < 0 || v >= m_size)) {
        return graph_api_interface::RetCode::FAILED;
    }
    m_listGraph[u].push_back(v);
    return graph_api_interface::RetCode::SUCCESS;
}

void directed_graph_api::printGraphic() {
    for (uint32_t i = 0; i < m_size; ++i) {
        std::cout << "Vertice " << i << ": head";
        for (int elem : m_listGraph[i]) {
            std::cout << " -> " << (elem);
        }
        std::cout << std::endl;
    }
}