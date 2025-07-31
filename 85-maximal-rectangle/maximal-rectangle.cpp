class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxArea = 0;
        for(int i = 0; i< row; i++ ){
            // prepare a histogram array whose bars are taken from i = i to i = 0; 
            vector<int>heightOfBar(col,0);
            for(int j = 0; j < col; j++){
                int temp = i;
                    while(temp >= 0 && matrix[temp][j] != '0'){
                        heightOfBar[j]++;
                        temp--; 
                    }
                    // height of a bar is set in the array heightOfBar

            }
            // array heightOfBar is fully set for i = i;
            // Now calculate the areas of rectangles --> put it into maxArea 
        for(int k = 0; k< col; k++){
            int s = k;
            int e = k;
            while(s-1 >= 0 && heightOfBar[s-1] >= heightOfBar[k]){
                s--;
            }
            while(e+1 < col && heightOfBar[e+1] >= heightOfBar[k]){
                e++;
            }

            int width = e-s+1;
            int height = heightOfBar[k];
            int area = width * height;
            maxArea = max(maxArea,area);
            }
        }
        return maxArea;
    }
};