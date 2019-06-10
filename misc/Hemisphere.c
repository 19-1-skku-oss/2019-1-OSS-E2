#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char shades[11] = "@%#&eo*!:.";
const int shade_length = 10;


void normalize(double* p, double* np);
double dot(double* p1, double* p2);
void make_hemisphere_points(const int R, double* xarr, double* yarr, double* zarr, int* length);
void draw_hemisphere(const int R, double* nlight);
void testsphere(const int R);


int main(){
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
		if (c == 'Q' || c == 'q') break;
		switch (c) {
		case 'W':
		case 'w':
			light[0]--;
			break;
		case 'S':
		case 's':
			light[0]++;
			break;
		case 'A':
		case 'a':
			light[1]--;
			break;
		case 'D':
		case 'd':
			light[1]++;
			break;
		case '+':
			R++;
			break;
		case '-':
			R--;
			break;
		}
	}
	return 0;
}


void normalize(double* p, double* np){
	double length;
	length = sqrt(pow(*p, 2) + pow(*(p + 1), 2) + pow(*(p + 2), 2));
	*np = *p / length;
	*(np + 1) = *(p + 1) / length;
	*(np + 2) = *(p + 2) / length;
}

double dot(double* p1, double* p2){
	return p1[0] * p2[0] + p1[1] * p2[1] + p1[2] * p2[2];
}

void make_hemisphere_points(const int R, double* xarr, double* yarr, double* zarr, int* length){

	for (int i = 0; i < 2 * R + 1; i++) {
		xarr[i] = -R + i + 0.5;
	}

	for (int i = 0; i < 4 * R + 1; i++) {
		yarr[i] = ((-2 * R + i) / 2) + 0.5;
	}
	for (int i = 0; i < 2 * R + 1; i++) {
		for (int j = 0; j < 4 * R + 1; j++) {
			if (pow(xarr[i], 2) + pow(yarr[j], 2) <= pow(R, 2)) zarr[i*(4 * R + 1) + j] = sqrt(pow(R, 2) - pow(yarr[j], 2) - pow(xarr[i], 2));
			else zarr[i*(4 * R + 1) + j] = -1;
		}
	}

}

void draw_hemisphere(const int R, double* nlight){
	int length = (2 * R + 1)*(4 * R + 1);
	double* xarr = (double*)malloc(sizeof(double)*(2 * R + 1));
	double* yarr = (double*)malloc(sizeof(double)*(4 * R + 1));
	double* zarr = (double*)malloc(sizeof(double)*(length));
	double* intensity = (double*)malloc(sizeof(double)*(length));
	char* hemisphere = (char*)malloc(sizeof(char)*(length));
	double narray[3];
	double array[3];

	make_hemisphere_points(R, xarr, yarr, zarr, &length);

	for (int i = 0; i < (2 * R + 1); i++) {
		for (int j = 0; j < 4 * R + 1; j++) {
			array[0] = xarr[i];  array[1] = yarr[j]; array[2] = zarr[i*(4 * R + 1) + j];
			normalize(array, narray);
			intensity[i*(4 * R + 1) + j] = dot(nlight, narray);
		}
	}

	for (int i = 0; i < (2 * R + 1); i++) {
		for (int j = 0; j < 4 * R + 1; j++) {
			if (zarr[i*(4 * R + 1) + j] < 0)
				printf(" ");
			else
				printf("%c", shades[(int)(shade_length * intensity[i*(4 * R + 1) + j])]);
		}
		printf("\n");
	}
	free(xarr);
	free(yarr);
	free(zarr);
	free(intensity);
	free(hemisphere);

}

void testsphere(const int R){
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
