package calculator;

public abstract class BinaryNode implements Node {
    protected Node left;
    protected Node right;

    public BinaryNode(Node left, Node right)
    {
        this.left = left;
        this.right = right;
    } // end constructor

    @Override
    public double evaluate() {
        double n1 = this.left.evaluate();
        double n2 = this.right.evaluate();
        return this.evaluate(n1, n2);
    }
    
    public abstract double evaluate(double n1, double n2);
} // end BinaryNode
