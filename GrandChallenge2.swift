//
//  GrandChallenge.swift
//
//
//  Teammates : Benjamin Lee, Zack Zumalt, Keaton Whitehead
//
// Note: This project does not produce any output. We were extremely close to implementing a pseudo BFS
// recursive algorithm to produce the correct output.

import Foundation

extension Array where Element: Hashable {
    func removingDuplicates() -> [Element] {
        var addedDict = [Element: Bool]()
        
        return filter {
            addedDict.updateValue(true, forKey: $0) == nil
        }
    }
    
    mutating func removeDuplicates() {
        self = self.removingDuplicates()
    }
}
class EdgeSet: Hashable {
    var e: Int
    var hashValue: Int {
        return self.e
    }
    
    init(e: Int) {
        self.e = e
    }
}

func ==(lhs: EdgeSet, rhs: EdgeSet) -> Bool {
    return lhs.e == rhs.e
}

class Node: Hashable {
    var e: Int
    var hashValue: Int {
        return self.e
    }
    
    init(e: Int) {
        self.e = e
    }
}

func ==(lhs: Node, rhs: Node) -> Bool {
    return lhs.e == rhs.e
}

struct EdgesUsed {
    var edges: [[Int]]
}

struct GraphNode {
    var id: Int
    var adjacentVertices: [Int:[Int]]
    var edgesCount: Int
    var edgeList: [[Int]]
    
}

struct Motif {
    var nodeList: [GraphNode]
    var edgeList: [[Int]]
    var size: Int
    var edgeCount: Int
    
    init(nodeList: [GraphNode], edgeList: [[Int]], size: Int, edgeCount: Int) {
        self.nodeList = nodeList
        self.edgeList = edgeList
        self.size = size
        self.edgeCount = edgeCount
    }
}


class GrandChallenge {
    
    // global variables
    var allGrahphNodesG = [GraphNode]()
    var allGrahphNodesH = [GraphNode]()
    
    var allGrahphNodesGDict: [Int: GraphNode] = [:]
    var allGrahphNodesHDict: [Int: GraphNode] = [:]
    
    var motif = Motif(nodeList: [GraphNode(id: 0, adjacentVertices: [:], edgesCount: 0, edgeList: [[]])], edgeList: [[]], size: 0, edgeCount: 0)
    
    
    var G : [[Int]] = [[]]
    var H : [[Int]] = [[0,1], [1,2], [0,2]] // Manually input
    var N = 0
    var K = 0
    var currentN = 1;
    
    var gNodes: [Int] = []
    var hNodes: [Int] = []
    
    var edgeListG: [Int : Int] = [:]
    var edgeListH: [Int : Int] = [:]
    
    var adjacencyListG: [Int : [Int]] = [:]
    var adjacencyListH: [Int : [Int]] = [:]
    
    
    var iteration = 1
    var nodesSeen: [Int] = []
    var nodePath: [Int] = [-1]
    
    var edgeHolder = [[[Int]]]()
    var newAdjacentNodesHolder = [GraphNode]()
    var edgesSeen: [[Int]] = [[]]
    
    func load()  {
        K = H.count
        makeEdgeListG(resource: "testG1", type: "txt")
        makeEdgeListH(resource: "testH1", type: "txt", h: [[0,1], [1,2], [0,2]])
        makeAdjacencyListH()
        makeAdjacencyListG()
        setupData()
        traverseGraph()
    }

    func setupData() {
        print(adjacencyListG)
        for (key, value) in adjacencyListG {
            
            var edgeList = [[Int]]()
            for node in value {
                let edge = [key, node]
                edgeList.append(edge as! [Int])
            }
            let graphNode = GraphNode(id: key, adjacentVertices: [key: value], edgesCount: value.count, edgeList: edgeList)
            allGrahphNodesG.append(graphNode)
            allGrahphNodesGDict[key] = graphNode
        }
        for (key, value) in adjacencyListH {
            var edgeList = [[Int]]()
            for node in value {
                let edge = [key, node]
                edgeList.append(edge as! [Int])
            }
            let graphNode = GraphNode(id: key, adjacentVertices: [key: value], edgesCount: value.count, edgeList: edgeList)
            allGrahphNodesH.append(graphNode)
            allGrahphNodesHDict[key] = graphNode
        }
        
        var graphNodes = [GraphNode]()
        
        for val in hNodes {
            var adjacentVertices = [Int:[Int]]()
            
            var edgeList = [[Int]]()
            
            let node = allGrahphNodesHDict[val]
            var adjacentNodes = node!.adjacentVertices
            let graphNode = GraphNode(id: val, adjacentVertices: adjacentNodes, edgesCount: node!.edgesCount, edgeList: node!.edgeList)
            graphNodes.append(graphNode)
            
            
        }
        
        let m = Motif(nodeList: graphNodes, edgeList: H, size: hNodes.count, edgeCount: H.count)
        motif = m
        
    }
    
    // This function begind the graph traversal
    func traverseGraph() {
        // get smallest number of edges
        var edgeLstH = edgeListH
        var edgeLstG = edgeListG
        var valuesOfEdgeListH :[ Int] = []
        var valuesOfEdgeListG :[ Int] = []
        
        //        var isomorphismsSeen = Set<Hashable[Int]>()
        var nodesToCheck: [Int] = []
        
        var currentOrder: [Int] = []
        
        for i in 0...edgeLstH.count - 1 {
            guard let val = edgeLstH[i] else {return}
            valuesOfEdgeListH.append(val)
        }
        guard let minEdgeH = valuesOfEdgeListH.min() else {return} // minimum value of edge to compare
        
        // find a vertex in G that has the same or greater connections as the minimum in H
        
        for i in 0...edgeLstG.count - 1 {
            
            guard let val = edgeLstG[i] else {return}
            valuesOfEdgeListG.append(val)
        }
        guard let minEdgeG = valuesOfEdgeListG.min() else {return} // minimum value of edge to compare
        
        //loop through each vertex
        for (node, numberOfEdges) in edgeLstG {
            if numberOfEdges >= minEdgeH { // if the number of edges for the node is greater than or equal to the minimum number in H
                nodesToCheck.append(node)
            }
        }
        
        
        // turning nodes to check into a collection of graphNodes
        var graphNodesToCheck = [GraphNode]()
        for node in nodesToCheck {
            let allGraphNodes = allGrahphNodesGDict
            let graphNode = allGraphNodes[node]
            graphNodesToCheck.append(graphNode!)
        }
        
        
        getNodesToCheck(nodesToCheck: graphNodesToCheck)
        
    }
    
    // This function removes any nodes that have a number of edge connections smaller than the minimum in H
    // This retrieves the new collection of nodes that is to be checked.
    func getNodesToCheck(nodesToCheck: [GraphNode]) {
        for node in nodesToCheck {
            let mainNodeId = node.id // Integer
            let mainNode = node
            var newNodesToCheck = nodesToCheck
            
            for i in 0...nodesToCheck.count - 1 {
                if nodesToCheck[i].id == mainNodeId {
                    newNodesToCheck.remove(at: i)
                }
            }
            // traverse through adjacent nodes to main node
            // get adjacent Nodes to the main node
            
            let adjacentNodesToMainNode = allGrahphNodesGDict[mainNodeId]!.adjacentVertices[mainNodeId]
            var adjacentNodesToCheck = [GraphNode]()
            for value in adjacentNodesToMainNode! {
                let graphNode = allGrahphNodesGDict[value]!
                adjacentNodesToCheck.append(graphNode)
            }
            
            traverseAdjacentNodesBFS(mainNodeId: mainNodeId, currentNodeCount: 1, adjacentNodesToCheck: adjacentNodesToCheck)
            
        }
    }
    
    
    // This function was made in preparation in order to expermient with a Pseudo Depth First Search
    func traverseAdjacentNodesDFS(mainNodeId: Int, currentNodeCount: Int, adjacentNodesToCheck: [GraphNode]) {
        removeNewAdjacentNodes()
        // depth search each adjacent node 1st level
        var nodeCount = currentNodeCount
        
        if nodeCount < N { // this doesnt run we reach K
            var newNodesToCheck = adjacentNodesToCheck
            
            
        } else { // When we reach N nodes ir 4/4 nodes we need to check if the motif has K edges
            let edgePath = [[Int]]()
            for edgeLevel in edgeHolder {
                for edge in edgeLevel {
                    
                }
            }
        }
    }
    
    // This function would traverse the nodes adjacent to the main node
    // It would act as a Pseudo BFS.
    // We were very close to implementing it correctly, we needed to add a queue and add a seen variable to each edge
    func traverseAdjacentNodesBFS(mainNodeId: Int, currentNodeCount: Int, adjacentNodesToCheck: [GraphNode]) {
        removeNewAdjacentNodes()
        // radially search each adjacent node 1st level
        var nodeCount = currentNodeCount
        
        if nodeCount < N { // this doesnt run we reach K
            var newNodesToCheck = adjacentNodesToCheck
            var adjacentNodes =  [Int]()
            for node in adjacentNodesToCheck {
                let edge = [node.id, mainNodeId]
                edgeHolder[nodeCount - 1].append(edge)
                adjacentNodes.append(node.id)
            }
            nodeCount += 1 //2nd level
            
            updateNewAdjacentNodes(nodesList: adjacentNodes)
            for node in newAdjacentNodesHolder { // This is where the
                let nodeId = node.id
                traverseAdjacentNodesBFS(mainNodeId: nodeId, currentNodeCount: nodeCount, adjacentNodesToCheck: newAdjacentNodesHolder)
            }
            
        } else { // When we reach N nodes ir 4/4 nodes we need to check if the motif has K edges
            let edgePath = [[Int]]()
            for edgeLevel in edgeHolder {
                for edge in edgeLevel {
                    
                }
            }
        }
    }
    
    // This function updates the adjacent nodes to pass the new nodes recursively
    func updateNewAdjacentNodes(nodesList: [Int]) {
        for node in nodesList {
            let graphNode = allGrahphNodesGDict[node]
            newAdjacentNodesHolder.append(graphNode!)
        }
    }
    
    func removeNewAdjacentNodes() {
        newAdjacentNodesHolder.removeAll()
    }
    
    // This function was made in attempt to find all combinations of motifs that have the same number of edges K as H
    // This would only be implemented when we reach the same number of nodes N as H
    // We abandoned this method because there is a much better way to do this uding a DFS or BFS
    func findCombinationsWithSameK(k: Int, nodePath: [Int], edgesSeen: [[Int]]) -> [[[Int]]] {
        var newEdgesSeen: [[Int]] = edgesSeen
        var combinationsWithSameK: [[[Int]]] = [[[]]]
        
        for node in nodePath {
            // at each node check all edges connected to different nodes in the path
            var currentNodePath = nodePath
            var nodesToCheck = nodePath.filter({$0 != node})
            var newNodesToCheck: [Int] = []
            let nodeEdgeValues = adjacencyListG[node]
            //print("NODE EDGE Vals:", nodeEdgeValues, nodesToCheck)
            for vertex in nodesToCheck {
                //let edge = [node, vertex]
                //print("vertex: ", vertex)
                newNodesToCheck =  nodesToCheck.filter({$0 != vertex})
                //print("NewNodesToCheck: ", newNodesToCheck)
                
                if (newNodesToCheck.count > 0) && (newEdgesSeen.count < K)  {
                    for newNode in newNodesToCheck {
                        let edge = [node, newNode].sorted()
                        if newEdgesSeen.contains(where: { $0 == edge}) {
                            //print("CONTAINS: ", edgesSeen, edge )
                            
                        } else {
                            newEdgesSeen.append(edge)
                            if newEdgesSeen.count == K {
                                combinationsWithSameK.append(newEdgesSeen)
                                newEdgesSeen = edgesSeen
                            }
                        }
                    }
                }
            }
        }
        combinationsWithSameK.remove(at: 0)
        combinationsWithSameK.remove(at: combinationsWithSameK.count - 1)
        return combinationsWithSameK
    }
    
    
    // Function produces an edge list for G
    func makeEdgeListG(resource: String, type: String) {
        if let path = Bundle.main.path(forResource: resource, ofType: type) {
            do {
                let data = try String(contentsOfFile: path, encoding: .utf8)
                var myStrings = data.components(separatedBy: .newlines)
                let s = myStrings.joined(separator: ", ")
                
                var connections: [[Int]] = []
                var allVertexOccurrences: [Int] = []
                var allConnections: [[Int]] = [[]]
                myStrings.removeLast()
                
                for i in 0...myStrings.count - 1 {
                    
                    var vals = myStrings[i].components(separatedBy: " ")
                    let v1 = Int(vals[0])
                    let v2 = Int(vals[1])
                    allVertexOccurrences.append(v1!)
                    allVertexOccurrences.append(v2!)
                    
                    let edge = [v1, v2] as! [Int]
                    allConnections.append(edge)
                }
                allConnections.remove(at: 0)
                
                var list: [Int] = []
                var edgeLst: [Int] = []
                G = allConnections
                for val in allConnections {
                    list.append(val[0])
                    list.append(val[1])
                }
                
                let max = list.max() as! Int
                
                for i in 0...(max) {
                    let items = list.filter({$0 == i})
                    let edgeCount = items.count
                    edgeLst.append(edgeCount)
                }
                
                var nodeValues: [Int] = []
                for i in 0...(max) {
                    let items = list.filter({$0 == i})
                    nodeValues.append(items[0])
                    let key = i
                    let value = edgeLst[i]
                    let dictionary = [key : value]
                    edgeListG[key] = value
                    gNodes.append(key)
                }
                
            } catch {
                print(error)
            }
        }
    }
    
    
    // Function produces an edge list for H
    func makeEdgeListH(resource: String, type: String, h: [[Int]]) {
        var list: [Int] = []
        var edgeLst: [Int] = []
        
        var edgeArray: [EdgeSet] = []
        for val in h {
            list.append(val[0])
            list.append(val[1])
        }
        
        let max = list.max() as! Int
        
        for i in 0...(max) {
            let items = list.filter({$0 == i})
            let edgeCount = items.count
            edgeLst.append(edgeCount)
            
            let key = i
            let value = edgeLst[i]
            let dictionary = [key : value]
            
            edgeListH[key] = value
            hNodes.append(key)
        }
        
        N = hNodes.count
    }
    // Function produces an adjacency list for G
    func makeAdjacencyListG() {
        for i in 0...gNodes.count - 1 {
            let key = i
            let value = [-1]
            adjacencyListG[key] = value
            var values1: [Int] = []
            var values2: [Int] = []
            
        }
        
        
        for nodeValue in 0...gNodes.count - 1 {
            var adjacencies :[Int] = []
            for edge in G {
                if edge.contains(nodeValue){
                    let v1 =  edge[0]
                    let v2 = edge[1]
                    if v1 == nodeValue {
                        adjacencies.append(v2)
                    } else {
                        adjacencies.append(v1)
                    }
                }
            }
            
            adjacencyListG[nodeValue] = adjacencies
            adjacencies.removeAll()
        }
    }
    // Function produces an adjacency list for H
    func makeAdjacencyListH() {
        for i in 0...hNodes.count - 1 {
            let key = i
            let value = [-1]
            adjacencyListH[key] = value
        }
        for nodeValue in 0...hNodes.count - 1 {
            var adjacencies :[Int] = []
            for edge in H {
                if edge.contains(nodeValue){
                    let v1 =  edge[0]
                    let v2 = edge[1]
                    if v1 == nodeValue {
                        adjacencies.append(v2)
                    } else {
                        adjacencies.append(v1)
                    }
                }
            }
            adjacencyListH[nodeValue] = adjacencies
            adjacencies.removeAll()
        }
    }
}
