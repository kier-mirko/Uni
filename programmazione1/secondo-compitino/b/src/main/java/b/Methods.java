public class Methods {
    public static void editArray(char[] copy, char c) {
	int count = 0;
	
	for(int i = 0; i < copy.length; ++i) {
	    if(copy[i] == c)
		++count;
	}

	if(count == 0) {
	    for(int i = 0; i < copy.length; ++i) {
		if(i % 2 == 0)
		    copy[i] = c;
	    }
	} else if(count < copy.length) {
	    for(int i = 0; i < copy.length; ++i) {
		if(i % 2 == 1)
		    copy[i] = c;
	    }
	}
    }

    public static int areEqual(char[] ch, char[] copy) {
	if(ch.length == copy.length) {
	    for(int i = 0; i < ch.length; ++i) {
		if(ch[i] != copy[i])
		    return 1;
	    }
	    return 0;
	} else {
	    return -1;
	}
    }
}
