public class App {
    public static void main( String[] args ){
	int n = 20;
	int m = 20;
	int[] matrix = Methods.newMatrix(n, m);
	Methods.writeElement(matrix, n, m, 0, 0, 1);
	Methods.writeElement(matrix, n, m, 0, 1, 2);
	Methods.writeElement(matrix, n, m, 0, 2, 3);
	Methods.writeElement(matrix, n, m, 0, 3, 4);
	Methods.writeElement(matrix, 10, m, 19, 19, 20);
	Methods.printMatrix(matrix, n, m);
	
    }
}
