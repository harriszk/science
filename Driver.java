import calculator.*;

public class Driver {
    public static void main(String[] args)
    {
        // (2.29 * 10^6) / (6.7 * 10^4) = 0.34 * 10^2
        Node n1 = new NumberNode(2.29, 6);
        Node n2 = new NumberNode(6.7, 4);
        Node n3 = new NumberNode(11);
        Node e1 = new MultiplicationNode(n1, n3);
        Node e2 = new DivisionNode(n1, n2);

        System.out.println(String.format("%6.3e",e1.evaluate()));
    } // end main
} // end Driver
