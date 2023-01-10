public class Driver {
    public static void main(String[] args)
    {
        // 5 * 4 / 5 = 4
        Node n1 = new NumberNode(5);
        Node n2 = new NumberNode(4);
        Node n3 = new NumberNode(8);
        Node e1 = new MultiplicationNode(n1, n2);
        Node e2 = new DivisionNode(e1, n1);

        System.out.println(e2.evaluate());
    } // end main
} // end Driver
