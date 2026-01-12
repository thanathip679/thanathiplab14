#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void showMatrix(const bool a[][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << a[i][j] << " ";
        }
    cout << endl;
    }
}

void inputMatrix(double a[][N]){
    double input[N];
    for(int i = 0; i < N; i++){
        cout << "Row " << i+1 << ": ";
    
        for(int j = 0 ; j < N; j++){
            cin >> input[j];
            a[i][j] = input[j];
        }
    }
}

void findLocalMax(const double a[][N], bool b[][N]){
    for(int i = 0; i < N; i++){
        b[0][i] = 0;
    }
    
    for(int k = 1 ; k < N-1; k++){
        b[k][0] = 0;
        for(int l = 1; l < N-1; l++){
            if(a[k][l] >= a[k-1][l] && a[k][l] >= a[k+1][l] && a[k][l] >= a[k][l-1] && a[k][l] >= a[k][l+1]){
                b[k][l] = 1;
            }else{
                b[k][l] = 0;
            }
        }
        b[k][N] = 0; 
    }
    
    for(int j = 0; j < N; j++){
        b[N][j] = 0;
    }
}