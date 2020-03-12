# tme comlexty union or find takes O(n) for n elements worst case
class TreeNode:
    def __init__(self, x):
        self.data = x
        self.parent = None
        self.rank = 0

class UnionFind:
    def __init__(self):
        self.sets = {}

    def makeSet(self, x):
        node = TreeNode(x)
        node.parent = node
        if x not in self.sets :
            self.sets[node.data] = node
    
    def union(self, nodeA, nodeB):
        #print ("findSet(nodeA) :", self.findSet(nodeA).data)
        #print ("findSet(nodeB) :", self.findSet(nodeB).data)
        return self.link(self.findSet(nodeA), self.findSet(nodeB))

    def link(self, nodeA, nodeB):
        if (nodeA == nodeB):
            return False  # loop
        if (nodeA.rank >= nodeB.rank):
            nodeB.parent = nodeA
            if (nodeA.rank == nodeB.rank) :
                nodeA.rank+=1
            #del self.sets[nodeB.data]
        else :
            nodeA.parent = nodeB
            #del self.sets[nodeA.data]
        return True

    def findSet(self, node):
        if (node == node.parent):
            return node
        node.parent = self.findSet(node.parent) #performs path compression by making all the nodes connecting directly to root
        return node.parent
    

uf = UnionFind()
for i in range(1, 8, 1):
    uf.makeSet(i)
#print("sets", uf.sets)
uf.union(uf.sets[1], uf.sets[2])
uf.union(uf.sets[2], uf.sets[3])
uf.union(uf.sets[4], uf.sets[5])
uf.union(uf.sets[6], uf.sets[7])
uf.union(uf.sets[5], uf.sets[6])
uf.union(uf.sets[3], uf.sets[7])
print ("find set 1 = ", uf.findSet(uf.sets[1]).data)
print ("find set 2 = ", uf.findSet(uf.sets[2]).data)
print ("find set 3 = ", uf.findSet(uf.sets[3]).data)
print ("find set 4 = ", uf.findSet(uf.sets[4]).data)
print ("find set 5 = ", uf.findSet(uf.sets[5]).data)
print ("find set 6 = ", uf.findSet(uf.sets[6]).data)
print ("find set 7 = ", uf.findSet(uf.sets[7]).data)
print(uf.union(uf.sets[3], uf.sets[7]))


