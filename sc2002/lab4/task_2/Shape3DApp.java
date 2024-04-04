import java.util.Arrays;

class Shape3DApp {
  public static void main(String[] args) {
    // read shapes
    Shape[] shapes = new Shape[] {
        new Sphere(10),
        new Cone(new Circle(5), 25),
        new Cylinder(new Circle(5), 20),
    };
    // perform calculation on shapes and sum
    System.out.println("Result: " + Arrays.stream(shapes).map(Shape::surfaceArea).reduce(0.0, Double::sum));
  }
}
