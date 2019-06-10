#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//predefined ascii codeset - use this for print
const char shades[11] = "@%#&eo*!:.";
const int shade_length = 10;

//*******************************************************//
void normalize(double* p, double* np)
{
	// normalize position. make position to Unit vector.
	// see here : http://mathworld.wolfram.com/NormalizedVector.html
	// parameter p is 1D double array.
	// length is 3 : [0] = x, [1] = y, [2]= z
	// don't modify original value.
	// pass new array to caller using input parameter np.
	// can use math.h header (ex. sqrt(), pow() ..)
}
//*******************************************************//
double dot(double* p1, double* p2)
{
	// dot product. return dot product of two position.
	// see here : https://ko.wikipedia.org/wiki/%EC%8A%A4%EC%B9%BC%EB%9D%BC%EA%B3%B1
	// parameter x,y is position : 1D double array.
	// length is 3 : [0] = x, [1] = y, [2]= z
	// don't modify original value.
	// can use math.h header (ex. sqrt(), pow() ..)
}
//*******************************************************//
void make_hemisphere_points(const int R, double* xarr, double* yarr, double* zarr, int* length)
{
	// make point array from given parameter R. see the document file.
	// count number of points. pass it to caller using input parameter length.
	// array structure :
	//	xarr[number of point].
	//	yarr[number of point].
	//	zarr[number of point].
	// can use math.h header (ex. sqrt(), pow() ..)
}
//*******************************************************//
void draw_hemisphere(const int R, double* nlight)
{
	// draw hemisphere on console from point array. see the document file.
	// call make_hemisphere_points here.
	// get point arrays, and calculate each intensity with parameter nlight.
	// nlight is already normalized value.
	// convert intensity to integer index, and print ascii code using that index.
	// using char array at the top of code
	// can use math.h header (ex. sqrt(), pow() ..)
}
//*******************************************************//
//dont modify it! point validation code
void testsphere(const int R)
{
	int length = 0;
	int flag = 1;
	double* test_x = (double*)malloc(sizeof(double)*(4 * R + 1)*(2 * R + 1));
	double* test_y = (double*)malloc(sizeof(double)*(4 * R + 1)*(2 * R + 1));
	double* test_z = (double*)malloc(sizeof(double)*(4 * R + 1)*(2 * R + 1));
	make_hemisphere_points(R, test_x, test_y, test_z, &length);
	for (int i = 0; i < length; i++) {
		double x = test_x[i];
		double y = test_y[i];
		double z = test_z[i];
		if (x * x + y * y <= R * R)
			flag *= (z == sqrt(R * R - x * x - y * y));
	}
	printf(flag ? "valid\n" : "Invalid\n");
	free(test_x);
	free(test_y);
	free(test_z);
	system("pause");
}
//*******************************************************//
int main()
{
	//dont modify not anotated section
	double light[3] = { 0, 0, 10 };
	double nlight[3] = { 0, 0, 0 };
	int R = 10;
	while (1) {
		//console clean
		system("cls");
		//draw hemisphere
		normalize(light, nlight);
		draw_hemisphere(R, nlight);
		//test normalize & action
		printf("Current Light pos : %.0f, %.0f, %.0f\n", light[0], light[1], light[2]);
		printf("Current Light dir : %.4f, %.4f, %.4f\n", nlight[0], nlight[1], nlight[2]);
		printf("Current Sphere radius : %d\n", R);
		//get input - make your act
		char c = getchar(); //read one character
		getchar(); //remove line end
		if (c == 't') testsphere(R); //test for make points
									 /****************************************/
									 // implement your code for input handling
									 /****************************************/
	}
	return 0;
}
