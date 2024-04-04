public interface Shape {
  public default String name() {
    return getClass().getName();
  }

  public default double area() {
    throw new UnsupportedOperationException("area() not implemented");
  }

  public default double surfaceArea() {
    throw new UnsupportedOperationException("surfaceArea() not implemented");
  }

  public default double volume() {
    throw new UnsupportedOperationException("volume() not implemented");
  }
}
