#include <iostream>

using namespace std;

struct node //used in class BSTNode
{
	int key;
	node* left;
	node* right;
	node* parent;
	int Color; // 0 for black 1 for red
	node() { //constructor
		key = NULL;
		left = NULL;
		right = NULL;
		parent = NULL;
		Color = 0;

	}
	node(int k)
	{
		key = k;
		left = NULL;
		right = NULL;
		parent = NULL;
		Color = 0;
	}
};
node* newNode(int data) {
    node* newnode = new node();
    newnode->key = data;
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->parent = NULL;
    newnode->Color = 0;
    return newnode;
}
node* insert(node* &root, int data) { //inserts elements into the tree
    // base case

}

int Maximum(node* root){
    node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp->key;
}
bool lookup(node* root, int data) { //looks up an element within the tree
    if (root == NULL)
        return false;

    while (root != NULL) {
        if (data > root->key) {
            root = root->right;
        }
        else if (data < root->key) {
            root = root->left;
        }
        else {
            return true;
        }
    }
    return false;
}
void postorder(node* root) {
    // if the current node is empty
    if (root == nullptr) {
        return;
    }
    // Traverse the left subtree
    postorder(root->left);
    // Traverse the right subtree
    postorder(root->right);
    // Display the data part of the root (or current node)
    cout << root->key << " ";
}

int main()
{
    node* BST = NULL;
    cout << "Inserted elements: ";
    int value = 0;
    int size, count;

    cout << "Insert a Size for the BST >> ";
    cin >> size;
    while (count != size){
    cout << "\nInsert a key to Insert >> ";
    cin >> value;
    BST = insert(BST, value);
    count++;
    }

    postorder(BST);
    cout << "\nPost-order: ";
    postorder(BST);

    cout << "\nLargest element in the list is: " << Maximum(BST) << endl;




    while(value != -1){
        cout << "\nInsert a number for look up >> ";
        cin >> value;

        if(lookup(BST, value))
            cout << value << endl;
        else
            cout << value << " is not a member of the list\n";
    }
    return 0;
}


