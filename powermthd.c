// Power method for finding dominant eigenvalue
//
//
//
//
//

// Matrix multiplication with a vector
void mult(int A[][2], int *b, int *r){
    int i,j;
    for(i=0;i<2;++i){
        r[i] = 0;
        for(j=0;j<2;++j){
           r[i] += A[i][j] * b[j];
        }
    }
}

void mult_(int *A, int *b, int *r){
    int i,j;
    for(i=0;i<2;++i){
        r[i] = 0;
        for(j=0;j<2;++j){
           r[i] += A[i*2+j] * b[j];
        }
    }
}




void powermthd(float A, float i_vec[], float tol, int maxitr){
    int itr = 0;
    float error = 1;
    while(error > tol && itr < maxitr){
        mult(A,i_vec); //eig_vec = A*init_vec;
        int m = abs(*std::max_element(v.begin(),v.end(), [](int a,int b){return abs(a)<abs(b);}));
        eig_vec = eig_vec/norm(eig_vec);
        error = 
        init_vec = eig_vec;
        itr++;
    }

}


int main(int argc, char* argv[]){
    float eig_res[2] = {};
    float eig_val;
    



return 0;
}