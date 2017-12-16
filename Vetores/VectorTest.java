class VectorTest{
  public static void main(String[] args){
    /*
    Vector<String> vector = new Vector(10);

    vector.add("teste1");
    vector.add("teste2");
    vector.add("teste3");
    vector.add("teste4");
    vector.add(8,"teste6");

    System.out.println(vector.get(1));
    System.out.println(vector.get(2));
    System.out.println(vector.get(0));

    System.out.println(vector.search("excella"));
    System.out.println(vector.toString());

    vector.remove("teste2");
    System.out.println(vector.toString());
    */

    Vector<Integer> vector = new Vector(10);

    vector.add(1);
    vector.add(1231);
    vector.add(45456);
    vector.add(555);
    vector.add(8,-342);

    System.out.println(vector.get(1));
    System.out.println(vector.get(2));
    System.out.println(vector.get(0));

    System.out.println(vector.search(1231));
    System.out.println(vector.toString());

    vector.remove((Integer) 1231);
    System.out.println(vector.toString());
  }

}
