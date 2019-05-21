import java.util.*;
class Graph{
    private int v;
    private LinkedList<Integer> adj[];
    Graph(int v){
      this.v=v;
      adj=new LinkedList[v];
      for(int i=0;i<v;i++){
          adj[i]=new LinkedList();
      }
    }
    void addEdge(int x,int y){
        adj[x].add(y);
    }
    void funct(int v,boolean visited[],Stack stack){
        visited[v]=true;
        Integer i;
        Iterator<Integer> it=adj[v].iterator();
        while(it.hasNext()){
            i=it.next();
            if(visited[i]==false){
                funct(i, visited, stack); 
            }
        }
        stack.push(new Integer(v)); 
    }
    void topologicalsort(){
        Stack stack=new Stack();
        boolean visited[]=new boolean[v];
        for(int i=0;i<v;i++){
            visited[i]=false;
        }
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                funct(i,visited,stack);
            }
        }
        while(stack.empty()==false){
            System.out.println(stack.pop() + " ");
        }
    }
    public static void main(String args[]) 
    { 
        // Create a graph given in the above diagram 
        Graph g = new Graph(6); 
        g.addEdge(5, 2); 
        g.addEdge(5, 0); 
        g.addEdge(4, 0); 
        g.addEdge(4, 1); 
        g.addEdge(2, 3); 
        g.addEdge(3, 1); 
  
        System.out.println("Following is a Topological " + 
                           "sort of the given graph"); 
        g.topologicalsort(); 
    } 
    
}