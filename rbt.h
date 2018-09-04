// Start with a BST 
// Then add DS to make it RBT ( LLRBT )
// Implementation adapted from Robert Sedgwick's (Princeton )Left leaning Red Black tree
// Then go on adding the rotate
#include <iostream>
// Define Structure
template<class T>
class RBTNode {
    public:
        T *left;
        T *right;
        bool color;
        
        RBTNode(){
            left = NULL;
            right = NULL;
            color = true;
        }

};

template <class T>
class RBTree {
    static const bool RED = true;
    static const bool BLACK = false;

    public:
        T *head;
        int count;
        int repeat;
        RBTree(){
            this->head = NULL;
            count =0;
            repeat =0;
        }
        // operations over a tree
        void addNode(T *a){
            count = count +1;
            std::cout<<count<<std::endl;

            if (!head) {
                head = a;
                head->color = BLACK;
            }
            else {
                head = addNode(head,a);
            }
        }
        void deleteNode(){
        }
        void printTree(){
            printTree(head);
        }
        

    private:
        // Left rotate
        T* leftRotate(T *a){
            T **x;
            *x = a->right;
            a->right = (*x)->left;
            (*x)->left = a;
            (*x)->color = (*x)->left->color;
            (*x)->left->color = RED;
            std::cout<<"left rotate\n";
            return *x;
        }
        // right rotate
        T* rightRotate(T *a){
            T **x;
            *x = a->left;
            a->left = (*x)->right;
            (*x)->right = a;
            (*x)->color = (*x)->right->color;
            (*x)->right->color = RED;
            std::cout<<"right rotate \n";
            return *x;
        }
        // flip color
        void colorFlip(T *a){
            if (a != head ) a->color = !(a->color);
            a->left->color = !a->left->color;
            a->right->color = !a->right->color;
            std::cout<<"flip colors \n";
        }

        bool isRed(T *a){
            if (!a)return false;
            else return a->color;
        }
        T* addNode(T *t,T *a){
            // if head is null , set pointer to head of the tree;
            if (!t){
                t  = a;
                return t;
            }
            // build a binary tree
            // Element exists, no need to add
            // duplicate elements are not supported as of now
            if (*a == *t){
                repeat +=1;
                std::cout<<"do nothing\n";
            }
            else if ( *a < *t ) {
                t->left = addNode(t->left,a);
                // reset the header back
                // to what was before in this context
                std::cout<<"adding to left\n";
            }
            else {
                t->right = addNode(t->right,a);
                std::cout<<"adding to right\n";
            }
            if (isRed(t->right)){
                t = leftRotate(t);
            } 
            if (isRed((t)->left) && isRed((t)->left->left)){
                t = rightRotate(t);
            }
            if (isRed((t)->left) && isRed((t)->right)){
                colorFlip(t);
            }
            return t; 

        }
        void printTree(T *head){
            if (head->left){
                printTree(head->left);
            }
            std::cout<<"\t"<<*head;
            if (head->right) {
                printTree(head->right);
            }
        }
};
