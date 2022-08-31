#define IMG_PATH "C:/Users/Dell/Desktop/OpenCV(송희강)/img/"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>


using namespace std;
using namespace cv;

String path_lenna = IMG_PATH + (String)"lenna.bmp";
String path_airplane = IMG_PATH + (String)"airplane.bmp";
String path_lenna_256 = IMG_PATH + (String)"lenna256.bmp";
String path_square = IMG_PATH + (String)"square.bmp";

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

void TrackBarEx();
void OnLevelChange(int pos, void* userdata);
void WriteData();
void ReadData();
void MaskSetTo();
void CopyTo();
void timeInverse();
void SumEx();
void NormalEx();
void brightness();
void brightness2();
void brightness_track();
void contrast1();
void contrast2();
Mat CalcGrayHist(const Mat& img);
Mat GetGrayHistImage(const Mat& hist);
void MakeGrayHist();
void Histogram_stretching();
void histogram_equlization();
void AddTest();
void AddTest2();
void SubtractTest();
void LogicTest();
void filter_embossing();
void blurring_mean();
void blurring_gaussian();
void UnsharpMask();
void NoiseGaussian();
void FilterMedian();
void FilterBilateral();
void AffineTransform();
void AffineTranslation();
void AffineShear();
void AffineScale();
void AffineRotation();

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
//	Example();
//	TrackBarEx();
//	WriteData();
//	ReadData();
//	MaskSetTo();
//	CopyTo();
//	timeInverse();
//	SumEx();
//	NormalEx();
//	brightness();
//	brightness2();
//	brightness_track();
//	contrast1();
//	contrast2();
//	MakeGrayHist();
//	Histogram_stretching();
//	histogram_equlization();
//	AddTest();
//	AddTest2();
//	SubtractTest();
//	LogicTest();
//	filter_embossing();
//	blurring_mean();
//	blurring_gaussian();
//	UnsharpMask();
//	NoiseGaussian();
//	FilterMedian();
//	FilterBilateral();
//	AffineTransform();
//	AffineTranslation();
//	AffineShear();
//	AffineScale();
	AffineRotation();
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
		if (flags & EVENT_FLAG_CTRLKEY) {
			if (flags & EVENT_FLAG_LBUTTON) {
				rec_pt2 = Point(x, y);
				rectangle(img, rec_pt1, rec_pt2, Scalar(0, 255, 255), 2);
				imshow("img", img);
			}
		}
		else if (flags & EVENT_FLAG_LBUTTON) {
			line(img, ptOld, Point(x, y), Scalar(0, 255, 255), 2);
			imshow("img", img);
			ptOld = Point(x, y);
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
void TrackBarEx() {
	Mat img = Mat::zeros(640, 480, CV_8UC1);
	int value = 0;

	namedWindow("image");
	createTrackbar("level", "image", &value, 16, OnLevelChange, (void*)&img);
	imshow("image", img);
	waitKey(0);
	return;
}

void OnLevelChange(int pos, void* userdata) {
	Mat img = *(Mat*)userdata;

	img.setTo(pos * 16);
	imshow("image", img);
}
String filename = "mydata.json";

void WriteData() {
	String name = "Jane";
	int age = 10;
	Point pt1(100, 200);
	vector<int> scores = { 80,90,50 };
	Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

	FileStorage fs(filename, FileStorage::WRITE);
	if (!fs.isOpened()) {
		cerr << "file open err _write" << endl;
		return;
	}

	fs << "name" << name;
	fs << "age" << age;
	fs << "point" << pt1;
	fs << "scores" << scores;
	fs << "data" << mat1;

	fs.release();
}
void ReadData() {

	String name;
	int age;
	Point pt1;
	vector<int> scores;
	Mat mat1;

	FileStorage fs(filename, FileStorage::READ);
	if (!fs.isOpened()) {
		cerr << "file open err" << endl;
		return;
	}

	fs["name"] >> name;
	fs["age"] >> age;
	fs["point"] >> pt1;
	fs["scores"] >> scores;
	fs["data"] >> mat1;

	fs.release();

	cout << "name : " << name << endl;
	cout << "age : " << age << endl;
	cout << "point : " << pt1 << endl;
	cout << "scores : " << Mat(scores).t() << endl;
	cout << "data : \n" << mat1 << endl;
	waitKey(0);
}

void MaskSetTo() {

	String path = IMG_PATH + (String)"lenna.bmp";
	String pathMask = IMG_PATH + (String)"mask_smile.bmp";
	Mat src = imread(path, IMREAD_COLOR);
	Mat mask = imread(pathMask, IMREAD_GRAYSCALE);

	if (src.empty() || mask.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	src.setTo(Scalar(0, 255, 255), mask);

	imshow("src", src);
	imshow("mask", mask);

	waitKey(0);

}

void CopyTo() {

	String path = IMG_PATH + (String)"airplane.bmp";
	String pathMask = IMG_PATH + (String)"mask_plane.bmp";
	String destination = IMG_PATH + (String)"field.bmp";


	Mat src = imread(path, IMREAD_COLOR);
	Mat mask = imread(pathMask, IMREAD_GRAYSCALE);
	Mat dst = imread(destination, IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "image load" << endl;
		return;
	}

	src.copyTo(dst, mask);
	imshow("dst", dst);
	waitKey(0);


}

void timeInverse() {
	String path = IMG_PATH + (String)"lenna.bmp";
	Mat src = imread(path, IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "image load fail" << endl;
		return;
	}
	Mat dst(src.rows, src.cols, src.type());
	TickMeter tm;

	tm.start();

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = ~dst.at<uchar>(j, i);
		}
	}

	tm.stop();
	cout << "image inverse took : " << tm.getAvgTimeMilli() << "ms" << endl;
	waitKey(0);

}

void SumEx() {
	String path = IMG_PATH + (String)"lenna.bmp";
	Mat src = imread(path, IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "image load fail" << endl;
		return;
	}

	//cout << "sum : " << (int)sum(src)[0] << endl;
	//cout << "sum : " << (int)sum(src)[1] << endl;
	//cout << "sum : " << (int)sum(src)[2] << endl;
	//cout << "mean : " << (int)mean(src)[0] << endl;
	//cout << "mean : " << (int)mean(src)[1] << endl;
	//cout << "mean : " << (int)mean(src)[2] << endl;

	//cout << sum(src) << endl;
	//cout << mean(src) << endl;

	double minVal, maxVal;
	Point minPos, maxPos;
	minMaxLoc(src, &minVal, &maxVal, &minPos, &maxPos);

	cout << "minVal : " << minVal << ", at : " << minPos << endl;
	cout << "maxVal : " << maxVal << ", at : " << maxPos << endl;


}

void NormalEx() {
	Mat src = Mat_<float>({ 1,5 }, { -1.f, -0.5f, 0.f, 0.5f, 1.5f });
	Mat dst;
	normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
	cout << src << endl;
	cout << dst << endl;

}

void brightness() {

	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "brightness imread fail" << endl;
		return;
	}

	Mat dst = src + 100;

	imshow("src", src);
	imshow("dst", dst);

	waitKey();

}
void brightness2() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "brightness imread fail" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;
		}
	}
	imshow("src", src);
	imshow("dst", dst);

	waitKey();
}

/* brightness 관련한 Call back 함수이다.*/
void on_brightness(int pos, void* userdata) {
	
	Mat src = *(Mat*)userdata; /*Track bar userdata 를 받는다.*/
	Mat dst = src + pos;
	imshow("dst", dst);
}

void brightness_track() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "brightness imread fail" << endl;
		return;
	}
	namedWindow("dst");
	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
	on_brightness(0, (void*)&src); /*0일때 강제로 넣어주지 않으면 출력되지 않는다*/
	waitKey();
}

/*명암비 조절*/
void contrast1() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "brightness imread fail" << endl;
		return;
	}
	
	/*open cv 는 실수형 자료형과 Mat 객체 가이의 곱셈 연산자에 대해서 재정의(operator)를 제공 한다
	*뿐만 아니라 결과 행렬에 대해서 포화 연산 또한 함께 수행한다
	*이러한 방식으로 상수를 단순하게 곱하여 명암비를 조절하는 방식은 잘 사용되지 않는다.
	*- 물체 구분이 잘된다 (명암비가 높다)
	*/

	float s = 2.f;     /*float 형식을 따로 선언해 주는 이유는 뭘까?*/
	Mat dst = s * src; /*모든 픽셀 값에 2.0을 곱한다*/

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
}

/*따라서 contrast 1 이 아닌 다음과 같은 방식을 사용한다*/
/*
- 명암비를 효과적으로 높이려면 밝은것은 더밝게 어두운것은 더 어둡게 한다 
- 그때 기준 값을 픽셀의 평균값으로 한다(sum, mean 함수 이용)거나 스케일 중간값인 128 을 이용 하는 방법이 있다
- 명암비를 낮추려면 위와 같은 특징을 반대로 적용하여 주면된다
*/
void contrast2() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "brightness imread fail" << endl;
		return;
	}
	
	/*scale 중간값인 128을 이용 하는 경우*/
	/*alpha
	- 알파 음수인 경우 명암비 감소
	- 알파 양수인 경우 명암비 증가 
	- 쓰레스 홀드 (임계값) 이용 가능
	*/
	float alpha = 1.f;
	float alpha2 = -0.5f;
	Mat dst1 = src + (src - 128) * alpha;
	Mat dst2 = src + (src - 128) * alpha2;

	/*모든 픽셀의 평균값을 이용하는 경우*/
	int avg = (int)mean(src)[0];
	cout << "avg : " << avg << endl;
	Mat dst3 = src + (src - avg) * alpha;
	Mat dst4 = src + (src - avg) * alpha2;

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
	waitKey();
}

/*히스토그램 
- 영상 픽셀 값 분포를 그래프로 나타낸것 
- 히스토 그램의 가로 : bin
- 그레이 스케일 영상의 경우 256개의 빈을 구하는것이 일반적이다.
- 히스토 그램을 전부 다 더한 값은 모든 픽셀 카운트 값이다.

*/

void MakeGrayHist() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "brightness imread fail" << endl;
		return;
	}

	Mat hist = CalcGrayHist(src);
	hist = GetGrayHistImage(hist);


	float alpha = 0.3f;
	float alpha2 = -0.5f;
	Mat dst1 = src + (src - 128) * alpha;
	Mat dst2 = src + (src - 128) * alpha2;

	Mat hist1 = CalcGrayHist(dst1);
	hist1 = GetGrayHistImage(hist1);

	Mat hist2 = CalcGrayHist(dst2);
	hist2 = GetGrayHistImage(hist2);


	imshow("src", src);
	imshow("hist", hist);

	imshow("dst1", dst1);
	imshow("dst2", dst2);

	imshow("hist1", hist1);
	imshow("hist2", hist2);
	waitKey();
}

/*히스토 그램을 계산하는 함수*/
Mat CalcGrayHist(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1);
	Mat hist;
	int channels[] = { 0 };

	int dims = 1; /*1차원 행렬로 하겠다* 행갯수 255 열갯수 1*/
	const int histSize[] = { 256 }; /*히스토그램 사이즈*/
	
	/*
	<<ranges>>
	- 최대값 256  포함하지 않는다.
	- 최소값 0    포함한다
	*/

	float graylevel[] = { 0, 256 }; 
	const float* ranges[] = { graylevel };
	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
	return hist;
}

/* 히스토 그램을 그려주는 함수*/
Mat GetGrayHistImage(const Mat& hist) {
	
	CV_Assert(hist.type() == CV_32FC1); // 픽셀 값이기 때문에 32bit 로 되어있다
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;// 최대값을 기준 비율 로써 히스토 그램을 그려주기 위해서 최대 값을 찾는다
	minMaxLoc(hist, 0, &histMax);
	Mat imgHist(100, 256, CV_8UC1, Scalar(255)); 

	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
		/*
		- pt1 : 가로축 이동하면서 위치
		- pt2 : 검은색 막대기를 그릴 포인트 위치
		*/
	}
	return imgHist;

}

/*히스토그램 스트레칭(입력구간)
- 히스토그램이 그레이 스케일 구간에 걸쳐서 나타나도록 변경한다. 
- 명암비가 높아진다
*/

void Histogram_stretching() {
	Mat src = imread(path_airplane, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Histogram_stretching imread fail" << endl;
		return;
	}

	double gmin, gmax;
	minMaxLoc(src, &gmin, &gmax);

	Mat dst = (src - gmin) * 255 / (gmax - gmin);

	imshow("src", src);
	imshow("srHist", GetGrayHistImage(CalcGrayHist(src)));

	imshow("dst", dst);
	imshow("dstHist", GetGrayHistImage(CalcGrayHist(dst)));
	waitKey();
}

/*히스토그램 평활화(전구간)
- 특정 그레이 스케일 값에서 픽셀 분포가 뭉쳐있는 경우 이를 넓게 펼쳐준다.
- 피크값이 높은것은 늘려준다
- 피크값이 낮은것은 좁혀준다
*/

void histogram_equlization() {
	Mat src = imread(path_airplane, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Histogram_stretching imread fail" << endl;
		return;
	}

	/* equalizeHist()
	- 많이 사용하기 때문에 함수화 되어있다.
	- 8UC_1 이미지 값만 받을 수 있다.
	*/ 
	Mat dst;
	equalizeHist(src, dst);

	imshow("src", src);
	imshow("srHist", GetGrayHistImage(CalcGrayHist(src)));

	imshow("dst", dst);
	imshow("dstHist", GetGrayHistImage(CalcGrayHist(dst)));
	waitKey();
}

/*산술연산
- 보통 빼주는 연산을 자주 사용한다 : 문제 발생지점과 정상점 과 의 차이지점을 찾기 위해서
- 덧셈 연산시에는 포화 연산또한 같이 행해 주어야 한다.|| add 함수의 경우 포화연산을 자동으로 행해준다.
- 특정한 지점을 더해주고 싶은경우 마스크 연산을 사용하면 된다.
- 두 사진 중 가중치를 정해줄 수 있다.

*/
void AddTest() {
	Mat src1 = imread(path_lenna, IMREAD_GRAYSCALE);
	Mat src2 = imread(path_airplane, IMREAD_GRAYSCALE);
	resize(src1, src1, Size(480, 480));
	resize(src2, src2, Size(480, 480));

	Mat dst1;
	Mat dst2;
	add(src1, src2, dst1);
	dst2 = src1 + src2;

	imshow("src1", src1);
	imshow("src2", src2);
	imshow("dst1", dst1);
	imshow("dst2", dst2);

	waitKey();

}

void AddTest2() {
	Mat src1 = imread(path_lenna, IMREAD_GRAYSCALE);
	Mat src2 = imread(path_airplane, IMREAD_GRAYSCALE);
	resize(src1, src1, Size(480, 480));
	resize(src2, src2, Size(480, 480));

	Mat dst;

	addWeighted(src1, 0.5, src2, 0.8, 0, dst);
	imshow("src1", src1);
	imshow("src2", src2);
	imshow("dst", dst);
	waitKey();
}

/* 
- 음수를 0으로 처리해주는 포화연산이 필요하다
- subtract()을 이용한다.
- add() 함수와 인자는 같다.
- 뺄셈 대상이 되는 영상의 '순서'에 따라서 결과값이 다르게 나타난다
- 차영상 : 순수한 두영상의 차이값
-> 차이 연산은 연산결과에 절대값을 취하는 연산이다.
-> 차이 연산은 변화가 있는 영역을 쉽게 찾을 수 있다.
*/
void SubtractTest() {

	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cerr << "Camera is not 1" << endl;
		cap.open(1);
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = 30;
	int delay = (1000 / fps);

	cout << "w : " << w << endl;
	cout << "h : " << h << endl;

	Mat camera;
	Mat frame0;
	Mat frame1;
	Mat dst;
	int flag = 0;
	int flag_diff = 0;

	while (1) {
		cap >> camera;
		cvtColor(camera, camera, COLOR_BGR2GRAY);
		int keycode = waitKey(delay);
		imshow("camera", camera);

		if (keycode == 's') {
			flag++;
			if (flag == 1) {
				frame0 = camera;

			}
			if (flag == 2) {
				frame1 = camera;

				absdiff(frame0, frame1, dst);
				imshow("frame0", frame0);
				imshow("frame1", frame1);
				imshow("dst", dst);
				flag = 0;
			}
		}
		if (keycode == 'w') {
			flag_diff = 1;
		}
		if (flag_diff == 1) {

			absdiff(frame0, camera, dst);
			imshow("dst", dst);
		}

		if (keycode == 27) {
			break;
		}
	}

	cap.release();
}

void LogicTest() {
	Mat src1 = imread(path_lenna_256, IMREAD_GRAYSCALE);
	Mat src2 = imread(path_square, IMREAD_GRAYSCALE);

	if (src1.empty() || src2.empty()) {
		cerr << "Logic image Load fail" << endl;
		return;
	}

	imshow("src1", src1);
	imshow("src2", src2);

	Mat dst1, dst2, dst3, dst4;

	bitwise_and(src1, src2, dst1);
	bitwise_or(src1, src2, dst2);
	bitwise_xor(src1, src2, dst3);
	bitwise_not(src1, dst4);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
	waitKey();

}
/**
- 다른 라이브러리는 embossing 함수 같은 필터링 함수가 이미 존재 한다. 
이를 알맞은 파라미터를이용하여 사용하면된다.
- filter 2D 함수에서 anchor, delta, bordertype 인자는 기본값을 가지고 있다.
- 엠보싱 엣지 특성상 수평, 수직이 아닌 대각선 엣지를 더 잘 검출한다. 
*/
void filter_embossing() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {

		cerr << "imread fail" << endl;
		return;
	
	}

	float data[] = { -1,-1,0,-1,0,1,0,1,1 };
	Mat emboss(3,3,CV_32FC1, data);

	Mat dst;
	filter2D(src, dst, -1, emboss, Point(-1, -1), 0);


	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);

}
/**
블러링(스무딩): 영상 부드럽게 하기 
- 평균값 필터, 가우시안 필더등이 이 종류에 해당한다.
- 입력 영상에 존재하는 잡음의 영향을 제거하는 전처리 과정으로도 사용된다.
*/

#define BLUR_NUM 11
/**
평균값 필터
- 평균값 필터는 마스크의 크기가 커지면 커질 수록 더욱 부드러운 
느낌을 표현 가능하다
- 더 부드럽게 할 수록 연산량이 증가한다.
*/
void blurring_mean() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	//Mat dst;
	//for (int ksize = 3; ksize <= 13; ksize += 2) {
	//	blur(src, dst, Size(ksize, ksize));

	//	String desc = format("Mean : %d%d", ksize, ksize);
	//	putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
	//	imshow("dst", dst);
	//	waitKey(0);
	//}

	float data[BLUR_NUM * BLUR_NUM] = {0};
	for (int i = 0; i < sizeof(data) / sizeof(float); i++) {
		data[i] = 1;
		data[i] = data[i] / (BLUR_NUM * BLUR_NUM);
	}
	Mat emboss(BLUR_NUM, BLUR_NUM, CV_32FC1, data);

	Mat dst;
	filter2D(src, dst, -1, emboss, Point(-1, -1), 0);

	Mat dst2;
	blur(src, dst2, Size(BLUR_NUM, BLUR_NUM));

	Mat dst3;
	dst3 = src - dst2;

	imshow("src", src);
	imshow("dst", dst);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	waitKey(0);

}

/**
가우시안 필터
- 가우시안 분포를 따른다
- 가까우면 가중치가 높고 멀게되면 가중치가 작아진다.
- 영상의 가우시안 필터는 평균이 0인 분포 함수를 사용한다.
- 가우시안 필터 마스크 크기는 보통 (시그마 + 1) == 표준편차에 의한값
*/

void blurring_gaussian() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	imshow("src", src);
	Mat dst;
	for (int sigma = 1; sigma <= 5; sigma++) {
		GaussianBlur(src, dst, Size(), (double)sigma);

		String text = format("SIGMA = %d", sigma);
		putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
		imshow("dst", dst);
		waitKey(0);
	}
}


/**
샤프닝 - 영상 날카롭게 하기 
언샤프 마스크 필터
*/

void UnsharpMask() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	imshow("src", src);

	float alpha = 1.f;
	for (;;) {
		int sigma = 1;
		int keyboard = waitKey();
		// blurred 로 blur 처리와 원본 사이의 차이로 G(x) 를 구한다.
		Mat blurred;
		GaussianBlur(src, blurred, Size(), (double)sigma);

		// alpha 는 그 차이를 배수 로 하여 사용자가 가중치를 선택 할 수 있도록 한다.
		

		if (keyboard == 'a') {
			Mat dst = (1 + alpha) * src - alpha * blurred;
			String text = format("SIGMA = %d", sigma);
			putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
			imshow("dst", dst);
			alpha++;
		}
		if (keyboard == 'x') {
			break;
		}
	}
}

/**
노이즈를 추가해준다
*/
void NoiseGaussian() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	imshow("src", src);
	for (int stddev = 10; stddev <= 30; stddev += 10) {
		Mat noise(src.size(), CV_32SC1);
		randn(noise, 0, stddev);

		Mat dst;
		add(src, noise, dst, Mat(), CV_8U);

		String desc = format("stddev = %d", stddev);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
		imshow("dst", dst);
		waitKey(0);
	}
}


/**
미디언 필터
- 잡음 픽셀값과 주변 픽셀값 차이가 큰경우에 효과적으로 동작한다.
- 자기자신 픽셀값과 주변 값 중에서 중간값을 선택 하여 결과 영상 픽셀 값으로 설정하는 필터링 
- boder replicate 방식으로 가장자리 외곽 픽셀값을 설정한다 
*/

void FilterMedian() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	imshow("src", src);

	int num = (int)(src.total() * 0.1);
	for (int i = 0; i < num; i++) {
		int x = rand() % src.cols;
		int y = rand() % src.rows;
		src.at<uchar>(y, x) = (i % 2) * 255;
	}

	Mat dst1;
	GaussianBlur(src, dst1, Size(), 1);

	Mat dst2;
	medianBlur(src, dst2, 3);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	waitKey(0);
}

/**
양방향 필터 - 에지를 죽이지 않으면서 필터링을 하는것
- 픽셀값 차이가 크면(엣지 이기 때문에) 0으로 채워넣고(처리를 하지 않는다) , 가우시안 필터 고정점과 픽셀차이가 비슷 하면 팔터값을 가져온다. 
- 거리(가우시안 필터) * 픽셀값 차이(가우시안 필터) 두개를 합친것
- 연산량이 엄청 많다. ==> ROI 를 사용 하는 이유 관심 영역 만 필터링을 해주면 되기 때문이다. 

*/

void FilterBilateral() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	imshow("src", src);

	Mat noise(src.size(), CV_32SC1);
	randn(noise, 0, 5);
	add(src, noise, src, Mat(), CV_8U);

	Mat dst1;
	GaussianBlur(src, dst1, Size(), 10);

	Mat dst2;
	bilateralFilter(src, dst2,-1, 10, 5);

	Mat dst3 = src - dst1;
	Mat dst4 = src - dst2;

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
	waitKey();
}


/**
어파인 변환
- 여유(마진) 을 주는 이유는 화면 크기가 더커야 좌표값을 이동시켜도 사진이 손상되지 않기 때문이다.
- 회전 때문에 어파인 변환은 실수형 행렬로 이루어져 있다.
- 도형의 필요 최소 요소 3가지 
==> 원본 꼭지점 3가지 변환후 에 꼭지점 3가지 
*/

void AffineTransform() {
	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	imshow("src", src);

	Point2f srcPts[3], dstPts[3];
	srcPts[0] = Point2f(0, 0);
	srcPts[1] = Point2f(src.cols-1, 0);
	srcPts[2] = Point2f(src.cols - 1, src.rows - 1);

	dstPts[0] = Point2f(50, 50);
	dstPts[1] = Point2f(src.cols - 100, 100);
	dstPts[2] = Point2f(src.cols - 50, src.rows - 50);
	Mat M = getAffineTransform(srcPts, dstPts);

	Mat dst;
	warpAffine(src, dst, M, Size());

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
}

/**
이동변환
*/

void AffineTranslation() {

	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	imshow("src", src);

	Mat M = Mat_<double>({ 2,3 }, { 1,0,150,0,1,100 });

	Mat dst;
	warpAffine(src, dst, M, Size(src.cols-1, src.rows-1) + Size(150,100));

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
}

/**
전단변환
- 원점은 이동하지 않는다. 
*/

void AffineShear() {

	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}
	imshow("src", src);

	double mx = 0.3;
	double my = 0.3;
	Mat M = Mat_<double>({ 2,3 }, { 1,mx,0,0,1,0 });
	Mat M2 = Mat_<double>({ 2,3 }, { 1,0,0,my,1,0 });

	Mat dst;
	Mat dst2;

	warpAffine(src, dst, M, Size(cvRound(src.cols + src.rows * mx), src.rows));
	warpAffine(src, dst2, M2, Size(src.cols, cvRound(src.rows + src.cols*mx)));

	imshow("src", src);
	imshow("dst", dst);
	imshow("dst2", dst2);
	waitKey();
}

/**
크기 변환
- dsize : 크기가 원본보다 더 크더라도 자동적으로 처리해준다. 
- 보간법(확장시)
==> INTER_NEAREST : 최근방 이웃 보간법, 간단하지만 결과물이 좋지 않다.
==> INTER_LINEAR  : 양선형 보간법, 
==> INTER_CUBIC   :3차 보간법
-------------------------------------------------------------------
- 보간법(축소시)
==> 란초스 보간법

*/

void AffineScale() {

	Mat src = imread(path_lenna, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}

	TickMeter tm;
	Mat dst1, dst2, dst3, dst4;
	tm.start();
	resize(src, dst1, Size(), 4, 4, INTER_NEAREST);
	imshow("dst1", dst1);
	tm.stop();
	cout << "INTER_NEAREST : " << tm.getAvgTimeMilli() << "ms" << endl;
	waitKey();

	tm.start();
	resize(src, dst2, Size(1920, 1280), INTER_LINEAR);
	imshow("dst2", dst2);
	tm.stop();
	cout << "INTER_LINEAR : " << tm.getAvgTimeMilli() << "ms" << endl;
	waitKey();

	tm.start();
	resize(src, dst3, Size(1920, 1280), 0, 0, INTER_CUBIC);
	imshow("dst3", dst3);
	tm.stop();
	cout << "INTER_CUBIC : " << tm.getAvgTimeMilli() << "ms" << endl;
	waitKey();

	tm.start();
	resize(src, dst4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);
	imshow("dst4", dst4);
	tm.stop();
	cout << "INTER_LANCZOS4 : " << tm.getAvgTimeMilli() << "ms" << endl;
	waitKey();

	imshow("src", src);

	waitKey();
}

/**
원점을 기준으로 영상을 반시계 방향으로 회전
*/

void AffineRotation() {
	Mat src = imread(path_airplane, IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "imread fail" << endl;
		return;
	}

//	Point2f cp(src.cols * 0.5, src.rows * 0.5);

//	Mat M = getRotationMatrix2D(cp, 30, 1);
//	Mat dst;
	Mat M = Mat_<double>({ 2,3 }, { 1,0,150,0,1,100 });

	// 해당하는 각도의 변환된 윈도우 생성 
	warpAffine(src, src, M, Size(src.cols - 1, src.rows - 1) + Size(150, 100));

	// 확장된 윈도우에서 중심점 찾아서 이동

	// dst 사진 getRotation 함수 이용하여 각도만큼 회전

	//circle(dst, cp, 30, Scalar(255, 255, 0), -1, LINE_AA);
//	resize(dst,dst, Size(800, 400));
	imshow("src", src);
//	imshow("dst", dst);
	waitKey();


}
