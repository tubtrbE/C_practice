#define IMG_PATH "C:/Users/Park/Desktop/OpenCV(송희강)/img/"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>


using namespace std;
using namespace cv;


Mat img;
Point ptOld;
void on_mouse(int event, int x, int y, int flags, void*);

int r_flag;
Point rec_pt1;
Point rec_pt2;


void readImgs();
int TestMat();
void TestCopy();
void TestCopyCat();
void TestMatrix();
void ScaleTest();
void MatrixTest();
void SizeTest();
void VectorScalar();

void InputArrayOp();
void printMat(InputArray _mat);

void ViedoTest1();
void ViedoTest2();
void DrawLines();
void DrawPolys();
void DrawText1();
void DrawText2();
void KeyboardEvent();
void MouseEvent();
void Example();


int main() {

//	TestMatrix();
//	ScaleTest();
//	MatrixTest();
//	SizeTest();
//	VectorScalar();
//	ViedoTest1();
//	ViedoTest2();
//	DrawLines();
//	DrawPolys();
//	DrawText2();
//	KeyboardEvent();
//	MouseEvent();
	Example();
	destroyAllWindows();
	return 0;


}


void readImgs() {
	Mat imgs[7];
	String windowName[7];
	int count = 0;
	int move_x = 0;
	int move_y = 0;

	for (int i = 0; i < 7; i++) {
		String filename = format("test%02d.jpg", i + 1);
		
		imgs[i] = imread(filename);

		windowName[i] = format("image%02d", i+1);
		
		if (imgs[i].empty()) {
			cerr << "Image load failed!!" << endl;
		}
		namedWindow(windowName[i], WINDOW_NORMAL);
		resizeWindow(windowName[i], 300, 300);
		imshow(windowName[i], imgs[i]);


		if (move_y >= 900) {
			count = 0;
			move_x = 300;
			move_y = 0;
		}
		move_y = count * 300;
		count++;

		moveWindow(windowName[i], move_x, move_y);
	}

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

		if (i == (int)imgName.size() - 1) {

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

	return 0;
}

void TestCopy() {

	String path_dog = IMG_PATH + (String)"dog.bmp";
	Mat img1 = imread(path_dog);
	Mat img2 = img1;
	Mat img3;
	img3 = img1;

	Mat img4 = img1.clone();
	Mat img5;
	img1.copyTo(img5);
	img1.setTo(Scalar(0, 255, 255));

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);
}

void TestCopyCat() {

	String path_cat = IMG_PATH + (String)"cat.bmp";
	Mat img1 = imread(path_cat);
	Mat img2 = img1(Rect(220, 120, 340, 240));
	Mat img3 = img1(Rect(220, 120, 340, 240)).clone();

	
	img2 = ~img2;
	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);


}

void TestMatrix() {
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++;
		}
	}

	for (int j = 0; j < mat1.rows; j++) {
		uchar* p = mat1.ptr<uchar>(j);
		for (int i = 0; i < mat1.cols; i++) {
			p[i]++;
		}
	}

	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) {
		(*it)++;
	}

	cout << "mat1:\n" << mat1 << endl;

}

void ScaleTest() {

	String path_lenna = IMG_PATH + (String)"lenna.bmp";
	Mat img1 = imread(path_lenna);
	Mat img2 = imread(path_lenna);
	cout << "Width : " << img1.cols << endl;
	cout << "Height : " << img1.rows << endl;
	cout << "Channels : " << img1.channels() << endl;

	if (img1.type() == CV_8UC1) {
		cout << "img1 is a grayscale image" << endl;
	}
	else if (img1.type() == CV_8UC3) {
		cout << "img1 is a colorscale image" << endl;
	}

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1 : \n" << mat1 << endl;
}

void MatrixTest() {
	float data[] = { 1,1,2,3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat2 = mat1.inv();
	cout << "mat2:\n" << mat2 << endl;

	cout << "mat1.t():\n" << mat1.t() << endl;
	cout << "mat1 + 3:\n" << mat1 + 3 << endl;
	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl;
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl;

}

void SizeTest() {
	String path_lenna = IMG_PATH + (String)"lenna.bmp";
	Mat img1 = imread(path_lenna);

	Mat img1f;
	img1.convertTo(img1f, CV_32FC1);

	uchar data1[] = {1,2,3,4,5,6,7,8,9,10,11,12};

	Mat mat1(3, 4, CV_8UC1, data1);
	Mat mat2 = mat1.reshape(0, 1);

	cout << "mat1 : \n" << mat1 << endl;
	cout << "mat2 : \n" << mat2 << endl;

	mat1.resize(5, 100);
	cout << "mat1 : \n" << mat1 << endl;

	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
	mat1.push_back(mat3);
	cout << "mat1 : \n" << mat1 << endl;

	mat1.resize(7, 150);
	cout << "mat1 : \n" << mat1 << endl;

	mat1.pop_back(2);
	cout << "mat1 : \n" << mat1 << endl;
}

void VectorScalar() {
	Vec<uchar, 3>p1, p2(0, 0, 255);
	p1.val[0] = 100;
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;

	Scalar gray = 128;
	cout << "gray : " << gray << endl;

	Scalar yellow(0, 255, 255);
	cout << "yellow : " << gray << endl;

	Mat img1(256, 256, CV_8UC3, yellow);
	Mat img2(256, 256, CV_8UC1, gray);

	for (int i = 0; i < 4; i++) {
		cout << yellow[i] << endl;
	}

	imshow("img1", img1);
	imshow("img2", img2);
}

void InputArrayOp() {
	uchar data1[] = { 1,2,3,4,5,6 };
	Mat mat1(2, 3, CV_8U, data1);
	printMat(mat1);

	vector<float> vec1 = { 1.2f, 3.4f, -2.1f };
	printMat(vec1);
}

void printMat(InputArray _mat) {
	Mat mat = _mat.getMat();
	cout << mat << endl;
}

void ViedoTest1() {
	VideoCapture cap(1);
	if (!cap.isOpened()) {
		cerr << "Camera is not 1" << endl;
		cap.open(0);
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = 30;
	int delay = (1000 / fps);

	cout << "w : " << w << endl;
	cout << "h : " << h << endl;


	VideoWriter video;
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');

	String VideoPath = IMG_PATH + (String)"output.avi";

	video.open(VideoPath, fourcc, fps, Size(w, h));

	Mat frame0, inversed0;
	while (1){
		cap >> frame0;
		if (frame0.empty()) {
			continue;
		}
		else {
			inversed0 = ~frame0;
			imshow("frame0", frame0);
			imshow("inversed0", inversed0);
			video.write(frame0);
		}

		if (waitKey(delay) == 27) {
			break;
		}
	}


	cap.release();

}

void ViedoTest2() {
	VideoCapture cap;
	String path = IMG_PATH + (String)"stopwatch.avi";
	cap.open(path);

	if (!cap.isOpened()) {
		cerr << "video open fail" << endl;
		return;
	}

	cout << "frame w : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "frame h : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "frame c : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

	double fps = cap.get(CAP_PROP_FPS);
	int delay = cvRound(1000 / fps);

	Mat frame, inversed;
	while (1) {
		cap >> frame;
		if (frame.empty()) {
			continue;
		}
		else {

			imshow("frame", frame);
			imshow("inversed", inversed);
		}


		if (waitKey(delay) == 27) {
			break;
		}
	}
}

void DrawLines() {

//	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
	Mat img;
	String path = IMG_PATH + (String)"lenna.bmp";
	img = imread(path, 1);


	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);

	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	 
	arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
	arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(0, 0, 255), 1);
	arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(0, 0, 255), 1, LINE_8, 0, 0.5);

	drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
	drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
	drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
	drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
	drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
	drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
	drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);

	imshow("img", img);
	waitKey(0);

}

void DrawPolys() {
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 2);
	rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 128), -1);

	circle(img, Point(300, 120), 30, Scalar(255, 255, 0), -1, LINE_AA);
	circle(img, Point(300, 120), 60, Scalar(255, 0, 0), 3, LINE_AA);

	ellipse(img, Point(120, 300), Size(60, 30), 20, 0, 270, Scalar(255, 255, 0), -1, LINE_AA);
	ellipse(img, Point(120, 300), Size(100, 50), 20, 0, 360, Scalar(0,255,0), 2, LINE_AA);

	vector<Point> pts;
	pts.push_back(Point(250, 250));
	pts.push_back(Point(300, 250));
	pts.push_back(Point(300, 300));
	pts.push_back(Point(350, 300));
	pts.push_back(Point(350, 350));
	pts.push_back(Point(250, 350));
	polylines(img, pts, true, Scalar(255, 0, 255), 2);

	imshow("img", img);
	waitKey(0);


}

void DrawText1() {
	Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));

	putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_PLAIN", Point(20, 100), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_DUPLEX", Point(20, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255));
	putText(img, "FONT_HERSHEY_COMPLEX", Point(20, 200), FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 0));
	putText(img, "FONT_HERSHEY_TRIPLEX", Point(20, 250), FONT_HERSHEY_TRIPLEX, 1, Scalar(255, 0, 0));
	putText(img, "FONT_HERSHEY_COMPLEX_SMALL", Point(20, 300), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255, 0, 0));

	putText(img, "FONT_HERSHEY_SCRIPT_SIMPLEX", Point(20, 350), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(255, 0, 255));
	putText(img, "FONT_HERSHEY_SCRIPT_COMPLEX", Point(20, 400), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(255, 0, 255));
	putText(img, "FONT_HERSHEY_COMPLEX | FONT_ITALIC", Point(20, 450), FONT_HERSHEY_COMPLEX | FONT_ITALIC, 1, Scalar(255, 0, 0));

	imshow("img", img);
	waitKey(0);

}

void DrawText2() {
	Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));


	const String text = "Hello, OpenCV";
	int fontFace = 4;
	double fontscale = 2.0;
	int thickness = 1;
	Size textsize = getTextSize(text, fontFace, fontscale, thickness, 0);

	cout << textsize.width << endl;
	cout << textsize.height << endl;

	Point point;
	point.x = (640 - textsize.width) / 2;
	point.y = (200 + textsize.height) / 2;
	putText(img, text, point, fontFace, fontscale, Scalar(255, 0, 255), thickness, LINE_8, false);
	imshow("img", img);
	waitKey(0);
}

void KeyboardEvent() {

	String path = IMG_PATH + (String)"lenna.bmp";
	Mat img = imread(path);
	if (img.empty()) {
		cerr << "img load fail" << endl;
		return;
	}

	namedWindow("img");
	imshow("img", img);
	while (1) {
		int keycode = waitKey();

		if (keycode == 'i' || keycode == 'I') {
			img = ~img;
			imshow("img", img);
		}

		else if (keycode == 'q' || keycode == 'Q' || keycode == 27) {
			break;
		}
	}
}

void MouseEvent() {
String path = IMG_PATH + (String)"lenna.bmp";
img = imread(path);
	if (img.empty()) {
		cerr << "img load fail" << endl;
		return;
	}
	namedWindow("img");
	setMouseCallback("img", on_mouse);
	imshow("img", img);
	waitKey(0);
}

void on_mouse(int event, int x, int y, int flags, void*) {
	switch (event) {
	case EVENT_LBUTTONDOWN:
		ptOld = Point(x, y);
		cout << "EVENT_LBUTTONDOWN: " << x << "," << y << endl;

		break;
	case EVENT_LBUTTONUP:
		cout << "EVENT_LBUTTONUP: " << x << "," << y << endl;
		break;
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON) {
			line(img, ptOld, Point(x, y), Scalar(0, 255, 255), 2);
			imshow("img", img);
			ptOld = Point(x, y);
		}
		if (flags & EVENT_FLAG_LBUTTON || flags & EVENT_FLAG_CTRLKEY) {
			ptOld = Point(x, y);
			rectangle(img, rec_pt1, rec_pt2, Scalar(0, 255, 255), 2);
			imshow("img", img);
		}
		break;
	default:
		break;
	}
}

void Example() {
	String path = IMG_PATH + (String)"lenna.bmp";
	img = imread(path);
	if (img.empty()) {
		cerr << "img load fail" << endl;
		return;
	}
	namedWindow("img");
	setMouseCallback("img", on_mouse);
	imshow("img", img);

	while (1) {
		int keycode = waitKey();

		if (keycode == 'i' || keycode == 'I') {
			img = ~img;
			imshow("img", img);
		}
		if (keycode == 'c' || keycode == 'C') {
			img = imread(path);
			imshow("img", img);
		}


		else if (keycode == 'q' || keycode == 'Q' || keycode == 27) {
			break;
		}
	}
	waitKey(0);
}

