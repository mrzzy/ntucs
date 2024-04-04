class Cylinder implements Shape {
  private Circle base;
  private double height;

  public Cylinder(Circle base, double height) {
    this.base = base;
    this.height = height;
  }

  @Override
  public double surfaceArea() {
    return 2 * base.area() + 2 * Math.PI * base.getRadius() * height;
  }

  public Circle getBase() {
    return base;
  }

  public double getHeight() {
    return height;
  }
}
