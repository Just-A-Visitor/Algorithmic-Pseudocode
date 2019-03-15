/* Remember, when you declare the size of vector n, the first n elements are already 0, the next push_back will
insert it at the end(append it), increasing size */
/* Vectors of constant length are initialised by name(size) */
#include <iostream>
#include <vector>
#include <complex>
#include <math.h>
#include <iomanip>
using namespace std;
const double PI =M_PI; //Remember the = sign
typedef complex<double> complex_num;
/* complex_num is a structure which stores 2 fields, real and imag (both of type double) */

/* Function to create complex number given theta */
complex_num create_complex(double theta)
{
    complex_num temp(cos(theta),sin(theta));
    return temp;
}

/* Function to copy even indices */
vector<complex_num> copy_even_indices(vector<complex_num> Vec, int n)
{
    vector<complex_num> temp;
    for(int i=0; i<n; i=i+2)
        temp.push_back(Vec[i]);
    return temp;
}

/* Function to copy odd indices */
vector<complex_num> copy_odd_indices(vector<complex_num> Vec, int n)
{
    vector<complex_num> temp;
    for(int i=1; i<n; i=i+2)
        temp.push_back(Vec[i]);
    return temp;
}

/* Function to scan a vector of double */ 
vector<double> scan_vector(int length)
{
    vector<double> temp;
    double x;
    for(int i=0; i<length; i++)
    {
        scanf("%lf",&x);
        temp.push_back(x);
    }
    return temp;
}    

/* Function to create a vector of complex entries, given their real and imaginary vectors */
vector<complex_num> create_complex_vec(vector<double> Vec_Real, vector<double> Vec_Imag, int length)
{
    vector<complex_num> temp;
    double x,y;
    for(int i=0; i<length; i++)
    {
        x=Vec_Real[i];
        y=Vec_Imag[i];
        // temp.push_back(x,y);// Won't work, Type needs to be specified again
        temp.push_back(complex_num(x,y));
    }
    return temp;
}

/* Function to print a vector of complex entries of given length*/
void print_complex_vec(vector<complex_num> temp, int length, int flag_divide_by_length)
{
    double x,y;
    for(int i=0; i<length; i++)
    {
        x=temp[i].real();
        if(flag_divide_by_length!=0) x=x/flag_divide_by_length;
        printf("%0.5lf ",x); //Precision is 5
    }
    printf("\n");
    for(int i=0; i<length; i++)
    {
        y=temp[i].imag();
        if(flag_divide_by_length!=0) y=y/flag_divide_by_length;
        printf("%0.5lf ",y);  //Precision is 5
    }
    printf("\n");
}
/* Note :-- The function has been modified to divide the result by n and the print it*/

/* Function to return the Discrete Fourier Transform of a vector */
vector<complex_num> Discrete_FFT(vector<complex_num> Vec, int n)
{
    /* n has been made a power of 2 by resize function */
    if(n==1) return Vec;
    complex_num w(1,0); //See the format of defining a complex number
    vector<complex_num> V_0=copy_even_indices(Vec,n);
    vector<complex_num> V_1=copy_odd_indices(Vec,n);
    vector<complex_num> Y_0=Discrete_FFT(V_0,n/2);
    vector<complex_num> Y_1=Discrete_FFT(V_1,n/2);
    vector<complex_num> Y(n);
    for(int k=0; k<n/2; k++)
    {
        /*In the initial iteration, remember, w=w_0 */
        Y[k]=Y_0[k]+w*Y_1[k];
        Y[k+n/2]=Y_0[k]-w*Y_1[k];
        double theta =2*PI*(k+1)/n;
        w=create_complex(theta);  
        /* Don't use the pseudo-code, w=w*w_n, as error propagates*/
        /* Strangely, if for this question, you use the technique of pseuodo-code, 
        it still works and passes all test cases */
    }
    return Y;
}
/* Function to return the inverse Fourier transform , multiplied by n */
vector<complex_num> Inverse_FFT(vector<complex_num> Vec, int n)
{
    /* n has been made a power of 2 by resize function */
    if(n==1) return Vec;
    complex_num w(1,0); //See the format of defining a complex number
    vector<complex_num> V_0=copy_even_indices(Vec,n);
    vector<complex_num> V_1=copy_odd_indices(Vec,n);
    vector<complex_num> Y_0=Inverse_FFT(V_0,n/2);
    vector<complex_num> Y_1=Inverse_FFT(V_1,n/2);
    vector<complex_num> Y(n);
    for(int k=0; k<n/2; k++)
    {
        /*In the initial iteration, remember, w=w_0 */
        Y[k]=Y_0[k]+w*Y_1[k];    //Remember to divide by n, since this is inverse FFT, but do it via complex
        Y[k+n/2]=Y_0[k]-w*Y_1[k];  //Rememer to divide by n, since this is inverse FFT, but do it via complex
        double theta =(-2)*PI*(k+1)/n; // Remember to multiply -1, since this is inverse FFT
        w=create_complex(theta);  
        /* Don't use the pseudo-code, w=w*w_n, as error propagates*/
        /* Strangely, if for this question, you use the technique of pseuodo-code, 
        it still works and passes all test cases */
    }
    return Y;
}

/* Function to compute the next number which is a power of 2 and just greater than or equal to it*/ 
int check_the_next_power_of_2(int k)
{
    int next_power=1;
    while (next_power<k) next_power=next_power*2;
    return next_power;
}

/* Function to multiply 2 complex vectors pointwise */
vector<complex_num> point_wise_mult(vector<complex_num> Vec_1, vector<complex_num> Vec_2, int length)
{
    vector<complex_num> temp;
    complex_num product;
    for(int i=0; i< length; i++)
    {
        product=Vec_1[i]*Vec_2[i]; 
        temp.push_back(product);
        /* CATCH:--  First catch, never ever do computations inside the push_back bracket, 
        instead, use another variable, and then push it */
        /* CATCH-2:-- Always use push_back, when size is not declared */
    }
    return temp;
}
/* Function works correctly */

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    /*Scanning the first Vector*/
    vector<double> Vec_Real_1;
    vector<double> Vec_Imag_1;
    vector<complex_num> Vec_1;
    /* above, we have defined three containers */
    Vec_Real_1=scan_vector(n);
    Vec_Imag_1=scan_vector(n);
    Vec_1=create_complex_vec(Vec_Real_1, Vec_Imag_1,n);
    
    /*Scanning the second vector*/
    vector<double> Vec_Real_2;
    vector<double> Vec_Imag_2;
    vector<complex_num> Vec_2;
    /* above, we have defined three containers */
    Vec_Real_2=scan_vector(m);
    Vec_Imag_2=scan_vector(m);
    Vec_2=create_complex_vec(Vec_Real_2, Vec_Imag_2,m);
    /*  Done*/
    /* The vectors are scanned properly */

    /* Important step */
    int original_length=m+n-1;
    int length=check_the_next_power_of_2(original_length);
    Vec_1.resize(length);
    Vec_2.resize(length);
    /* The vectors are resized properly */
    
    Vec_1=Discrete_FFT(Vec_1,length);
    Vec_2=Discrete_FFT(Vec_2,length);
    /* The dicsrete FFT are computed correctly */
    
    vector<complex_num> Mult;
    Mult=point_wise_mult(Vec_1, Vec_2, length);
    /* The multiplication is computed correctly */   

    vector<complex_num> answer ;
    answer=Inverse_FFT(Mult, length);
    print_complex_vec(answer,original_length, length);
    return 0;
}
/* TEST FUNCTIONS
    vector<complex_num> Even_indices_vector=copy_even_indices(Vec,n);
    print_complex_vec(Even_indices_vector,n/2);
    vector<complex_num> Odd_indices_vector=copy_odd_indices(Vec,n);
    print_complex_vec(Odd_indices_vector,n);
    complex_num test=Vec[0]*Vec[1];
    print_complex_num(test);
*/

/*Utility Functions */

/* Function to print a complex number */
/*void print_complex_num(complex_num temp)
{
    double x,y;
    x=temp.real();
    y=temp.imag();
    printf("(%lf,%lf)",x,y);
    printf("\n");
} */

/* Function to append zeroes. Not creating this was the reason for the -0.0000  */
/* void append_zeroes(vector<complex_num> Vec, int n)
{
    while(Vec.size()!=n)
        Vec.push_back(complex_num(0,0));
} */
/* But anyways, we are not using this, since the resize function does all the work for us */


/*

    print_complex_vec(Vec_1,length);
    print_complex_vec(Vec_2,length);

*/







