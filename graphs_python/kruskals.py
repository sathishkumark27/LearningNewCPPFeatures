import union_find
# tomecomlexity of kuskals = time for sorting the dict + union_find
# kruskal tme = O(nLogn + n)
# both kruskal and prims alogo work even if the weights are negatve because
# these algo selects single minimum weight edge without caring about the overall total weights. 
class Graph :
    def __init__ (self, nodes):
        self.nodes = nodes
        self.graph = []
        self.mst = []

    def addEdge(self, src, dst, wt):
        self.graph.append([src, dst, wt])

    def kruskalMST(self) :
        self.graph = sorted(self.graph, key = lambda x : x[2])
        print("sorted graph", self.graph)
        uf = union_find.UnionFind()
        e = 0
        for i in self.graph:
            if (e == self.nodes - 1): # MST will hva eatmost nodes-1 edges so break when satsfies
                break
            if i[0] not in uf.sets :
                uf.makeSet(i[0]) # add node to sets in union_find
            if i[1] not in uf.sets :
                uf.makeSet(i[1])
            #print("i0 =", i[0])
            #print("i1 =", i[1])
            if (False ==  uf.union(uf.sets[i[0]], uf.sets[i[1]])): # can't make union beacuse this edge formas cycle
                continue
            self.mst.append(i)
            e+=1
'''
g = Graph(3)
g.addEdge(1, 2, 2)
g.addEdge(2, 3 ,3)
g.addEdge(3, 1, 1)
'''
# geeks for geeks test case
g = Graph(4) 
g.addEdge(0, 1, 10) 
g.addEdge(0, 2, 6) 
g.addEdge(0, 3, 5) 
g.addEdge(1, 3, 15) 
g.addEdge(2, 3, 4) 


g.kruskalMST()
print("mst = ", g.mst)






    