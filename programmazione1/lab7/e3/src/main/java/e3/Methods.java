public class Methods {
    public static int[] newMatrix(int n, int m) {
	int[] matrix = new int[n*m];
	for(int i = 0; i < matrix.length; ++i)
	    matrix[i] = 0;
	return matrix;
    }

    public static void writeElement(int[] matrix, int n, int m, int i, int j, int element) {
	if(n*m != matrix.length || i < 0 || i > n - 1 || j < 0 || j > m-1) {
	    System.out.println("Error");
	    System.exit(0);
	}

	matrix[i*n+j] = element;
    }

    public static int readElement(int[] matrix, int n, int m, int i, int j) {
	if(n*m != matrix.length || i < 0 || i > n - 1 || j < 0 || j > m-1) {
	    System.out.println("Error");
	    System.exit(0);
	}

	return matrix[i*n+j];
    }

    public static void printMatrix(int[] matrix, int n, int m) {
	for(int i = 0; i < n; ++i) {
	    for(int j = 0; j < m; ++j) {
		System.out.print(Methods.readElement(matrix, n, m, i, j));
	    }
	    System.out.println();
	}
    }
    
}
