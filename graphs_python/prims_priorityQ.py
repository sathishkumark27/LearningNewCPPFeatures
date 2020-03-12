from heapq import *
from collections import defaultdict
import sys

class Graph :
    def __init__(self, vertices):
        self.vertices = vertices
        self.mst = [-1 for i in range(self.vertices)]
        self.graph = defaultdict(list)

    def addEdge(self, src, dst, wt):
            self.graph[src].append([wt, dst])
            self.graph[dst].append([wt,src])

    def primsMST(self):
        wts = [sys.maxsize for i in range(self.vertices)]
        wts[0] = 0   
        #self.mst[0] = -1  #has the parent nodes 
        priQu = [[0, 0]] #nodewt, srcNodeIndex
        #for cout in range(self.vertices):
        while (len(priQu) > 0) :
            heapify(priQu)
            nodeWt, nodeIndex  = heappop(priQu)           
            adjnodes = self.graph[nodeIndex]
            for adjnodeWt, adjnodeIndex  in adjnodes :              
                if (adjnodeWt < wts[adjnodeIndex]):
                    wts[adjnodeIndex] = adjnodeWt
                    priQu.append([adjnodeWt, adjnodeIndex])
                    self.mst[adjnodeIndex] = nodeIndex

g = Graph(5)
g.addEdge(0, 1, 2)
g.addEdge(0, 3, 6)
g.addEdge(1, 2, 3)
g.addEdge(1, 3, 8)
g.addEdge(1, 4, 5)
g.addEdge(2, 4, 7)
g.addEdge(3, 4, 9)
g.primsMST()
print("mst  = ", g.mst)
