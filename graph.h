#ifndef __GRAPH__
#define __GRAPH__

#include <vector>
#include <iostream>

struct node {
    uint32_t _val;
    node* next;
    node() {}
    node(const uint32_t& val) : _val(val), next(nullptr) {}
};

class graph_api_interface {
    public:
        enum RetCode {
            SUCCESS = 0,
            FAILED
        };

        enum TypeOfGraph {
            UNDIRECTED  =   0,
            DIRECTED,
        };

    public:
        virtual void init() = 0;
        virtual RetCode insertVertice(const uint32_t& u, const uint32_t& v) = 0;
        virtual void printGraphic() = 0;
    protected:
        virtual graph_api_interface::RetCode addVertices(const uint32_t& u, const uint32_t& v) = 0;
};

class undirected_graph_api : public graph_api_interface {
    
    public:
        static undirected_graph_api* getInstance(const uint32_t&);
        void init();
        graph_api_interface::RetCode insertVertice(const uint32_t& u, const uint32_t& v);
        void printGraphic();
    
    protected:
        graph_api_interface::RetCode addVertices(const uint32_t& u, const uint32_t& v);

    private:
        undirected_graph_api(const uint32_t&);

    private:
        std::vector< std::vector<int> > m_listGraph;
        uint32_t m_size;
};

#endif