class Solution {
public:
    void flowWater(int i, int j, int m, int n, vector<vector<int>>& image, int color, int targetColor) {
        if(i < 0 || j < 0 || i >= m || j >= n) return;
        if(image[i][j] != targetColor || image[i][j] == color) return;

        image[i][j] = color;
        flowWater(i+1, j, m, n, image, color, targetColor);
        flowWater(i-1, j, m, n, image, color, targetColor);
        flowWater(i, j+1, m, n, image, color, targetColor);
        flowWater(i, j-1, m, n, image, color, targetColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int targetColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        flowWater(sr, sc, m, n, image, color, targetColor);

        return image;
    }
};
