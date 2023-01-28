import java.util.Scanner;

public class App {
    public static void main( String[] args ) {
	Scanner in = new Scanner(System.in);

	System.out.println("Inserisci n: ");
	int n = in.nextInt();
	int[] num = new int[n];

	System.out.println("Inserisci i valori: ");
	for(int i = 0; i < num.length; ++i) {
	    num[i] = in.nextInt();
	}

	int a, b;
	System.out.println("Inserisci a e b: ");
	do {
	    a = in.nextInt();
	    b = in.nextInt();
	} while(a >= b);

	int[] copy = new int[num.length];
	for(int i = 0; i < copy.length; ++i) {
	    copy[i] = num[i];
	}

	Methods.occorrenzeElementi(copy, a, b);

	System.out.println("originale: ");
	for(int i = 0; i < num.length; ++i) {
	    System.out.print(num[i] + "\t");
	}
	
	System.out.println("\ncopia: ");
	int count = 0;
	for(int i = 0; i < copy.length; ++i) {
	    System.out.print(copy[i] + "\t");
	    if(copy[i] != num[i])
		++count;
	}
	System.out.println();

	if(count > num.length / 2) {
	    int[] union = Methods.modificaElementi(num, copy);
	    System.out.println("union: ");
	    for(int i = 0; i < union.length; ++i) {
		System.out.print(union[i] + "\t");
	    }
	    System.out.println();
	}
    }
}
