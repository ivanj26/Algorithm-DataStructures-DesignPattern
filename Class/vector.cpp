
/**
 * File   : cvector.cpp
 * Author : Ivan Jonathan
 **/
#include <iostream>
#include <math.h>
using namespace std;

class CVector {
  public:
    double x,y,z;

    CVector() : x(0), y(0), z(0) {}
    CVector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    void display() {
      printf("(%.2f, %.2f, %.2f)\n", x, y, z);
    }

    /**
     * Vector operation -> operator overloading 
     **/
    CVector operator+(const CVector& v) {
      CVector vec;
      vec.x = (x + v.x);
      vec.y = (y + v.y);
      vec.z = (z + v.z);

      return vec;
    }

    CVector operator-(const CVector& v) {
      CVector vec;
      vec.x = (x - v.x);
      vec.y = (y - v.y);
      vec.z = (z - v.z);

      return vec;
    }

    CVector operator*(const double c) {
      CVector vec;
      vec.x = (x * c);
      vec.y = (y * c);
      vec.z = (z * c);

      return vec;
    }

    // Dot product
    double operator*(const CVector& v){
      double u = x * v.x;
      double w = y * v.y;
      double y = z * v.z;

      return u + w + y;
    }

    // Cross product
    CVector operator&(const CVector& v) {
      /**
       *         i  j  k
       * u x v = u1 u2 u3
       *         v1 v2 v3
       * 
       * u x v = ((u2 * v3)i + (u1 * v3)j + (u1 * v2)k) -
       *         ((v2 * u3)i + (v1 * u3)j + (v1 * u2)k)
       * */
      double x = (y * v.z) - (v.y * z);
      double y = (z * v.x) - (v.z * x);
      double z = (x * v.y) - (v.x * y);

      return CVector(x, y, z);
    }
};

int main(int argc, char const *argv[])
{
  CVector v1(-1.0, -7.0, 1.0);
  CVector v2(3.0, 1.0, 1.0);

  CVector v3 = (v1 * 2) + (v2 * (-3));

  cout << "v2: ";
  v2.display();

  cout << "v3: ";
  v3.display();

  //Cross product
  v3 = v1 & v2;

  cout << endl;
  cout << "Cross product v1 x v2\t: ";
  v3.display();
  
  //Dot product
  cout << "Dot product\t\t: ";
  cout << (v1 * v2) << endl;

  v3 = v2 & v1;

  cout << endl;
  cout << "Cross product v2 x v1\t: ";
  v3.display();

  return 0;
}
