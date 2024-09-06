#ifndef EDGELISTS_SOL_579846984654
#define EDGELISTS_SOL_579846984654

typedef struct {
  int from, to;
  int weight;
} Edge;

int getVerticesCount();

int readEdge(Edge *oEdge);
void init();

// this function is called whet the graph is no more needed
// you are expected to cleanup the used resources
void destroy();

// returns number of edges indicent to vertex iVertex
int getEdgesCount(int iVertex);

// returns iIndex-th edge incident to the vertex iVertex
// it must have .from == Vertex and .to denoting the other end
Edge getIncidentEdge(int iVertex, int iIndex);

#endif
