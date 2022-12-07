#include <vector>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Graph.hpp"
#include "doctest/doctest.h"
#include <iostream>

using namespace assignment7;

auto v1 = Vertex(1);
auto v2 = Vertex(2);
auto v3 = Vertex(3);
auto v4 = Vertex(4);
auto v5 = Vertex(5);

std::vector<Vertex> vertices{v1, v2, v3, v4, v5};

std::vector<Edge> edges{Edge{v1, v2, 10}, Edge{v1, v3, 5}, Edge{v2, v3, 2},
                        Edge{v3, v2, 3},  Edge{v2, v4, 1}, Edge{v3, v4, 9},
                        Edge{v3, v5, 2},  Edge{v5, v4, 6}, Edge{v4, v5, 4},
                        Edge{v5, v1, 7}};

auto G = Graph(vertices, edges);

TEST_CASE("Bellman Ford Early Termination I") {
  std::vector<int> expected_distances{0, 8, 5, 9, 7};
  auto num_iterations = G.BellmanFord(v1);

  CHECK_LE(num_iterations, 3);

  // Checking that Bellman-Ford really did work.
  for (int i = 0; i < 5; i++) {
    int expected = expected_distances.at(i);
    CHECK_EQ(expected, G.GetVertex(i + 1).d);
  }
}

TEST_CASE("Bellman Ford Early Termination II") {
  auto num_iterations = G.BellmanFord(v4);

  CHECK_LE(num_iterations, 4);
}

TEST_CASE("Shortest Path I") {
  std::deque<int> expected_path{1, 3, 5};
  auto result = G.ShortestPath(1, 5);
  CHECK_EQ(expected_path, result);
}

TEST_CASE("Shortest Path II") {
  std::deque<int> expected_path{4, 5, 1, 3, 2};
  auto result = G.ShortestPath(4, 2);
  CHECK_EQ(expected_path, result);
}
