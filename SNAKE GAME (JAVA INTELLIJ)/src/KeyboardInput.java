import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Arrays;

public class KeyboardInput extends KeyAdapter {
    private final boolean[] keyReleased = new boolean[4];
    public KeyboardInput(){
        Arrays.fill ( keyReleased,false );
    }
    public void keyPressed ( KeyEvent key ) {
        for(GameObjects object : ObjectsStorage.objects) {
            if ( object.ID == ObjectsID.Snake ) {
                if ( key.getKeyCode ( ) == KeyEvent.VK_UP ) {
                    object.setYVelocity ( -5 );
                    keyReleased[0]=true;
                }
                if ( key.getKeyCode ( ) == KeyEvent.VK_DOWN ) {
                    object.setYVelocity ( 5 );
                    keyReleased[1]=true;
                }
                if ( key.getKeyCode ( ) == KeyEvent.VK_LEFT ) {
                    object.setXVelocity ( -5 );
                    keyReleased[2]=true;
                }
                if ( key.getKeyCode ( ) == KeyEvent.VK_RIGHT ) {
                    object.setXVelocity ( 5 );
                    keyReleased[3]=true;
                }
            }
        }
    }
    public void keyReleased(KeyEvent key){
        for(GameObjects object : ObjectsStorage.objects) {
            if ( object.ID == ObjectsID.Snake ) {
                if ( key.getKeyCode ( ) == KeyEvent.VK_UP ) {
                    keyReleased[0]=false;
                }
                if ( key.getKeyCode ( ) == KeyEvent.VK_DOWN ) {
                    keyReleased[1]=false;
                }
                if ( key.getKeyCode ( ) == KeyEvent.VK_LEFT ) {
                    keyReleased[2]=false;
                }
                if ( key.getKeyCode ( ) == KeyEvent.VK_RIGHT ) {
                    keyReleased[3]=false;
                }
                if(!keyReleased[0]&&!keyReleased[1]) object.setYVelocity ( 0 );
                if(!keyReleased[2]&&!keyReleased[3]) object.setXVelocity ( 0 );
            }
        }
    }
}
