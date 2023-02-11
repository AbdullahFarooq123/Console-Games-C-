import javax.swing.*;
import java.awt.*;

public class Window extends Canvas {

    public Window ( float Width , float Height , String Title , Game game ) {

        JFrame Frame = new JFrame ( Title );
        Frame.setPreferredSize ( new Dimension ( (int)Width , (int)Height ) );
        Frame.setMaximumSize ( new Dimension ( (int)Width , (int)Height ) );
        Frame.setMinimumSize ( new Dimension ((int) Width ,(int) Height ) );
        Frame.setDefaultCloseOperation ( JFrame.EXIT_ON_CLOSE );
        Frame.setResizable ( false );
        Frame.setLocationRelativeTo ( null );
        Frame.add ( game );
        Frame.setVisible ( true );
        game.start ( );

    }
}
