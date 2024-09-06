#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200001
#define INF INT_MAX

typedef struct Node {
  int vertex;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
} AdjList;

typedef struct {
  int items[MAX_N];
  int front, rear;
} Queue;

void init_queue(Queue* q);
bool is_empty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);

Node* create_node(int v);
void add_edge(AdjList* graph, int u, int v);
void bfs(int start, int n, AdjList* graph, int* dist);

int main() {
  FILE* input = fopen("input.txt", "r");
  FILE* output = fopen("output.txt", "w");

  int n, m;
  fscanf(input, "%d %d", &n, &m);

  AdjList* graph = (AdjList*)malloc((n + 1) * sizeof(AdjList));
  for (int i = 0; i <= n; ++i) {
    graph[i].head = NULL;
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    fscanf(input, "%d %d", &u, &v);
    add_edge(graph, u, v);
  }

  int* dist = (int*)malloc((n + 1) * sizeof(int));
  for (int i = 0; i <= n; ++i) {
    dist[i] = INF;
  }

  bfs(1, n, graph, dist);

  for (int i = 1; i <= n; ++i) {
    if (dist[i] == INF) {
      fprintf(output, "-1\n");
    } else {
      fprintf(output, "%d\n", dist[i]);
    }
  }

  for (int i = 0; i <= n; ++i) {
    Node* temp = graph[i].head;
    while (temp) {
      Node* to_free = temp;
      temp = temp->next;
      free(to_free);
    }
  }
  free(graph);
  free(dist);

  fclose(input);
  fclose(output);

  return 0;
}

void init_queue(Queue* q) {
  q->front = 0;
  q->rear = 0;
}

bool is_empty(Queue* q) { return q->front == q->rear; }

void enqueue(Queue* q, int value) { q->items[q->rear++] = value; }

int dequeue(Queue* q) { return q->items[q->front++]; }

Node* create_node(int v) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->vertex = v;
  new_node->next = NULL;
  return new_node;
}

void add_edge(AdjList* graph, int u, int v) {
  Node* new_node = create_node(v);
  new_node->next = graph[u].head;
  graph[u].head = new_node;
}

void bfs(int start, int n, AdjList* graph, int* dist) {
  Queue q;
  init_queue(&q);
  enqueue(&q, start);
  dist[start] = 0;

  while (!is_empty(&q)) {
    int u = dequeue(&q);
    Node* temp = graph[u].head;
    while (temp) {
      int v = temp->vertex;
      if (dist[v] == INF) {
        dist[v] = dist[u] + 1;
        enqueue(&q, v);
      }
      temp = temp->next;
    }
  }
}

// как переделать в дфс