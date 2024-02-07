import java.util.Scanner;

class P3 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int init, end, increment;
    init = scanner.nextInt();
    end = scanner.nextInt();
    increment = scanner.nextInt();
    scanner.close();

    // for loop
    final double fxRate = 1.82;
    for (int i = init; i <= end; i += increment) {
      System.out.printf("%d US dollar(US$) = %s Singapore dollars (S$)\n", i, i * fxRate);
    }

    // while loop
    int i = init;
    while (i <= end) {
      System.out.printf("%d US dollar(US$) = %s Singapore dollars (S$)\n", i, i * fxRate);
      i += increment;
    }

    // while loop
    i = init;
    do {
      System.out.printf("%d US dollar(US$) = %s Singapore dollars (S$)\n", i, i * fxRate);
      i += increment;
    } while (i <= end);
  }
}
