//No.1 -> Junction is Perfect
//No.0 -> Junction is Opened
//No.2 -> Junction is Closed
//No.3 -> Junction is Covered Opened or Closed
//No.4 -> Rejected Defective Columns 

#include "FuncDefn.h"

int main()
{
    FILE *fp;
    fp = fopen("test_result.txt", "w+");
    
    int dimen_matrix, defective_junc;
    //cout << "Enter the Dimension of the Matrix : ";
    //cin >> dimen_matrix;
    dimen_matrix = 40;
    int arr[dimen_matrix][dimen_matrix];
    int ori_mat[dimen_matrix][dimen_matrix];
    int row[dimen_matrix][2];
    int col[dimen_matrix][2];
    
    int row_defect[dimen_matrix];
    int col_defect[dimen_matrix];
    
    //cout << "Enter the number of Defective Junction  : ";
    //cin >> defective_junc;
    defective_junc = dimen_matrix * dimen_matrix * 0.25;
      
   for(int tcase=1; tcase<=100; tcase++)
   {   
    for(int i=0; i<dimen_matrix; i++)
    {
       for(int j=0; j<dimen_matrix; j++)
          arr[i][j] = 1;
       row_defect[i] = 0;
       col_defect[i] = 0;
    }

    int x, y, val; 
    int struck_open  = defective_junc * 0.9;
    int struck_close = defective_junc * 0.1;   
      
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    //Generating defect for Struck-Open 
    for(int i=0; i<struck_open; i++)
    {       
       x = (rand() + (tm.tm_hour+tm.tm_min+tm.tm_sec))  % dimen_matrix;
       y = (rand() + (tm.tm_hour+tm.tm_min+tm.tm_sec))  % dimen_matrix;
       val = 0;
       if(arr[x][y] == 1)
       {
          ori_mat[x][y] = val;
          arr[x][y] = val;
       }
       else
         i--;
    }

    //Generating defect for Struck-Close 
    for(int i=0; i<struck_close; i++)
    {       
       x = (rand() + (tm.tm_hour+tm.tm_min+tm.tm_sec))  % dimen_matrix;
       y = (rand() + (tm.tm_hour+tm.tm_min+tm.tm_sec))  % dimen_matrix;
       val = 2;
       if(arr[x][y] == 1 && arr[x][y] != 0)
       {
          ori_mat[x][y] = val;
          arr[x][y] = val;
       }
       else
         i--;
    }
        
    traverse_in_the_Row((int *)arr, (int *)row, dimen_matrix);
    traverse_in_the_Col((int *)arr, (int *)col, dimen_matrix);
    printMatrix((int *)arr, (int *)row, (int *)col, (int *)row_defect, (int *)col_defect ,dimen_matrix);
      
      
    int defect_row_count=0, defect_col_count=0;
    
    int status = 1;
    for(int step=0; step<dimen_matrix; step++)
    {
      int maxRow=0, maxRowPos;
      int maxCol=0, maxColPos;
      int sumRow=0, sumCol=0;
      
      //Repairing the Defective in Row
      if(status == 1)
      {
        //Finding the Value and Position of Maximum Closed Defect in Row
        for(int i=0; i<dimen_matrix; i++)
    	{
          if(maxRow <= row[i][0])
          {
           maxRow = row[i][0];
           maxRowPos = i;
          }
        }
            
        //Finding the MAXIMUM Defect including OPEN Defect in Row
      	  for(int i=0; i<maxRowPos; i++)
      	  {
            if(row[i][0] == maxRow)
            {
              if(sumRow < row[i][0] + row[i][1])
              {
                sumRow = row[i][0] + row[i][1];
                maxRowPos = i;
              }
           }
      	  }//End of finding the Maximum Defect in Row
       
         cout << "MaxRow : " << maxRow << "\tPos : " << maxRowPos << endl;

       //Removing the Defective Junction in Row 
         for(int i=0; i<dimen_matrix; i++)
      	 { 
           if(arr[maxRowPos][i] == 2)// || arr[maxRowPos][i] == 0)
           {
            arr[maxRowPos][i] = 3;
            row_defect[maxRowPos] = 4;
           }
         }  
        status = 2;
        
       cout << "STEP : " << step << endl;
       traverse_in_the_Row((int *)arr, (int *)row, dimen_matrix);
       traverse_in_the_Col((int *)arr, (int *)col, dimen_matrix);      
       printMatrix((int *)arr, (int *)row, (int *)col, (int *)row_defect, (int *)col_defect, dimen_matrix);  
      }//End of Repairing in Row
      
      //Repairing the Defective in Columns
      else if(status == 2)
      {
        //Finding the Value and Position of Maximum Closed Defect in Row      
        for(int i=0; i<dimen_matrix; i++)
    	{
          if(maxCol <= col[i][0])
          {
           maxCol = col[i][0];
           maxColPos = i;
          }
        }
            
        //Finding the MAXIMUM Defect in Columns
      	  for(int i=0; i<maxColPos; i++)
      	  {
            if(col[i][0] == maxCol)
            {
              if(sumRow < col[i][0] + col[i][1])
              {
                sumCol = col[i][0] + col[i][1];
                maxColPos = i;
              }
            }
      	  }//End of finding the Maximum Defect in Columns
       
        cout << "MaxCol : " << maxCol << "\tPos : " << maxColPos << endl;           
              
        //Removing the Defective Junction in Columns 
         for(int i=0; i<dimen_matrix; i++)
      	 { 
           if(arr[i][maxColPos] == 2)// || arr[i][maxColPos] == 0)
           {
            arr[i][maxColPos] = 3;
            col_defect[maxColPos] = 4;
           }
         }  
        status = 1;
        
       cout << "STEP : " << step << endl;        
       traverse_in_the_Row((int *)arr, (int *)row, dimen_matrix);
       traverse_in_the_Col((int *)arr, (int *)col, dimen_matrix);      
       printMatrix((int *)arr, (int *)row, (int *)col, (int *)row_defect, (int *)col_defect, dimen_matrix);         
 	         
      }//End of Repairing in Columns 
    }   
    final_RowNCol((int *)row_defect, (int *)col_defect, dimen_matrix);
    
    int row_count=0, col_count=0;
    for(int j=0; j<dimen_matrix; j++)
    {
       if(row_defect[j] != 4)
            row_count += 1;
        if(col_defect[j] != 4)
            col_count += 1;
    }
    
    int final_mat=0;
    if(row_count < col_count)
      final_mat = row_count;
    else 
      final_mat = col_count;      
    
    int defect_open=0;
    for(int i=0; i<dimen_matrix; i++)
    {
      for(int j=0; j<dimen_matrix; j++)
      {
         if(arr[i][j] == 0)
            defect_open += 1;
      }
    }        
        
    fprintf(fp, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", tcase, dimen_matrix, struck_open, struck_close, row_count, col_count, final_mat, defect_open);	    
 
   }//End of test case
    return 0;
}
