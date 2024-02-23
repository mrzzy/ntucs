/*
 * SC2002
 * Tutorial 3
 * Question 2
*/

class Point {
  private int x;
  private int y;

  Point(int x, int y) {
    setPoint(x, y);
  }

  @Override
  public String toString() {
    return String.format("[%d, %d]", this.x, this.y);
  }

  void setPoint(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public int getX() {
    return x;
  }

  public int getY() {
    return y;
  }

}
