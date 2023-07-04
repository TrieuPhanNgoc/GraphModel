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

class graph_api {
    public:
        enum RetCode {
            SUCCESS = 0,
            FAILED
        };

    public:
        static graph_api* getInstance(const uint32_t&);
        void init();
        RetCode insertVertice(const uint32_t& u, const uint32_t& v);
        void printGraphic();
    
    protected:
        RetCode addVertices(const uint32_t& u, const uint32_t& v);

    private:
        graph_api(const uint32_t&);

    private:
        std::vector< std::vector<int> > m_listGraph;
        uint32_t m_size;
};

#endif