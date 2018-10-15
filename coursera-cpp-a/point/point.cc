#include <iostream>

using namespace std;

class Point {
 public:
  Point(double a = 0.0, double b = 0.0):x_(a), y_(b) {}

  double getx() const {return x_;}
  void setx(double v) {x_ = v;}

  Point operator +(const Point& p) {
    return Point(x_ + p.x_, y_ + p.y_);
  }

  friend ostream& operator <<(ostream& out, const Point& p); 

 private:
  double x_, y_;
  
};

ostream& operator <<(ostream& out, const Point& p) {
    out << "(" << p.x_ << ", " << p.y_ << ")";
    return out;
}

int main(int argc, char *argv[]) {
  Point a(3.5, 2.5);
  Point b(2.5, 4.5);

  cout << "a = " << a << " b = " << b << endl;
  cout << "sum = " << a + b << endl;
  
  return 0;
}
