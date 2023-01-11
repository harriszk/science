package calculator;

public class SubtractionNode extends BinaryNode {
    public SubtractionNode(Node left, Node right) {
        super(left, right);
    } // end constructor

    @Override
    public double evaluate(double n1, double n2) {
        return n1 - n2;
    }    
} // end SubtractionNode
