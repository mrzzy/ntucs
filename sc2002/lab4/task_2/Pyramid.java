class Pyrmaid implements Shape {
  private Square base;
  private Triangle side;

  public Pyrmaid(Square base, Triangle side) {
    this.base = base;
    this.side = side;
  }

  @Override
  public double surfaceArea() {
    return base.area() + 4 * side.area();
  }
}
