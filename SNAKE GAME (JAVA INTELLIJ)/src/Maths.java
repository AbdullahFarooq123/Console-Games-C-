import java.util.Random;

public class Maths {
    public static double random ( double min , double max ) {
        int value = ( int ) ( min + ( new Random ( ).nextDouble ( ) * ( max - min ) ) );
        return value == 0 ? value + 1 : value;
    }
}
