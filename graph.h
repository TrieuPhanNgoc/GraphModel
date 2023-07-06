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
        static graph_api_interface* getInstance(const TypeOfGraph&, const uint32_t&);
        virtual RetCode insertVertice(const uint32_t& u, const uint32_t& v) = 0;
        virtual void printGraphic()  = 0;

        graph_api_interface* operator=(graph_api_interface* other) {
            return other;
        }
    protected:
        virtual void init()  = 0 ;
        virtual graph_api_interface::RetCode addVertices(const uint32_t& u, const uint32_t& v)  = 0;
};

class undirected_graph_api : public graph_api_interface {
    public:
        undirected_graph_api(const uint32_t&);
        graph_api_interface::RetCode insertVertice(const uint32_t& u, const uint32_t& v);
        void printGraphic();
    
    protected:
        void init();
        graph_api_interface::RetCode addVertices(const uint32_t& u, const uint32_t& v);

    private:
        std::vector< std::vector<int> > m_listGraph;
        uint32_t m_size;
        TypeOfGraph m_type;
};

class directed_graph_api : public graph_api_interface {
    public:
        directed_graph_api(const uint32_t&);
        RetCode insertVertice(const uint32_t& u, const uint32_t& v) ;
        void printGraphic() ;

    protected:
        void init() ;
        graph_api_interface::RetCode addVertices(const uint32_t& u, const uint32_t& v) ;

    private:
        std::vector< std::vector<int> > m_listGraph;
        uint32_t m_size;
        TypeOfGraph m_type;
};

#endif