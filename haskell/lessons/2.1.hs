import Data.Array

type Vertex = Int
type Graph = Array Vertex [Vertex]
type Bounds = (Vertex, Vertex)
type Edge = (Vertex, Vertex)

hasCycle :: Graph -> Bool
hasCycle graph = any (hasCycleFrom graph []) (indices graph)

hasCycleFrom :: Graph -> [Vertex] -> Vertex -> Bool
hasCycleFrom graph visited v =
    case graph ! v of
        neighbors ->
            let newVisited = v : visited
                cyclicNeighbor = any (`elem` newVisited) neighbors
                recursiveCycle = any (hasCycleFrom graph newVisited) neighbors
            in cyclicNeighbor || recursiveCycle

buildG :: Bounds -> [Edge] -> Graph
buildG bounds edges =
    accumArray (flip (:)) [] bounds $ edges ++ [(v, u) | (u, v) <- edges]



deepFirst :: Graph -> Vertex -> (StateT Coloring) (Writer String) Bool
deepFirst graph vertex = do
    st <- get
    if coloring!vertex == White
        then do
            put (coloring // [(v, Gray)])
            lift (tell ("Start vertice " ++ (show v) ++ "\n"))
            results <- mapM (deepFirst g) (g!v)
            lift (tell ("Quit vertice " ++ (show v) ++ "\n"))
            modify (//[(v, Black)])
            return (or result)
    else return (coloring!vertex == Gray)

