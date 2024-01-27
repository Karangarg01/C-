class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int row = matrix.size();
        int col = matrix[0].size();

        int total = row*col;
        int count = 0;

        int startRow=0, startCol=0;
        int endRow=row-1, endCol=col-1;

        while(count<total){
            for(int i=startCol; count<total &&  i<=endCol;i++){
                v.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            for(int i=startRow;  count<total && i<=endRow; i++){
                v.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for(int i=endCol;count<total &&  i>= startCol; i--){
                v.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            for(int i=endRow; count<total && i>=startRow; i--){
                v.push_back(matrix[i][startCol]);
                count++;
            }

            startCol++;
        }
        return v;
    }
};
