package com.example.socialnetworkgradlejavafx.domain;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class Graph<T> {
    public Map<T, LinkedList<T>> map =new HashMap<>();

    public Graph(List<Pair<T, T>> nodes)
    {
        for(var node:nodes)
        {
            T first = node.getA();
            T second = node.getB();
            addNode(first);
            addNode(second);
        }

        for(var node:nodes)
        {
            map.get(node.getA()).push(node.getB());
            map.get(node.getB()).push(node.getA());
        }
    }

    /**
     * In the graph map we add a empty list to each node
     * @param node the node where we want to save the neighbours
     */
    public void addNode(T node)
    {
        map.computeIfAbsent(node, k->new LinkedList<>());
    }

}
