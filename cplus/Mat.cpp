#define IMG_PATH "C:/Users/DELL/Desktop/OpenCV(송희강)/img/"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace cv;
using namespace std;

int TestMat();

int main() {

	TestMat();
	waitKey();
	return 0;
}

int TestMat() {

	Mat img1;

	Mat img2(480, 640, CV_8UC1); // unsigned char, 1-channel
	Mat img3(480, 640, CV_8UC3); // unsigned char, 3-channel
	Mat Img4(Size(480, 640), CV_8UC3); //Size(width, height)_unsigned char_3-channel

	// the reason using the unsigned char is 8bit == 256 
	Mat img5(480, 640, CV_8UC3, Scalar(0, 0, 255)); //initial values, red
	Mat img6(480, 640, CV_8UC3, Scalar(0, 255, 0)); //initial values, green
	Mat img7(480, 640, CV_8UC3, Scalar(255, 0, 0)); //initial values, blue

	// OpenCV == BGR(blue, green, red) is the reason why Scalar(0,0,255) is red 
	Mat img8(480, 640, CV_8UC1, Scalar(255)); // initial values, 255 white == (255,255,255) 
	Mat img9(480, 640, CV_8UC1, Scalar(0)); // initial values, 0 black == (0,0,0)
	Mat img10(480, 640, CV_8UC1, Scalar(128)); // initial values, 0 grey == (128,128,128)

	// Matrix 를 디버그 상에서는 볼 수가 있는데 실제로 출력해서 볼 수 는 없는것인가???
	Mat img11 = Mat::zeros(3, 3, CV_32FC1); //0's matrix
	Mat img12 = Mat::ones(3, 3, CV_32FC1); //1's matrix
	Mat img13 = Mat::eye(3, 3, CV_32FC1); //identity matrix

	float data[] = { 1,2,3,4,5,6 }; // -channel
	Mat img14(2, 3, CV_32FC1, data); // -channels CV_32FC1 == float
	Mat img15 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);  
	Mat img16 = Mat_<uchar>({ 2,3 }, { 1,2,3,4,5,6 });    

	img1.create(256, 256, CV_8UC3);
	img2.create(4, 4, CV_32FC1); //단순 float 형식을 사용하면 쓰레기 값이 들어가 있다.

	img1 = Scalar(255, 0, 0);
	img2.setTo(1.f);  //setTo 를 통하여 기본 값으로 다시 재정의 해주어 사용 할 수 있다.

	vector<Mat>img;
	vector<String>imgName;

	//img.push_back(img5);
	//imgName.push_back("image" + to_string(img.size()));

	//img.push_back(img6);
	//imgName.push_back("image" + to_string(img.size()));

	//img.push_back(img7);
	//imgName.push_back("image" + to_string(img.size()));

	//img.push_back(img8);
	//imgName.push_back("image" + to_string(img.size()));

	//img.push_back(img9);
	//imgName.push_back("image" + to_string(img.size()));

	//img.push_back(img10);
	//imgName.push_back("image" + to_string(img.size()));

	//img.push_back(img11);
	//imgName.push_back("image" + to_string(img.size()));

	//img.push_back(img12);
	//imgName.push_back("image" + to_string(img.size()));

	//img.push_back(img13);
	//imgName.push_back("image" + to_string(img.size()));

	img.push_back(img1);
	imgName.push_back("image" + to_string(img.size()));

	for (int i = 0; i < (int)imgName.size(); i++) {
		if (img.at(i).empty()) {
			cerr << "Image Load Failed" << endl;
			return -1;
		}
		else {
			imshow(imgName.at(i), img.at(i));
		}
		namedWindow(imgName.at(i), WINDOW_NORMAL);
		moveWindow(imgName.at(i), i * 100, 0);

		if (i == (int)imgName.size()-1) {

			while (true) {
				for (int j = 0; j < 256; j++) {
					img.at(i) = Scalar(0, 0, j);
					imshow(imgName.at(i), img.at(i));
					namedWindow(imgName.at(i), WINDOW_NORMAL);
					moveWindow(imgName.at(i), j * 1, 0);
					Sleep(10);
				}
				// 만약 esc 트리거 가 발생할 경우 while 문을 나오게 된다.
				//if ((waitKey() & 0xff) == 27) {
				//	break;
				//}
			}
		}
	}
}