#include <iostream>

using namespace std;

template <class T>
class TreeNode 
{
  private:
    T data;
  public:
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode() { left= right= NULL; }
    TreeNode(T D, TreeNode<T> *L = 0, TreeNode<T> *R = 0) 
    {
      left= L;
      right= R;
      data= D;
    }

    T getData() { return data; }
    void setData(T D) { data = D; }
    
    static void PreOrder(TreeNode<T> *node) 
    {
      if(node != NULL) 
      {
        cout<< node->data  << " "; // Visit operation
        PreOrder(node->left);
        PreOrder(node->right);
      }
    }

    static void PostOrder(TreeNode<T> *node) 
    {
      if(node != NULL) 
      {
        PostOrder(node->left);
        PostOrder(node->right);
        cout<< node->data << " "; // Visit operation
      }
    }

    static void InOrder(TreeNode<T> *node) 
    {
      if(node != NULL) 
      {
        InOrder(node->left);
        cout<< node->data << " "; // Visit operation
        InOrder(node->right);
      }
    }

    int countNodes( ) 
    {
      int lcnt=0, rcnt=0;
      if(left!=NULL) lcnt= left->countNodes();
      if(right!=NULL) rcnt= right->countNodes();
      return 1 + lcnt + rcnt;
    }

    int getHeight()
    {
        if (this == NULL)
            return 0;
        int leftHeight = (left != NULL) ? left->getHeight() : 0;
        int rightHeight = (right != NULL) ? right->getHeight() : 0;
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() 
{
   TreeNode<int> *LChild3= new TreeNode<int>(4);
   TreeNode<int> *LChild2= new TreeNode<int>(3, LChild3);
   TreeNode<int> *LChild1= new TreeNode<int>(2, LChild2);
   
   TreeNode<int> *RChild2= new TreeNode<int>(11);
   TreeNode<int> *RChild1= new TreeNode<int>(10, 0, RChild2);
   
   
   TreeNode<int> T1(1, LChild1, RChild1);

   cout << "Count Nodes:" << T1.countNodes() << endl;

   TreeNode<int>::PreOrder(&T1); cout<<endl;
   TreeNode<int>::PostOrder(&T1); cout<<endl;
   TreeNode<int>::InOrder(&T1); cout<<endl;

  cout << "Height of the Binary Tree: " << T1.getHeight();
  
   return 0;
}