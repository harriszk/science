package calculator;

public class AdditionNode extends BinaryNode {

    public AdditionNode(Node left, Node right)
    {
        super(left, right);
    } // end cosntructor

    @Override
    public double evaluate(double n1, double n2) {
        return n1 + n2;
    }
    
} // end AdditionNode
