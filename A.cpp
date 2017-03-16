#include<iostream>
#include<string>
#include<fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"


#define SF 1   //Scaling Factor

using namespace std;
using namespace cv;


int main(int argc, char *argv[])
{

  int n= stoi(argv[1]);   //Total no of bots
  std::vector<Point2f> vec;

  int k;                  // k is the number of bots present on left and right arms of A
  double v=(n+1.6)/2.6;   // This formula has been derived in the documentation.
  if((v-(int)v)>0.5)
    k=v+1;
  else
    k=v;

  vec.push_back(Point(0, k-1));

  for(int t=1; t<=k-1; t++)
    {
      // The ratio of the height of A versus its base(considering it as a triangle) is 1:1
      vec.push_back(Point2f((-SF*t), (k-1-(2*SF*t))));
      vec.push_back(Point2f((SF*t), (k-1-(2*SF*t))));
    }

  int rem=n-(2*k-1);
  double f=(2*(k-1))/3;   //The ratio of the height of the middle arm of A to the total height of A is 1:3
  double sub=(2*SF*f)/(float)(rem+1);

  if(n==4)
    vec.push_back(Point2f(0,0));
  else
    {
      for(int t=1; t<=rem; t++)
        {
          vec.push_back(Point2f((SF*f-(sub*t)), (k-1-(2*SF*f))));
        }
    }

  ofstream obj("f.txt", ios::out);  //File to write the co-ordinates

  //Points written to a file so that it can be plotted using python matplot.
  for(Point2f p: vec)
    {
      obj<<p.x<<" ";
    }
  obj<<endl;
  for(Point2f p: vec)
    {
      obj<<p.y<<" ";
    }

}
