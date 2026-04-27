/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* solve(vector<vector<int>>& grid,int row,int col,int size){
        if(isuniform(grid,row,col,size)){
            return new Node(grid[row][col]==1,true);
        }
        int half=size/2;
        Node* topleft=solve(grid,row,col,half);
        Node* topright=solve(grid,row,col+half,half);
        Node* bottomleft=solve(grid,row+half,col,half);
        Node* bottomright=solve(grid,row+half,col+half,half);
        return new Node(true,false,topleft,topright,bottomleft,bottomright);
    }
    bool isuniform(vector<vector<int>>& grid,int row,int col,int size){
        int first=grid[row][col];
        for(int i=row;i<row+size;i++){
            for(int j=col;j<col+size;j++){
                if(grid[i][j]!= first) return false;
            }
        }
        return true;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid,0,0,grid.size());
        
    }
};