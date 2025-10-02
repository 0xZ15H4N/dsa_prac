#include<iostream>
#include<queue>

using namespace std;
// test case :1 3 7 -1 -1 11 -1 -1 5 13 -1 -1 -1
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree(Node* root){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }else{
        root = new Node(data);
        root->left = buildTree(root->left);
        root->right = buildTree(root->right);
        return root;
    }
}
//level order Traversal
void levelOrder(Node* root){
    if(root!=NULL){
    queue<Node* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp -> data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
    }else{
        cout<<"ROOT NODE EMPTY";
        return;
    }
}
void buildLevelTree(Node * &root){
    queue <Node*>q;
    cout<<"enter data for root node";
    int data;
    cin>>data;
    if(data == -1){
        root = NULL;
        return;
    }else{
        root = new Node(data);
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            int left_ ;
            cout<<"enter data for left node";
            cin>>left_;
            if(left_ != -1){
                temp ->left = new Node(left_);
                q.push(temp->left);
            }
            int right_;
            cout<<"enter data for right node";
            cin>>right_;
            if(right_ != -1){
                temp->right = new Node(right_);
                q.push(temp->right);
            }            
        }
    }

}

void inorderTraversal(Node* root){
    //base case
    if(root ==NULL){
        return;
    }else{
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);

    }

}
void PreorderTraversal(Node* root){
    //base case
    if(root ==NULL){
        return;
    }else{
       
        cout<<root->data<<" ";
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);

    }

}
void PostorderTraversal(Node* root){
    //base case
    if(root ==NULL){
        return;
    }else{
       
        PostorderTraversal(root->left);
         PostorderTraversal(root->right);
        cout<<root->data<<" ";
    }

}

int main(){
    Node*root;
    //Node*root = buildTree(root);
    /*cout<<"level order traversal"<<endl;
    levelOrder(root);
    cout<<"inorderal Traversal"<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"Preorderal Traversal"<<endl;
    PreorderTraversal(root);
    cout<<endl;
    cout<<"Postorderal Traversal"<<endl;
    PostorderTraversal(root);*/
    buildLevelTree(root);
    cout<<"level order traversal"<<endl;
    levelOrder(root);

    return 0;

}