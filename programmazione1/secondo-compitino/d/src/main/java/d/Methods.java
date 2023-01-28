public class Methods {
    public static void editArray(char[] even, char[] odd) {
	if(even.length < odd.length) {
	    for(int i = 0; i < even.length; ++i) {
		switch(even[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		    even[i] = (char) (even[i] - 'a' + 'A');
		    break;
		}
	    }
	} else if(even.length > odd.length) {
	    for(int i = 0; i < odd.length; ++i) {
		switch(odd[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		    break;
		default:
		    odd[i] = (char) (odd[i] - 'a' + 'A');
		}
	    }
	}
    }

    public static String union(char[] even, char[] odd) {
	return String.valueOf(even) + String.valueOf(odd);
    }
}
