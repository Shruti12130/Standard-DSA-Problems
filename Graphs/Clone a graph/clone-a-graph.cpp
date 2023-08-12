unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) 
            return NULL;
        Node* clonedGraph = new Node(node->val);
        mp[node] = clonedGraph;
        for(auto it: node->neighbors) {
            if(mp.count(it)) {
                clonedGraph->neighbors.push_back(mp[it]);
            } else {
                clonedGraph->neighbors.push_back(cloneGraph(it));
            }
        }
        return clonedGraph;
    }
