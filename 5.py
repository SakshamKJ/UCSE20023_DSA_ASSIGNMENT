class Graph():
    def __init__(self):
        self.vertex = {}

    def edge_add(self, fromVertex, toVertex):
        if fromVertex in self.vertex.keys():
            self.vertex[fromVertex].append(toVertex)
        else:
            self.vertex[fromVertex] = [toVertex]

    def BFS(self, startVertex):
        visited = [False] * len(self.vertex)
        queue = []
        visited[startVertex] = True
        queue.append(startVertex)
        while queue:
            startVertex = queue.pop(0)
            print(startVertex, end = ' ')
            for i in self.vertex[startVertex]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True

    def DFS(self):
        visited = [False] * len(self.vertex)
        for i in range(len(self.vertex)):
            if visited[i] == False:
                self.DFSRec(i, visited)

    def DFSRec(self, startVertex, visited):
        visited[startVertex] = True
        print(startVertex, end = ' ')
        for i in self.vertex.keys():
            if visited[i] == False:
                self.DFSRec(i, visited)

                

    
gr = Graph()
gr.edge_add(0, 1)
gr.edge_add(0, 2)
gr.edge_add(1, 2)
gr.edge_add(2, 0)
gr.edge_add(2, 3)
gr.edge_add(3, 3)

print('BFS:')
gr.BFS(2)

print('\nDFS: ')
gr.DFS()


