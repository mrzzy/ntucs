/*
 * SC2002
 * Tutorial 3
 * Question 1
*/

class Circle extends Point {
  private double radius;

  public Circle(int x, int y, double radius) {
    super(x, y);
    this.radius = radius;
  }

  public double getRadius() {
    return radius;
  }

  public void setRadius(double radius) {
    this.radius = radius;
  }

  public double area() {
    return Math.PI * Math.pow(radius, 2.0);
  }
}
