import java.io.*;
import java.util.*;

public class LinkedList {
	public static Node head;

	public static class Node {
		int data;
		Node next;

		public Node(int data){
			this.data = data;
			next = null;
		}
	}

	public void insertAtFront(int new_data)
	{

    	Node new_node = new Node(new_data);
    	new_node.next = head;
    	head = new_node;
	}

	public void insertAfter(Node prev_node, int new_data)
	{
  
    if (prev_node == null) {
        System.out.println(
            "The given node cannot be null");
        return;
    }
  
    	Node new_node = new Node(new_data);
    	new_node.next = prev_node.next;
    	prev_node.next = new_node;
	}

	public void append(int new_data)
	{
    
    	Node new_node = new Node(new_data);
  
    	if (head == null)
    	{
        	head = new Node(new_data);
        	return;
    	}

    	new_node.next = null;
    	Node last = head; 
    	while (last.next != null)
        	last = last.next;
  
    	last.next = new_node;
    	return;
	}

    void deleteNode(int key)
    {
        Node temp = head, prev = null;
 
        if (temp != null && temp.data == key) {
            head = temp.next; 
            return;
        }
 
        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }
 
        if (temp == null)
            return;
 
        prev.next = temp.next;
    }

	public static void printList(){
        Node tmp = head;
        while(tmp != null){
        	System.out.print(tmp.data + "->");
        	tmp = tmp.next;
        }
        System.out.println();
    }

    public static void main(String [] args){

        try {
            System.setIn(new FileInputStream("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        } catch(Exception e) {
            System.err.println("Error");
        }
        
        LinkedList list = new LinkedList();

        list.head = new Node(10);
        Node second = new Node(20);
        Node third = new Node(30);

        head.next = second;
        second.next = third;

        list.printList();

        list.insertAtFront(100);
        list.printList();
    }
}
