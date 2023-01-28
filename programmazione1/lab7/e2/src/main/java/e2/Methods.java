import java.lang.Math;
import java.util.Random;

public class Methods {
    public static int[][] newWorld() {
	int[][] world = new int[20][20];

	for(int i = 0; i < world.length; ++i) {
	    for(int j = 0; j < world[0].length; ++j) {
		world[i][j] = 0;
	    }
	}
	return world;
    }

    public static boolean addGoal(int[][] world, int row, int col) {
	if(row >= 0 && row <= 19 && col >= 0 && col <= 19 && world[row][col] == 0) {
	    world[row][col] = 1;
	    return true;
	}
	return false;
    }

    public static void initObstacle(int[][] world) {
	Random rand = new Random();
	for(int i = 0; i < 10; ++i) {
	    int row = rand.nextInt(20);
	    int col = rand.nextInt(20);
	    while(world[row][col] != 0) {
		row = rand.nextInt(20);
		col = rand.nextInt(20);
	    }
	    world[row][col] = 2;
	}
    }

    public static int putRobotPositions(int[][] world, String path) {
	int robotY = 0;
	int robotX = 0;

	for(int i = 0; i < path.length(); ++i) {
	    if(robotY < 0 || robotY > 19 || robotX < 0 || robotX > 19) {
		return 3;
	    } else if(world[robotY][robotX] == 1) {
		return 1;
	    } else if(world[robotY][robotX] == 2) {
		return 2;
	    } else {
		world[robotY][robotX] = 3;
		switch(path.charAt(i)) {
		case 's':
		    ++robotY;
		    break;
		case 'n':
		    --robotY;
		    break;
		case 'e':
		    ++robotX;
		    break;
		case 'o':
		    --robotX;
		    break;
		}
	    }
	}
	return 0;
    }

    public static void printWorld(int[][] world) {
	System.out.println("**********************");
	for(int i = 0; i < world.length; ++i) {
	    System.out.print("*");
	    for(int j = 0; j < world[0].length; ++j) {
		switch(world[i][j]) {
		case 0:
		    System.out.print(" ");
		    break;
		case 1:
		    System.out.print("X");
		    break;
		case 2:
		    System.out.print("#");
		    break;
		case 3:
		    System.out.print("O");
		    break;
		}
	    }
	    System.out.println("*");
	}
	System.out.println("**********************");
    }
}
