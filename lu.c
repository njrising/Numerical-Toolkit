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
    
    //std::cout<<n_rows<<std::endl;
    //std::cout<<n_cols<<std::endl;
    float in_matrix[n_rows][n_cols] = {};
    int row_itr = 0;
    int col_itr = 0;
    float in_num;   
    while(getline(in_file, in_str))
    {
        //std::cout<<in_str<<std::endl;
        std::istringstream ss(in_str);
        while(getline(ss,token,' '))
        {
            if(!token.empty())
            {
                std::stringstream(token) >> in_num;
                in_matrix[row_itr][col_itr] = in_num;
                //std::cout<<in_num<<std::endl;
                col_itr++;
            }
        }
        row_itr++;
        col_itr = 0;
    }
        
    in_file.close();
    std::cout<<"here"<<std::endl;
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            std::cout<<in_matrix[i][j]<<' ';    
        }
        std::cout<<'\n';
    }
    
    
      
}
else
{
    std::cout<<"Insufficient number of arguments\n";
    return -1;
}
return 0;
}