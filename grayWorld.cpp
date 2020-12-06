#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <ctime>
using namespace std;
using namespace cv;
Mat grayWorld(Mat img){
    vector<Mat> rgb;
    cv::split(img,rgb);
    double b,g,r;
    b=g=r=0.0;
    int i,j,rows,cols;
    rows=img.rows;
    cols=img.cols;
    Mat result=Mat(rows,cols,CV_8UC3);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
          b += 1.0 * img.at<Vec3b>(i, j)[0];
          g+=1.0*img.at<Vec3b>(i,j)[1];
          r+=1.0*img.at<Vec3b>(i, j)[2];
        }
    }
    b/=rows*cols;
    g/=rows*cols;
    r/=rows*cols;
    double grayValue=(b+g+r)/3;
    double kb=grayValue/b;
    double kg=grayValue/g;
    double kr=grayValue/r;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            b=img.at<Vec3b>(i, j)[0]*kb;
            g=img.at<Vec3b>(i, j)[1]*kg;
            r=img.at<Vec3b>(i, j)[2]*kr;
            result.at<Vec3b>(i, j)[0]=(int)(b)>255?255:(int)b;
            result.at<Vec3b>(i, j)[1]=(int)(g)>255?255:(int)g;
            result.at<Vec3b>(i, j)[2]=(int)(r)>255?255:(int)r;


        }
    }

    return result;


}

int main(){
    printf("hello");
   Mat img=imread("1.jpg",1);
   clock_t time_stt = clock();
    img=grayWorld(img);
    imwrite("2.jpg",img);
    time_stt = clock();
    cout <<"time use in grayWorld is " <<1000*  (clock() - time_stt)/(double)CLOCKS_PER_SEC <<"ms" << endl;
}