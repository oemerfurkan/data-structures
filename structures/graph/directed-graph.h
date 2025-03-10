#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <vector>

namespace directed_graph_impl
{
    class GraphNode
    {
    public:
        int id;
        std::vector<GraphNode> neighbors;
    };

    class DirectedGraph
    {
    public:
        int node_count;
        std::vector<GraphNode> nodes;
        DirectedGraph *create();
        GraphNode *add_node();
        GraphNode *delete_node(GraphNode *);
        GraphNode *add_edge(GraphNode *node1, GraphNode *node2, int weight);
        GraphNode *delete_edge(GraphNode *node1, GraphNode *node2);
        void print_graph();
        void render_graph();
    };
}

#endif