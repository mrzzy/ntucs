import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.function.Function;

class Shape2DApp {

  private static Shape readShape(Scanner input) {
    System.out.println("Shapes: 0: Rectangle, 1: Circle, 2: Triangle, 3: Square");
    System.out.print("Enter choice of shape: ");
    int shapeChoice = input.nextInt();
    if (shapeChoice == 0) {
      System.out.print("length: ");
      double length = input.nextDouble();
      System.out.print("width: ");
      return new Rectangle(length, input.nextDouble());
    }
    if (shapeChoice == 1) {
      System.out.print("radius: ");
      return new Circle(input.nextDouble());
    }
    if (shapeChoice == 2) {
      System.out.print("base: ");
      double base = input.nextDouble();
      System.out.print("height: ");
      return new Triangle(base, input.nextDouble());
    }
    if (shapeChoice == 3) {
      System.out.print("length: ");
      return new Square(input.nextDouble());
    }

    throw new IllegalArgumentException("Unsupported Shape choice: " + shapeChoice);
  }

  private static Function<Shape, Double> readCalculation(Scanner input) {
    System.out.println("Calculation: 0: Area, 1: Volume, 2: SurfaceArea");
    System.out.print("Enter choice of calculation: ");
    int calculationChoice = input.nextInt();

    if (calculationChoice == 0) {
      // area
      return Shape::area;
    }
    if (calculationChoice == 1) {
      // volume
      return Shape::volume;
    }
    throw new IllegalArgumentException("Unsupported SurfaceArea choice: " + calculationChoice);
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    System.out.print("Enter total number of shapes:");
    int nShapes = input.nextInt();

    // read shapes
    List<Shape> shapes = new LinkedList<>();
    for (int i = 0; i < nShapes; i++) {
      shapes.add(readShape(input));
    }

    // read calculation
    Function<Shape, Double> calculation = readCalculation(input);
    input.close();

    // perform calculation on shapes and sum
    double result = shapes.stream().map(calculation).reduce(0.0, Double::sum);

    // output result
    System.out.println("Result: " + result);
  }
}
