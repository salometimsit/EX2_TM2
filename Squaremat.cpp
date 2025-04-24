#include "Squaremat.hpp"
#include <cmath>
using namespace std;
using namespace square;
Squaremat::Squaremat(int s):size(s){
    if (s <= 0) throw invalid_argument("Size must be positive");
    mat=new double*[size];
    for(int i=0;i<size;i++){
        mat[i]=new double[size];
        for(int j=0;j<size;j++){
            mat[i][j]=0;
        }
    }

}
Squaremat::Squaremat(const Squaremat& other) : size(other.size) {
    if (other.mat == nullptr) throw runtime_error("Cannot copy invalid matrix");
    mat=new double*[size];
    for(int i=0;i<size;i++){
        mat[i]=new double[size];
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

double** Squaremat::getmat() const {
    if (mat == nullptr) throw runtime_error("Matrix not initialized");
    return mat;
}
Squaremat& Squaremat::operator=(const Squaremat& other) {
    if (this != &other) {
        for (int i = 0; i < size; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        size = other.size;
        mat = new double*[size];
        for (int i = 0; i < size; i++) {
            mat[i] = new double[size];
            for (int j = 0; j < size; j++) {
                mat[i][j] = other.getmat()[i][j];
            }
        }
    }
    return *this;
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
Squaremat& Squaremat::operator+=(const Squaremat& other) {
    *this = *this+other;
    return *this;
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
Squaremat& Squaremat::operator-=(const Squaremat& other) {
    if(size!=other.getsize()){
        throw invalid_argument("cannot sub without same size of matrix");
    }
    *this = *this-other;
    return *this;
}
Squaremat Squaremat::operator%(const Squaremat& other)const{
    if(size!=other.getsize()){
        throw invalid_argument("cannot modulo without same size of matrix");
    }
    Squaremat newm(size);
    for(int i=0;i<getsize();i++){
        for(int j=0;j<getsize();j++){
            newm.getmat()[i][j]=fmod(mat[i][j],other.getmat()[i][j]);
        }
    }
    return newm;
}
Squaremat& Squaremat::operator%=(const Squaremat& other) {
    if(size!=other.getsize()){
        throw invalid_argument("cannot modulo without same size of matrix");
    }
    *this = *this % other;
    return *this;
}
Squaremat Squaremat::operator%(int n)const{
    if(n==0){
        throw invalid_argument("cannot modulo without same size of matrix");
    }
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newm.getmat()[i][j]=fmod(mat[i][j] ,n);
        }
    }
    return newm;
}
Squaremat& Squaremat::operator%=(int n) {
    if(n==0){
        throw invalid_argument("cannot modulo without same size of matrix");
    }
    *this = *this % n;
    return *this;
}
Squaremat& Squaremat::operator++(){
    //pre increment
    for (int i = 0; i < getsize(); i++) {
        for (int j = 0; j < getsize(); j++) {
            mat[i][j] += 1; 
        }
    }
    return *this; 
}
Squaremat Squaremat::operator++(int){
    //post incriment
    Squaremat newm(size);
    newm=*this;
    for(int i=0;i<getsize();i++){
        for(int j=0;j<getsize();j++){
            mat[i][j]+=1;
        }
    }
    return newm;
}
// Squaremat& Squaremat::operator++()const{
//     Squaremat newm(size);
//     for(int i=0;i<getsize();i++){
//         for(int j=0;j<getsize();j++){
//             mat[i][j]=mat[i][j]+1;
//         }
//     }
//     return *this;

// }
Squaremat& Squaremat::operator--(){
    for (int i = 0; i < getsize(); i++) {
        for (int j = 0; j < getsize(); j++) {
            mat[i][j] -= 1; 
        }
    }
    return *this; 
}
Squaremat Squaremat::operator--(int){
    //post incriment
    Squaremat newm(size);
    newm=*this;
    for(int i=0;i<getsize();i++){
        for(int j=0;j<getsize();j++){
            mat[i][j]-=1;
        }
    }
    return newm;
}

Squaremat Squaremat::operator/(double n)const{
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newm.getmat()[i][j]=mat[i][j]/n;
        }
    }
    return newm;
}
Squaremat Squaremat::operator/(const Squaremat& other) const {
    return (*this) * other.inversematrix();
}
Squaremat& Squaremat::operator/=(const Squaremat& other) {
    *this = *this/other;
    return *this;
}

Squaremat Squaremat::inversematrix()const{
    Squaremat cof(size);
    double d= !(*this);
    std::cout << "Determinant: " << d << std::endl;
    int sign=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if((i+j)%2==0){
                sign =1;
            }
            else{
                sign =-1;
            }
            Squaremat min=deletee(*this,i,j);
            cof[i][j]=sign*!min;
            
        }
    }
    Squaremat adj= ~cof;
    return adj/d;
   
}


Squaremat Squaremat::operator*(double n)const{
    Squaremat newm(size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            newm.getmat()[i][j]=mat[i][j] *n;
        }
    }
    return newm;
}
Squaremat& Squaremat::operator*=(double n) {
    *this = *this * n;
    return *this;
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
Squaremat& Squaremat::operator*=(const Squaremat& other) {
    *this = *this*other;
    return *this;
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


Squaremat Squaremat::operator^(int n)const{
    if (n < 0) throw invalid_argument("Negative exponents not supported");
    Squaremat id(size);
    for(int i =0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j){
                id[i][j]=1;
            }
        }
    }
    if(n==0){
        return id;
    }
    Squaremat newm(size);
    newm=id;
   
    Squaremat tmp(*this);
    
    while(n>0){
        if(n%2==1){
            newm= newm*tmp;
        }
        Squaremat tmp2(tmp*tmp);
        tmp=Squaremat(tmp2);
        n/=2;
    }
    return newm;
}
// Squaremat Squaremat::operator^(int n)const{
//     Squaremat newm(size);
//     newm=mat;
//     for(int i =0;i<n;i++){
//         newm*=newm;
//     }
//     return newm;
// }
double* Squaremat::operator[](int x){
    return mat[x];
}
const double* Squaremat::operator[](int x) const {
    return mat[x];
}

Squaremat Squaremat::deletee(const Squaremat& m,int row,int col)const{
    Squaremat newm(m.getsize()-1); 
    int tmpi=0;
    for(int i=0;i<m.getsize();i++){
        int tmpj=0;
        if(i==row){
            continue;
        }
        for(int j=0;j<m.getsize();j++){
            if(j==col){
                continue;
            }
            newm[tmpi][tmpj]=m[i][j];
            tmpj++;
        
        }
        tmpi++;
    }
    return newm;

}
double Squaremat::operator!()const{
    double res=0;
    int sign;
    if(size==1){
        return mat[0][0];
    }
    if(size==2){
        double sum= (mat[0][0]*mat[1][1])- (mat[0][1]*mat[1][0]);
        return sum;

    }
    for(int j=0;j<size;j++){
        if(j%2==0){
            sign =1;
        }
        else{
            sign =-1;
        }
        Squaremat m=deletee(*this,0,j);
        double det =!m;
        res+=sign*det*mat[0][j];
    }
    return res;

}
namespace square {
    std::ostream& operator<<(std::ostream& os, const Squaremat& mat) {
        for(int i=0; i<mat.getsize(); i++) {
            for(int j=0; j<mat.getsize(); j++) {
                os << mat[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    
    }
}