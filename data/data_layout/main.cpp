#include <iostream>


class Point {
  public:
    Point (float x = 0.0)
        : mX(x) {
    }

    float getX () {
        return mX;
    }

    void setX (float x) {
        mX = x;
    }

  protected:
    float mX;
};

class Point2d : public Point {
  public:
    Point2d (float x = 0.0, float y = 0.0)
        : Point(x), mY(y) {
    }

    float getY () {
        return mY;
    }

    void setY (float y) {
        mY = y;
    }

  protected:
    float mY;
};

class Point3d : public Point2d {
  public:
    Point3d (float x = 0.0, float y = 0.0, float z = 0.0)
      : Point2d(x, y), mZ(z) {
    }

    float getZ () {
        return mZ;
    }

    void setZ (float z) {
        mZ = z;
    }

  protected:
    float mZ;
};



int main() {

    std::cout << "sizeof(Point):" << sizeof(Point)
            << ", sizeof(Point2d):" << sizeof(Point2d)
            << ", sizeof(Point3d):" << sizeof(Point3d) << std::endl;

    return 0;
}
