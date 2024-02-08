import java.util.Scanner;

class CircleApp {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    Circle c = null;
    while (true) {
      System.out.println(
          "==== Circle Computation ===== \n" +
              "|1. Create a new circle | \n" +
              "|2. Print Area | \n" +
              "|3. Print circumference | \n" +
              "|4. Quit |\n" +
              "============================= Choose option (1-3):");
      int choice = scanner.nextInt();
      switch (choice) {
        case 1:
          System.out.print("radius: ");
          c = new Circle(scanner.nextDouble());
          break;
        case 2:
          System.out.println(c);
          System.out.println((c == null) ? "No circle" : c.area());
          break;
        case 3:
          System.out.println((c == null) ? "No circle" : c.circumference());
          break;
        case 4:
          scanner.close();
          return;
        default:
          System.out.println("Invalid choice");
      }
    }
  }
}
