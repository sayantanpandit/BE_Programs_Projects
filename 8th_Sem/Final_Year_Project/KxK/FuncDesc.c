#include "FuncDefn.h"

void printMatrix(int *arr, int *row, int *col, int *row_defect, int *col_defect, int dimen_matrix)
{ 
  //For printing the matrix 
    for(int i=0; i<dimen_matrix; i++)
    {
       for(int j=0; j<dimen_matrix; j++)
       {
          cout << *((arr+i*dimen_matrix)+j) << "\t";
       }                            
       //For printing Row Status
       if(*(row_defect+i) == 4)
          cout << "(x,x)" << "\n";
       else
          cout << "(" << *((row+i*2)+ 0) << ","  << *((row+i*2)+1) << ") "<< "\n";
    }     
    
    //For printing Columns Status     
    for(int i=0; i<dimen_matrix; i++)
    {
       if(*(col_defect+i) == 4)
          cout << "(x,x)" << "\t";
       else
          cout << "(" << *((col+i*2)+0) << ","  << *((col+i*2)+1) << ") "<< "\t";
    } 
    
    //For displaying the Count of the new Rows n Columns
    int row_Count=0, col_Count=0;
    for(int i=0; i<dimen_matrix; i++)
    {
       if(*(row_defect+i)  != 4)
            row_Count += 1;
        if(*(col_defect+i) != 4)
            col_Count += 1;
    }
    
    cout << endl;    
    cout << "Rows : " << row_Count << " \tColumns : " << col_Count << endl;
    cout << endl;
}

void final_RowNCol(int *row_defect, int *col_defect, int dimen_matrix)
{
    //For displaying the Count of the new Rows n Columns
    int row_Count=0, col_Count=0;
    for(int i=0; i<dimen_matrix; i++)
    {
       if(*(row_defect+i)  != 4)
            row_Count += 1;
        if(*(col_defect+i) != 4)
            col_Count += 1;
    }
    
    if(row_Count < col_Count)
      col_Count = row_Count;
    else //if(col_Count < row_Count)
      row_Count = col_Count;
    
    cout << endl; 
    cout << "Final Matrix" << endl;   
    cout << "Rows : " << row_Count << " \tColumns : " << col_Count << endl;
    cout << endl;	
}

int find_Closed_Defect_Row(int *row, int dimen_matrix)
{
    int flag = 0;
    for(int i=0; i<dimen_matrix; i++)
    {
       if(*((row+i*2)+0) == 2)
         flag++;
    }
    if(flag == 0)
       return 0;
    else
       return 1;
}

int find_Closed_Defect_Col(int *col, int dimen_matrix)
{
    int flag = 0;
    for(int i=0; i<dimen_matrix; i++)
    {
       if(*((col+i*2)+0) >= 1)
         ++flag;
       //cout << "col : " << *((col+i*2)+0) << endl; 
    }
    //cout << "Flag Col : " << flag << endl;
    if(flag == 0)
       return 0;
    else
       return 1;
}

void traverse_in_the_Row(int *arr, int *row, int dimen_matrix)
{
   for(int i=0; i<dimen_matrix; i++)
   {
       *((row+i*2)+0) = 0;
       *((row+i*2)+1) = 0; 
   }
   
    for(int i=0; i<dimen_matrix; i++)
    {
       for(int j=0; j<dimen_matrix; j++)
       {
          //For taking Closed Defect in Row in Row_Array 
          if(*((arr+i*dimen_matrix)+j) == 2)
          {
             *((row+i*2)+ 0) += 1;
           //cout << i << j << " row : " << row[i][0] << endl;
          }
          else if(*((arr+i*dimen_matrix)+j) == 0)  //For taking Row Defect
          {
             //row[i][1] += 1;           
             *((row+i*2)+ 1) += 1;
          }
       }
    }
}

void traverse_in_the_Col(int *arr, int *col, int dimen_matrix)
{
   for(int i=0; i<dimen_matrix; i++)
   {
       *((col+i*2)+0) = 0;
       *((col+i*2)+1) = 0; 
   }

    for(int i=0; i<dimen_matrix; i++)
    {
       for(int j=0; j<dimen_matrix; j++)
       {
          if(*((arr+j*dimen_matrix)+i) == 2)
          {
             *((col+i*2)+0) += 1; 
             //cout << i << j << " col : " << col[i][0] << endl;
          }
          else if(*((arr+j*dimen_matrix)+i) == 0)
          {
             *((col+i*2)+1) += 1;           
             //cout << i << j << " col : " << col[i][1] << endl;
          }
       }
    } 
}
