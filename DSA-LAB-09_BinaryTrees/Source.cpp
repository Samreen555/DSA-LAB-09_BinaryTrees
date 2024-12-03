#include <iostream>
using namespace std;

typedef int ElementType;  

// Node structure
struct node {
    ElementType data;
    node* left;
    node* right;

    node(ElementType value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    node* root; // Root of the binary tree

public:
    BinaryTree() 
    {
        root = nullptr;
    }

    // ADT of binary trees
    void Insert(ElementType info);
    void AddLeft(node* parent, ElementType value);
    void AddRight(node* parent, ElementType value);
    bool IsEmpty() const;
    bool IsLeaf(node* current) const;
    node* LeftChild() const;
    node* RightChild() const;
    ElementType Data() const;
    void DisplayRoot() const;
    //void DisplayTree(node* current, int level = 0) const;
    node* GetRoot() const { return root; }
    node* FindNode(node* current, ElementType value) const;
    node* FindSiblings(node* current, ElementType value) const;
};

// Display menu function
void DisplayMenu() {
    cout << "-----------------------------------\n";
    cout << "------- ADT of Binary Trees -------\n";
    cout << "1. Insert root node\n";
    cout << "2. Display left child of root\n";
    cout << "3. Display right child of root\n";
    cout << "4. Check if a node is a leaf node\n";
    cout << "5. Display root of the tree\n";
    cout << "6. Find sibling of a node\n"; // New menu option
    cout << "7. Exit\n";
    cout << "-----------------------------------\n";
}

// Function to find a node by value
node* BinaryTree::FindNode(node* current, ElementType value) const {
    if (current== nullptr)  return nullptr;
    if (current->data == value) return current;

    // Recursively search left and right subtrees
    node* foundNode = FindNode(current->left, value);
    if (foundNode == nullptr) {
        foundNode = FindNode(current->right, value);
    }
    return foundNode;
}

// Insert root node
void BinaryTree::Insert(ElementType info) {
    if (IsEmpty()) {
        root = new node(info);
    }
    else {
        cout << "Root already exists. Use option 7 to add children to nodes.\n";
    }
}

// Add left child to a node
void BinaryTree::AddLeft(node* parent, ElementType value) {
    if (parent == nullptr) {
        cout << "Parent node is null. Cannot add left child.\n";
        return;
    }
    if (parent->left == nullptr) {
        parent->left = new node(value);
        cout << "Left child added with value: " << value << "\n";
    }
    else {
        cout << "Left child already exists for this node.\n";
    }
}

// Add right child to a node
void BinaryTree::AddRight(node* parent, ElementType value) {
    if (parent == nullptr) {
        cout << "Parent node is null. Cannot add right child.\n";
        return;
    }
    if (parent->right == nullptr) {
        parent->right = new node(value);
        cout << "Right child added with value: " << value << "\n";
    }
    else {
        cout << "Right child already exists for this node.\n";
    }
}

// Check if the tree is empty
bool BinaryTree::IsEmpty() const {
    return root == nullptr;
}

// Check if a node is a leaf
bool BinaryTree::IsLeaf(node* current) const {
    return current && current->left == nullptr && current->right == nullptr;
}

// Get left child of root
node* BinaryTree::LeftChild() const {
    return root ? root->left : nullptr;
}

// Get right child of root
node* BinaryTree::RightChild() const {
    return root ? root->right : nullptr;
}

// Get data from root
ElementType BinaryTree::Data() const {
    if (IsEmpty()) {
        throw runtime_error("Tree is empty!");
    }
    return root->data;
}

// Display root node
void BinaryTree::DisplayRoot() const {
    if (IsEmpty()) {
        cout << "The tree is empty.\n";
    }
    else {
        cout << "Root node data: " << root->data << "\n";
    }
}

// Display the entire tree
//void BinaryTree::DisplayTree(node* current, int level) const {
//    if (current == nullptr) return;
//
//    // Display right subtree
//    DisplayTree(current->right, level + 1);
//
//    // Display current node
//    for (int i = 0; i < level; i++) cout << "   ";
//    cout << current->data << "\n";
//
//    // Display left subtree
//    DisplayTree(current->left, level + 1);
//}

// Add children to a specific node
//void AddChildToNode(BinaryTree& tree) {
//    if (tree.IsEmpty()) {
//        cout << "The tree is empty. Add a root first.\n";
//        return;
//    }
//
//    cout << "Enter the value of the parent node where you want to add children: ";
//    ElementType parentValue;
//    cin >> parentValue;
//
//    node* parent = tree.FindNode(tree.GetRoot(), parentValue);
//    if (parent == nullptr) {
//        cout << "Parent node with value " << parentValue << " not found.\n";
//        return;
//    }
//
//    // Add left child
//    cout << "Do you want to add a left child? (y/n): ";
//    char choice;
//    cin >> choice;
//    if (choice == 'y' || choice == 'Y') {
//        cout << "Enter value for the left child: ";
//        ElementType value;
//        cin >> value;
//        tree.AddLeft(parent, value);
//    }
//
//    // Add right child
//    cout << "Do you want to add a right child? (y/n): ";
//    cin >> choice;
//    if (choice == 'y' || choice == 'Y') {
//        cout << "Enter value for the right child: ";
//        ElementType value;
//        cin >> value;
//        tree.AddRight(parent, value);
//    }
//}
// Function to find siblings
node* BinaryTree::FindSiblings(node* current, ElementType value) const {
    if (current == nullptr || current->left == nullptr || current->right == nullptr)
        return nullptr;

    // Check if the siblings exist
    if (current->left && current->left->data == value)
        return current->right;
    if (current->right && current->right->data == value)
        return current->left;

    // Recursively search in left and right subtrees
    node* sibling = FindSiblings(current->left, value);
    if (sibling == nullptr) {
        sibling = FindSiblings(current->right, value);
    }
    return sibling;
}
// Main function
int main() {
    BinaryTree tree;
    string choice;
    ElementType value;

    while (true) {
        DisplayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            cout << "Enter value to insert(for root): ";
                        while (!(cin >> value)) {
                            cout << "Invalid input. Please enter an integer: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        tree.Insert(value);
            
                        if (tree.GetRoot() != nullptr) {
                            // Add left child
                            while (true) {
                                cout << "Do you want to add a left child to the root? (y/n): ";
                                string leftChoice;
                                cin >> leftChoice;
            
                                if (leftChoice == "y" || leftChoice == "Y") {
                                    cout << "Enter value for the left child: ";
                                    while (!(cin >> value)) {
                                        cout << "Invalid input. Please enter an integer: ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                    tree.AddLeft(tree.GetRoot(), value);
                                    
                                }
                                else if (leftChoice == "n" || leftChoice == "N") {
                                    break;
                                }
                                else {
                                    cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                                }
                            }
            
                            // Add right child
                            while (true) {
                                cout << "Do you want to add a right child to the root? (y/n): ";
                                string rightChoice;
                                cin >> rightChoice;
            
                                if (rightChoice == "y" || rightChoice == "Y") {
                                    cout << "Enter value for the right child: ";
                                    while (!(cin >> value)) {
                                        cout << "Invalid input. Please enter an integer: ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                    tree.AddRight(tree.GetRoot(), value);
                                    
                                }
                                else if (rightChoice == "n" || rightChoice == "N") {
                                    break;
                                }
                                else {
                                    cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                                }
                            }
                        }
        }
        else if (choice == "2") {
            node* left = tree.LeftChild();
            if (left) {
                cout << "Left child of root: " << left->data << "\n";
            }
            else {
                cout << "No left child.\n";
            }
        }
        else if (choice == "3") {
            node* right = tree.RightChild();
            if (right) {
                cout << "Right child of root: " << right->data << "\n";
            }
            else {
                cout << "No right child.\n";
            }
        }
        else if (choice == "4") {
            cout << "Enter node value to check if it's a leaf: ";
            cin >> value;
            node* target = tree.FindNode(tree.GetRoot(), value);
            if (target && tree.IsLeaf(target)) {
                cout << "The node is a leaf.\n";
            }
            else {
                cout << "The node is not a leaf or doesn't exist.\n";
            }
        }
        else if (choice == "5") {
            tree.DisplayRoot();
        }
     
        else if (choice == "6") {
            cout << "Enter node value to find sibling: ";
            cin >> value;
            node* sibling = tree.FindSiblings(tree.GetRoot(), value);
            if (sibling) {
                cout << "Sibling of node " << value << ": " << sibling->data << "\n";
            }
            else {
                cout << "No sibling found or the node doesn't exist.\n";
            }
        }
        else if (choice == "7") {
            cout << "Exiting program.\n";
            return 0;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
