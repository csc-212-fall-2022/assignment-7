#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <utility>
#include <vector>

namespace assignment7 {

struct Vertex {
  int id;
  Vertex *pred;
  int d;

  Vertex(int n) {
    id = n;
    pred = nullptr;
    d = INT_MAX;
  }

  auto operator<(const Vertex &other) const -> bool { return id < other.id; }
};

auto operator<<(std::ostream &os, Vertex &v) -> std::ostream &;

struct Edge {
  Vertex &source;
  Vertex &target;
  int weight;

  Edge(Vertex &s, Vertex &t, int w) : source(s), target(t) { // NOLINT
    weight = w;
  }

  auto operator<(const Edge &other) const -> bool {
    std::pair<Vertex, Vertex> p1 = {source, target};
    std::pair<Vertex, Vertex> p2 = {other.source, other.target};
    return p1 < p2;
  }
};

auto operator<<(std::ostream &os, Edge &e) -> std::ostream &;

class Graph {
private:
  std::map<int, Vertex> vertices_;
  std::vector<Edge> edges_;

  void InitializeSingleSource(Vertex &);

  auto Relax(const Edge &) -> bool;

public:
  Graph(std::vector<Vertex> &, std::vector<Edge> &);

  auto GetVertex(int i) -> Vertex &;

  auto BellmanFord(Vertex &) -> int;

  auto ShortestPath(int, int) -> std::deque<int>;
};
} // namespace assignment7
