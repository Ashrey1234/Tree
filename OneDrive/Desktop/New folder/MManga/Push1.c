 #include <stdio.h> 
#define size 3 
 
int stack [size],top =-1; 
 
void push(int item);
 int pop(); 
  void display(); 
 
int main()
{   
   int choice=1,value;     
    while(choice == 1){  
	printf("Stack Operations\n\n"); 
	printf("1.Push Operation\n");   
	printf("2.Pop Operation \n");       
    printf("3.Display Operation \n");   
	scanf("%d",&choice);      
	switch (choice) 
        { 
        case 1: 
        printf("\nEnter the data you want to add:"); 
		scanf("%d",&value); 
		push(value);        
		break; 
 
        case 2: 
        value = pop();    
	if (value!=-1){   
	    printf("Deleted data is %d\n",value); 
        } 
 
    
 
        case 3:   
	display();  
	  break; 
      } 
      printf("\n Do you want to continue (1/0)\n");
	scanf("%d",&choice); 
    } 
 } 
void push(int item){   
  if ( top >=size-1){ 
    printf("The stack is full"); 
       
    }else{ 
        
          top++; 
    stack[top]=item; 
    } 
 
} 
 
int pop(){   
  int item;  
     if (top == -1){    
     printf("Stack is empty");       
     return -1;    
	  }
	  else{ 
 stack[top]=item; 
        top --; 
    } 
    return item; 
    
} 
 
int peek(){ 
    if(top == -1){ 
 printf("stack is empty");
  return -1; 
      
	  }
	  else
	   {
 return stack[top]; 
    } 
} 
 
void display(){ 
    if (top == -1){
printf("Stack is empty"); 
    }
	else
	 { 
for (int i = top;i>=0;i--)
{         printf("The element in stack is %d \n",stack[i]); 
} 
 } 
} 
