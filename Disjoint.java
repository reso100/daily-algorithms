import java.util.*;
class Disjointset{
    public Map<Integer,Integer> parent=new HashMap();
    public void makeset(int[] universe){
        for(int i: universe){
            parent.put(i,i);
        }
    }
    public int find(int k){
        if(parent.get(k)==k){
            return k;
        }
        else{
            return find(parent.get(k));
        }
    }
    public void union(int a,int b){
        int x=find(a);
        int y=find(b);
        parent.put(x,y);
    }
    public static void print(int[] universe,Disjointset ds){
        for(int i:universe){
            System.out.print(ds.find(i) + " " );
        }
        System.out.println();
    }
    public static void main(String[] args){
        int[] universe = { 1, 2, 3, 4, 5 };
		Disjointset ds = new Disjointset();
		ds.makeset(universe);
		print(universe, ds);
		ds.union(4, 3);
		print(universe, ds);
		ds.union(2, 1);
		print(universe, ds);
		ds.union(1, 3);
		print(universe, ds);
    }
}