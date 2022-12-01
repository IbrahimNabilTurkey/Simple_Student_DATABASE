#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "simpleDB.h"

static DB*      glbl_pstr_head_node      = NULL ;
static char     glbl_total_list_length   = -1   ;

bool SDB_IsFull(void)
{
    if(glbl_total_list_length == 10)
    {
        return 1 ; 
    }
    else
    {
        return 0 ;
    }
}

char SDB_GetUsedSize(void)
{
    return (glbl_total_list_length+1) ;
}

bool SDB_AddEntry(void)
{
    if (glbl_pstr_head_node == NULL)
    {
        glbl_pstr_head_node = (DB*) malloc(sizeof(DB));
        if (glbl_pstr_head_node != NULL)
        {
            printf("\nENTER FIRST STUDENT ID : ");
            while(!(scanf("%d", &glbl_pstr_head_node->Student_ID)))
            {
                printf("Enter Valid ID !!");
            }
            printf("ID SAVED SUCCESSFULLY");
            printf("\nPlease Enter the Study Level: ");
            while(!(scanf("%d", &glbl_pstr_head_node->Student_YEAR)))
            {
                printf("Enter Valid Study Level !!");
            }
            printf("STUDY LEVEL SAVED SUCCESSFULLY");

            for (int i = 0 ; i<3 ; i++)
            {
                printf("\nPlease Enter the %d Course ID: \n", i+1);
                while(!(scanf("%d", &glbl_pstr_head_node->Courses_IDs[i])))
                {
                    printf("\nEnter Valid Course ID for Course No.%d !!\n",i+1);
                }
                printf("\nCOURSE ID FOR COURSE No.%d SAVED SUCCESSFULLY\n",i+1);
                printf("\nPlease Enter the %d Course Grade: \nNote: Please Enter a number between 0 -> 100\n", i+1);
                while(!(scanf("%d", &glbl_pstr_head_node->Courses_Grades[i])))
                {
                    printf("\nEnter Valid Course Grade for Course No.%d",i+1);
                    printf("\nFor Help : Course Grade Can range from 0 to 100\n");
                }
                printf("\nGRADE FOR COURSE No.%d SAVED SUCCESSFULLY !!\n",i+1);
            }
            glbl_total_list_length ++ ;
            glbl_pstr_head_node->ptr_next_node = NULL ;
            return 1 ;
        }
        
        else
        {
            return 0 ;
        }
    }
    else 
    {
        if (glbl_total_list_length < 10)
        {
            DB* ptr_to_allocated_node = NULL ;
            DB* pstr_last_node = glbl_pstr_head_node ;
            ptr_to_allocated_node = (DB*) malloc(sizeof(DB));
            if(ptr_to_allocated_node != NULL)
            {

                printf("\nENTER FIRST STUDENT ID : \n");
                scanf("%d", &ptr_to_allocated_node->Student_ID);
                printf("\nPlease Enter the Year of the student: \n");
                scanf("%d", &ptr_to_allocated_node->Student_YEAR);
                for (char i = 0 ; i<3 ; i++)
                {
                    printf("\nPlease Enter the %d Course ID: \n", i+1);
                    scanf("%d", &ptr_to_allocated_node->Courses_IDs[i]);
                    printf("\nPlease Enter the %d Course Grade: \nNote: Please Enter a number between 0 -> 100\n", i+1);
                    scanf("%d", &ptr_to_allocated_node->Courses_Grades[i]);
                }
                while (pstr_last_node->ptr_next_node != NULL)
                {
                    pstr_last_node = pstr_last_node->ptr_next_node;
                }
                glbl_total_list_length ++ ;
                pstr_last_node->ptr_next_node = ptr_to_allocated_node ;
                ptr_to_allocated_node->ptr_next_node = NULL ;
                return 1 ;
            }
            else
            {
                return 0 ;
            }
            
        }
        else
        {
            return 0 ;
        }
    }
}

void SDB_DeleteEntry(void)
{
    if (glbl_pstr_head_node != NULL)
    {
        DB* pstr_current_node = glbl_pstr_head_node ;
        DB* Temp =  glbl_pstr_head_node ;
        int identification_number = 0 ;
        printf("\nENTER DESIRED ID TO DELETE :");
        scanf("%d", &identification_number);
        
        if (Temp->Student_ID == identification_number)
        {
            glbl_pstr_head_node = glbl_pstr_head_node->ptr_next_node ;
            free(Temp);
            Temp = NULL ;
            glbl_total_list_length -- ;
            printf("\nID IS DELETED SUCCESSFULLY !!!");
        }
        else
        {
            while (pstr_current_node->ptr_next_node != NULL)
            {
                if (pstr_current_node->ptr_next_node->Student_ID == identification_number )    // search if id matches the one in the next node
                {
                    Temp = pstr_current_node->ptr_next_node ;
                    break ;
                }
                else 
                {
                    pstr_current_node = pstr_current_node->ptr_next_node; // iterate (jump) on the next node
                }

            }
            if (pstr_current_node->ptr_next_node == NULL)
            {
                printf("\nID IS NOT FOUND 404\n");
            }
            else
            {
                pstr_current_node->ptr_next_node = Temp->ptr_next_node ;
                free(Temp);
                glbl_total_list_length -- ;
                printf("ID IS DELETED SUCCESSFULLY");
            }

        }

    }
    else
    {
        printf("\nDATABASE IS EMPTY ! CREATE AT LEAST ONE NODE");
    }

}

bool SDB_ReadEntry(void)
{
    if (glbl_pstr_head_node != NULL)
    {
        DB* ID_LOOKUP = glbl_pstr_head_node ;
        int identification_number = -1 ;
        printf("\nEnter The LookUP ID : ");
        while(!(scanf("%d",&identification_number)))
        {
            printf("\nEnter Valid ID !\n");
        }
        printf("\nID SAVED SUCCESSFULLY !\n");
        printf("SEARCHING .............\n");
        while (ID_LOOKUP != NULL)
        {
            if (ID_LOOKUP->Student_ID = identification_number )
            {
                printf("\nWe found the ID (%d) of the student in year %d: \n", identification_number, ID_LOOKUP->Student_YEAR);
                for (char i = 0 ; i < 3 ; i++)
                {
                    printf("\nCOURSE ID : %d \t",ID_LOOKUP->Courses_IDs[i]);
                    printf("COURSE GRADE : %d \n ",ID_LOOKUP->Courses_Grades[i]);
                }
                return 1 ;
            }
            else
            {
                ID_LOOKUP = ID_LOOKUP->ptr_next_node;
            }
        }
        return 0 ;
    }
    return 0 ;
}


void SDB_GetIdList(void)
{
    if(glbl_pstr_head_node != NULL)
    {
        char LIST_COUNT = 0 ;
        DB* ID_LIST = glbl_pstr_head_node ;
        while(ID_LIST != NULL)
        {
            printf("\n%d) ID : %d \tSTUDY LEVEL : %d",LIST_COUNT+1,ID_LIST->Student_ID,ID_LIST->Student_YEAR);
            for (char i = 0 ; i < 3 ; i++)
            {
                printf("\nCOURSE ID : %d \t",ID_LIST->Courses_IDs[i]);
                printf("COURSE GRADE : %d \n ",ID_LIST->Courses_Grades[i]);
            }
            printf("*******************************************************");
            LIST_COUNT++;
            ID_LIST = ID_LIST->ptr_next_node;
        }
    }
    else
    {
        printf("\nDATABASE IS EMPTY ! CREATE AT LEAST ONE NODE");
    }
}

bool SDB_IsIdExist(void)
{
    if(glbl_pstr_head_node!=NULL)
    {
        DB* CHECK_ID_EXISTENCE = glbl_pstr_head_node;
        int identification_number = -1 ;
        printf("\n ENTER ID TO CHECK EXISTENCE IN DATABASE");
        while(!(scanf("%d",&identification_number)))
        {
            printf("\nENTER VALID ID !\n");
        }
        printf("ID IS SUCCESSFULLY ENTERED\n");
        printf("CHECKING ....\n");
        while (CHECK_ID_EXISTENCE != NULL)
        {
            if(CHECK_ID_EXISTENCE->Student_ID = identification_number)
            {
                return 1 ;
            }
            else
            {
                CHECK_ID_EXISTENCE = CHECK_ID_EXISTENCE->ptr_next_node;
            }
        }
        return 0 ;
    }
    else
    {
        return 0 ;
    }
}



int _menu_ (void)
{
    int Select = 0 ;
    char check = -1 ;
    printf("\nSelect between the following choices \n");
    printf("1. ADD ENTRY \n 2. DELETE ENTRY \n 3. READ ENTRY WiTH SPECIFIC ID \n 4. GET ID LIST \n 5. CHECK IF ID EXIST \n 6.GET USED SIZE\n7.CHECK IF DB IS FULL\n8.EXIT\n");
    scanf("%d",&Select);
    switch(Select)
    {
        case 1 :    
            check = SDB_AddEntry();
            switch(check)
            {
                case 0 : printf("\nFAILED TO CREATE NEW ENTRY\n");break;
                case 1 : printf("\nNEW ENTRY CREATED SUCCESSFULLY\n");break;
            }
            break;
        case 2 :
            SDB_DeleteEntry();
            break;
        case 3 :
            check = SDB_ReadEntry();
            switch(check)
            {
                case 0 : printf("\nENTRY NOT FOUND\n");break;
                case 1 : printf("\nENTRY FOUND SUCCESSFULLY\n");break;
            }
            break;
        case 4 :
            SDB_GetIdList();
            break ; 
        case 5 :
            check = SDB_IsIdExist();
            switch (check)
            {
                case 0 : printf("ID NOT IN THE DATABASE");break;
                case 1 : printf("ID EXIST IN THE DATA BASE");break;
            }
        case 6 :
            printf("DATABASE IS %d LENGTH",SDB_GetUsedSize());
            break;
        case 7 :
            check = SDB_IsFull();
            switch(check)
            {
                case 0 : printf("DATABASE IS NOT FULL !");break;
                case 1 : printf("DATABASE IS FULL !");break;
            }
        case 8 :
            return 0 ;
    }
    return 1 ;
}
