// LU decomposition for square matrices
// PLU decomposition for non-square matrices
// 

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[])
{


if(argc > 1)
{

    std::string file_name;
    file_name = argv[1];
    
    // Open file
    std::fstream in_file;
    in_file.open(file_name,std::ios::in);
    if(in_file.is_open())
    {
        std::string in_str;
        std::string token;
        // get first line of string
        // create input stream to operate on string
        getline(in_file, in_str);
        std::istringstream ss(in_str);
        // get rows
        int n_rows;
        getline(ss,token,' ');
        std::stringstream(token) >> n_rows;
        // get columns
        int n_cols;
        getline(ss,token,' ');
        std::stringstream(token) >> n_cols;    
        // matrix data
        float in_matrix[n_rows][n_cols] = {};
    
        int row_itr = 0;
        int col_itr = 0;
        float in_num;   
        // read in matrix data and assign elements to array
        while(getline(in_file, in_str)){
            std::istringstream ss(in_str);
            while(getline(ss,token,' ')){
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
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                std::cout<<in_matrix[i][j]<<' ';    
            }
                std::cout<<'\n';
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
    return -1;
}
return 0;
}