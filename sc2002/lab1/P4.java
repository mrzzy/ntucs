import java.util.Scanner;

class P4 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int height = scanner.nextInt();
    scanner.close();

    if (height == 0) {
      System.out.println("Error input");
      System.exit(1);
    }
    for (int i = 0; i < height; i++) {
      boolean isA = i % 2 == 0;
      for (int j = 0; j <= i; j++) {
        char c = (isA) ? 'A' : 'B';
        System.out.printf("%c%c", c, c);
        isA = !isA;
      }
      System.out.println();
    }
  }
}
