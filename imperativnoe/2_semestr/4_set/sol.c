#include "sol.h"

#include <stdlib.h>

typedef struct {
  Edge* edges;
  int size;
  int capacity;
} EdgeList;

static EdgeList* incidentLists;
static int numVertices;

static void initEdgeList(EdgeList* list) {
  list->size = 0;
  list->capacity = 4;
  list->edges = (Edge*)malloc(list->capacity * sizeof(Edge));
}

static void addEdge(EdgeList* list, Edge edge) {
  if (list->size == list->capacity) {
    list->capacity *= 2;
    list->edges = (Edge*)realloc(list->edges, list->capacity * sizeof(Edge));
  }
  list->edges[list->size++] = edge;
}

void init() {
  numVertices = getVerticesCount();
  incidentLists = (EdgeList*)malloc(numVertices * sizeof(EdgeList));
  for (int i = 0; i < numVertices; i++) {
    initEdgeList(&incidentLists[i]);
  }

  Edge edge;
  while (readEdge(&edge)) {
    addEdge(&incidentLists[edge.from], edge);
    addEdge(&incidentLists[edge.to], (Edge){edge.to, edge.from, edge.weight});
  }
}

void destroy() {
  for (int i = 0; i < numVertices; i++) {
    free(incidentLists[i].edges);
  }
  free(incidentLists);
}

int getEdgesCount(int iVertex) { return incidentLists[iVertex].size; }

Edge getIncidentEdge(int iVertex, int iIndex) {
  return incidentLists[iVertex].edges[iIndex];
}
