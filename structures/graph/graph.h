#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

namespace graph_impl
{
    class GraphNode
    {
    public:
        int id;
        std::vector<GraphNode> neighbors;
    };

    class Graph
    {
    public:
        int node_count;
        std::vector<GraphNode> nodes;
        Graph *create();
        GraphNode *add_node();
        GraphNode *delete_node(GraphNode *);
        GraphNode *add_edge(GraphNode *node1, GraphNode *node2, int weight);
        GraphNode *delete_edge(GraphNode *node1, GraphNode *node2);
        void print_graph();
        void render_graph();
    };
}

#endif