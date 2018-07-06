#include <iomanip>
#include <iostream>
#include "matrixDefine.h"
using namespace std;

void main()
{
	int m[10] = {0,1,2,3,4,5,6,7,8,9};
	Matrix<int> matrix(m, 2, 5);
	Matrix<int> matrix1(2, 5), matrix2, matrix3, matrix4;
	matrix1.create(m);
	matrix2.zeros(10);
	matrix3.eye(10);
	matrix4 = matrix+matrix1;
	matrix.show();
	cout<<"show matrix1"<<endl;
	matrix1.show();
	cout<<endl;
	matrix2.show();
	cout<<endl;
	matrix3.show();
	cout<<endl;
	matrix4.show();
}