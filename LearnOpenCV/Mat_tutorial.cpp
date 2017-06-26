#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\opencv_modules.hpp>

using namespace std;
using namespace cv;

#define STRING_INPUT_IMG "./cat.jpg"

// This function demonstrates different ways of copying data from one Mat to another Mat
int mat_copy_tutorial()
{
	Mat sMatInput = imread(STRING_INPUT_IMG);

	// Copying Mat to different variable without allocating the memory
	// Each Mat will have different headers 
	Mat sMatOutput(sMatInput); // Copy constructor
	Mat sMatProcessed = sMatInput; // Assignment operator

	// Copying Mat to different variable allocating a new memory
	Mat sMatInputClone = sMatInput.clone();
	Mat sMatInputCopy;
	sMatInput.copyTo(sMatInputCopy);

	// Copying ROI of Mat to another Mat variable without allocating memory
	Mat sMatInputROI = sMatInput(Range::all(), Range(1, 10));
	Mat sMatInputROI_1(sMatInput, Rect(100, 100, 900, 900));

	// Copying part of the image using a mask
	Mat sMatMask = Mat::zeros(sMatInput.size(), CV_8UC1);
	Mat sMatROI = sMatMask(Rect(100, 100, 900, 900));
	sMatROI.setTo(Scalar(255));
	Mat sMatInputPart;
	sMatInput.copyTo(sMatInputPart, sMatMask);

	return 0;
}

// This functions demonstrates different ways to get the basic image info like width, height, channels etc.
int mat_image_info()
{
	Mat sMatInput = imread(STRING_INPUT_IMG);

	// Number of rows and columns (width, height, channels)
	cout << "The number of columns in the image " << sMatInput.cols << endl;
	cout << "The number of rows in the image " << sMatInput.rows << endl;
	cout << "The number of channels in the image " << sMatInput.channels() << endl;
	cout << "The dimensions of the image " << sMatInput.size().width << " x " << sMatInput.size().height << endl;

	return 0;
}

// This functions demonstrates different ways to create mat 
int mat_create()
{
	int s32Height = 100;
	int s32Width  = 100;
	Mat sMatInputC1(Size(s32Width, s32Height), CV_8U, Scalar(255));

	Mat sMatInputC2;
	sMatInputC2.create(Size(s32Width, s32Height), CV_8UC(3));

	return 0;
}

int mat_read_image_display()
{
	Mat sMatInput = imread(STRING_INPUT_IMG);

	namedWindow("Input", CV_WINDOW_NORMAL);
	imshow("Input", sMatInput);
	imwrite("./output.jpg", sMatInput);
	waitKey(0);

	return 0;
}

// 
int main()
{
	// mat_copy_tutorial();
	// mat_image_info();
	//mat_create();
	mat_read_image_display();
}
