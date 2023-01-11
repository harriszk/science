package calculator;
/**
 * NumberNode.java
 */
public class NumberNode implements Node {
    // Numbers are stored in scientific notation.
    // i.e. (coefficient) * 10^(exponenet)
    private double number;
    private int significant_digits;

    public NumberNode(double number) {
        this.number = number;
    }

    public NumberNode(double coefficient, int exponenet) {
        this.number = Double.parseDouble(coefficient + "E" + exponenet);
    }

    @Override
    public double evaluate() {
        return number;
    }
    
} // end NumberNode
