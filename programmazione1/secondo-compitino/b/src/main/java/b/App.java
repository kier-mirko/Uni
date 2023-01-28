public class App {
    public static void main( String[] args ) {
        char[] ch = new char[5];

	for(int i = 0; i < ch.length; ++i) {
	    ch[i] = args[i].charAt(0);
	}

	char c = args[5].charAt(0);

	char[] copy = new char[5];
	for(int i = 0; i < copy.length; ++i) {
	    copy[i] = ch[i];
	}

	Methods.editArray(copy, c);
	
	System.out.println("array caratteri:");
	for(int i = 0; i < ch.length; ++i) {
	    System.out.print(ch[i] + "\t");
	}
	System.out.println("\ncopia array:");
	for(int i = 0; i < copy.length; ++i) {
	    System.out.print(copy[i] + "\t");
	}
	System.out.println();

	switch(Methods.areEqual(ch, copy)) {
	case -1:
	    System.out.println("error: arrays length are not equal");
	    break;
	case 0:
	    System.out.println("copia");
	    for(int i = 0; i < copy.length; ++i) {
		System.out.print(copy[i] + "\t");
	    }
	    System.out.println();
	    break;
	default:
	    System.out.println("originale");
	    for(int i = 0; i < ch.length; ++i) {
		System.out.print(ch[i] + "\t");
	    }
	    System.out.println();
	    break;
	}
    }
}
