#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <vector>

namespace directed_graph_impl
{
    class DirectedGraphNode
    {
    public:
        int id;
        std::vector<DirectedGraphNode> neighbors;
    };

    class DirectedGraph
    {
    public:
        int node_count;
        std::vector<DirectedGraphNode> nodes;
        DirectedGraph *create();
        DirectedGraphNode *add_node();
        DirectedGraphNode *delete_node(DirectedGraphNode *);
        DirectedGraphNode *add_edge(DirectedGraphNode *node1, DirectedGraphNode *node2, int weight);
        DirectedGraphNode *delete_edge(DirectedGraphNode *node1, DirectedGraphNode *node2);
        void print_graph();
        void render_graph();
    };
}

#endif