from graphviz import Digraph

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert_recursive(self.root, key)

    def _insert_recursive(self, node, key):
        if key < node.key:
            if node.left is None:
                node.left = Node(key)
            else:
                self._insert_recursive(node.left, key)
        else:
            if node.right is None:
                node.right = Node(key)
            else:
                self._insert_recursive(node.right, key)

    def find_node(self, node, key, level=1):
        if node is None:
            return None, None
        if node.key == key:
            return node, level
        left_result = self.find_node(node.left, key, level + 1)
        if left_result[0]:
            return left_result
        return self.find_node(node.right, key, level + 1)

    def find_siblings(self, node, key, parent=None):
        if node is None:
            return []
        
        if node.key == key:
            if parent is None:
                return []  # Root node has no siblings
            if parent.left and parent.left.key == key:
                return [parent.right.key] if parent.right else []
            if parent.right and parent.right.key == key:
                return [parent.left.key] if parent.left else []
        
        left_result = self.find_siblings(node.left, key, node)
        if left_result:
            return left_result
        return self.find_siblings(node.right, key, node)
    
    # Function to generate the tree visualization
    def visualize(self):
        dot = Digraph()
        self._add_edges(dot, self.root)
        return dot

    def _add_edges(self, dot, node):
        if node is not None:
            if node.left:
                dot.edge(str(node.key), str(node.left.key))
                self._add_edges(dot, node.left)
            if node.right:
                dot.edge(str(node.key), str(node.right.key))
                self._add_edges(dot, node.right)

# User Input
tree = BinaryTree()
n = int(input("Enter the number of elements in the tree: "))
print("Enter the elements:")
values = [int(input()) for _ in range(n)]
for value in values:
    tree.insert(value)

search_key = int(input("Enter the node value to search: "))
node, height = tree.find_node(tree.root, search_key)
if node:
    print(f"Node {search_key} is present at height {height}.")
    siblings = tree.find_siblings(tree.root, search_key)
    print(f"Siblings of {search_key}: {siblings if siblings else 'None'}")
else:
    print(f"Node {search_key} is not present in the tree.")

# Visualize the tree
dot = tree.visualize()
dot.render('binary_tree', format='png', view=True)  # This will save the tree as 'binary_tree.png' and open it
