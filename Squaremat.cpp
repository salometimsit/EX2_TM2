//Email: timsitmelosa@gmail.com
/**
 * Explanation: Implementation of the Squaremat class for working with square matrices
 * 
 * This file contains the implementation of the Squaremat class, which provides
 * functionality for creating and manipulating square matrices of arbitrary size.
 * It includes various matrix operations such as addition, subtraction, multiplication,
 * transpose, inversion, and other mathematical operations.
 * @author Salome Timsit
 */

 #include "Squaremat.hpp"
 #include <cmath>
 using namespace std;
 using namespace square;
 
 /**
  * Explanation: Constructor that creates a square matrix of given size
  * @param s The size of the square matrix (number of rows and columns)
  * @throw invalid_argument if size is not positive
  */
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
 
 /**
  * Explanation: Copy constructor that creates a new matrix from an existing one
  * @param other The matrix to copy
  * @throw runtime_error if the source matrix is invalid
  */
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
 
 /**
  * Explanation: Destructor that frees all dynamically allocated memory
  */
 Squaremat::~Squaremat(){
     for(int i=0;i<size;i++){
         delete[] mat[i];
     }
     delete[] mat;
 }
 
 /**
  * Explanation: Returns the size of the square matrix
  * @return The size of the matrix (number of rows or columns)
  */
 int Squaremat::getsize() const {
     return size;
 }
 
 /**
  * Explanation: Returns a pointer to the matrix data
  * @return Double pointer to the matrix data
  * @throw runtime_error if matrix is not initialized
  */
 double** Squaremat::getmat() const {
     if (mat == nullptr) throw runtime_error("Matrix not initialized");
     return mat;
 }
 
 /**
  * Explanation: Assignment operator that copies one matrix to another
  * @param other The matrix to copy from
  * @return Reference to this matrix after assignment
  */
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
 
 /**
  * Explanation: Addition operator that adds two matrices
  * @param other The matrix to add to this one
  * @return A new matrix resulting from the addition
  * @throw invalid_argument if matrices have different sizes
  */
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
 
 /**
  * Explanation: Addition assignment operator
  * @param other The matrix to add to this one
  * @return Reference to this matrix after addition
  */
 Squaremat& Squaremat::operator+=(const Squaremat& other) {
     *this = *this+other;
     return *this;
 }
 
 /**
  * Explanation: Subtraction operator that subtracts another matrix from this one
  * @param other The matrix to subtract from this one
  * @return A new matrix resulting from the subtraction
  * @throw invalid_argument if matrices have different sizes
  */
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
 
 /**
  * Explanation: Subtraction assignment operator
  * @param other The matrix to subtract from this one
  * @return Reference to this matrix after subtraction
  * @throw invalid_argument if matrices have different sizes
  */
 Squaremat& Squaremat::operator-=(const Squaremat& other) {
     if(size!=other.getsize()){
         throw invalid_argument("cannot sub without same size of matrix");
     }
     *this = *this-other;
     return *this;
 }
 
 /**
  * Explanation:  modulo operator between two matrices
  * @param other The matrix to take modulo with
  * @return A new matrix with  modulo results
  * @throw invalid_argument if matrices have different sizes
  */
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
 
 /**
  * Explanation:  modulo assignment operator
  * @param other The matrix to take modulo with
  * @return Reference to this matrix after modulo operation
  * @throw invalid_argument if matrices have different sizes
  */
 Squaremat& Squaremat::operator%=(const Squaremat& other) {
     if(size!=other.getsize()){
         throw invalid_argument("cannot modulo without same size of matrix");
     }
     *this = *this % other;
     return *this;
 }
 
 /**
  * Explanation: Modulo operator with a scalar value
  * @param n The scalar value to take modulo with
  * @return A new matrix with each element taking modulo n
  * @throw invalid_argument if n is zero
  */
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
 
 /**
  * Explanation: Modulo assignment operator with a scalar value
  * @param n The scalar value to take modulo with
  * @return Reference to this matrix after modulo operation
  * @throw invalid_argument if n is zero
  */
 Squaremat& Squaremat::operator%=(int n) {
     if(n==0){
         throw invalid_argument("cannot modulo without same size of matrix");
     }
     *this = *this % n;
     return *this;
 }
 
 /**
  * Explanation: Pre-increment operator that adds 1 to each element
  * @return Reference to this matrix after increment
  */
 Squaremat& Squaremat::operator++(){
     //pre increment
     for (int i = 0; i < getsize(); i++) {
         for (int j = 0; j < getsize(); j++) {
             mat[i][j] += 1; 
         }
     }
     return *this; 
 }
 
 /**
  * Explanation: Post-increment operator that adds 1 to each element
  * @return A copy of the matrix before increment
  */
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
 
 /**
  * Explanation: Pre-decrement operator that subtracts 1 from each element
  * @return Reference to this matrix after decrement
  */
 Squaremat& Squaremat::operator--(){
     for (int i = 0; i < getsize(); i++) {
         for (int j = 0; j < getsize(); j++) {
             mat[i][j] -= 1; 
         }
     }
     return *this; 
 }
 
 /**
  * Explanation: Post-decrement operator that subtracts 1 from each element
  * @return A copy of the matrix before decrement
  */
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
 
 /**
  * Explanation: Division operator with a scalar value
  * @param n The scalar value to divide by
  * @return A new matrix with each element divided by n
  */
 Squaremat Squaremat::operator/(double n)const{
     Squaremat newm(size);
     for(int i=0;i<size;i++){
         for(int j=0;j<size;j++){
             newm.getmat()[i][j]=mat[i][j]/n;
         }
     }
     return newm;
 }
 
 /**
  * Explanation: Matrix division operator (multiplies by the inverse of the other matrix)
  * @param other The matrix to divide by
  * @return The result of this * inverse(other)
  */
 Squaremat Squaremat::operator/(const Squaremat& other) const {
     return (*this) * other.inversematrix();
 }
 
 /**
  * Explanation: Division assignment operator
  * @param other The matrix to divide by
  * @return Reference to this matrix after division
  */
 Squaremat& Squaremat::operator/=(const Squaremat& other) {
     *this = *this/other;
     return *this;
 }
 
 /**
  * Explanation: Calculates the inverse of this matrix
  * @return The inverse of this matrix
  * @note Uses the adjugate method for matrix inversion
  */
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
 
 /**
  * Explanation: Scalar multiplication operator
  * @param n The scalar value to multiply with
  * @return A new matrix with each element multiplied by n
  */
 Squaremat Squaremat::operator*(double n)const{
     Squaremat newm(size);
     for(int i=0;i<size;i++){
         for(int j=0;j<size;j++){
             newm.getmat()[i][j]=mat[i][j] *n;
         }
     }
     return newm;
 }
 
 /**
  * Explanation: Scalar multiplication assignment operator
  * @param n The scalar value to multiply with
  * @return Reference to this matrix after multiplication
  */
 Squaremat& Squaremat::operator*=(double n) {
     *this = *this * n;
     return *this;
 }
 
 /**
  * Explanation: Matrix multiplication operator
  * @param other The matrix to multiply with
  * @return The result of matrix multiplication
  * @throw invalid_argument if matrices have incompatible sizes
  */
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
 
 /**
  * Explanation: Matrix multiplication assignment operator
  * @param other The matrix to multiply with
  * @return Reference to this matrix after multiplication
  */
 Squaremat& Squaremat::operator*=(const Squaremat& other) {
     *this = *this*other;
     return *this;
 }
 
 /**
  * Explanation: Equality operator that compares matrices by sum of elements
  * @param other The matrix to compare with
  * @return true if the sum of all elements is equal, false otherwise
  */
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
 
 /**
  * Explanation: Inequality operator that compares matrices by sum of elements
  * @param other The matrix to compare with
  * @return true if the sum of all elements is not equal, false otherwise
  */
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
 
 /**
  * Explanation: Less than operator that compares matrices by sum of elements
  * @param other The matrix to compare with
  * @return true if the sum of this matrix's elements is less than the other's, false otherwise
  */
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
 
 /**
  * Explanation: Less than or equal operator that compares matrices by sum of elements
  * @param other The matrix to compare with
  * @return true if the sum of this matrix's elements is less than or equal to the other's, false otherwise
  */
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
 
 /**
  * Explanation: Greater than operator that compares matrices by sum of elements
  * @param other The matrix to compare with
  * @return true if the sum of this matrix's elements is greater than the other's, false otherwise
  */
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
 
 /**
  * Explanation: Greater than or equal operator that compares matrices by sum of elements
  * @param other The matrix to compare with
  * @return true if the sum of this matrix's elements is greater than or equal to the other's, false otherwise
  */
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
 
 /**
  * Explanation: Transpose operator that returns the transpose of this matrix
  * @return A new matrix that is the transpose of this one
  */
 Squaremat Squaremat::operator~()const{
     Squaremat newm(size);
     for(int i=0;i<size;i++){
         for(int j=0;j<size;j++){
             newm.getmat()[i][j]=mat[j][i];
         }
     }
     return newm;
 }
 
 /**
  * Explanation: Unary minus operator that negates all elements of the matrix
  * @return A new matrix with all elements negated
  */
 Squaremat Squaremat::operator-() const{
     Squaremat newm(size);
     for(int i=0;i<size;i++){
         for(int j=0;j<size;j++){
             newm.getmat()[i][j]=-(mat[i][j]);
         }
     }
     return newm;
 }
 
 /**
  * Explanation: Power operator that raises the matrix to the nth power
  * @param n The exponent (must be non-negative)
  * @return A new matrix that is this matrix raised to power n
  * @throw invalid_argument if n is negative
  * @note Uses binary exponentiation for efficiency
  */
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
 
 /**
  * Explanation: Subscript operator for accessing and modifying matrix elements
  * @param x The row index
  * @return Pointer to the row, allowing for [row][col] access
  */
 double* Squaremat::operator[](int x){
     return mat[x];
 }
 
 /**
  * Explanation: Const subscript operator for accessing matrix elements
  * @param x The row index
  * @return Const pointer to the row, allowing for [row][col] access
  */
 const double* Squaremat::operator[](int x) const {
     return mat[x];
 }
 
 /**
  * Explanation: Helper function to create a submatrix by deleting a row and column
  * @param m The original matrix
  * @param row The row to delete
  * @param col The column to delete
  * @return A new matrix of size n-1 with the specified row and column removed
  */
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
 
 /**
  * Explanation: Determinant operator that calculates the determinant of the matrix
  * @return The determinant value
  * @note Uses recursive cofactor expansion method
  */
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
     /**
      * Explanation: Output stream operator for printing matrices
      * @param os The output stream
      * @param mat The matrix to print
      * @return The output stream after printing
      */
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