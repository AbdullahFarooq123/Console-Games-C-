import java.awt.*;

public class Snake extends GameObjects{

    public Snake ( double XCoordinate , double YCoordinate , ObjectsID ID ) {
        super ( XCoordinate , YCoordinate , ID );
    }

    public void RenderGraphics ( Graphics G ) {
        G.setColor ( Color.GREEN );
        G.fillRect ( (int)XCoordinate,(int)YCoordinate,20,20 );
    }

    public void CalculateProcess ( ) {
        XCoordinate+=XVelocity;
        YCoordinate+=YVelocity;
    }
}
