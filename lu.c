// LU decomposition for square matrices
// PLU decomposition for non-square matrices
// Write results to output or generate text files 
// to store result for large matrices
//
// Author: Nathan Rising
// Last Revision: 02/10/2021

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[])
{

// Take in only one text file
if(argc == 2)
{

    std::string file_name;
    file_name = argv[1]; // extract textfile name
                        
    // Open file
    std::fstream in_file;
    in_file.open(file_name,std::ios::in);
    
    if(in_file.is_open())
    {
        std::string in_str;
        std::string token;
        // get first line of string
        // create input stream to operate on string
        std::getline(in_file, in_str);
        std::istringstream ss(in_str);
        // get rows
        int n_rows;
        std::getline(ss,token,' ');
        std::stringstream(token) >> n_rows;
        // get columns
        int n_cols;
        std::getline(ss,token,' ');
        std::stringstream(token) >> n_cols;    
        // matrix data
        float in_matrix[n_rows][n_cols] = {};
    
        int row_itr = 0;
        int col_itr = 0;
        float in_num;   
        // read in matrix data and assign elements to array
        while(std::getline(in_file, in_str)){
            std::istringstream ss(in_str);
            while(std::getline(ss,token,' ')){
                if(!token.empty()){  // in case there are too many spaces
                    std::stringstream(token) >> in_num;
                    in_matrix[row_itr][col_itr] = in_num;
                    col_itr++;
                }
            }
            row_itr++;
            col_itr = 0;
        }
    
        // close file    
        in_file.close();
    
        // print contents of file
        std::cout<<"step: 0\n";    
        for(unsigned i = 0;i < 2;i++){
            for(unsigned j = 0;j < 2;j++){
                std::cout<<in_matrix[i][j]<<' ';    
            }
                std::cout<<'\n';
        }
        
        float zero_tol = 0.0001;
        // Permutation matrix
        float P[n_rows][n_rows] = {};
        float L[n_rows][n_rows] = {};
        float U[n_rows][n_cols] = {};
        // place zeros on diagonal
        for(unsigned i = 0;i < n_rows;++i){
            P[i][i] = 1.0;
            L[i][i] = 1.0;
            U[i][i] = 1.0;        
        }
    
    
    // iterate through columns
    for(unsigned i = 0;i <= n_rows;++i){
        // Make sure pivot is nonzero
        if(abs(in_matrix[i][i]) < zero_tol){
            for(unsigned j = i+1; j <n_rows;++j){
                if(abs(in_matrix[j][i]) > zero_tol){
                    // swap rows
                    for(unsigned k = 0;k < n_cols;++k){
                        float num_swap = in_matrix[j][k];
                        in_matrix[j][k] = in_matrix[i][k];
                        in_matrix[i][k] = num_swap; 
                    }
                    //--------- permutation matrix
                    float PN[n_rows][n_rows] = {};
                    PN[i][j] = 1.0;
                    PN[j][i] = 1.0;
                    for(int l = 0;l < n_rows;++l){
                        if(l != i | l != j}{
                            PN[l][l] = 1.0;
                        }
                    }
                    
                    // Multiply permutation matrices together
                    float R[n_rows][n_rows] = {}; // temporary
                    for(unsigned m = 0;m < n_rows;++m){
                        for(unsigned n = 0;n < n_rows;++n){
                            for(unsigned o = 0;o < n_rows;++o){
                                R[m][n] += PN[m][o] * P[o][n];
                            }
                        }
                    }
                    // set matrix [P] = [R]
                    for(unsigned p = 0;p < n_rows;++p){
                        for(unsigned q = 0;q < n_rows;++q){
                            P[p][q] = R[p][q];
                        }
                    }
                    //--------- not best implementation    
                    break; // if pivot found, stop searching
                }
            }    
        }    
    
    // Continue
    
    
    
    
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
    else
    {
        // print error message if unable to open file
        std::cout<<"Could not open file\n";
    }      
}
else
{
    std::cout<<"Insufficient number of arguments\n";
    return 1;
}
return 0;
}