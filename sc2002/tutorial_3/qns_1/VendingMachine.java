/*
 * SC2002
 * Tutorial 3
 * Question 1
*/

import java.util.Scanner;

public class VendingMachine {
  private final Scanner stdin = new Scanner(System.in);

  // constructor
  public VendingMachine() {
  }

  public void run() {
    double drinkCost = selectDrink();
    double amount = insertCoins(drinkCost);
    checkChange(amount, drinkCost);
    printReceipt();
  }

  // get the drink selection, and return the cost of the drink
  private double selectDrink() {
    System.out.println("====== Vending Machine ======");
    System.out.println(" 1. Buy Beer ($3.00)      |");
    System.out.println(" 2. Buy Coke ($1.00)      |");
    System.out.println(" 3. Buy Green Tea ($5.00) |");
    System.out.println("===========================");
    System.out.println("Please enter selection:");
    int drink = stdin.nextInt();
    switch (drink) {
      case 1:
        // beer
        return 3.0;
      case 2:
        // Coke
        return 1.0;
      case 3:
        // Green Tea
        return 5.0;
      default:
        throw new IllegalArgumentException(String.format("Invalid drink: %d", drink));
    }
  }

  // insert the coins and returns the amount inserted
  private double insertCoins(double drinkCost) {
    System.out.println("========= Coins Input ============");
    System.out.println("|Enter 'Q' for ten cents input   |");
    System.out.println("|Enter 'T' for twenty cents input|");
    System.out.println("|Enter 'F' for fifty cents input |");
    System.out.println("|Enter 'N' for a dollar input    |");
    System.out.println("==================================");

    double inserted = 0.0;
    while (inserted < drinkCost) {
      System.out.println("Please insert coins: ");
      switch (stdin.next().charAt(0)) {
        case 'Q':
          inserted += 0.1;
          break;
        case 'T':
          inserted += 0.2;
          break;
        case 'F':
          inserted += 0.5;
          break;
        case 'N':
          inserted += 1.0;
          break;
      }
    }
    return inserted;
  }

  // check the change and print the change on screen
  private void checkChange(double amount, double drinkCost) {
    System.out.printf("Change: $%.2f\n", amount - drinkCost);
  }

  // print the receipt and collect the drink
  private void printReceipt() {
    System.out.println("Please collect your drink");
    System.out.println("Thank You !!");
  }
}
