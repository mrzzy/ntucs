public class Sphere extends Circle {
  public Sphere(double radius) {
    super(radius);
  }

  @Override
  public double surfaceArea() {
    return 4.0 / 3.0 * area();
  }
}
