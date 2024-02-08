public class Circle {
  private double radius;
  // radius of circle
  private static final double PI = 3.14159;

  // constructor
  public Circle(double radius) {
    this.radius = radius;
  }

  // mutator method – set radius
  public void setRadius(double radius) {
    this.radius = radius;
  }

  // accessor method – get radius
  public double getRadius() {
    return radius;
  }

  // calculate area
  public double area() {
    return Math.pow(radius, 2) * PI;
  }

  // calculate circumference
  public double circumference() {
    return radius * 2;
  }

  // print area
  public void printArea() {
    System.out.println(area());
  }

  // print circumference
  public void printCircumference() {
    System.out.println(circumference());
  }

}
