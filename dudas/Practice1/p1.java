package Practice1;
public class p1{
  public static void main (String[] args){
    abs frutas = new abs("hey");

    frutas[0] = new mango("MAngo,","Amarillo", 1);

    for (abs a : frutas)
      System.out.println(a.getName() + " , soy de color: " + a.getColor());
  }
}
