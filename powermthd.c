// Power method for finding dominant eigenvalue
//
//
//
//
//

// Matrix vector multiplication
//void vmult(float *A, float *b, float *r){
//    int i,j,nr,nc;
//    nr=r[0];nc=r[1];
//    for(i=0;i<nr;++i){
//        r[i] = 0;
//        for(j=0;j<nc;++j){
//           r[i] += A[i*nr+j] * b[j];
//       }
//    }
//}

// Matrix Matrix multiplication Mult()
void Mult(float *A, float *B, float *R, int *d){
    int i,j,k,ar,bc,in;
    ar=d[0];bc=d[1];in=d[2];
    for(i=0;i<ar;++i){
        for(j=0;j<bc;++j){
            R[i*bc+j]=0;
            for(k=0;k<in;++k){
                R[i*bc+j]+=A[i*in+k]*B[k*bc+j];
            }
        }
    }
}
// divides elements of array by its infinity norm
void inf_norm(float *v){
    //float m = abs(*std::max_element(std::begin(v),std::end(v),[](int a,int b){return abs(a)<abs(b);}));
    //std::for_each(std::begin(v),std::end(v),[m](float &n){return n/=m;})
    float max = 0;
    for(int i = 0;i<2;++i){
        if(abs(v[i]) > max){
            max = abs(v[i]);        
        }
    }
    for(int i = 0;i<2;++i){
        v[i]/=max;
    }
}
// 
void error(float *a, float *b, float &err){
    err = 0;
    for(int i=0;i<2;++i){
        err += (a[i]-b[i])*(a[i]-b[i]);
        a[i] = b[i];
    }
}


void powermthd(float *A, float i_vec[], float tol, int maxitr, float *eig_vec, float *eig_val){
    int itr = 0;	// current iteration
    float err = 1;  // error
    int d[] = {2,1,2};
    while((err*err > tol) && (itr < maxitr)){
        Mult(A, i_vec, eig_vec, d);    //eig_vec = A*init_vec;
        inf_norm(eig_vec);         	   //eig_vec = eig_vec/norm(eig_vec);
        error(eig_vec,i_vec,err); 
        itr++;
    }
    float arr[2] ={};
    Mult(A,eig_vec,arr,{});
    //int k = std::inner_product(std::begin(arr),std::end(arr),std::begin(eig_vec),0);
    //int m = std::inner_product(std::begin(eig_vec),std::end(eig_vec),std::begin(eig_vec),0);
    eig_val =k/m;
}


int main(int argc, char* argv[]){
    float eig_vec[2] = {};
    float eig_val;
    
    float A[4] = {1.0,2.0,3.0,4.0};
    float i_vec[2] = {1.0,1.0};
    
    powermthd(A, i_vec, 0.001, 10, eig_vec, eig_val);
    



return 0;
}