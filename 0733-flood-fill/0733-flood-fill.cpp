class Solution {
public:
      void dfs(vector<vector<int>>& image,int i , int j, int newColor,int initial){
        int n = image.size();
        int m = image[0].size();
        
        if(i<0||j<0||i>=n||j>=m||image[i][j]!=initial) return;   
        
        image[i][j]=newColor;
        dfs(image,i+1,j,newColor,initial);
        dfs(image,i-1,j,newColor,initial);
        dfs(image,i,j+1,newColor,initial);
        dfs(image,i,j-1,newColor,initial);}
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {      
	if(image[sr][sc]!=newColor)
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }

};