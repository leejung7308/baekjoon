#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct tree{
    int idx;
    int x;
    int y;
    tree* left;
    tree* right;
};
bool cmp(const tree& a, const tree& b){
    if(a.y>b.y) return true;
    else if(a.y<b.y) return false;
    else if(a.x<b.x) return true;
    else return false;
}
void make_tree(tree* root, tree* child){
    if(root->x > child->x){
        if(root->left == NULL){
            root->left = child;
            return;
        }    
        make_tree(root->left, child);
    }
    else{
        if(root->right == NULL){
            root->right = child;
            return;
        }
        make_tree(root->right,child);
    }
}
void pre(tree* root, vector<vector<int>>& answer){
    if(root==NULL) return;
    answer[0].push_back(root->idx);
    pre(root->left, answer);
    pre(root->right, answer);
}
void post(tree* root, vector<vector<int>>& answer){
    if(root==NULL) return;
    post(root->left,answer);
    post(root->right,answer);
    answer[1].push_back(root->idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<tree> v;
    for(int i=0;i<nodeinfo.size();i++) 
        v.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1],NULL,NULL});
    sort(v.begin(),v.end(),cmp);
    tree* root = &v[0];
    for(int i=1;i<v.size();i++) make_tree(root,&v[i]);
    pre(root, answer);
    post(root, answer);
    return answer;
}