

/*

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        //failed to handle this case where the original color is same as color to fill 
        //such a scenario, it will keep re-filling the same cells indefinitely
        if(image[sr][sc] == color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int st = image[sr][sc];
        image[sr][sc] = color;

        int row[4] = {0,1,0,-1};
        int col[4] = {1,0,-1,0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row[i] + r;
                int ncol = col[i] + c;

                if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && image[nrow][ncol]==st){
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};


/*
    Intution : 
    In this problem, we have to fill the adjacent cells with the same color as the starting cell. 
    we choose bfs for this purpose as it traverse level by level filling the cells with same color 
    the only fall to consider here is that if the original color is same as the color to be filled then we need to return the answer there itself as it will keep refilling the same cells indefinitely. 

    Time Complexity : O(N*M) as we are traversing the whole matrix at the worst case to fill all the matrix
    Space Complexity : O(N*M) as we are using the queue to store the cells to be filled. we are not using any extra space to return the answer

*/