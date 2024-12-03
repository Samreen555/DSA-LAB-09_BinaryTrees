//#include <iostream>
//using namespace std;
//
//typedef int ElementType;
//
//// Node structure
//struct node {
//    ElementType data;
//    node* left;
//    node* right;
//
//    node(ElementType value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//// BinaryTree class
//class BinaryTree {
//private:
//    node* root; // Root of the binary tree
//
//public:
//    // Constructors
//    BinaryTree() : root(nullptr) {}
//    BinaryTree(BinaryTree& lbt, ElementType info, BinaryTree& rbt);
//
//    // ADT of binary trees
//    void Insert(ElementType info);
//    void AddLeft(node* parent, ElementType value);
//    void AddRight(node* parent, ElementType value);
//    bool IsEmpty();
//    bool IsLeaf();
//    node* LeftChild();
//    node* RightChild();
//    ElementType Data();
//    void DisplayRoot();
//    void DisplayTree(node* current, int level = 0);
//    node* GetRoot() { return root; } // Getter for root
//};
//
//// Display menu function
//void Display_menu() {
//    cout << "-----------------------------------\n";
//    cout << "------- ADT of Binary Trees -------\n";
//    cout << "1. Insert value into the tree\n";
//    cout << "2. Display left child of root\n";
//    cout << "3. Display right child of root\n";
//    cout << "4. Check if root is a leaf node\n";
//    cout << "5. Display root of the tree\n";
//    cout << "6. Display entire tree\n";
//    cout << "7. Exit\n";
//    cout << "-----------------------------------\n";
//}
//
//BinaryTree::BinaryTree(BinaryTree& lbt, ElementType info, BinaryTree& rbt) {
//    root = new node(info);
//    root->left = lbt.root;
//    root->right = rbt.root;
//}
//
//void BinaryTree::Insert(ElementType info) {
//    if (IsEmpty()) {
//        root = new node(info);
//    }
//    else {
//        node* temp = root;
//        while (true) {
//            if (info < temp->data) {
//                if (temp->left == nullptr) {
//                    temp->left = new node(info);
//                    break;
//                }
//                temp = temp->left;
//            }
//            else {
//                if (temp->right == nullptr) {
//                    temp->right = new node(info);
//                    break;
//                }
//                temp = temp->right;
//            }
//        }
//    }
//}
//
//void BinaryTree::AddLeft(node* parent, ElementType value) {
//    if (parent == nullptr) {
//        cout << "Parent node is null. Cannot add left child.\n";
//        return;
//    }
//    if (parent->left == nullptr) {
//        parent->left = new node(value);
//        cout << "Left child added with value: " << value << "\n";
//    }
//    else {
//        cout << "Left child already exists.\n";
//    }
//}
//
//void BinaryTree::AddRight(node* parent, ElementType value) {
//    if (parent == nullptr) {
//        cout << "Parent node is null. Cannot add right child.\n";
//        return;
//    }
//    if (parent->right == nullptr) {
//        parent->right = new node(value);
//        cout << "Right child added with value: " << value << "\n";
//    }
//    else {
//        cout << "Right child already exists.\n";
//    }
//}
//
//bool BinaryTree::IsEmpty() {
//    return root == nullptr;
//}
//
//bool BinaryTree::IsLeaf() {
//    return root && root->left == nullptr && root->right == nullptr;
//}
//
//node* BinaryTree::LeftChild() {
//    return root ? root->left : nullptr;
//}
//
//node* BinaryTree::RightChild() {
//    return root ? root->right : nullptr;
//}
//
//ElementType BinaryTree::Data() {
//    if (IsEmpty()) {
//        throw runtime_error("Tree is empty!");
//    }
//    return root->data;
//}
//
//void BinaryTree::DisplayRoot() {
//    if (IsEmpty()) {
//        cout << "The tree is empty.\n";
//    }
//    else {
//        cout << "Root node data: " << root->data << "\n";
//    }
//}
//
//void BinaryTree::DisplayTree(node* current, int level) {
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
//
//// Main function
//int main() {
//    BinaryTree tree;
//    string choice;
//    ElementType value;
//
//    while (true) {
//        Display_menu();
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        if (choice == "1") {
//            cout << "Enter value to insert: ";
//            while (!(cin >> value)) {
//                cout << "Invalid input. Please enter an integer: ";
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            }
//            tree.Insert(value);
//
//            if (tree.GetRoot() != nullptr) {
//                // Add left child
//                while (true) {
//                    cout << "Do you want to add a left child to the root? (y/n): ";
//                    string leftChoice;
//                    cin >> leftChoice;
//
//                    if (leftChoice == "y" || leftChoice == "Y") {
//                        cout << "Enter value for the left child: ";
//                        while (!(cin >> value)) {
//                            cout << "Invalid input. Please enter an integer: ";
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                        }
//                        tree.AddLeft(tree.GetRoot(), value);
//                        
//                    }
//                    else if (leftChoice == "n" || leftChoice == "N") {
//                        break;
//                    }
//                    else {
//                        cout << "Invalid choice. Please enter 'y' or 'n'.\n";
//                    }
//                }
//
//                // Add right child
//                while (true) {
//                    cout << "Do you want to add a right child to the root? (y/n): ";
//                    string rightChoice;
//                    cin >> rightChoice;
//
//                    if (rightChoice == "y" || rightChoice == "Y") {
//                        cout << "Enter value for the right child: ";
//                        while (!(cin >> value)) {
//                            cout << "Invalid input. Please enter an integer: ";
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                        }
//                        tree.AddRight(tree.GetRoot(), value);
//                        
//                    }
//                    else if (rightChoice == "n" || rightChoice == "N") {
//                        break;
//                    }
//                    else {
//                        cout << "Invalid choice. Please enter 'y' or 'n'.\n";
//                    }
//                }
//            }
//        }
//        else if (choice == "2") {
//            node* left = tree.LeftChild();
//            if (left) {
//                cout << "Left child of root: " << left->data << "\n";
//            }
//            else {
//                cout << "No left child.\n";
//            }
//        }
//        else if (choice == "3") {
//            node* right = tree.RightChild();
//            if (right) {
//                cout << "Right child of root: " << right->data << "\n";
//            }
//            else {
//                cout << "No right child.\n";
//            }
//        }
//        else if (choice == "4") {
//            if (tree.IsLeaf()) {
//                cout << "The root is a leaf node.\n";
//            }
//            else {
//                cout << "The root is not a leaf node.\n";
//            }
//        }
//        else if (choice == "5") {
//            tree.DisplayRoot();
//        }
//        else if (choice == "6") {
//            cout << "Tree Structure:\n";
//            tree.DisplayTree(tree.GetRoot());
//        }
//        else if (choice == "7") {
//            cout << "Exiting program.\n";
//            return 0;
//        }
//        else {
//            cout << "Invalid choice. Please try again.\n";
//        }
//    }
//
//    return 0;
//}
