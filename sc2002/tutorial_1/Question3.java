import java.util.Scanner;

public class Question3 {

  private static void bubble(int a[], int n) {
    int i, j, t;
    for (i = n - 2; i >= 0; i--) {
      for (j = 0; j <= i; j++) {
        if (a[j] > a[j + 1]) {
          t = a[j];
          a[j] = a[j + 1];
          a[j + 1] = t;
        }
      }
    }
  }// end function.

  public static void main(String[] args) {
    int n, i;
    Scanner scanner = new Scanner(System.in);
    System.out.printf("\n\n Enter number of Integer elements to be sorted: ");
    // parse input
    n = scanner.nextInt();
    int[] a = new int[n];
    for (i = 0; i <= n - 1; i++) {
      System.out.printf("\n\n Enter integer value for element no.%d : ", i + 1);
      a[i] = scanner.nextInt();
    }
    scanner.close();

    bubble(a, n);

    // write sorted output
    System.out.printf("\n\n Finally sorted array is: ");
    for (i = 0; i <= n - 1; i++)
      System.out.printf("%d ", a[i]);
  }
}
// end program.
