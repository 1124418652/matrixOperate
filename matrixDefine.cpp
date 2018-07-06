#ifndef MATRIX_T_T_T
#define MATRIX_T_T_T
#include "matrixDefine.h"
#endif

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
			cout<<setw(sizeof(T))<<*matrix++;
		}
		cout<<endl;
	}
	
}


template<class T>
UINT Matrix<T>::create(T *m)
{
	//////////
	return 1;
}