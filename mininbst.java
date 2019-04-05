//PROBLEM 1 
//java code
//find min node in a binary search tree;
class Node{
    int data;
    Node left,right;
    Node(int data){
        this.data=data;
        left=null;
        right=null;
    }
}
class Bst{
    void inorder(Node node){
        if(node==null){
            return;
        }
        inorder(node.left);
        System.out.println(node.data);
        inorder(node.right);
    }
    Node insert(Node node,int data){
        if (node == null) { 
            return (new Node(data)); 
          }
        if (data <= node.data) { 
                node.left = insert(node.left, data); 
        } else { 
                node.right = insert(node.right, data); 
        } 
        return node; 
    }
    void minvalue(Node node){
        Node current=node;
        while(current.left!=null){
            current=current.left;
        }
        System.out.println(current.data);
    }
    public static void main(String[] args){
        Bst tree=new Bst();
        Node root=null;
        root=tree.insert(root,10);
        System.out.println(root);
        root=tree.insert(root,20);
        System.out.println(root);
        root=tree.insert(root,30);
        root=tree.insert(root,40);
        root=tree.insert(root,70);
        root=tree.insert(root,50);
        System.out.println(root);
        root=tree.insert(root,60);
        System.out.println(root);
        tree.minvalue(root);
    }
}