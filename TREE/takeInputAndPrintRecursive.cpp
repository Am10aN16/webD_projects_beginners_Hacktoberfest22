#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

int numNodes(TreeNode<int>* root)
{
   int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+= numNodes(root->children[i]);
    }
    return ans;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void printTreeLevelWise(TreeNode<int> *root)
{
    // queue<TreeNode<int>*> pendingNodes;
    // pendingNodes.push(root);
    // // cout<<queue.front
    // while(pendingNodes.size()!=0)
    // {
    //     cout<<pendingNodes.front();
    //     pendingNodes.pop();
    //     for(int i=0;i<root->children.size();i++)
    //     {
    //         pendingNodes.push(root->children[i]->data);
    //     }

    // }
    if(root==NULL)
    return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for (int  i = 0; i < front->children.size(); i++)
        {
            if(i==0)
            cout<<front->children[i]->data;
            else
            cout<<","<<front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
        
    }




}

TreeNode<int> *takeInputLevelWise()

{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout<<"Enter "<<i+1<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    int n=numNodes(root);
    cout<<n<<endl;
    return 0;
}