import java.awt.*;
import java.awt.image.BufferStrategy;

public class Game extends Canvas implements Runnable {

    public static final float     Height = 480;
    public static final float     Width  = 640;
    public static       int     frames = 0;
    public static       int     FPS    = 0;
    private              Thread     thread;
    private              boolean    Running      = false;

    public Game ( ) {
        new Window ( Width,Height,"Snake",this );
        this.addKeyListener ( new KeyboardInput () );
        ObjectsStorage.addGameObjects ( new Snake ( Maths.random ( 0,Width-100 ),Maths.random ( 0,Height-100 ),ObjectsID.Snake ) );
    }

    public synchronized void start ( ) {
        thread = new Thread ( this );
        thread.start ( );
        Running = true;

    }

    public synchronized void stop ( ) {
        try {
            thread.join ( );
            Running = false;
        } catch (Exception e) {
            e.printStackTrace ( );
        }
    }

    public void run ( ) {
        this.requestFocus ( );
        double delta = 0;
        double amountOfTricks = 60.0;
        long lastTime = System.nanoTime ( );
        double ns = 1000000000 / amountOfTricks;
        long timer = System.currentTimeMillis ( );
        while (Running) {
            long now = System.nanoTime ( );
            delta += ( now - lastTime ) / ns;
            lastTime = now;
            while (delta >= 1) {
                CalculateProcess ( );
                delta--;
            }
            if ( Running )
                RenderGraphics ( );
            frames++;
            if ( System.currentTimeMillis ( ) - timer > 1000 ) {
                timer += 1000;
                FPS    = frames;
                frames = 0;
            }
        }
        stop ( );
    }

    private void CalculateProcess ( ) {
        ObjectsStorage.CalculateProcess ();
    }

    private void RenderGraphics ( ) {
        BufferStrategy bs = this.getBufferStrategy ( );
        if ( bs == null ) {
            this.createBufferStrategy ( 3 );
            return;
        }
        Graphics G = bs.getDrawGraphics ( );
        G.setColor ( Color.BLACK );
        G.fillRect ( 0,0,(int)Width,(int)Height );
        ObjectsStorage.RenderGraphics ( G );
        G.dispose ( );
        bs.show ( );
    }
}