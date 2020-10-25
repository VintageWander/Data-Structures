#include <iostream>
#include <queue>

class BinaryTree{
    private:
    struct Node{
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(){}
        Node(int&& data) : data{data}, left{nullptr}, right{nullptr} {}
        Node(const int& data, Node* left, Node* right) : data{data}, left{left}, right{right} {}
    };
    Node* root = nullptr;
    public:
    bool isEmpty() {return root == nullptr ? 1 : 0;}
    void InsertNode(int&& data){
        if(!root){
            root = new Node(std::move(data)); return;
        }
        else{
            std::queue<Node*> nodePointers;
            nodePointers.emplace(root);
            while(!nodePointers.empty()){
                Node* current = nodePointers.front(); nodePointers.pop();
                if(current->left) {nodePointers.emplace(current->left);}
                else{current->left = new Node(std::move(data)); return;}
                if(current->right) {nodePointers.emplace(current->right);}
                else{current->right = new Node(std::move(data)); return;}
            }
        }
    }
    void deleteNode(int&& data){
        //edge cases
        if(!root){return;}
        if(root->data == data && !root->left && !root->right) {delete root; return;}
        //function engine
        std::queue<Node*> nodePointers; // a queue to store nodes while doing bfs
        Node* deleteTarget = nullptr;   // pointer to the target node needs to be deleted
        Node* deepRightNode = nullptr;  // the deepest node to replace the deleted Node
        nodePointers.emplace(root);
        while(!nodePointers.empty()){ //this loop will do an entire bfs on the tree
            Node* temp = deepRightNode = nodePointers.front(); nodePointers.pop();
            /* update the temp pointer and deepRightNope so then when the loop stops, 
              deepRightNode will be at the end of the tree */
            if(temp->data == data){ deleteTarget = temp; }
            /* if the data matches with the data that the temp pointer is pointing to
            deleteTarget will point into the Node the temp is pointing to */
            if(temp->left){nodePointers.emplace(temp->left);}
            if(temp->right){nodePointers.emplace(temp->right);}
        }
        
        if(deleteTarget && deepRightNode){ // if both are available
            int replaceValue = deepRightNode->data;
            nodePointers.emplace(root);
            while(!nodePointers.empty()){
                Node* temp = nodePointers.front(); nodePointers.pop();
                /*still the temp pointer that used to traverse the tree*/
                if(temp == deepRightNode) { 
                    /* if the temp pointer is pointing to the same Node that the deepRightNode
                    is pointing to, make the temp pointer null, and then delete deepRightNode */
                    temp = nullptr; 
                    delete deepRightNode; 
                    return;
                }
                if(temp->left){
                    if(temp->left == deepRightNode) {
                        /*if the left side of the Node that the temp pointer is pointing to
                        also the same as the deepRightNode pointer is pointing to
                        make that left Node of temp null, and then delete deepRightNode*/
                        temp->left = nullptr; 
                        delete deepRightNode; 
                    } else {
                        /*if not, then push the address of the left Node into the queue
                        to continue traversing*/
                        nodePointers.emplace(temp->left);
                    }
                }
                if(temp->right){
                    if(temp->right == deepRightNode) {
                        /*if the right side of the Node that the temp pointer is pointing to
                        also the same as the deepRightNode pointer is pointing to
                        make that left Node of temp null, and then delete deepRightNode*/
                        temp->right = nullptr; 
                        delete deepRightNode; 
                    } else {
                        /*if not, then push the address of the right Node into the queue
                        to continue traversing*/
                        nodePointers.emplace(temp->right);
                    }
                }
            }
            deleteTarget->data = replaceValue;
            /*replace the target's data that needs to be deleted
            into the value that deepRightNode used to hold before getting deleted*/ 
        }
        return;
    }
    void PrintTree(){
        if(!root) {return;}
        std::queue<Node*> nodePointers; nodePointers.emplace(root);
        while(!nodePointers.empty()){
            Node* temp = nodePointers.front(); nodePointers.pop();
            std::cout << temp->data << ' ';
            if(temp->left) {nodePointers.emplace(temp->left);}
            if(temp->right) {nodePointers.emplace(temp->right);}
        }
    }
    void Clear(){
        if(!root) {return;}
        std::queue<Node*> nodePointers; nodePointers.emplace(root);
        while(!nodePointers.empty()){
            Node* temp = nodePointers.front(); nodePointers.pop();
            if(temp->left) {nodePointers.emplace(temp->left);}
            if(temp->right) {nodePointers.emplace(temp->right);}
            delete temp;
        }
    }
};

int main(){
    BinaryTree bt;
    bt.InsertNode(1);
    bt.InsertNode(2);
    bt.InsertNode(3);
    bt.InsertNode(4);
    bt.InsertNode(5);
    bt.InsertNode(6);
    bt.InsertNode(7);
    bt.InsertNode(8);
    bt.InsertNode(9);
    bt.InsertNode(10);
    bt.InsertNode(11);
    bt.InsertNode(12);

    bt.deleteNode(5);
    bt.deleteNode(2);
    bt.deleteNode(12);

    bt.PrintTree();
    bt.Clear();
    return 0;

}