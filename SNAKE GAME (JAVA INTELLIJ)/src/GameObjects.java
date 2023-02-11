import java.awt.*;

public abstract class GameObjects {
    public double XCoordinate ;
    public double YCoordinate ;
    public ObjectsID ID ;
    protected double XVelocity ;
    protected double YVelocity ;
    public GameObjects(double XCoordinate,double YCoordinate ,ObjectsID ID){
        this.XCoordinate=XCoordinate;
        this.YCoordinate=YCoordinate;
        this.ID=ID;
    }
    public abstract void RenderGraphics( Graphics G );
    public abstract void CalculateProcess();
    public double getXVelocity(){
        return XVelocity;
    }
    public double getYVelocity(){
        return YVelocity;
    }
    public void setXVelocity(double XVelocity){
        this.XVelocity=XVelocity;
    }
    public void setYVelocity(double YVelocity){
        this.YVelocity=YVelocity;
    }
}
