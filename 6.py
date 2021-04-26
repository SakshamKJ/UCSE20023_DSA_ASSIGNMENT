import sys

class Graph(object):
    def __init__(self, vertices):
        self.vertices = vertices                        #total number of Vertices in the graph
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]        #initializing the adjacency matrix with zeroes

    def getMinimumKey(self, weight, visited_edges):
        min = 9999                                      #initializing the min key by an infinite number

        for i in range(self.vertices):
            
            if weight[i] < min and visited_edges[i] == False:         #finding the edge with minimum weight if the edge is not visited
                min = weight[i]
                minIndex = i

        return minIndex                                         #returning the index of the found edge with minimum weight

    def primsMST(self):
        weight = [9999] * self.vertices     #this lists stores the weights of all the vertices
        MST = [None] * self.vertices        #this list contains our MST
        weight[0] = 0                       #weight of the root node will be 0
        visited_edges = [False] * self.vertices
        MST[0] = -1                         #we choose the first node as root vertex

        for _ in range(self.vertices):
            minIndex = self.getMinimumKey(weight, visited_edges)
            
            visited_edges[minIndex] = True                #marking the index as visited

            for vertex in range(self.vertices):
                if self.graph[minIndex][vertex] > 0 and visited_edges[vertex] == False and weight[vertex] > self.graph[minIndex][vertex]:
                    weight[vertex] = self.graph[minIndex][vertex]
                    MST[vertex] = minIndex

        self.printMST(MST)

    def printMST(self, MST):
        print ("Edge      Weight")
        for i in range(1, self.vertices):
            print (MST[i],"-",i,"      ",self.graph[i][ MST[i] ])
        
if __name__ == '__main__':
    g  = Graph(6)

    g.graph = [[0, 3, 2, 5, 7, 3],
               [3, 0, 4, 8, 6, 6],
               [2, 4, 0, 7, 1, 3],
               [5, 8, 7, 0, 2, 4],
               [7, 6, 1, 2, 0, 3],
               [3, 6, 3, 4, 3, 0]]

    g.primsMST()
