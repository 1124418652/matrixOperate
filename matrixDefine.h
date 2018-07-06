#include <iostream>
using namespace std;
typedef unsigned int UINT;

template<class T>
class Matrix
{
	int col;
	int row;
	T *matrix;
	public:
		Matrix(T *m, int row1, int col1):matrix(m), row(row1), col(col1){}
		Matrix(int row1, int col1):row(row1), col(col1)
		{
			matrix = new T[row*col];
			cout<<"Have set the shape of the matrix, but should use create() to initialize the matrix!"<<endl;
		}
		Matrix(){}
		~Matrix(){}
		void show();
		UINT create(T *m);
		UINT zeros(int size);
		UINT eye(int size);

		//friend Matrix operator+(const Matrix &a, const Matrix &b);
		Matrix operator+(const Matrix &);
		//friend Matrix operator-(const Matrix &a, const Matrix &b);
		Matrix operator-(const Matrix &);
		//friend Matrix operator*(const Matrix &a, const Matrix &b);
		Matrix operator*(const Matrix &);
		friend ostream &operator<<(ostream &output, const Matrix &a);
		Matrix matrix_T();              // transpose the matrix
		Matrix matrix_Inv();            // calculate matrix's inverse
		Matrix matrix_Adjoint();        // calculate the adjoint matrix
};


template<class T>
void Matrix<T>::show()
{
	if (col==0 || row ==0)
	{
		cout<<"The matrix is empty"<<endl;
		return;
	}
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			cout<<setw(sizeof(T))<<matrix[i*col+j];
		}
		cout<<endl;
	}
	cout<<endl;
}


template<class T>
UINT Matrix<T>::create(T *m)
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			matrix[i*col+j] = *m++;
		}
	}
	return 1;
}


template<class T>
UINT Matrix<T>::zeros(int size)
{
	col = size;
	row = size;
	if(NULL == (matrix=new T[row*col]))
	{
		cout<<"don't have enough memory!"<<endl;
		return 0;
	}
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			matrix[i*col+j] = 0;
		}
	}
	return 1;
}


template<class T>
UINT Matrix<T>::eye(int size)
{
	col = size;
	row = size;
	if (NULL == (matrix=new T[row*size]))
	{
		cout<<"Don't have enough memory"<<endl;
		return 0;
	}
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			if (i==j)
				matrix[i*col+j] = 1;
			else
				matrix[i*col+j] = 0;
		}
	}
	return 1;
}


template<class T>
Matrix<T> Matrix<T>::operator +(const Matrix<T> &m1)
{
	if (m1.col!=col || m1.row!=row)
	{
		cout<<"These two matrices can't be plused!"<<endl;
		exit(0);
	}
	T *tmp = new T[col*row];
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			tmp[i*col+j] = m1.matrix[i*col+j] + matrix[i*col+j];
		}
	}
	return Matrix<T>(tmp, row, col);
}

template<class T>
Matrix<T> Matrix<T>::operator -(const Matrix<T> &m1)
{
	if (m1.col!=col || m1.row!=row)
	{
		cout<<"These two matrices can't be plused!"<<endl;
		exit(0);
	}
	T *tmp = new T[col*row];
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			tmp[i*col+j] = m1.matrix[i*col+j] - matrix[i*col+j];
		}
	}
	return Matrix<T>(tmp, row, col);
}


template<class T>
Matrix<T> Matrix<T>::operator *(const Matrix &m1)
{
	if (col != m1.row)
	{
		cout<<"These two matrices can't be multiplied"<<endl;
		exit(0);
	}
	T *tmp = new T[row*m1.col];
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<m1.col; j++)
		{

		}
	}
	return Matrix<T>(tmp, row, m1.col);
}

/*
template<class T>
Matrix<T> operator +(const Matrix<T> &m1, const Matrix<T> &m2)
{
	if (m1.col!=m2.col || m1.row!=m2.row)
	{
		cout<<"These two matrices can't be plused!"<<endl;
		exit(0);
	}
	T *tmp = new T[m1.col*m1.row];
	for (int i=0; i<m1.row; i++)
	{
		for (int j=0; j<m1.col; j++)
		{
			tmp[i*m1.col+j] = m1.matrix[i*m1.col+j] + m2.matrix[i*m1.col+j];
		}
	}
	return Matrix<T>(tmp, m1.row, m1.col);
}

template<class T>
Matrix<T> operator -(const Matrix<T> &m1, const Matrix<T> &m2)
{
	if (m1.col!=m2.col || m1.row!=m2.row)
	{
		cout<<"These two matrices can't be plused!"<<endl;
		exit(0);
	}
	T *tmp = new T[m1.col*m1.row];
	for (int i=0; i<m1.row; i++)
	{
		for (int j=0; j<m1.col; j++)
		{
			tmp[i*m1.col+j] = m1.matrix[i*m1.col+j] - m2.matrix[i*m1.col+j];
		}
	}
	return Matrix<T>(tmp, m1.row, m1.col);
}
*/