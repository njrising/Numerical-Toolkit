// Tool for putting matrices in reduced row echelon form
// using Gaussian elimination
// To use, make sure text file containing matrix data is in
// same folder and run as ./[program name] [file.txt] after compilation
// First line of text file contains matrix size e.g. for 2x2 matrix, write 2 2
// next lines contain matrix data e.g. write  1 2
//					      3 4 
// Author: Nathan Rising
// Last revision: 01/30/2021
// Gaussian elimination is a very simple method to row reduce matrices
// This program was created for educational purposes and outputs the major steps
// after each iteration.
// Maybe wierd using vector, but whatever.
// 
#include <iostream> 
#include <fstream>  
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>

int main(int argc,char* argv[])
{
    std::vector<float> matrix; // matrix data is stored in vector
    float zero_tol = 0.0001;   // any number |num| < tol defined as zero
    int n_rows;		       // number of matrix rows
    int n_cols;		       // number of matrix columns

    if(argc > 1)
    {
        std::string file_name;
        file_name = argv[1];

        // open file containing matrix data
        std::fstream in_file;
        in_file.open(file_name,std::ios::in);

        if(in_file.is_open()){

            std::string in_str;
            std::string token;
            float in_num;

            // read in columns and rows of matrix
            getline(in_file,in_str);
            std::istringstream ss(in_str);
            std::getline(ss,token,' ');
            std::stringstream(token)>>n_rows;
            std::getline(ss,token,' ');
            std::stringstream(token)>>n_cols;

            // read in matrix data and assign elements to vector
            while(getline(in_file,in_str)){
                std::istringstream ss(in_str);
                while(std::getline(ss,token,' ')){
                    std::stringstream(token)>>in_num;
                    matrix.push_back(in_num);
                }
            }
            // close file since no longer needed
            in_file.close();
        }
        else{
            // print error message if unable to open file
            std::cout<<"could not open file"<<'\n';
        }

        // print contents of file
        std::cout<<"step: 0"<<'\n';
        for(int i = 0;i < n_rows;++i){
            for(int j = 0;j < n_cols; ++j){
            std::cout<<matrix[j + n_cols * i]<<' ';
            }
            std::cout<<'\n';
        }
    }

    // put into reduced row echelon form
    // iterate through each column. a is column pivot
    for(int a = 0;a < n_rows;++a){
        // find nonzero pivot
        if(abs(matrix[a + n_cols * a]) < zero_tol){
            for(int b = a + 1;b < n_rows;++b){
                if(abs(matrix[a + n_cols * b]) > zero_tol){
                    // swap rows
                    for(int c = 0;c < n_cols;++c){
                        float num_swap = matrix[c + n_cols * a];
                        matrix[c + n_cols * a] = matrix[c + n_cols * b];
                        matrix[c + n_cols * b] = num_swap;
                    }
                }
            }
        }
        // perform row operations provided pivot is nonzero
        if(abs(matrix[a + n_cols * a]) > zero_tol){
            // divide row by pivot value
            float pivot = matrix[a + n_cols * a];
            for(int d = a;d < n_cols;++d){
                matrix[d + n_cols * a] /= pivot;
            }
            for(int e = n_rows - 1;e > -1 ;--e){
                if(a != e){
                    for(int f = n_cols - 1;f > -1;--f){
                        matrix[f + n_cols * e] += -matrix[a + n_cols * e]/matrix[a + n_cols * a] * matrix[f + n_cols * a];
                    }
                }
            }
        }
        // print row reduction progress
        std::cout<<"step: "<<a + 1<<'\n';
        for(int i = 0;i < n_rows;++i){
            for(int j = 0;j < n_cols; ++j){
            std::cout<<std::setprecision(2)<<matrix[j + n_cols * i]<<' ';
            }
            std::cout<<'\n';
        }
    }
    return 0;
}