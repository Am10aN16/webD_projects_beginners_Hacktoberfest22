public boolean searchMatrix(int[][] matrix, int target) {
        int row=0;
        int col=matrix[row].length-1;
        
        while(row<matrix.length&& col>=0){
            
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]<target) row++;
            else col--;
        }
        return false;
        
    }