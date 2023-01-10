/**
 * NumberNode.java
 */
public class NumberNode implements Node {
    // Numbers are stored in scientific notation.
    // i.e. (coefficient) * 10^(exponenet)
    private double coefficient;
    private int exponent;
    private int significant_digits;

    private int number;

    public NumberNode(int number) {
        this.number = number;
    }

    @Override
    public int evaluate() {
        return number;
    }
    
} // end NumberNode
