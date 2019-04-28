def createHEdgeList():
    h = [[0,1], [0,2], [0,3], [1,2], [1,3], [2,3]]
    edgeList = []
    for v in h:
        
        v1 = v[0]
        v2 = v[1]
        edgeList.append(v1)
        edgeList.append(v2)
    
    marked = []
    b = [(edgeList.count(i), marked.append(i))[0] for i in edgeList if i not in marked]
    print(b)
    
createHEdgeList()