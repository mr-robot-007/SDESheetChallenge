// Bruteforce 
// Ask interviewer if all values are +ve in matrix
// Then iterate over the whole matrix and if any zero is found , then set all nonzero values to -1 in that row and column.

// Then again iterate over the whole matrix and make all -1 values to 0.


#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    int rows = matrix.size();
    int cols =  matrix[0].size();
    
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j <  cols ; j++) {
            if(matrix[i][j] == 0) {
                int ind = i - 1;
                while(ind>=0) {
                    if(matrix[ind][j]!=0){
                        matrix[ind][j]=-1;
                    }
                    ind--;
                }
                ind = i + 1;
                while(ind<rows) {
                    if(matrix[ind][j]!=0){
                        matrix[ind][j] = -1;
                    }
                    ind++;
                }
                ind = j - 1 ;
                while(ind>=0) {
                    if(matrix[i][ind]!=0){
                        matrix[i][ind] = -1;
                    }
                    ind--;
                }
                ind = j + 1;
                while(ind<cols){
                    if(matrix[i][ind]!=0){
                        matrix[i][ind] = -1;
                    }
                    ind++;
                }
            }
        }
    }
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j]=0;   
            }
        }
    }
}





// Better 
// Create two dummy arrays of size of rows and cols and set all values to -1;
// Then iterate over matrix and set 0 at resp. Row and col in dummy array .
// Then again iterate over matrix and set 0 at every pos if dummy[i] == 0 or dummy[j] ==0


#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    int rows = matrix.size(),cols = matrix[0].size();
    vector<int> dummy1(rows,-1),dummy2(cols,-1);
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            if(matrix[i][j]==0) {
                dummy1[i] = 0;
                dummy2[j] = 0;
            }
        }
    }
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ;j++) {
            if(dummy1[i]==0 || dummy2[j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
}






// Optimised 

// We will use first row and column as dummy array and set values to 0 in them if any 0 value is found
// for any value that will be 0 in 0th column we will use a variable to mark if any value is actually 0 in 0th column
//then we will iterate backwards checking if any element with resp 0th row or col index has value 0 should be marked 0 and if our col varaible is true and we will mark all elements 0 in 0th column.


#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.3
    int rows = matrix.size(),cols = matrix[0].size();
    bool col = false;
    for (int i = 0 ; i < rows ; i++) {
	//checking if 0 is present in the 0th column or not	
        if(matrix[i][0]==0){
            col = true;
        }
        for(int j = 1 ; j < cols; j++) {
            
            if(matrix[i][j] == 0 ) {
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }

//traversing in the reverse direction and //checking if the row or col has 0 or not //and setting values of matrix accordingly.

    for(int  i = rows-1; i>=0 ;i--) {
        for(int j = cols-1; j>=1;j--) {
            if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j]=0;
            }
        }
        if(col == true) {
            matrix[i][0] = 0;
        }
    }
}



