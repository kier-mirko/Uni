public class App 
{
    public static void main( String[] args ) {
	int[] num = new int[5];

	for(int i = 0; i < num.length; ++i) {
	    num[i] = Integer.parseInt(args[i]);
	}

	int n = Integer.parseInt(args[5]);

	int[] copy = new int[5];

	for(int i = 0; i < copy.length; ++i) {
	    copy[i] = num[i];
	}
	System.out.println();
	for(int i = 0; i < copy.length; ++i) {
	    System.out.print(copy[i] + "\t");
	}

	Methods.editArray(copy, n);

	for(int i = 0; i < num.length; ++i) {
	    System.out.print(num[i] + "\t");
	}

	System.out.println();
	for(int i = 0; i < copy.length; ++i) {
	    System.out.print(copy[i] + "\t");
	}

	switch(Methods.areEqual(num, copy)) {
	case -1:
	    System.out.println("Error: arrays length are not equal");
	    break;
	case 0:
	    System.out.println();
	    for(int i = 0; i < copy.length; ++i) {
		System.out.print(copy[i] + "\t");
	    }
	    break;
	default:
	    System.out.println();
	    for(int i = 0; i < num.length; ++i) {
		System.out.print(num[i] + "\t");
	    }
	}
	System.out.println();
    }
}
