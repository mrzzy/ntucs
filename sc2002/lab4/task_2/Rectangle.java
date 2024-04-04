class Rectangle implements Shape {
  private double length;
  private double width;

  public Rectangle(double length, double width) {
    this.length = length;
    this.width = width;
  }

  @Override
  public String name() {
    return "rectangle";
  }

  @Override
  public double area() {
    return length * width;
  }

  public double getLength() {
    return length;
  }

  public double getWidth() {
    return width;
  }
}
