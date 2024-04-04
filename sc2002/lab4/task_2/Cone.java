class Cone implements Shape {
  private Circle base;
  private double height;

  public Cone(Circle base, double height) {
    this.base = base;
    this.height = height;
  }

  @Override
  public double surfaceArea() {
    return base.area() + Math.sqrt(Math.pow(base.getRadius(), 2) + Math.pow(height, 2));
  }

  public Circle getBase() {
    return base;
  }

  public double getHeight() {
    return height;
  }
}
