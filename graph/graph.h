#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
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
    };

    Graph *Graph::create()
    {
        Graph *graph = new Graph();
        graph->node_count = 0;
        return graph;
    }

    GraphNode *Graph::add_node()
    {
        GraphNode *node = new GraphNode();
        node->id = node_count;
        nodes.push_back(*node);
        node_count++;
        return node;
    }

    GraphNode *Graph::delete_node(GraphNode *node)
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].id == node->id)
            {
                nodes.erase(nodes.begin() + i);
                node_count--;
                return node;
            }
        }
        return nullptr;
    }

    GraphNode *Graph::add_edge(GraphNode *node1, GraphNode *node2, int weight)
    {
        node1->neighbors.push_back(*node2);
        node2->neighbors.push_back(*node1);
        return node1;
    }

    GraphNode *Graph::delete_edge(GraphNode *node1, GraphNode *node2)
    {
        for (int i = 0; i < node1->neighbors.size(); i++)
        {
            if (node1->neighbors[i].id == node2->id)
            {
                node1->neighbors.erase(node1->neighbors.begin() + i);
            }
        }
        for (int i = 0; i < node2->neighbors.size(); i++)
        {
            if (node2->neighbors[i].id == node1->id)
            {
                node2->neighbors.erase(node2->neighbors.begin() + i);
            }
        }
        return node1;
    }

    void Graph::print_graph()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            std::cout << "Node " << nodes[i].id << " has neighbors: ";
            for (int j = 0; j < nodes[i].neighbors.size(); j++)
            {
                std::cout << nodes[i].neighbors[j].id << " ";
            }
            std::cout << std::endl;
        }
    }
}

#endif