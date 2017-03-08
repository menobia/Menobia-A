#include<iostream>
using namespace std;
//Menobia Arif 
//BESE 5B
//111176 

// LAB 2
void printmatrix(int mat[15][15], int R, int C);
struct res{

};

class matrixmultiplication{
public:
	int rowA, rowB, colA, colB; //variables for rows and columns of the two matrices
	int A[15][15], B[15][15]; // matrices A and B for Multiplication
	int res[15][15];// matrix to store result of Multiplication
	int temp;//for input of matrix
	int sum = 0; // for result 

	void printmatrix(int mat[15][15], int R, int C) // function to print the matrix
	{

		for (int i = 0; i <R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}

	void setA()
	{
		cout << "INPUT MATRIX A" << endl; // geting rows and columns of matrix A
		cout << "Number of rows of matrix A?" << endl;
		cin >> rowA;
		cout << "Number of columns of matrix A?" << endl;
		cin >> colA;

		cout << "Input values of the matrix A Row by Row " << endl;//taking input of matrix A
		cout << "Rows: " << rowA << " Columns: " << colA << endl;
		for (int i = 0; i < rowA; i++)
		{
			for (int j = 0; j < colA; j++)
			{
				cin >> temp;
				A[i][j] = temp;
			}
		}
	}

	void setB()
	{
		cout << "INPUT SECOND MATRIX" << endl; // geting rows and columns of matrix B
		cout << "Number of rows of matrix B?" << endl;
		cin >> rowB;
		cout << "Number of columns of matrix B?" << endl;
		cin >> colB;

		cout << "Input values of the matrix B Row by Row" << endl;//taking input of matrix B
		cout << "Rows: " << rowB << " Columns: " << colB << endl;
		for (int i = 0; i < rowB; i++)
		{
			for (int j = 0; j < colB; j++)
			{
				cin >> temp;
				B[i][j] = temp;
			}
		}

	}

	bool iterativemultiplication(int RA, int CB, int CA,int RB)
	{
		if (CA != RB)
		{              //if columns of matrix A are not equal to rows of matrix B then multiplication not possible
			cout << "MATRIX MULTIPLICATION NOT POSSIBLE" << endl<<"Because: number of Columns of A is not equal to number of rows of B"<<endl;
			return false;
		}
		for (int i = 0; i <RA; i++)   // matrix multiplaction by iterative method begins 
		{
			for (int j = 0; j <CB; j++)
			{
				for (int k = 0; k<CA; k++)
				{
					sum = sum + A[i][k] * B[k][j];
				}
				res[i][j] = sum;
				sum = 0;
			}
		}
		return true;
	} // matrix multiplaction by iterative method ends 



	void strassentmultiplication()  // matrix multiplaction by strassen method begins 
	{

	} // matrix multiplaction by strassen method ends


};

class unittests
{
public:
	matrixmultiplication tests1, tests2, tests3, tests4; // for different tests of iterative and strassen multiplication 
	void test1() // test to check if matrix multiplication work for 3x2 X 2X6 matrix //ITERATIVE METHOD 
	{
		cout << endl << "test to check if matrix multiplication work for 3x2 X 2X6 matrix(ITERATIVE METHOD)" << endl;
		for (int i = 0; i < 3; i++) // setting matrix A 
		{
			for (int j = 0; j < 2; j++)
			{
				tests1.A[i][j] = rand() % 10 + 1;
			}
		}

		for (int i = 0; i < 2; i++) // setting matrix B 
		{
			for (int j = 0; j < 6; j++)
			{
				tests1.B[i][j] = rand() % 10 + 1;
			}
		}

		tests1.iterativemultiplication(3, 6, 2,2);
		cout << endl << "MATRIX A =" << endl;
		tests1.printmatrix(tests1.A, 3, 2);
		cout << endl << "MATRIXB =" << endl;
		tests1.printmatrix(tests1.B, 2, 6);
		cout << endl << "A X B =" << endl;
		tests1.printmatrix(tests1.res, 3, 6);
		cout << endl << "PASSED" << endl;
	}

	void test2() // test to check if matrix multiplication work for 2x2 X 2X2 matrix //ITERATIVE METHOD 
	{
		cout << endl << "test to check if matrix multiplication work for 2x2 X 2X2 matrix(ITERATIVE METHOD)" << endl;
		for (int i = 0; i < 2; i++) // setting matrix A 
		{
			for (int j = 0; j < 2; j++)
			{
				tests2.A[i][j] = rand() % 10 + 1;
			}
		}

		for (int i = 0; i < 2; i++) // setting matrix B 
		{
			for (int j = 0; j < 2; j++)
			{
				tests2.B[i][j] = rand() % 10 + 1;
			}
		}

		tests2.iterativemultiplication(2, 2, 2,2);
		cout << endl << "MATRIX A =" << endl;
		tests2.printmatrix(tests2.A, 2, 2);
		cout << endl << "MATRIXB =" << endl;
		tests2.printmatrix(tests2.B, 2, 2);
		cout << endl << "A X B =" << endl;
		tests2.printmatrix(tests2.res, 2, 2);
		cout << endl << "PASSED" << endl;
	}

	void test3() // test to check if matrix multiplication work for 2x3 X 4X3 matrix //ITERATIVE METHOD 
	{
		cout << endl << "test to check if matrix multiplication work for 2x3 X 4X3 matrix(ITERATIVE METHOD)" << endl;
		for (int i = 0; i < 2; i++) // setting matrix A 
		{
			for (int j = 0; j < 3; j++)
			{
				tests3.A[i][j] = rand() % 10 + 1;
			}
		}

		for (int i = 0; i < 4; i++) // setting matrix B 
		{
			for (int j = 0; j < 3; j++)
			{
				tests3.B[i][j] = rand() % 10 + 1;
			}
		}

		if (tests3.iterativemultiplication(2, 3, 3, 4) == false)
			cout << endl << "PASSED" << endl;
			return;

		cout << endl << "MATRIX A =" << endl;
		tests3.printmatrix(tests3.A, 2, 3);
		cout << endl << "MATRIXB =" << endl;
		tests3.printmatrix(tests3.B, 4, 3);
		cout << endl << "A X B =" << endl;
		tests3.printmatrix(tests3.res, 2, 3);
	}
	void runtests() // it runs all the unit tests one by one 
	{
		test1();
		test2();
		test3();
	}
};




