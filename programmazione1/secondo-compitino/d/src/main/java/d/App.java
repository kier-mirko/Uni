public class App {
    public static void main( String[] args ) {
	char[] even = new char[(args[0].length() / 2) + args[0].length() % 2];
	char[] odd = new char[args[0].length() / 2];

	for(int i = 0, j = 0, k = 0; i < args[0].length(); ++i) {
	    if(i % 2 == 0)
		even[j++] = args[0].charAt(i);
	    else
		odd[k++] = args[0].charAt(i);
	}

	char[] copy = new char[odd.length];
	for(int i = 0; i < odd.length; ++i) {
	    copy[i] = odd[i];
	}
	
	System.out.println("pari: ");
	for(int i = 0; i < even.length; ++i) {
	    System.out.print(even[i] + "\t");
	}
	System.out.println("\ndispari: ");
	for(int i = 0; i < odd.length; ++i) {
	    System.out.print(odd[i] + "\t");
	}
	System.out.println();

	Methods.editArray(even, odd);

	System.out.println("pari: ");
	for(int i = 0; i < even.length; ++i) {
	    System.out.print(even[i] + "\t");
	}
	System.out.println("\ndispari: ");
	boolean modificato = false;
	for(int i = 0; i < odd.length; ++i) {
	    System.out.print(odd[i] + "\t");
	    if(copy[i] != odd[i])
		modificato = true;
	}
	System.out.println();

	if(modificato) {
	    System.out.println(Methods.union(even, odd));
	}
    }
}
