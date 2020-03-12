import sys
# time complexity O(n**2) for every node checking the nearest node 
# If the input graph is represented using adjacency list, then the time complexity of Prim’s algorithm can be reduced to O(E log V) ,this method I willluse 
# Dijkstar algo as it is smilar to prims
# both kruskal and prims alogo work even if the weights are negatve because
# these algo selects single minimum weight edge without caring about the overall total weights. 

class Graph :
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = [[0 for i in range(vertices)] for j in range(vertices)]
        self.mst = []
        self.parent = [0 for i in range(vertices)]

    def minWtnode(self, nodeWts):
        minwt = sys.maxsize
        minwt_node = 0
        print("nodewts = ",nodeWts)
        for i in range(self.vertices):
            if (nodeWts[i] < minwt) and (i not in self.mst):
                minwt = nodeWts[i]
                minwt_node = i
        print("minwt_node = ", minwt_node)
        return minwt_node

    def primsMST(self):
        nodeWts = [sys.maxsize for i in range(self.vertices)]
        nodeWts[0] = 0
        self.parent[0] = -1
        for count in range(self.vertices) :
            minnode = self.minWtnode(nodeWts)   
            print("minode = ", minnode)        
            self.mst.append(minnode)
            for adjnode in range(self.vertices) : 
                if (self.graph[minnode][adjnode] > 0) and (adjnode not in self.mst) and (nodeWts[adjnode] > self.graph[minnode][adjnode]):
                    nodeWts[adjnode] = self.graph[minnode][adjnode]
                    self.parent[adjnode] = minnode

g = Graph(5)
#print(g.graph)
'''
g.graph =  [ [0, 2, 1],
             [2, 0, 3],
             [1, 3, 0]]
'''
g.graph = [ [0, 2, 0, 6, 0], 
            [2, 0, 3, 8, 5], 
            [0, 3, 0, 0, 7], 
            [6, 8, 0, 0, 9], 
            [0, 5, 7, 9, 0]]    
                 
g.primsMST()
print("mst = ", g.mst)
print("mst = ", g.parent)