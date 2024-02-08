import java.util.Random;

class Dice {
  private int valueOfDice;

  public Dice() {
    Random random = new Random();
    // random value 1-6
    this.valueOfDice = random.nextInt(6) + 1;
  }

  public int getValueOfDice() {
    return valueOfDice;
  }

  public void setValueOfDice(int valueOfDice) {
    this.valueOfDice = valueOfDice;
  }

  public void printDiceValue() {
    System.out.println(getValueOfDice());
  }
}
