#include "Squaremat.hpp"
using namespace std;
using namespace square;
Squaremat::Squaremat(int s):size(s){
    if (s <= 0) throw invalid_argument("Size must be positive");
    mat=new int*[size];
    for(int i=0;i<size;i++){
        mat[i]=new int[size];
        for(int j=0;j<size;j++){
            mat[i][j]=0;
        }
    }

}
Squaremat::Squaremat(const Squaremat& other) : size(other.size) {
    if (other.mat == nullptr) throw runtime_error("Cannot copy invalid matrix");
    mat=new int*[size];
    for(int i=0;i<size;i++){
        mat[i]=new int[size];
        for(int j=0;j<size;j++){
            mat[i][j]=other.mat[i][j];
        }
    }

}
Squaremat::~Squaremat(){
    for(int i=0;i<size;i++){
        delete[] mat[i];
    }
    delete[] mat;
}
int Squaremat::getsize() const {
    return size;
}

int** Squaremat::getmat() const {
    if (mat == nullptr) throw runtime_error("Matrix not initialized");
    return mat;
}

Squaremat Squaremat::operator+(const Squaremat& other) const{
    //handle if there not the same size'
    if(size!=other.getsize()){
        throw invalid_argument("cannot add without same size of matrix");
    }
    Squaremat newm(size);
    for(int i=0;i<getsize();i++){
        for(int j=0;j<getsize();j++){
            newm.getmat()[i][j]=mat[i][j]+other.getmat()[i][j];
        }
    }
    return newm;
}
Squaremat Squaremat::operator-(const Squaremat& other)const{
    if(size!=other.getsize()){
        throw invalid_argument("cannot sub without same size of matrix");
    }
    Squaremat newm(size);
    for(int i=0;i<getsize();i++){
        for(int j=0;j<getsize();j++){
            newm.getmat()[i][j]=mat[i][j]-other.getmat()[i][j];
        }
    }
    return newm;
}
Squaremat Squaremat::operator%(const Squaremat& other)const{
    if(size!=other.getsize()){
        throw invalid_argument("cannot sub without same size of matrix");
    }
    Squaremat newm(size);
    for(int i=0;i<getsize();i++){
        for(int j=0;j<getsize();j++){
            newm.getmat()[i][j]=mat[i][j]*other.getmat()[i][j];
        }
    }
    return newm;
}
Squaremat Squaremat::operator++()const{
    Squaremat newm(size);
    for(int i=0;i<getsize();i++){
        for(int j=0;j<getsize();j++){
            newm.getmat()[i][j]=mat[i][j]+1;
        }
    }
    return newm;

}
Squaremat Squaremat::operator--()const{
    Squaremat newm(size);
    for(int i=0;i<getsize();i++){
        for(int j=0;j<getsize();j++){
            newm.getmat()[i][j]=mat[i][j]-1;
        }
    }
    return newm;

}
Squaremat Squaremat::operator/(int n)const{
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newm.getmat()[i][j]=mat[i][j]/n;
        }
    }
    return newm;
}

Squaremat Squaremat::operator%(int n)const{
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newm.getmat()[i][j]=mat[i][j] %n;
        }
    }
    return newm;
}
Squaremat Squaremat::operator*(int n)const{
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newm.getmat()[i][j]=mat[i][j] *n;
        }
    }
    return newm;
}
bool Squaremat::operator==(const Squaremat& other)const{
    int sum1=0;
    int sum2=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            sum1+=mat[i][j];
            sum2+=other.getmat()[i][j];
        }
    }
    if(sum1==sum2){
        return true;
    }
    return false;
}
bool Squaremat::operator!=(const Squaremat& other)const{
    int sum1=0;
    int sum2=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            sum1+=mat[i][j];
            sum2+=other.getmat()[i][j];
        }
    }
    if(sum1==sum2){
        return false;
    }
    return true;
}
bool Squaremat::operator<(const Squaremat& other)const{
    int sum1=0;
    int sum2=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            sum1+=mat[i][j];
            sum2+=other.getmat()[i][j];
        }
    }
    if(sum1<sum2){
        return true;
    }
    return false;
}
bool Squaremat::operator<=(const Squaremat& other)const{
    int sum1=0;
    int sum2=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            sum1+=mat[i][j];
            sum2+=other.getmat()[i][j];
        }
    }
    if(sum1<=sum2){
        return true;
    }
    return false;
}
bool Squaremat::operator>(const Squaremat& other)const{
    int sum1=0;
    int sum2=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            sum1+=mat[i][j];
            sum2+=other.getmat()[i][j];
        }
    }
    if(sum1>sum2){
        return true;
    }
    return false;
}
bool Squaremat::operator>=(const Squaremat& other)const{
    int sum1=0;
    int sum2=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            sum1+=mat[i][j];
            sum2+=other.getmat()[i][j];
        }
    }
    if(sum1>=sum2){
        return true;
    }
    return false;
}
Squaremat Squaremat::operator~()const{
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newm.getmat()[i][j]=mat[j][i];
        }
    }
    return newm;
}
Squaremat Squaremat::operator-() const{
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newm.getmat()[i][j]=-(mat[i][j]);
        }
    }
    return newm;
}
Squaremat Squaremat::operator*(const Squaremat& other) const{
    if (size != other.getsize()) throw invalid_argument("Sizes must match");
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newm.getmat()[i][j] = 0; 
            for (int k = 0; k < size; k++) {
                newm.getmat()[i][j] += mat[i][k] * other.mat[k][j];
            }
        }
    }
    return newm;
}

Squaremat Squaremat::operator^(int n)const{
    if (n < 0) throw invalid_argument("Negative exponents not supported");
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        newm.getmat()[i][i]=1;
    }
    Squaremat tmp(*this);
    
    while(n>0){
        if(n%2==1){
            Squaremat tmp2(tmp*newm);
            newm =Squaremat(tmp2);
        }
        Squaremat tmp2(tmp*tmp);
        tmp=Squaremat(tmp2);
        n/=2;
    }
    return newm;
}
void Squaremat::printmat()const{
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<mat[i][j]<<"";
        }
        
        cout<<endl;
    }

}