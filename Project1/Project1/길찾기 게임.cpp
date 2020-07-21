#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> PI;

vector<int>pre;
vector<int>post;

struct node
{
    int val;
    int x;
    int y;
    node* left;
    node* right;
};

void makeTree(node* r,node* Node)
{
    if (Node->x < r->x)
    {
        if (r->left != NULL)
        {
            makeTree(r->left, Node);
        }
        else r->left = Node;
    }
    else
    {
        if (r->right != NULL)
        {
            makeTree(r->right, Node);
        }
        else r->right = Node;
    }
}

void postorder(node* r)
{
    if (r->left != NULL) postorder(r->left);
    if (r->right != NULL) postorder(r->right);
    if (r != NULL) {
        post.push_back(r->val);
    }
}

void preorder(node* r)
{
    if (r != NULL) {
        pre.push_back(r->val);
    }
    if (r->left != NULL) preorder(r->left);
    if (r->right != NULL) preorder(r->right);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<PI>v;
    node* root;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        v.push_back({ {nodeinfo[i][1],nodeinfo[i][0]},i+1 });
    }
    sort(v.begin(),v.end(),greater<PI>());

    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
        {
            root = new node();
            root->val = v[i].second;
            root->y = v[i].first.first;
            root->x = v[i].first.second;
        }
        else
        {
            node* nnode = new node();
            nnode->val = v[i].second;
            nnode->y = v[i].first.first;
            nnode->x = v[i].first.second;
            makeTree(root, nnode);
        }
    }
    preorder(root);
    postorder(root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}