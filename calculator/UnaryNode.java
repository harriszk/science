package calculator;

public abstract class UnaryNode implements Node {
    protected Node child;

    public UnaryNode(Node child) {
        this.child = child;
    } // end constructor

    @Override
    public double evaluate() {
        return this.child.evaluate();
    } // end evaluate
} // end UnaryNode
