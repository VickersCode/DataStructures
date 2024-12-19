#ifndef MATRIX_GRAPH
#define MATRIX_GRAPH
#include "graph.h"
#include <vector>

template<class LabelType>
class Graph: public GraphInterface<LabelType>{
    std::vector<std::vector<int>> graphMatrix;
    std::vector<LabelType> vertices;

    public:
        Graph();

        int getNumVertices() const;
        int getNumEdges() const;
        bool add(LabelType start, LabelType end, int edgeWeight);
        bool remove(LabelType start, LabelType end);
        int getEdgeWeight(LabelType start, LabelType end) const;
        void depthFirstTraversal(LabelType start, void visit(LabelType&));
        void breadthFirstTraversal(LabelType start, void visit(LabelType&));
        // for testing remove later
        void printGraph();

    private: 
        int getVertexIndex(LabelType label) const;
        void recursiveDFSHelper(LabelType start, LabelType current, std::vector<bool>& visited, std::vector<LabelType>& currentPath, void visit(LabelType&));
};
#include "graph.cpp"
#endif