package calculator;

public class DivisionNode extends BinaryNode {
    public DivisionNode(Node left, Node right) {
        super(left, right);
    } // end constructor

    @Override
    public double evaluate(double n1, double n2) {
        return n1 / n2;
    }
} // end DivisionNode