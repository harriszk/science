public class MultiplicationNode extends BinaryNode {
    public MultiplicationNode(Node left, Node right) {
        super(left, right);
    } // end constructor

    @Override
    public int evaluate(int n1, int n2) {
        return n1 * n2;
    }
} // end MultiplicationNode
