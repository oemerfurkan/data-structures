#include <iostream>
#include "../structures/graph/directed-graph.h"

int main() {
    directed_graph_impl::DirectedGraph *graph = new directed_graph_impl::DirectedGraph();

    graph->add_node();
    graph->add_node();
    graph->add_node();
    graph->add_node();
    graph->add_node();
    graph->add_node();
    graph->add_node();
    graph->add_node();
    graph->add_node();
    graph->add_node();

    graph->add_edge(&graph->nodes[0], &graph->nodes[1], 1);
    graph->add_edge(&graph->nodes[4], &graph->nodes[8], 1);
    graph->add_edge(&graph->nodes[0], &graph->nodes[7], 1);
    graph->add_edge(&graph->nodes[6], &graph->nodes[3], 1);
    graph->add_edge(&graph->nodes[1], &graph->nodes[2], 1);
    graph->add_edge(&graph->nodes[8], &graph->nodes[3], 1);
    graph->add_edge(&graph->nodes[1], &graph->nodes[4], 1);
    graph->add_edge(&graph->nodes[2], &graph->nodes[3], 1);
    graph->add_edge(&graph->nodes[4], &graph->nodes[2], 1);
    graph->add_edge(&graph->nodes[3], &graph->nodes[4], 1);
    graph->add_edge(&graph->nodes[6], &graph->nodes[0], 1);
    graph->add_edge(&graph->nodes[7], &graph->nodes[1], 1);
    

    std::cout << "Graph after creation." << std::endl;
    graph->print_graph();

    std::cout << "Graph after deleting edge between 0 and 1." << std::endl;
    graph->delete_edge(&graph->nodes[0], &graph->nodes[1]);

    graph->print_graph();

    graph->render_graph();

    delete graph;
}