/*
 * Algorithm
 *
*/

class Cylinder extends Circle {
  private double height;

  public Cylinder(int x, int y, double radius, double height) {
    super(x, y, radius);
    this.height = height;
  }

  public double volume() {
    return area() * height;
  }

  public double getHeight() {
    return height;
  }

  public void setHeight(double height) {
    this.height = height;
  }

}
