class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data=data;
        left=null;
        right=null;
    }
}
class Bst{
    static int[] arr=new int[6];
    static int i=0;
    void inorder(Node root){
        
        if(root==null){
            return;
        }
        inorder(root.left);
        //System.out.println(root.data);
        arr[i]=root.data;
        i=i+1;
        inorder(root.right);
    }
    void inorderabc(Node root){
        
        if(root==null){
            return;
        }
        inorderabc(root.left);
        System.out.println(root.data);
        inorderabc(root.right);
    }
    Node sortedArrayToBST(int arr[], int start, int end) { 
        if (start > end) { 
            return null; 
        } 
        int mid = (start + end) / 2; 
        Node temp = new Node(arr[mid]);
        temp.left = sortedArrayToBST(arr, start, mid - 1); 
        temp.right = sortedArrayToBST(arr, mid + 1, end); 
        return temp; 
    } 
    Node insert(Node node,int data){
        if(node==null){
            Node temp=new Node(data);
            return temp;
        }
        else if(data>node.data){
            node.right=insert(node.right,data);
        }
        else if(data<=node.data){
            node.left=insert(node.left,data);
        }
        return node;
    }
    public static void main(String args[]){
        Bst tree=new Bst();
        Node root=null;
        Node ans;
        root=tree.insert(root,10);
        root=tree.insert(root,20);
        root=tree.insert(root,30);
        root=tree.insert(root,40);
        root=tree.insert(root,50);
        root=tree.insert(root,60);
        tree.inorder(root);
        ans=tree.sortedArrayToBST(tree.arr, 0, 5); 
        tree.inorderabc(ans);
        
    }
}