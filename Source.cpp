#include <iostream>
#include <string>
#include <iomanip>     // for setw
#include "randgen.h"
using namespace std;
#include <vector>


void sort(const vector<vector<char>> & mat1 , vector<vector<char>> & mat2 , int rows, int cols, bool issecound )
{

	int j,k ;
	for (j=0; j < rows; j++)
    {
		for (k=0; k < cols; k++)
        {
			
				int adjesent;
				adjesent = 48;
				
				if ( j>= 1 && k>= 1 )
				{
					if (mat1[j-1][k-1] == 'B')
					{
						adjesent += 1;
						//cout<<"kas";
						
					}
				}
				if (j>= 1)
				{
					if (mat1[j-1][k] == 'B')
					{
						adjesent += 1;
					}
				}
				if (j>= 1 && k+2 <= cols ) // && k+1 <= cols
				{
					if (mat1[j-1][k+1] == 'B')
					{
						adjesent += 1;
					}
				}
				if (k>= 1)
				{
					if (mat1[j][k-1] == 'B')
					{
						adjesent += 1;
					}
				}
				if (k+2  <= cols )
				{
					if (mat1[j][k+1] == 'B')
					{
						adjesent += 1;
					}
				}
				if (j+2 <= rows && k+2  <= cols )
				{
					if (mat1[j+1][k+1] == 'B')
					{
						adjesent += 1;
					}
				}
			
				if (j+2 <= rows)
				{
					
					if (mat1[j+1][k] == 'B')
					{
						adjesent += 1;
					}
				}
				if (j+2 <= rows && k>= 1)
				{
						if (mat1[j+1][k-1] == 'B')
					{
						adjesent += 1;
					}
				}



				mat2[j][k] = (char)adjesent;
				adjesent = 48;

				
			}
       



	}
}

void Print(const vector<vector<char>> & mat)
{
    for (int j=0; j < mat.size(); j++)
    {   
		for (int k=0; k < mat[0].size(); k++)
        {   
			cout << setw(4) << mat[j][k];
        }
        cout << endl;
    }
}
void Print1(const vector<vector<char>>  mat , int a ,int b ,const vector<vector<char>> & mat1)
{

	cout<<"Displaying the surrounding of ("<<a<<","<<b<<"): \n";
    for (int j=0; j < mat.size(); j++)
    {   
		for (int k=0; k < mat[0].size(); k++)
		{  

			cout << setw(4);

            if ( j == a && k == b)
			{
				cout << mat1[j][k];
			}else
			{
				cout << mat[j][k];
			}


			
        }
        cout << endl;
    }

	//cout<<"\nAround ("<<a<<","<<b<<") you have "<< mat1[a][b] <<"bomb(s)\n";

}


int main()
{

	RandGen gen;
	int j,k,temp;
    int rows, cols,bomb,bomb1;
	int rowchosen , colchosen;
	char temp1;
	string depo;
	bool exist,issecound;
	exist = false ;
	depo = "acdf";
	cout << "Give the dimensions of the matrix: ";
    cin >> rows >> cols;
	
	vector<vector<char>> mat(rows, vector<char>(cols));
	vector<vector<char>> mat1(rows, vector<char>(cols));
	vector<vector<char>> mat2(rows, vector<char>(cols));
	//vector<vector<char>> mat(rows,cols));
	// a vector of vector<int> who has row many elements, which are vector<int>, all 0
	cout << "How many bombs:  ";
    cin >> bomb;
	if (bomb <= 0 || bomb >= rows*cols )
	{
		do
		{
			if (bomb >= rows*cols)
			{
				cout <<"The number of bombs can not be greater than the whole number of cells minus one. Please give the number of bombs again: ";
				cin >> bomb;
			}else
			{
				cout << "The number of bombs could not be less than one. Please give the number of bombs again: ";
	            cin >> bomb;

			}




		} while (bomb <= 0 || bomb >= rows*cols );
	
	}

    for (j=0; j < rows; j++)
    {
		for (k=0; k < cols; k++)
        {
			mat[j][k] = 'X';
        }
    }
	bomb1 = bomb; 
	mat2 = mat1;
	do
	{
		bomb = bomb1;
		for (j=0; j < rows; j++)	
		{

			for (k=0; k < cols; k++)
			{/*
				temp1 = gen.RandChar("123B");
				if (temp1 == 'B' && bomb != 0)
				{
					bomb -=1;
					mat1[j][k] = 'B';
				}else 
				{
					mat1[j][k] = gen.RandChar("123");
				}
				*/
				temp1 = gen.RandChar("FDKCB");
				if (temp1 == 'B' && bomb != 0)
				{
					bomb -=1;
					mat1[j][k] = 'B';
				}else 
				{
					mat1[j][k] = temp1;
				}
			}
		}
	} while (bomb != 0);



	for (j=0; j < rows; j++)
    {
		for (k=0; k < cols; k++)
        {
			
			if (mat1[j][k] != 'B')
			{
				int adjesent;
				adjesent = 48;
				
				if ( j>= 1 && k>= 1 )
				{
					if (mat1[j-1][k-1] == 'B')
					{
						adjesent += 1;
						//cout<<"kas";
						
					}
				}
				if (j>= 1)
				{
					if (mat1[j-1][k] == 'B')
					{
						adjesent += 1;
					}
				}
				if (j>= 1 && k+2 <= cols ) // && k+1 <= cols
				{
					if (mat1[j-1][k+1] == 'B')
					{
						adjesent += 1;
					}
				}
				if (k>= 1)
				{
					if (mat1[j][k-1] == 'B')
					{
						adjesent += 1;
					}
				}
				if (k+2  <= cols )
				{
					if (mat1[j][k+1] == 'B')
					{
						adjesent += 1;
					}
				}
				if (j+2 <= rows && k+2  <= cols )
				{
					if (mat1[j+1][k+1] == 'B')
					{
						adjesent += 1;
					}
				}
			
				if (j+2 <= rows)
				{
					
					if (mat1[j+1][k] == 'B')
					{
						adjesent += 1;
					}
				}
				if (j+2 <= rows && k>= 1)
				{
						if (mat1[j+1][k-1] == 'B')
					{
						adjesent += 1;
					}
				}



				mat1[j][k] = (char)adjesent;
				adjesent = 48;

				
			}
        }
    }
	mat2 = mat1;
	sort(mat1,mat2,rows,cols,issecound);
	
    Print(mat);
	cout<<endl;
    Print(mat1);
	cout<<endl;
	Print(mat2);

	while(exist == false)
	{
		
		cout <<"Press: \n \n" ;
		cout<<"1. If you want to find out the surrounding of a cel \n";
		cout<<"2. If you want to open the cell \n";
		cout<<"3. If you want to exit. \n";

		cin >> temp;
		while ( temp > 3 || temp < 1 )
		{
		cout<<"Your input is wrong. Please select one of the options: 1, 2 or 3. \n";
		cin >> temp;
		
		}

		if (temp == 3)
		{
			exist = true;
			
			cout<<"\nProgram exiting ...\n";
		}
		if (temp == 2)//opeing celss
		{
			cout<<"Give the coordinates: ";
			cin >> rowchosen >> colchosen ;
			while (rowchosen >= rows || rowchosen < 0 || colchosen >= cols || colchosen < 0 )
			{
				cout<<"It is out of range. Please give a valid coordinates:" ;
				cin >> rowchosen >> colchosen ;
			}
			mat[rowchosen][colchosen] = mat1[rowchosen][colchosen];
			cout<<"Opening cell ("<<rowchosen<<","<<colchosen<<"): \n";
			Print(mat);
			if (mat1[rowchosen][colchosen] == 'B')
			{
				exist = true;

				cout<<"\nUnfortunately, you stepped on a mine";
				cout<<"\nArrangement of mines: \n";
				Print(mat1);

				cout<<"\n>>>>> Game Over! <<<<<";

			}
				

		}
		if (temp == 1)
		{
			cout<<"Give the coordinates: ";
			cin >> rowchosen >> colchosen ;
			while (rowchosen >= rows || rowchosen < 0 || colchosen >= cols || colchosen < 0 )
			{
				cout<<"It is out of range. Please give a valid coordinates: ";
				cin >> rowchosen >> colchosen ;
			}
			Print1(mat,rowchosen,colchosen,mat2);
			

		}




	}

}