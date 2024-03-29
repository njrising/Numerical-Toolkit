// Gauss-Seidel method for solving Ax=b
// input: [A], b, x, iterations, rows, cols 
void gaussSeidel(float *A,float *b, float *x, int itr, int row, int col){
float sum; unsigned i,j,k;
for(i=0;i<itr;++i){
    for(j=0;j<row;++j){
        sum = 0;
        for(k=0;k<col;++k){
            if(j!=k){
                sum += A[col*j+k] * x[k];
            }        
        }
    x[j] = -1/A[(col+1)*j] * (sum - b[j]);                
    }
}
}

