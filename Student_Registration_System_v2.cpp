#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct studentInfo                      
{
   string name;
   string SRCODE;
   string SUBJ_CODE;
   string PROF;
   string TIME;
   studentInfo* next;
};

studentInfo* createNode()
{
    studentInfo* newNode = new studentInfo();                 //creates a new structure everytime newNode is called
    newNode->next = NULL;                                     //makes sure the newNode is the last in the linked list
    return newNode;
}

void insertNode(studentInfo** head, studentInfo** tail, studentInfo* newNode)
{
    if (*head == NULL)
    {
        *head = *tail = newNode;                //makes everything NULL if *head is NULL
    }
    else
    {
        (*tail)->next = newNode;                //puts newNode to tail
        *tail = newNode;
    }
}

studentInfo* searchNode(studentInfo* head, string SRCODE)       //for searching students
{
    studentInfo* userfindstudent = head;
    while (userfindstudent != NULL)                                     //if user inputs a valid SRcode, it will accept the input
    {
        if (userfindstudent->SRCODE == SRCODE)
        {
            return userfindstudent;
        }
        userfindstudent = userfindstudent->next;                           //userfindstudent goes to next
    }
    return NULL;
}


int main()
{
    studentInfo* head = NULL;                              //initializing nodes to be null
    studentInfo* tail = NULL;
    string findStudent;
    char findAgain;
    system("cls");


    for (int i = 0; i < 3; i++)                            //inputs until there are 3 newNodes
    {
        studentInfo* newNode = createNode();

        cout << "\n----Enter the data for student no. " << i + 1 << "----\n";
        cout << "Enter the SRCODE: ";
        getline(cin, newNode->SRCODE);              //getline so whitespaces are accepted
        cout << "Enter the Name: ";
        getline(cin, newNode->name);
        cout << "Enter the Subject Code: ";
        getline(cin, newNode->SUBJ_CODE);
        cout << "Enter Professor Name: ";
        getline(cin, newNode->PROF);
        cout << "Enter Schedule Time: ";
        getline(cin, newNode->TIME);

        insertNode(&head, &tail, newNode);
    }

    do
    {
        cout << "\nEnter the SRCODE to display the details: ";
        getline(cin, findStudent);
        
        studentInfo* foundStudent = searchNode(head, findStudent);              //creates a new object foundStudent
        if (foundStudent != NULL)                                               //outputs if userinput foundStudent is accepted
        {
            cout << "\n-----------------------Student Information------------------------------\n";
            cout << "\nName: " << foundStudent->name;
            cout << "\nSubject Code: " << foundStudent->SUBJ_CODE << "\nProfessor: " << foundStudent->PROF << "\nSchedule: " << foundStudent->TIME;
        }
        else
        {
            cout << "\n\nThe student identified by the given ID does not exist. ";
        }
        
        cout << "\nWould you like to try again? [Y/N]: ";
        cin >> findAgain;
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');               //removes last line
    }
    while (findAgain == 'Y' || findAgain == 'y');


    return 0;
}
