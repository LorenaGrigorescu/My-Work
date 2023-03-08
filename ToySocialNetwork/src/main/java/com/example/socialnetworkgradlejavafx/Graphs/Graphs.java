package com.example.socialnetworkgradlejavafx.Graphs;


import com.example.socialnetworkgradlejavafx.domain.Graph;


import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Graphs<T> {
    private Graph<T> graph;

    public Graphs(Graph<T> graph) {
        this.graph = graph;
    }

    /**
     * The DFS method we call in order to find the conex components
     *
     * @param node
     * @param visitedNodes
     * @param currentComponent
     */
    public void DFS(T node, Set<T> visitedNodes, List<T> currentComponent) {
        if (visitedNodes.contains(node)) return;
        visitedNodes.add(node);
        currentComponent.add(node);
        for (T _node : graph.map.get(node)) {
            if (!visitedNodes.contains(_node))
                DFS(_node, visitedNodes, currentComponent);
        }
    }

    /**
     * The metohds returns a list with the connected components
     *
     * @return the list of the connected components
     */
    public List<List<T>> getConnectedComponents() {
        List<List<T>> components = new ArrayList<>();
        Set<T> visitedNodes = new HashSet<>();
        for (var node : graph.map.keySet()) {
            if (!visitedNodes.contains(node)) {
                List<T> currentComponent = new ArrayList<>();
                DFS(node, visitedNodes, currentComponent);
                components.add(currentComponent);
            }
        }
        return components;
    }
    // daca lista de noduri vizitate nu contine nodul curent, se face DFS din acel nod pentru determinarea componentei conexe => vector de componente conexe

    /**
     * The method returns the longest path in each connected component
     *
     * @param component the current component
     * @return a list of nodes which consists the longest path
     */
    public List<T> longestPathInComponent(List<T> component) {
        List<T> longestPath = new ArrayList<>();
        for (T node : component) {
            Set<T> visitedNodes = new HashSet<>();
            List<T> currentList = new ArrayList<>();
            List<T> currentLongestPath = new ArrayList<>();
            visitedNodes.add(node);
            currentList.add(node);
            longestDfsUtil(node, visitedNodes, currentList, currentLongestPath);
            if (currentLongestPath.size() > longestPath.size())
                longestPath = currentLongestPath;
        } //pentru fiecare nod din fiecare componenta conexa, calculam cel mai lung in drum, in final avand cea mai lunga retea sociabila
        return longestPath;
    }

    /**
     * a DFS recursive function which is creating a new set for every node we're visiting
     *
     * @param nod         the node we're currently visiting
     * @param visited     a set of the already visited nodes
     * @param currentList : the connected component we visit
     * @param longestList : the longest path
     */
    private void longestDfsUtil(T nod, Set<T> visited, List<T> currentList, List<T> longestList) {
        int setSize = visited.size();
        if (setSize > longestList.size()) {
            longestList.clear();
            longestList.addAll(currentList);
        } //daca componenta conexa este mai lunga decat ce am avut pana acum, se inlocuieste
        for (T nextNode : graph.map.get(nod)) {
            if (visited.contains(nextNode)) continue;
            Set<T> newVisited = new HashSet<>(visited);
            List<T> newCurrentList = new ArrayList<>(currentList);
            //se creeaza o noua lista de noduri vizitate si una de noduri conexe in cazul in care gasim una si mai mare decat cea pe care o avem deja
            //facem un DFS ca sa gasim cea mai lunga lista de noduri conexe
            newVisited.add(nextNode);
            newCurrentList.add(nextNode);
            longestDfsUtil(nextNode, newVisited, newCurrentList, longestList);
        }
    }
}
