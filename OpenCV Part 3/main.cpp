#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2\imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("Image.png", IMREAD_GRAYSCALE);
	namedWindow("Input", WINDOW_NORMAL);
	namedWindow("Output", WINDOW_NORMAL);
	Mat outputImg;
	
	int dx = 1;
	int dy = 1;
	int sobelKernelSize = 3;
	int scaleFactor = 1;
	int deltaValue = 1;

	while (1)
	{
		Sobel(img, outputImg, CV_8UC1, dx, dy, sobelKernelSize, scaleFactor,deltaValue);

		int c = waitKey(1);
		if ((char)c == 'q')
		{
			cout << "pressed to q" << endl;
			break;
		}
		else if ((char)c == 'a')
		{
			cout << "pressed to a" << endl;
			if (dx && dy)
			{
				dx = 0;
			}
			else
			{
				dx = 1;
			}
		}
		else if ((char)c == 's')
		{
			cout << "pressed to s" << endl;
			if (dx && dy)
			{
				dy = 0;
			}
			else
			{
				dy = 1;
			}
		}
		else if ((char)c == 'd')
		{
			cout << "pressed to d" << endl;
			sobelKernelSize += 2;
		}
		else if ((char)c == 'f')
		{
			cout << "pressed to f" << endl;
			if (sobelKernelSize > 1)
				sobelKernelSize -= 2;
		}
		else if ((char)c == 'z')
		{
			cout << "pressed to z" << endl;
			scaleFactor++;
		}
		else if ((char)c == 'x')
		{
			cout << "pressed to x" << endl;
			scaleFactor--;
		}
		else if ((char)c == 'c')
		{
			cout << "pressed to c" << endl;
			deltaValue++;
		}
		else if ((char)c == 'v')
		{
			cout << "pressed to v" << endl;
			deltaValue--;
		}
		imshow("Input", img);
		imshow("Output", outputImg);
		waitKey(1);
	}


	return 0;
}