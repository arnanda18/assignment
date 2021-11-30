class Node{
    public int data;
    public Node next;
}

public class myStack{
    Node atas;

    boolean isEmpty(){
        return atas == null;
    }

    void masuk(int value){
        Node baru = new Node();
        baru.data = value;
        if(isEmpty()){
            atas = baru;
            baru.next = null;
        }
        else{
            baru.next = atas;
            atas = baru;
        }
        System.out.println("Masuk ke Stack dengan value : " + value);
    }

    void keluar(){
        if(isEmpty()){
            System.out.println("Tidak dapat kelaur, stack kosong!");
            return;
        }

        Node temp = atas;
        atas = atas.next;
        System.out.println("Keluar dari Stack dengan value: " + temp.data);
    }
    int jumlah_node(){
        if(isEmpty()){
            System.out.println("Tidak dapat menghitung, stack kosong");
            return 0;
        }
        Node temp = atas;
        int count = 0;
        while(temp != null){
            temp = temp.next;
            count++;
        }
        return count;
    }

    void remove_all_node(){
        if(isEmpty()){
            System.out.println("Tidak dapat menghapus node, stack Kosong");
            return;
        }
        Node temp = atas;
        System.out.println("\n------- Bagian Delete Node --------");
        while(temp != null){
            System.out.println("hapus node -> " + temp.data);
            temp = temp.next;
            
           
            if(temp !=null){
                atas = temp;
            }
        }
        System.out.println("------ Akhir delete Node -----\n");
    }

    void display(){
        if(isEmpty()){
            System.out.println("Tidak dapat ditampilkan, Stack kosong");
            return;
        }

        Node temp = atas;
        int count = jumlah_node();
        System.out.println("\n-------Bagian Display Node --------");
        while(temp != null){
            System.out.println("Node " + count + " -> " + temp.data);
            temp = temp.next;
            count--;
        }
        System.out.println("----------- Akhir Display Node -------\n");
    }

    public static void main(String[]args){
        myStack stk = new myStack();
        stk.masuk(2);
        stk.masuk(8);
        stk.masuk(6);
        stk.masuk(2);
        stk.masuk(5);

        stk.display();

        stk.keluar();
        stk.keluar();
        stk.display();

        stk.masuk(11);
        stk.display();

        stk.remove_all_node();
    }
};
