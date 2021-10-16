#include<stdio.h>
#include<math.h>
#include<complex.h>
#define MAX 1000
double PI=atan2(1,1)*4;
struct Complex
{
  float real;
  float imag;
};
typedef struct Complex cmx;
void nhap(float x[], int N){
  printf("\nNhap tin hieu dau vao!");
  for(int i=0; i<N; ++i){
    printf("\nTin hieu x[%d] = ",i);
    scanf("%f",&x[i]);
  }
}
void xuat(float x[], int N){
  for(int i=0; i<N; ++i){
    printf("%.4f\t",x[i]);
  }
}
void DFT(cmx X[], float x[], int N){
  for(int i=0 ; i< N; i++){
    for(int j=0 ; j< N; j++){
      X[i].real= X[i].real + x[j]*cos(-2*PI*i*j/N);
      X[i].imag= X[i].imag + x[j]*sin(-2*PI*i*j/N);
    }
  }
}
void FFT1(cmx X[], float x[], int N){
  float y[MAX/2] , z[MAX/2] , a[MAX/4] , b[MAX/4] , c[MAX/4] , d[MAX/4];
  printf("\nDay ban dau duoc chia thanh 2 day con: ");
  for(int r=0 ; r < (N/2) ; r++){
    y[r] = x[2*r];
    z[r] = x[2*r+1];
  }
  printf("\nTin hieu y[n]: ");
  xuat(y,N/2);
  printf("\nTin hieu z[n]: ");
  xuat(z,N/2);
  printf("\nChia tiep day y[n] thanh 2 day con: ");
  for(int l=0 ; l < (N/4) ; l++){
    a[l] = y[2*l];
    b[l] = y[2*l+1];
  }
  printf("\nTin hieu a[n]: ");
  xuat(a,N/4);
  printf("\nTin hieu b[n]: ");
  xuat(b,N/4);
  printf("\nChia tiep day z[n] thanh 2 day con: ");
  for(int l=0 ; l < (N/4) ; l++){
    c[l] = z[2*l];
    d[l] = z[2*l+1];
  }
  printf("\nTin hieu c[n]: ");
  xuat(c,N/4);
  printf("\nTin hieu d[n]: ");
  xuat(d,N/4);
  cmx Y[MAX/2] , Z[MAX/2] , A[MAX/4] , B[MAX/4] , C[MAX/4] , D[MAX/4];
  DFT(A,a,N/4);
  //Tinh B[k]
  DFT(B,b,N/4);
  //Tinh C[k]
  DFT(C,c,N/4);
  //Tinh D[k]
  DFT(D,d,N/4);
  //Tinh Y[k]
  for(int k=0 ; k < (N/4) ; k++){
    Y[k].real= A[k].real + B[k].real*cos(-4*PI*k/N) - B[k].imag*sin(-4*PI*k/N);
    Y[k].imag= A[k].imag + B[k].imag*cos(-4*PI*k/N) + B[k].real*sin(-4*PI*k/N);
  }
  for(int k=(N/4) ; k < (N/2) ; k++){
    Y[k].real= A[k - (N/4)].real + B[k - (N/4)].real*cos(-4*PI*k/N) - B[k - (N/4)].imag*sin(-4*PI*k/N);
    Y[k].imag= A[k - (N/4)].imag + B[k - (N/4)].imag*cos(-4*PI*k/N) + B[k - (N/4)].real*sin(-4*PI*k/N);
  }
  //Tinh Z[k]
  for(int k=0 ; k < (N/4) ; k++){
    Z[k].real= C[k].real + D[k].real*cos(-4*PI*k/N) - D[k].imag*sin(-4*PI*k/N);
    Z[k].imag= C[k].imag + D[k].imag*cos(-4*PI*k/N) + D[k].real*sin(-4*PI*k/N);
  }
  for(int k=(N/4) ; k < (N/2) ; k++){
    Z[k].real= C[k - (N/4)].real + D[k - (N/4)].real*cos(-4*PI*k/N) - D[k - (N/4)].imag*sin(-4*PI*k/N);
    Z[k].imag= C[k - (N/4)].imag + D[k - (N/4)].imag*cos(-4*PI*k/N) + D[k - (N/4)].real*sin(-4*PI*k/N);
  }
  //Tinh X[k]
  for(int k=0 ; k < (N/2) ; k++){
    X[k].real= Y[k].real + Z[k].real*cos(-2*PI*k/N) - Z[k].imag*sin(-2*PI*k/N);
    X[k].imag= Y[k].imag + Z[k].imag*cos(-2*PI*k/N) + Z[k].real*sin(-2*PI*k/N);
  }
  for(int k=(N/2) ; k < N ; k++){
    X[k].real= Y[k - (N/2)].real + Z[k - (N/2)].real*cos(-2*PI*k/N) - Z[k - (N/2)].imag*sin(-2*PI*k/N);
    X[k].imag= Y[k - (N/2)].imag + Z[k - (N/2)].imag*cos(-2*PI*k/N) + Z[k - (N/2)].real*sin(-2*PI*k/N);
  }
}


int check_integer(int N){
  int x=1;
  float n = log2(N);
  if(ceil(n)!=floor(n)) {x=0;}
  return x;
}
void FFT(cmx X[], float x[], int N){
  int check = check_integer(N);
  if(N<4){
    DFT(X,x,N);
  }
  else{
    if(check == 1){
      FFT1(X,x,N);
    }
    else{
      DFT(X,x,N);
    }
  }
  printf("\nDay dau ra X[k]= ");
  for(int k=0 ; k < N ; k++){
    if(X[k].imag<0) {
      printf("%.4f - %.4fi\t",X[k].real,-X[k].imag);}
    else{
    printf("%.4f + %.4fi\t",X[k].real,X[k].imag);}
  }
}
int main(){
  float x[MAX];
  cmx X[MAX];
  int N;
  printf("\nNhap chu ky tin hieu: "); scanf("%d",&N);
  nhap(x,N);
  printf("Tin hieu dau vao x[n]: ");
  xuat(x,N);
  FFT(X,x,N);
}
