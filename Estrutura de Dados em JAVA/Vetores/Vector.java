public class Vector<T>{

  private T[] vector;
  int qtElements;

  public Vector(int capacity){
    this.vector = (T[]) new Object[capacity];
    this.qtElements = 0;
  }

  public boolean add(T t){
    //verifica se array está cheio
    if( qtElements != vector.length)
    {
      vector[qtElements] =  t;
      qtElements++;
      return true;
    }
    return false;
  }


  public boolean add(int position, T t){
    //verifica se array está cheio
    validate(position);
    if( qtElements != vector.length && vector[position] == null)
    {
      vector[position] =  t;
      qtElements++;
      return true;
    }
    return false;
  }

  public Object get(int position){
    //validate position
    validate(position);
    return vector[position];
  }

  public Object get(T t){
    int position = search(t);
    if(position >= 0)
      return vector[position];
    else
      return "not found";
  }

  public boolean remove(T t){
    int position = search(t);
    remove(position);
    return true;
  }

  public boolean remove(int position){
    validate(position);
    //se no final só remove
    if(position == qtElements){
      vector[position] = null;
      qtElements--;
      return true;
    }
    //entre elementos
    else if(0 < position && position < qtElements){
      vector[position] = null;
      for(int i = position; i < qtElements; i++){
        vector[i] = vector[i+1];
      }
      qtElements--;
      return true;
    }
    return false;
  }

  public int search(T t2) throws ArrayIndexOutOfBoundsException{
    int i = 0;
    for(T t: vector)
    {
      if(t != null)
      {
        if(t.equals(t2))
          return i;
        i++;
      }
    }

    return -1;
  }

  public int size(){
    return qtElements;
  }

  public boolean isNull(){
    return size() == -1;
  }

  public String toString(){
    if(isNull())
      return "[]";

    StringBuilder builder = new StringBuilder();
    builder.append("[");

    for(T t: vector)
    {
      builder.append(t);
      builder.append(", ");
    }
    //removendo caractere desnecessarios
    builder.deleteCharAt(builder.length() -1);
    builder.deleteCharAt(builder.length() -1);

    builder.append("]");
    return builder.toString();
  }

  private void validate(int position){
    //validate position
    if(isNull() || position > vector.length || position < 0)
      throw new ArrayIndexOutOfBoundsException("position out array size");
  }

  private void moreSpace(){
    T[] newVector = null;
    if(qtElements == vector.length){
      newVector =(T[]) new Object[vector.length*2];
    }

    for(int i = 0; i < vector.length; i++){
      newVector[i] = vector[i];
    }

    this.vector = newVector;
  }
}
