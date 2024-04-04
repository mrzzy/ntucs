class Cuboid implements Shape {
  private Rectangle base;
  private double height;

  public Cuboid(Rectangle base, double height) {
    this.base = base;
    this.height = height;
  }

  @Override
  public double surfaceArea() {
    return 2 * base.area() + 2 * base.getWidth() * height + 2 * base.getLength() * height;
  }
}
