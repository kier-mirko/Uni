package ES1;

import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args ) {
	int n;
	Scanner in = new Scanner(System.in);
	
	do {
	    System.out.print("Inserisci un numero > 0:");
	    n = in.nextInt();
	} while (n <= 0);

	int i;
	for (i = 1; i < n; i*=2) {
	    ;
	}

	System.out.println(i);
	in.close();
    }
}
