package Practice1{
public class mango extends abs{

  private int semillas;
  public mango (String name, int color, int semillas){
    super(name);
    this.color = color;
  }
   private String getColor(){
      return String.format("Es amarillo", color);
    }

}
}
