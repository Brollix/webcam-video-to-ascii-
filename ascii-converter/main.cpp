#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main() {
	/*$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,"^`'. */

	string ascii = "  .'`^\",:;Il!i<>~+_-?[]{}1()|/tfjrxnuvczXYUJCLQ0OZmwqpbdkhao*#MW&8%B@$";

	//Mat img = imread("img/yo.jpg", IMREAD_GRAYSCALE);
	//Mat outimg;

	string vid = "yo.MP4";
	VideoCapture video(0);
	Mat frame;

	int b = ascii.length();
	int l;
	const int max = 255;
	int index;

	int res = 16;
	while (video.read(frame)){
		
		imshow("frame", frame);
		
		if (waitKey(25) >= 0){
			break;
		}		
		
		for (int x = 0; x < frame.rows; x++){
			if (x % res == 0){
				for (int y = 0; y < frame. cols; y++){
					if (y % res == 0){
						l = frame.at<uchar>(x, y);
						index = (b * l) / max;
						cout << ascii[index] /* << " " */;
					}
				}
				cout << endl;
			}		
		}
		system("cls");
	}
	
	//capture.release();
	//destroyAllWindows();
	
	return 0;
}
