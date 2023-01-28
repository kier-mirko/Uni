public class App {
    public static void main( String[] args ) {
	int[][] world = Methods.newWorld();
	Methods.addGoal(world, Integer.parseInt(args[0]), Integer.parseInt(args[1]));
	Methods.initObstacle(world);
	Methods.putRobotPositions(world, args[2]);
	Methods.printWorld(world);
    }
}

