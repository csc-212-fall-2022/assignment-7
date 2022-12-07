#include "Graph.hpp"
#include <climits>
#include <deque>
#include <iostream>
#include <set>
#include <stdexcept>

namespace assignment7 {
auto operator<<(std::ostream &os, const Edge &e) -> std::ostream & {
  os << e.source << "->" << e.target;
  return os;
}

auto operator<<(std::ostream &os, Vertex &v) -> std::ostream & {
  os << "Vertex{id=" << v.id << ",pred=" << v.pred << ",d=" << v.d << "}";
  return os;
}

Graph::Graph(std::vector<Vertex> &vertices, std::vector<Edge> &edges)
    : edges_(edges) {
  for (const auto &v : vertices) {
    vertices_.emplace(v.id, v);
  }
}

void Graph::InitializeSingleSource(Vertex &source) {
  for (auto &[k, v] : vertices_) {
    v.pred = nullptr;
    v.d = INT_MAX;
    if (v.id == source.id) {
      v.d = 0;
    }
  }
}

// The standard Relax implementation, except we return a bool saying
// whether we actually relaxed the edge.
auto Graph::Relax(const Edge &e) -> bool {
  // this is a bit of a hack around the fact I'm failing at modifying the
  // references in the Edge
  auto &source = vertices_.at(e.source.id);
  auto &target = vertices_.at(e.target.id);
  // Need to make sure we don't overflow the integers
  if (source.d < INT_MAX && target.d > e.weight + source.d) {
    target.d = e.weight + source.d;
    target.pred = &source;
    return true;
  }
  return false;
}

auto Graph::GetVertex(int i) -> Vertex & { return vertices_.at(i); }

// The standard Bellman-Ford implementation we saw in class, but counting
// the number of iterations we make through the outer loop.
auto Graph::BellmanFord(Vertex &source) -> int {
  InitializeSingleSource(source);
  int iterations = 0;
  // start iterating at 1 to iterate |V| - 1 times
  for (auto i = 1; i < vertices_.size(); i++) {
    // count our iterations for part 2
    iterations++;
    for (auto const &e : edges_) {
      auto relaxed = Relax(e);
    }
  }
  for (auto const &e : edges_) {
    // Again hacking around the fact we're not updating in the edges.
    auto source = vertices_.at(e.source.id);
    auto target = vertices_.at(e.target.id);
    if (source.d < INT_MAX && target.d > e.weight + source.d) {
      return INT_MAX;
    }
  }
  return iterations;
}

// Find the shortest path in G from the vertex with id = source_id
// to the vertex with id = target_id
// Return a deque rather than a vector so we can call push_front()
auto Graph::ShortestPath(int source_id, int target_id) // NOLINT
    -> std::deque<int> {
  throw std::runtime_error("Implement me!");
}
} // namespace assignment7
