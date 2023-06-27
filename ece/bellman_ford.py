class Graph:
    def __init__(self,v):
        self.v = v
        self.vertices=[]

    def add_edge(self,s,d,w):
        self.vertices.append([s,d,w])

    def print_distance(self, dist):
        print("Vertex\t\tDistance")
        for i in range(self.v):
            print(f"{i}\t\t{dist[i]}")

    def bellmanFord(self, src):
        dist = [float('inf') for _ in range(self.v)]
        dist[src] = 0

        for _ in range(self.v-1):
            for s,d,w in self.vertices:
                if dist[s]!=float('inf') and dist[d]>dist[s]+w:
                    dist[d] = dist[s]+w

        for s,d,w in self.vertices:
            if dist[s]!=float('inf') and dist[d]>dist[s]+w:
                print("Graph has negative cycle")
                return

        self.print_distance(dist)

nv = int(input("Enter no. of vertices: "))
ne = int(input("Enter no. of edges: "))

g = Graph(nv)

print("Enter source, destination and weights of edges")
for _ in range(ne):
    s,d,w=map(int,input().split())
    g.add_edge(s,d,w)

src = int(input("Enter source node: "))

g.bellmanFord(src)