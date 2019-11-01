import java.util.Scanner;

public class Methods{
    public static int pickCard(){
	return (int) (Math.random() * 52);
    }
    
    public static int drawCard(int c1, int c2, int c3, int c4, int c5){
	int randCard = pickCard();
	
	while(c1 == randCard || c2 == randCard || c3 == randCard || c4 == randCard || c5 == randCard){
	    randCard = pickCard();
	}    
	return randCard;
    }
    
    public static void main(String[] args){
	int c1 = -1, c2 = -1, c3 = -1, c4 = -1, c5 = -1; 
	    //int c3 = -1, int c4 = -1, int c5 = -1; 
	c1 = drawCard(c1,c2,c3,c4,c5);
	c2 = drawCard(c1,c2,c3,c4,c5);
	c3 = drawCard(c1,c2,c3,c4,c5);
	c4 = drawCard(c1,c2,c3,c4,c5);
	c5 = drawCard(c1,c2,c3,c4,c5);

	System.out.println(c1);
	System.out.println(c2);
	System.out.println(c3);
	System.out.println(c4);
	System.out.println(c5);
	
	Scanner scan = new Scanner(System.in); //scan is just your Scanner object
	String input = "";
	do{
	System.out.println("Enter y, or n");
	
	input = scan.nextLine(); //this is what's asking the user for inpu
	System.out.println(input);
	} while(!input.equals("n"));
	 
	
	
    }

}

