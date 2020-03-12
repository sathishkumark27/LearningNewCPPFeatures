from heapq import *
from collections import defaultdict
import sys

class Graph :
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = defaultdict(list)
        self.spt = [0 for i in range(vertices)]

    def addEdge(self, src, dst, wt) :
        self.graph[src].append([wt, dst])
        self.graph[dst].append([wt, src])

    def dijkstra(self, src) :
        wts = [sys.maxsize for i in range(self.vertices)]
        wts[src] = 0
        h = [[0,src]] #[nodeWeight, nodeIndex]
        heapify(h)
        #for count in range(self.vertices) :
        while (len(h) > 0) :
            nodewt, nodeindex  = heappop(h) #[nodeWeight, nodeIndex]            
            adjnodes = self.graph[nodeindex]
            for adjnodewt, adjnodeindex  in adjnodes :
                if (nodewt + adjnodewt < wts[adjnodeindex]) :
                    wts[adjnodeindex] = nodewt + adjnodewt
                    heappush(h, [nodewt + adjnodewt, adjnodeindex])
                    self.spt[adjnodeindex] =  nodewt + adjnodewt 


'''
g = Graph(3)
g. addEdge(0, 1, 2)
g. addEdge(1, 2, 1)
g. addEdge(2, 0, 4)
g.dijkstra(0)
'''
graph = Graph(9) 
graph.addEdge(0, 1, 4) 
graph.addEdge(0, 7, 8) 
graph.addEdge(1, 2, 8) 
graph.addEdge(1, 7, 11) 
graph.addEdge(2, 3, 7) 
graph.addEdge(2, 8, 2) 
graph.addEdge(2, 5, 4) 
graph.addEdge(3, 4, 9) 
graph.addEdge(3, 5, 14) 
graph.addEdge(4, 5, 10) 
graph.addEdge(5, 6, 2) 
graph.addEdge(6, 7, 1) 
graph.addEdge(6, 8, 6) 
graph.addEdge(7, 8, 7) 
graph.dijkstra(0) 
print("spt = ", graph.spt)
