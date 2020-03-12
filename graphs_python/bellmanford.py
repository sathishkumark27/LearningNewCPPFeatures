from collections import defaultdict
import sys

class Graph:
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.vertices = vertices
        self.spt = [sys.maxsize for i in range(self.vertices)]
        self.parent = [-1 for i in range(self.vertices)]

    def addEdge(self, src, dst, wt):
        self.graph[src].append([dst, wt])

    def BellmanFord(self, start):
        self.spt[start] = 0
        for v in range(self.vertices-1):
            for src in range(len(self.graph)):
                edges = self.graph[src]
                for dst, wt in edges:
                    if (self.spt[src]+wt < self.spt[dst]):
                        self.spt[dst] = self.spt[src]+wt
                        self.parent[dst] = src

    def isNegtiveWtCycle(self): #after v- time if weights updated then negative weight cycles is present
        for src in range(len(self.graph)):
                edges = self.graph[src]
                for dst, wt in edges:
                    if (self.spt[src]+wt < self.spt[dst]):
                        print("negative weight cycle present")
                        return
        

'''
g = Graph(5) 
g.addEdge(0, 1, -1) 
g.addEdge(0, 2, 4) 
g.addEdge(1, 2, 3) 
g.addEdge(1, 3, 2) 
g.addEdge(1, 4, 2) 
g.addEdge(3, 2, 5) 
g.addEdge(3, 1, 1) 
g.addEdge(4, 3, -3) 
g.BellmanFord(0)
print("spt = ", g.spt)
print("parents = ", g.parent)
'''

g = Graph(4) 
g.addEdge(0, 1, 2) 
g.addEdge(0, 2, 1) 
g.addEdge(2, 3, 4) 
g.addEdge(3, 1, -10) 
g.addEdge(1, 2, 3) 
g.BellmanFord(0)
g.isNegtiveWtCycle()
print("spt = ", g.spt)
print("parents = ", g.parent)