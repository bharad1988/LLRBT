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
            //std::cout<<count<<std::endl;

            if (!head) {
                head = a;
            }
            else {
                head = addNode(head,a);
            }
            std::cout<<head->color;
        }

        bool searchTree(T *a){
            return searchTree(head,a);
        }
        void deleteMax(){
            if (head) head = deleteMax(head);
            else std::cout<<"Tree already empty\n";
            if (head) head->color = BLACK;
        }

        void deleteMin(){
            if(head) head = deleteMin(head);
            else std::cout<<"Tree already empty\n";
            if (head) head->color = BLACK;
        }
        void deleteNode(T *a){
            deleteNode(head,a);
        }
        void printTree(){
            if (head)printTree(head);
            else std::cout<<"Tree is empty\n";
        }
        

    private:
        // Helper for delete
        T* fixUp(T *t){
            if (!t){
                return t;
            }
            if (isRed(t->right)){
                t = leftRotate(t);
            } 
            if (isRed((t)->left) && isRed((t)->left->left)){
                t = rightRotate(t);
            }
            if (isRed((t)->left) && isRed((t)->right)){
                t = colorFlip(t);
            }
            return t;

        }
        // Helper 2. for  delete
        // Rotate red links to the right
        T* moveRedRight(T *t){
            colorFlip(t);
            if (isRed(t->left->left)){
                t = rightRotate(t);
                colorFlip(t);
            }
            return t;
        }

        // Helper 3 for deleteMin
        T* moveRedLeft(T *t){
            colorFlip(t);
            if (isRed(t->right->left)){
                t = leftRotate(t);
                colorFlip(t);
            }
            return t;
        }

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
        T* colorFlip(T *a){
            a->color = !(a->color); 
            a->left->color = !a->left->color;
            a->right->color = !a->right->color;
            std::cout<<"flip colors \n";
            return a;
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
            }/*
            if (isRed((t)->left) && isRed((t)->right)){
                t = colorFlip(t);
            }*/
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
                t = colorFlip(t);
                
            }
            return t; 

        }

        bool searchTree(T *t,T *a){
            if (*a == *t){
                std::cout<<"\ncolour\t"<<t->color<<"\n";
                std::cout<<"found\n";
                return true;
            }
            if ( *a < *t){
                if (t->left){
                    std::cout<<"go left\n";
                    searchTree(t->left,a);
                }
                else
                    return false;
            }
            else if ( *a > *t){
                if (t->right){
                    std::cout<<"go right\n";
                    searchTree(t->right,a);
                }else return false;
            }
        }
        T* deleteMax(T *t){
            if (isRed(t->left))
                t = rightRotate(t);
            if (!t->right ){
                free(t);
                return NULL;
            }
            if (!isRed(t->right) && !isRed(t->right->left))
                t = moveRedRight(t);
            t->right  = deleteMax(t->right);
            return fixUp(t);

        }
        T* deleteMin(T *t){
            if (!t->left ){
                free(t);
                return NULL;
            }
            if (!isRed(t->left) && !isRed(t->left->left))
                t = moveRedLeft(t);
            t->left  = deleteMin(t->left);
            return fixUp(t);
        }

        void deleteNode(T *t,T *a){
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

