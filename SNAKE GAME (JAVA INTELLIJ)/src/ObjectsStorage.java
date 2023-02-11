import java.awt.*;
import java.util.ArrayList;

public class ObjectsStorage {
    public static ArrayList <GameObjects> objects = new ArrayList<> (  );
    public static void RenderGraphics( Graphics G  ){
        for(int i = 0 ; i < objects.size ();i++) {
            GameObjects tempObject = objects.get ( i );
                    tempObject.RenderGraphics ( G );
        }
    }
    public static void CalculateProcess(){
        for(int i = 0 ; i < objects.size ();i++) {
            GameObjects tempObject = objects.get ( i );
            tempObject.CalculateProcess ();
        }
    }
    public static void addGameObjects(GameObjects object){
        objects.add ( object );
    }
}
