#include "graph.h"
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <string>

const std::string font_path = "/System/Library/Fonts/Avenir.ttc";
using namespace graph_impl;

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

void Graph::render_graph()
{

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Graph", sf::Style::Default, sf::State::Windowed, settings);

    window.clear(sf::Color::White);

    std::vector<std::array<int, 2>> rendered_edges;
    for (int i = 0; i < nodes.size(); i++)
    {
        // Draw every node around a circular shape
        float angle = 2 * 3.14159 / nodes.size() * i;
        float x = 400 + 200 * cos(angle);
        float y = 300 + 200 * sin(angle);
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color(255, 0, 0));
        circle.setPosition(sf::Vector2f(x, y));

        sf::Font font(font_path);
        sf::Text text(font);
        text.setString(std::to_string(nodes[i].id));
        text.setCharacterSize(18);
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(x + 10, y + 5));

        // Draw edges between nodes
        for (int j = 0; j < nodes[i].neighbors.size(); j++)
        {
            bool is_rendered = false;
            for (int k = 0; k < rendered_edges.size(); k++)
            {
                if (rendered_edges[k][0] == nodes[i].id && rendered_edges[k][1] == nodes[i].neighbors[j].id)
                {
                    is_rendered = true;
                }
            }
            if (is_rendered)
            {
                continue;
            }
            rendered_edges.push_back({nodes[i].neighbors[j].id, nodes[i].id});

            // Calculate the length of the edge
            float neighbor_angle = 2 * 3.14159 / nodes.size() * nodes[i].neighbors[j].id;
            float neighbor_x = 400 + 200 * cos(neighbor_angle);
            float neighbor_y = 300 + 200 * sin(neighbor_angle);

            float length = sqrt(pow(neighbor_x - x, 2) + pow(neighbor_y - y, 2));
            sf::RectangleShape line({length, 1.0f});

            float angle = atan2(neighbor_y - y, neighbor_x - x);
            line.setRotation(sf::degrees(angle * 180 / 3.14159));

            line.setFillColor(sf::Color::Black);
            line.setPosition(sf::Vector2f(x + 20, y + 20));
            window.draw(line);
        }

        window.draw(circle);
        window.draw(text);
    }

    window.display();
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    }
}