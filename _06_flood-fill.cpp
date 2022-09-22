class Solution {
public:
    void recur(vector<vector<int>>& image, int sr, int sc, int color, int init) {
        if (sr < 0 || sr > image.size()-1 ||
           sc < 0 || sc > image[0].size()-1) 
            return ;
        printf("%d %d\n", sr, sc);
        if (init == color) return ;
        if (image[sr][sc] == init) {
            image[sr][sc] = color;
            recur(image, sr-1, sc, color, init);
            recur(image, sr+1, sc, color, init);
            recur(image, sr, sc-1, color, init);
            recur(image, sr, sc+1, color, init);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        recur(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
