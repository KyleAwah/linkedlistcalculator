//  Created by Kyle Awah on 22/3/2019.
//
//  UWI Studentd ID: 816012635
//  Email: kyle.awah@my.uwi.edu
//  COMP 1603: Computer Programing 3
//  Assignment #3
//
//  The Program is 100% working, no errors


#include <iostream>            // calling the library file for input and output to be used within the program
#include <fstream>             // calling the library file for files to be used within the program
#include <cstdlib>             // library for pointers on windows
#include <string>              // library for string functions
using namespace std;      // Declaring standard output method to be used


// structures for linked lists and stacks both with ints and chars
struct Node         // nodes for linked lists with chars in them
{
    char Data;
    Node * Next;
};


struct Node_INT     // nodes for linked lists with ints in them
{
    int Data = 0;
    Node_INT * Next;
};


struct Stack        // stacks with chars in them
{
    Node * Top;
};


struct Stack_INT    // stacks with ints in them
{
    Node_INT * Top;
};



// GLOBAL FILE STREAMS
ifstream input_stream;      // this is the variable for input from a file
ofstream output_stream;     // this is the variable for input from a file



// functions for linked lists with charaters

Node * CreateNode (char n)       // creates a node
{
    Node* NewNode = (Node*) malloc(sizeof(Node));   // creates a new node and allocates memory for it
    
    NewNode -> Data = n;    // gives the data to the new node
    NewNode -> Next = NULL;   // points the node to NULL
    
    return NewNode;
}


Node * InsertAtHead (Node* top, char number)       // insert at head function
{
    Node* NewNode;  // creates a new node variable
    
    NewNode = CreateNode(number);    // creates a new node with the function to create a new node
    
    NewNode -> Next = top;  // points the new node to whatever top is pointing to
    top = NewNode;         // points top to the new node
    
    return top;
}


Node * getLast (Node * top)            // finds the last node in the linked list
{
    Node * curr;
    Node * last;
    
    last = NULL;
    curr = top;
    while (curr != NULL)
    {
        last = curr;
        curr = curr -> Next;
    }
    
    return last;
}


Node * InsertAtTAIL (Node * top, char number)    // inserts the node at the end of the linked list
{
    Node * NewNode;
    Node * LastNode;
    
    NewNode = CreateNode (number);
    LastNode = getLast (top);
    
    if (LastNode == NULL)
    {
        top = NewNode;
    }
    
    else
    {
        LastNode -> Next = NewNode;
    }
    
    return top;             // return top in case it got changed
}


void Print_List (Node* head)    // this prints the linked list in reverse to that it appears normally on the output console
{
    if (head == NULL)
    {
        return;
    }
    
    Print_List(head -> Next);
    
    cout<< head -> Data<<" ";
}


void Print_List_TO_FILE (Node* head)    // this prints the linked list in reverse to that it appears normally on the output console
{
    if (head == NULL)
    {
        return;
    }
    
    Print_List_TO_FILE(head -> Next);
    
    output_stream<< head -> Data<<" ";
}


Node * deleteAtHead (Node * top)
{
    Node * curr;
    
    curr = top;
    if (top == NULL)
    {
        return NULL;
    }
    
    else
    {
        curr = top;
        top = top -> Next;
        free (curr);
        return top;
    }
}

Node * DeleteAtMiddle (Node* top, int key)       // insert at head function
{
    Node * curr;
    Node * prev;
    
    curr = top;
    prev = NULL;
    
    if (top == NULL)
    {
        cout << "\nList is empty.\n";
        return top;
    }
    
    
    while (curr != NULL)
    {
        if (curr -> Data == key)
        {
            if (prev == NULL)
            {
                top = top -> Next;
            }
            
            else
            {
                prev -> Next = curr -> Next;
            }
            
            free (curr);
            return top;
        }
        
        prev = curr;
        curr = curr -> Next;
        
    }
    return top;
}


bool IS_EMPTY_LINKED_LIST(Node * top)   // return true if the linked list is empty
{
    Node * curr;
    
    curr = top;
    if (top == NULL)
    {
        return true;
    }
    
    return false;
}


Node * DELETE_LINKED_LISTS (Node* Top)  // this clears all the data in the linked lists
{
    
    while(Top != NULL)  // delete at head until top is null
    {
        Top = deleteAtHead(Top);    // calls the function to delete at head
    }
    
    return Top;
}






// functions for linked lists with integers

Node_INT * CreateNode_INT (int n)       // creates a node
{
    Node_INT* NewNode = (Node_INT*) malloc(sizeof(Node_INT));   // creates a new node and allocates memory for it
    
    NewNode -> Data = n;    // gives the data to the new node
    NewNode -> Next = NULL;   // points the node to NULL
    
    return NewNode;
}


Node_INT * InsertAtHead_INT (Node_INT* top, int number)       // insert at head function
{
    Node_INT* NewNode;  // creates a new node variable
    
    NewNode = CreateNode_INT(number);    // creates a new node with the function to create a new node
    
    NewNode -> Next = top;  // points the new node to whatever top is pointing to
    top = NewNode;         // points top to the new node
    
    return top;
}


Node_INT * InsertAtMiddle_INT (Node_INT* top, int key, int number)       // insert at head function
{
    Node_INT * curr;
    Node_INT * prev;
    
    Node_INT* NewNode;                 // creates a new node variable
    NewNode = CreateNode_INT(number);    // creates a new node with the function to create a new node
    
    curr = top;
    prev = NULL;
    
    while (curr != NULL)
    {
        if (curr -> Data == key)
        {
            if (prev == NULL)    // if the prev is null because we are at the end of the linked list then do this
            {
                top = InsertAtHead_INT(top, number);
                return top;
            }
            
            NewNode -> Next = curr;
            prev -> Next = NewNode;
            
            return top;
        }
        
        else
        {
            prev = curr;
            curr = curr -> Next;
        }
    }
    
    return top;
}


Node_INT * DeleteAtMiddle_INT (Node_INT* top, int key)       // insert at head function
{
    Node_INT * curr;
    Node_INT * prev;
    
    curr = top;
    prev = NULL;
    
    if (top == NULL)
    {
        cout << "\nList is empty.\n";
        return top;
    }
    
    
    while (curr != NULL)
    {
        if (curr -> Data == key)
        {
            if (prev == NULL)
            {
                top = top -> Next;
            }
            
            else
            {
                prev -> Next = curr -> Next;
            }
            
            free (curr);
            return top;
        }
        
        prev = curr;
        curr = curr -> Next;
        
    }
    return top;
}


Node_INT * getLast_INT (Node_INT * top)            // finds the last node in the linked list
{
    Node_INT * curr;
    Node_INT * last;
    
    last = NULL;
    curr = top;
    while (curr != NULL)
    {
        last = curr;
        curr = curr -> Next;
    }
    
    return last;
}

Node_INT * InsertAtTAIL_INT (Node_INT * top, int number)    // inserts the node at the end of the linked list
{
    Node_INT * NewNode;
    Node_INT * LastNode;
    
    NewNode = CreateNode_INT (number);
    LastNode = getLast_INT (top);
    
    if (LastNode == NULL)
    {
        top = NewNode;
    }
    
    else
    {
        LastNode -> Next = NewNode;
    }
    
    return top;             // return top in case it got changed
}


void Print_List_INT (Node_INT* head)    // this prints the linked list in reverse to that it appears normally on the output console
{
    if (head == NULL)
    {
        return;
    }
    
    Print_List_INT(head -> Next);
    
    cout << head -> Data << " ";
}


void Print_List_TO_FILE_INT (Node_INT* head)    // this prints the linked list in reverse to that it appears normally on the output console
{
    if (head == NULL)
    {
        return;
    }
    
    Print_List_TO_FILE_INT (head -> Next);
    
    output_stream<< head -> Data<<" ";
}


Node_INT * deleteAtHead_INT (Node_INT * top)
{
    Node_INT * curr;
    
    curr = top;
    if (top == NULL)
    {
        return NULL;
    }
    
    else
    {
        curr = top;
        top = top -> Next;
        free (curr);
        return top;
    }
}


bool IS_EMPTY_LINKED_LIST_INT(Node_INT * top)   // return true if the linked list is empty
{
    Node_INT * curr;
    
    curr = top;
    if (top == NULL)
    {
        return true;
    }
    
    return false;
}


Node_INT * DELETE_LINKED_LISTS_INT (Node_INT* Top)  // this clears all the data in the linked lists
{
    while(Top != NULL)  // delete at head until top is null
    {
        Top = deleteAtHead_INT(Top);    // calls the function to delete at head
    }
    
    return Top;
}






bool Is_Number (char the_number)    // this checks to see if the given charater is a number
{
    if (the_number >= '0' && the_number <= '9')
    {
        return true;
    }
    
    else
    {
        return false;
    }
}






// Stack Functions for stacks with charaters

Stack * initStack()
{
    Stack * A_STACK;
    
    A_STACK = (Stack *) malloc (sizeof (Stack));
    
    A_STACK -> Top = NULL;
    
    return A_STACK;
}


bool isEmpty (Stack * A_STACK)
{
    return (A_STACK -> Top == NULL);
}


void push (Stack * A_STACK, char charater)
{
    A_STACK -> Top = InsertAtHead(A_STACK -> Top , charater);
}


// global variable for invalid checker
bool *INVALID_CAL = (bool*) malloc(sizeof(bool));               // holds if the number of brackets ever went under aka the brackets were unballanced

char pop (Stack * A_STACK)
{
    char charater;
    
    if (isEmpty(A_STACK))
    {
        // STACK IS EMPTY NO WARNING MESSAGE TO CLUTTER THE OUTPUT OF THE PROGRAM
        *INVALID_CAL = true;
        return NULL;
    }
    
    charater = A_STACK -> Top -> Data;
    
    A_STACK -> Top = deleteAtHead(A_STACK -> Top);

    return charater;
}








// Stack Functions for stacks with Integers

Stack_INT * initStack_INT()
{
    Stack_INT * A_STACK;
    
    A_STACK = (Stack_INT *) malloc (sizeof (Stack_INT));
    
    A_STACK -> Top = NULL;
    
    return A_STACK;
}


bool isEmpty_INT (Stack_INT * A_STACK)
{
    return (A_STACK -> Top == NULL);
}


void push_INT (Stack_INT * A_STACK, int number)
{
    A_STACK -> Top = InsertAtHead_INT(A_STACK -> Top , number);
}


int pop_INT (Stack_INT * A_STACK)
{
    int number;
    
    if (isEmpty_INT(A_STACK))
    {
        cout<<"The Stack is Empty"<<endl<<endl;
        return NULL;
    }
    
    number = A_STACK -> Top -> Data;
    
    A_STACK -> Top = deleteAtHead_INT(A_STACK -> Top);
    
    return number;
}

// contains functions for int and char linked lists
bool contains (Node * top, int key)
{
    Node * curr;
    curr = top;
    while (curr != NULL)
    {
        if (curr -> Data == key)
        {
            return true;
        }
        
        else
        {
            curr = curr -> Next;
        }
    }
    
    return false;
}

bool contains_INT (Node_INT * top, int key)
{
    Node_INT * curr;
    curr = top;
    while (curr != NULL)
    {
        if (curr -> Data == key)
        {
            return true;
        }
        
        else
        {
            curr = curr -> Next;
        }
    }
    
    return false;
}




int main()                  // This Just Tells it Where to Go
{
    // general variables
    char the_current_equation_charater_array[10000];          // charater array to hold the current equation from the text file
    string *the_current_equation = (string*) malloc(sizeof(string));  // string to hold the current equation from the text file
    
    char Postfix_REP_Array[100];
    int *Postfix_Subscript = (int*) malloc(sizeof(int));
    string *Postfix_REP = (string*) malloc(sizeof(string));           // string to hold the postfix rep

    string convert;                                          // using a normal string and not a pointer because copying with a pointer doesnt work for some reason
    long int *Length_of_string = (long int*) malloc(sizeof(long int)); // holds the length of the strings
    
    int *current_num_int_rep = (int*) malloc(sizeof(int));         // the integer representation of the current number
    int *subscript = (int*) malloc(sizeof(int));                   // this goes through the charater array
    
    
    
    // variables for calculating the answer
    int *SUM_COUNTER = (int*) malloc(sizeof(int));                 // counts which sum is currently being processed

    int *Closing_bracket_location = (int*) malloc(sizeof(int));    // holds the location of the closing bracket
    int *Opening_bracket_location = (int*) malloc(sizeof(int));    // holds the location of the opening bracket
    
    int *Number_1 = (int*) malloc(sizeof(int));                    // counts which sum is currently being processed
    int *Number_2 = (int*) malloc(sizeof(int));                    // counts which sum is currently being processed
    int *Number_tester = (int*) malloc(sizeof(int));               // tests where the number is to be stored
    
    char *CAL_OPERATOR = (char*) malloc(sizeof(char));              // is it a multiply divide or add ?

    float *FINAL_ANS = (float*) malloc(sizeof(float));               // holds the final answer from the calculations
    float *Current_ANS = (float*) malloc(sizeof(float));             // holds the final answer from the calculations
    
    // Postfix ADT's
    
    char *number_to_push = (char*) malloc(sizeof(char));
    
    
    
    // ADT Variables
    
    Stack * BRACKETS_TESTER;             // this is a charater stack used to test if the brackets match
    Stack_INT * Brackets_Locations;        // this holds the subscript in the array where the brackets start and stop

    Node * Operators_TOP;
    Node_INT * NUMBERS_TOP;
    
    Node_INT * curr_number;
    Node  * curr_operator;
    
    Node * POSTFIX_TOP;     // converts the string to postfix in linked list form
    
    // Postfix ADT's
    
    Node_INT * Postfix_CONVERT;
    Node * Postfix_Operator_CONVERT;
    
    Stack * Numbers_Reverse;
    Stack * Operator_Reverse;
    
    
   
    
    

    
    // Initilization of all varaibles
    
    Numbers_Reverse = initStack();
    Operator_Reverse = initStack();

    
    BRACKETS_TESTER = initStack();
    Brackets_Locations = initStack_INT();
    
    curr_number = NULL;
    curr_operator = NULL;

    Operators_TOP = NULL;
    NUMBERS_TOP = NULL;
    
    Postfix_CONVERT = NULL;
    Postfix_Operator_CONVERT = NULL;
    
    POSTFIX_TOP = NULL;
    
    *SUM_COUNTER = 0;
    *Length_of_string = 0;
    *FINAL_ANS = 0.0;
    *Current_ANS = 0.0;
    *Closing_bracket_location = 0;
    *Opening_bracket_location = 0;
    *Number_1 = 0;
    *Number_2 = 0;
    *Number_tester = 1;
    *Postfix_Subscript = 0;
    
    
    
    
    // open the file streams
    input_stream.open("input.txt");           // linking the input.txt file to the input_stream variable to be used within the program
    output_stream.open("output.txt");          // linking the input.txt file to the input_stream variable to be used within the program
    
    if (!input_stream.is_open())    // if it cannot find the file input.txt notify the user by doing this
    {
        cout<<endl<<endl;
        cout<<"\t =============================================== \n";
        cout<<"\t      ERROR: FILE input.txt CANNOT BE FOUND      \n";
        cout<<"\t =============================================== \n";
        cout<<endl;
        cout<<"\t Please try moving the input.txt file to the same\n";
        cout<<"\t folder as your .cpp file and restart the program\n";
        cout<<endl<<endl<<endl;
        return 0;
    }
    
    // read in an equation first to makesure its not the terminating value
    
    getline(input_stream, *the_current_equation);   // gets the current equation the program is supposed to be working on

    while (*the_current_equation != "$")   // goes through the entire charater array until $ is found to finish all operations
    {
        
        convert = *the_current_equation;    // using a normal string from the pointer because you cannot use .c_str() on a pointer to identify that variable as the cstring
        
        
        // .c_str() is used to identify the string variable as a C-String and not a normal charater array and then strcpy is used to copy the contense of that C-String into a Charater array
        strcpy(the_current_equation_charater_array, convert.c_str());
        
        *Length_of_string = strlen(convert.c_str());

        
        
        
        
        
        // go through the whole equation and do this to find if the amount of brackets match before we do anything else;
        for (*subscript = 0 ; *subscript <= *Length_of_string ; *subscript = *subscript + 1)
        {
            if (the_current_equation_charater_array[*subscript] == '(')
            {
                push(BRACKETS_TESTER, '(');
            }
            
            else if (the_current_equation_charater_array[*subscript] == ')')
            {
                pop(BRACKETS_TESTER);
            }
            
        }   // finished going through the string for the current equation to find the matching brackets

        
        
        
        
        
        
        
        if (!isEmpty(BRACKETS_TESTER))  // if the stack still has items in it then there are more left than right
        {
            cout<<"\t           CANNOT PERFORM CALCULATION       "<<endl;
            cout<<"\t    Error: more left than right parentheses "<<endl;
            cout<<"\t        Moving on to the next expression     "<<endl;
            cout<<endl<<endl<<endl<<endl;
        }
        
        
        if (*INVALID_CAL == true)    // this bool will be true if there are more right than left brackets
        {
            cout<<"\t           CANNOT PERFORM CALCULATION      "<<endl;
            cout<<"\t    Error: more right than left parentheses"<<endl;
            cout<<"\t        Moving on to the next expression     "<<endl;
            cout<<endl<<endl<<endl<<endl;
        }
        
      
        
        
        
        
       
        
        if (isEmpty(BRACKETS_TESTER) && *INVALID_CAL == false)   // if the amount of brackets match then do the storage and calcuations
        {
            // once the brackets are balanced then we can store the operators and numbers
            
            // go through the whole string and break it down by charater and sorts it into the charater linked list for the operators and int linked list for the numbers
            for (*subscript = 0 ; *subscript <= *Length_of_string ; *subscript = *subscript + 1)
            {

                if (the_current_equation_charater_array[*subscript] == '(')
                {
                    Operators_TOP = InsertAtHead(Operators_TOP, '(');
                    push_INT(Brackets_Locations, *subscript);             // stores the location of this bracket in a stack
                }

                else if (the_current_equation_charater_array[*subscript] == ')')
                {
                    Operators_TOP = InsertAtHead(Operators_TOP, ')');
                    push_INT(Brackets_Locations, *subscript);             // stores the location of this bracket in a stack
                }

                
                else if (the_current_equation_charater_array[*subscript] == '+')
                {
                    Operators_TOP = InsertAtHead(Operators_TOP, '+');
                }
                
                else if (the_current_equation_charater_array[*subscript] == '-')
                {
                    Operators_TOP = InsertAtHead(Operators_TOP, '-');
                }
                
                else if (the_current_equation_charater_array[*subscript] == '*')
                {
                    Operators_TOP = InsertAtHead(Operators_TOP, '*');
                }
                
                else if (the_current_equation_charater_array[*subscript] == '^')
                {
                    Operators_TOP = InsertAtHead(Operators_TOP, '^');
                }
                
                else if (the_current_equation_charater_array[*subscript] == '/')
                {
                    Operators_TOP = InsertAtHead(Operators_TOP, '/');
                }
                
                
                if (Is_Number(the_current_equation_charater_array[*subscript]))    // if is is a number and not an operation then store it
                {
                    *current_num_int_rep = the_current_equation_charater_array[*subscript] - '0';  // converting to the int rep
                    
                    NUMBERS_TOP = InsertAtHead_INT(NUMBERS_TOP, *current_num_int_rep);
                }
                
            }
            // finished going through the string for the current equation and looking at all of the charaters and sorting them into ints for the int linked list and operators for the operators list
            
            
            
            
            // Performing The Calculations on the sums in the program
            
            if(!isEmpty_INT(Brackets_Locations))    // if there are brackets in the equation then do this
            {
                
                
                cout<<"The Numbers Linked List has: "<<endl;
                Print_List_INT(NUMBERS_TOP);
                cout<<endl<<endl<<endl;
                cout<<"The Opserators Linked List has: "<<endl;
                Print_List(Operators_TOP);
                
                cout<<endl<<endl<<endl<<endl<<endl<<endl;
                
            
                
                Postfix_CONVERT = NUMBERS_TOP;
                Postfix_Operator_CONVERT = Operators_TOP;
                
                
                cout<<"The Original Equation is: "<<*the_current_equation<<endl<<endl;
                cout<<"STORING THE FOLLOWING DATA: "<<endl;

                
                
                
                while (Postfix_CONVERT != NULL)
                {
                    // convert the two numbers to their charater representations and push them unto the stack to be stored in reverse later
                    
                    cout<<"Number 1: "<< Postfix_CONVERT -> Data <<endl;

                    *number_to_push = (Postfix_CONVERT -> Data) + '0';
                    push(Numbers_Reverse, *number_to_push);
                    
                    Postfix_CONVERT = Postfix_CONVERT -> Next;
                }
                
                
                
                while (Postfix_Operator_CONVERT != NULL)
                {
                    if (Postfix_Operator_CONVERT -> Data == ')' || Postfix_Operator_CONVERT -> Data == '(')    // if its a bracket, skip it
                    {
                        Postfix_Operator_CONVERT = Postfix_Operator_CONVERT -> Next;
                    }
                    
                    // push the operator into a stack so that it can be reverse for storing later
                    push(Operator_Reverse, (Postfix_Operator_CONVERT -> Data));
 
                    cout<<"Operator: "<< Postfix_Operator_CONVERT -> Data <<endl;
                    
                    Postfix_Operator_CONVERT = Postfix_Operator_CONVERT -> Next;
                }
                
                
                
                // go through the two stacks and store the data into the post fix version
                
                while (!isEmpty(Numbers_Reverse))
                {
                    // pop the number off the stack and add it into the post fix conversion of the equation
                    POSTFIX_TOP = InsertAtHead(POSTFIX_TOP, pop(Numbers_Reverse));
                }
                
                
                while (!isEmpty(Operator_Reverse))
                {
                    // pop the operator off the stack and add it into the post fix conversion of the equation
                    POSTFIX_TOP = InsertAtHead(POSTFIX_TOP, pop(Operator_Reverse));
                }
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                while (!isEmpty_INT(Brackets_Locations))    // while there are still brackets in the equation do the calculations and remove the brackets
                {
                    // gets the location of the opening and closing brackets
                    *Closing_bracket_location = pop_INT(Brackets_Locations);
                    *Opening_bracket_location = pop_INT(Brackets_Locations);
                    
                    *Opening_bracket_location = *Opening_bracket_location + 1;  // add one so that it stops on a number and not an operator

                    
                    // go through all the array subscripts for the numbers inbetween the brackets and perform the calculations
                    for (*Opening_bracket_location ; *Opening_bracket_location < *Closing_bracket_location ; *Opening_bracket_location = *Opening_bracket_location + 1)
                    {
                        
                        if (the_current_equation_charater_array[*Opening_bracket_location] == '+')
                        {
                            *CAL_OPERATOR = '+';
                        }
                        
                        else if (the_current_equation_charater_array[*Opening_bracket_location] == '-')
                        {
                            *CAL_OPERATOR = '-';
                        }
                        
                        else if (the_current_equation_charater_array[*Opening_bracket_location] == '*')
                        {
                            *CAL_OPERATOR = '*';
                        }
                        
                        else if (the_current_equation_charater_array[*Opening_bracket_location] == '^')
                        {
                            *CAL_OPERATOR = '^';
                        }
                        
                        else if (the_current_equation_charater_array[*Opening_bracket_location] == '/')
                        {
                            *CAL_OPERATOR = '/';
                        }
                        
                        
                        if (Is_Number(the_current_equation_charater_array[*Opening_bracket_location]))    // if is is a number and not an operation then store it
                        {

                            if(*Number_tester % 2 == 0) // if its the second number then store it in the second
                            {
                                *Number_2 = the_current_equation_charater_array[*Opening_bracket_location] - '0';
                            }
                            
                            else
                            {
                                *Number_1 = the_current_equation_charater_array[*Opening_bracket_location] - '0';
                            }
                            
                            *Number_tester = *Number_tester + 1;    // incriments so that the next number gets stored as a number
                        }
                        
                        
                        
                    }   // finished going through the string
 
                    
                    // look at the operator to decide what to do
                    
                    if (*CAL_OPERATOR == '+')
                    {
                        *Current_ANS = *Number_1 + (*Number_2);
                    }
                    
                    else if (*CAL_OPERATOR == '-')
                    {
                        *Current_ANS = *Number_1 - (*Number_2);
                    }
                    
                    else if (*CAL_OPERATOR == '*')
                    {
                        *Current_ANS = *Number_1 * (*Number_2);
                    }
                    
                    else if (*CAL_OPERATOR == '^')  // use a for loop to calculate powers of
                    {
                        for (*Number_2 ; *Number_2 != 0 ; *Number_2 = *Number_2 - 1)
                        {
                            *Number_1 = *Number_1 * (*Number_1);
                        }
                        *Current_ANS = *Number_1;
                    }
                    
                    else if (*CAL_OPERATOR == '/')
                    {
                        *Current_ANS = (*Number_1 / (*Number_2)) * 1.0;
                    }
                    
                    
                    *FINAL_ANS = *FINAL_ANS + (*Current_ANS);   // add the answer to whatever was the answer from the previous calculation
                    
                    
                    
                    
                    
                    // delete the nodes with those numbers in it and add in the new final ans to the variable where those were
                    
                    NUMBERS_TOP = InsertAtMiddle_INT(NUMBERS_TOP, *Number_2 , *Current_ANS);  // puts the answer of the calculation between the two numbers where number 2 was
                    
                    
                    // if one of the numbers cannot be found before deleting them then do this
                    if(!contains_INT(NUMBERS_TOP, *Number_1) || !contains_INT(NUMBERS_TOP, *Number_2))
                    {
                        cout<<"ERROR: CANT FIND THE NUMBER WE'RE LOOKING TO DELETE FROM THE LIST"<<endl;
                        return 0;
                    }
                    
                    
                    // deletes the two numbers from the linked list
                    NUMBERS_TOP = DeleteAtMiddle_INT(NUMBERS_TOP, *Number_1);
                    NUMBERS_TOP = DeleteAtMiddle_INT(NUMBERS_TOP, *Number_2);
                    Operators_TOP = DeleteAtMiddle(Operators_TOP, *CAL_OPERATOR);
                    Operators_TOP = DeleteAtMiddle(Operators_TOP, '(');
                    Operators_TOP = DeleteAtMiddle(Operators_TOP, ')');
                    
                    
                    // reset the locations for the opening and closing brackets
                    *Closing_bracket_location = 0;
                    *Opening_bracket_location = 0;
                }
            }
            
            
            
            
            
            // gives the tops of the two lists to the variables
            curr_number   = NUMBERS_TOP;
            curr_operator = Operators_TOP;
            
            
            // go through the whole equations until there is no more items in either linked list
            while(!IS_EMPTY_LINKED_LIST_INT(NUMBERS_TOP) && !IS_EMPTY_LINKED_LIST(Operators_TOP))
            {
                // gets the two digits
                * Number_1 = curr_number -> Data;
                * Number_2 = curr_number -> Next -> Data;
                
                // gets the operator for the current operation
                * CAL_OPERATOR = curr_operator -> Data;
                
                // checks what kind of operation has to be performed
                if (*CAL_OPERATOR == '+')
                {
                    *Current_ANS = *Number_1 + (*Number_2);
                }
                
                else if (*CAL_OPERATOR == '-')
                {
                    *Current_ANS = *Number_1 - (*Number_2);
                }
                
                else if (*CAL_OPERATOR == '*')
                {
                    *Current_ANS = *Number_1 * (*Number_2);
                }
                
               else if (*CAL_OPERATOR == '^')
                {
                    for (*Number_2 ; *Number_2 != 0 ; *Number_2 = *Number_2 - 1)
                    {
                        *Number_1 = *Number_1 * (*Number_1);
                    }
                    *Current_ANS = *Number_1;
                }
                
                else if (*CAL_OPERATOR == '/')
                {
                    *Current_ANS = (*Number_1 / (*Number_2)) * 1.0;
                }
                
                
                *FINAL_ANS = *FINAL_ANS + (*Current_ANS);   // add the answer to whatever was the answer from the previous calculation
                
            
                
                // inserting the current answer into the linked list
                NUMBERS_TOP = InsertAtMiddle_INT(NUMBERS_TOP, *Number_2, *Current_ANS);
                
                // deleted the operators and the numbers that were just calculated
                Operators_TOP = DeleteAtMiddle(Operators_TOP, *CAL_OPERATOR);
                NUMBERS_TOP = DeleteAtMiddle_INT(NUMBERS_TOP, *Number_2);
                NUMBERS_TOP = DeleteAtMiddle_INT(NUMBERS_TOP, *Number_1);
                
                
                
                // resets both pointers back to the tops because since we removed the digits that were calculated we just need to start back from the same position again
                
                curr_number   = NUMBERS_TOP;
                curr_operator = Operators_TOP;
            }
            
            
            
            if (!IS_EMPTY_LINKED_LIST(Operators_TOP))   // Error checking just in case there is still and operator left in the linked list for some reason
            {
                cout<<"UNKNOWN ERROR ITEMS STILL LEFT IN THE OPERATOR LINKED LIST"<<endl;
                return 0;
            }
            
            
            
            
            
            
            
            
            
                            // PRINTING THE OUTPUT
            
            // CONSOLE PRINT
            
            *SUM_COUNTER = *SUM_COUNTER + 1;    // incriments the counter
            
            
            cout<<endl<<endl;
            cout<<"\t\t\t     Calculating Valid Sum # "<<*SUM_COUNTER<<endl<<endl<<endl;
            cout<<"\t INFIX :      "<<*the_current_equation<<endl<<endl;
            cout<<"\t POSTFIX :    ";
            Print_List(POSTFIX_TOP);
            cout<<endl<<endl<<endl;
            cout<<"\t EVALUATION : "<< NUMBERS_TOP -> Data;
            cout<<endl<<endl<<endl<<endl<<endl<<endl;
            
            
            // FILE PRINT

            output_stream<<endl<<endl;
            output_stream<<"\t\t\t     Calculating Valid Sum # "<<*SUM_COUNTER<<endl<<endl<<endl;
            output_stream<<"\t INFIX :      "<<*the_current_equation<<endl<<endl;
            output_stream<<"\t POSTFIX :    ";
            Print_List_TO_FILE(POSTFIX_TOP);
            output_stream<<endl<<endl<<endl;
            output_stream<<"\t EVALUATION : "<< NUMBERS_TOP -> Data;
            output_stream<<endl<<endl<<endl<<endl<<endl<<endl;
            
            

            
            
            // Deleting Linked Lists so that they will correctly function for the next equation that is to be processed
            
            Operators_TOP = DELETE_LINKED_LISTS(Operators_TOP);
            NUMBERS_TOP = DELETE_LINKED_LISTS_INT(NUMBERS_TOP);
            
            Postfix_CONVERT = NULL;
            Postfix_Operator_CONVERT = NULL;
            
            
            // delete the last postfix conversion of the eqution
            POSTFIX_TOP = DELETE_LINKED_LISTS(POSTFIX_TOP);
            
            // deletes the two stacks to reverse the numbers and operators when converting them to postfix
            Numbers_Reverse -> Top = DELETE_LINKED_LISTS(Numbers_Reverse -> Top);
            Operator_Reverse -> Top = DELETE_LINKED_LISTS(Operator_Reverse -> Top);
        }
        
        
        // Deleting The Stack so that it will correctly function for the next equation that is to be processed
        BRACKETS_TESTER -> Top = DELETE_LINKED_LISTS(BRACKETS_TESTER -> Top);

        // resets the variables before the next equation
        *subscript = 0;
        *Length_of_string = 0;
        
        getline(input_stream, *the_current_equation);   // gets a new current equation the program is supposed to be working on
    }
    
    
    cout<<endl<<endl<<endl;
    
    input_stream.close();       // closing the input file stream
    output_stream.close();      // closing the output file stream
    return 0;
}
