/* Copyright (C) 2020 Sai Manasa S
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Description: This is a program used to find 2 integer array 
 * elements that add up to a given target sum
 *
 * Revision History:
 * Initial version: 1 - July 4th, 2020: Added code to solve Prison cell
 * Another version: 2 - July 5th, 2020: Added code to solve Ugly Number II
 */

#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (): left(NULL), right(NULL){}
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *left, TreeNode* right): val(x), left(left), right(right) {}
} TreeNode;

/*vector<vector<int>> levelOrderBottom(TreeNode *root)
{
	
}*/

void prison_cells()
{
	int array[] = {1,0,0,1,0,0,1,0}; //[0,1,0,1,1,0,0,1], N = 7; 1,0,0,1,0,0,1,0
	int  i = 0;
	long int n = 0;
	vector<int> in_cells, out_cells, orig_cells;
	in_cells.assign(array, array + 8);
	out_cells.assign(array, array + 8);
	orig_cells.assign(array, array + 8);

	for(i = 0; i < 8; i++)
	{
		//cout << in_cells.at(i);
		cout << out_cells.at(i);
	}
	cout << endl;

	//cout << "DBG#1 " << endl;
	out_cells.at(0) = 0;
	out_cells.at(7) = 0;
	for(n = 1; n < 999999999; n++) // 7 days 1000000000 days
	{
		for(i = 1; i < 7; i++) // 1 to (number-1) of prison cells
		{
			//cout << "DBG#2 ";
			if( in_cells[i - 1] == in_cells[i + 1])
			{
				//cout << "DBG#3 ";
				out_cells[i] = 1;
			}
			else
			{
				//cout << "DBG#4 ";
				out_cells[i] = 0;
			}
		}

	    /*for(int j = 0; j < 8; j++)
		{
			cout << out_cells.at(j);
		}*/

		cout << endl;
	    out_cells[0] = 0;
	    out_cells[7] = 0;

		in_cells = out_cells;
		//in_cells[0] = 0;
	    //in_cells[7] = 0;
	}

	for(i = 0; i < 8; i++)
	{
		cout << out_cells.at(i);
	}

}

vector<int> prison_cells_v2(vector<int> in_cells, int N)
{

	//int array[] = {1,0,0,1,0,0,1,0}; //[0,1,0,1,1,0,0,1], N = 7; 1,0,0,1,0,0,1,0
	int  i = 0, num_of_prison_cells = 0;
	int n = N; // number of days input
	vector<int> out_cells;
	out_cells = in_cells;
	num_of_prison_cells = in_cells.size();

	/*out_cells.assign(array, array + num_of_prison_cells);
	orig_cells.assign(array, array + num_of_prison_cells);*/

	/*for(i = 0; i < num_of_prison_cells; i++)
	{
		//cout << in_cells.at(i);
		cout << out_cells.at(i);
	}
	cout << endl;*/

	//cout << "DBG#1 " << endl;
	out_cells.at(0) = 0;
	out_cells.at(num_of_prison_cells - 1) = 0;

	for(int j = 1; j < n; j++) // 7 days 1000000000 days
	{
		for(i = 1; i < (num_of_prison_cells-1); i++) // 1 to (number-1) of prison cells
		{
			//cout << "DBG#2 ";
			if( in_cells[i - 1] == in_cells[i + 1])
			{
				//cout << "DBG#3 ";
				out_cells[i] = 1;
			}
			else
			{
				//cout << "DBG#4 ";
				out_cells[i] = 0;
			}
		}

	    /*for(int j = 0; j < 8; j++)
		{
			cout << out_cells.at(j);
		}*/

		//cout << endl;
	    out_cells[0] = 0;
	    out_cells[num_of_prison_cells-1] = 0;

		in_cells = out_cells;
		//in_cells[0] = 0;
	    //in_cells[7] = 0;
	}

	/*for(i = 0; i < num_of_prison_cells; i++)
	{
		cout << out_cells.at(i);
	}
	cout << endl;*/
	return out_cells;
}

vector<int> prison_cells_leetcodeversion(vector<int>& cells, int N) 
{
        int  i = 0, num_of_prison_cells = 0;
        int n = N; // number of days input
        vector<int> out_cells;
        out_cells = cells;
        num_of_prison_cells = cells.size();

        out_cells.at(0) = 0;
        out_cells.at(num_of_prison_cells - 1) = 0;

        for(int j = 1; j <= n; j++) // 7 days 1000000000 days
        {
            for(i = 1; i < (num_of_prison_cells-1); i++) // 1 to (number-1) of prison cells
            {
                if( cells[i - 1] == cells[i + 1])
                {
                    out_cells[i] = 1;
                }
                else
                {
                    out_cells[i] = 0;
                }
            }

            out_cells[0] = 0;
            out_cells[num_of_prison_cells-1] = 0;

            cells = out_cells;
            for(int k = 0; k < num_of_prison_cells; k++)
            {
                cout << out_cells[k];
            }
            cout << endl;

        }

        return out_cells;
    }

void traverseTree(TreeNode *root)
{
	if(root->left)
	{
		cout << "DEBG#1";
		traverseTree(root->left);
		cout << root->left->val << " " ;
	}
	else if(root->right)
	{
		cout << "DEBG#2";
		traverseTree(root->right);
		cout << root->right->val << " ";
	}
	else if(root->left == NULL && root->right == NULL)
	{
		cout << "DEBG#3";
		cout << root->val << " ";
	}
}

// *******************************************************
// Function:    isprime()
// Description: Function to validate if the number, 
//              is a prime number or not.
// Input:       n - Number to be validated for being a prime number
// Output:      True - if it is a prime number, else False
// *******************************************************

bool isprime(int n)
{
	unsigned int i = 1;
	bool ret_val = true;

	vector<int> divisors;

	for(i = 1; i <= n; i++)
	{
		if(n%i == 0)
		{
			divisors.emplace_back(i);
		}
	}

	/*for(i = 0; i < divisors.size(); i++)
	{
		cout << divisors[i] << " ";
	}
	cout << endl;*/

	if(divisors.size() > 2)
	{
		ret_val = false;
	}
	return ret_val;
}

// *******************************************************
// Function:    get_divisors()
// Description: Function to get all the divisors of the 
//              input number.
// Input:       n - Number whose divisors are needed
// Output:      vector of ints - all divisors of the number
// *******************************************************

vector<int> get_divisors(int n)
{
	unsigned int i = 1;

	vector<int> divisors;

	for(i = 1; i <= n; i++)
	{
		if(n%i == 0)
		{
			divisors.emplace_back(i);
		}
	}

	/*for(i = 0; i < divisors.size(); i++)
	{
		cout << divisors[i] << " ";
	}*/

	//cout << endl;
	return divisors;
}

// *******************************************************
// Function:    get_prime_divisors()
// Description: Function to return a vector of divisors
//              of the input number, that are prime numbers
// Input:       n - Number whose divisors that are prime numbers
// Output:      vector of int - Vector containing divisors
//              of the number, that are prime numbers
// *******************************************************

vector<int> get_prime_divisors(int n)
{
	unsigned int i = 1;

	vector<int> divisors;

	for(i = 1; i <= n; i++)
	{
		if(n%i == 0)
		{ 
			if(isprime(i))
			{
				divisors.emplace_back(i);
			}
		}
	}

	/*for(i = 0; i < divisors.size(); i++)
	{
		cout << divisors[i] << " ";
	}*/

	//cout << endl;
	return divisors;
}

// *******************************************************
// Function:    print_nthUglyNumber()
// Description: Function to return the n-th ugly number, 
//              after validating it, else return -1.
// Input:       n - Number to be validated for being ugly number
// Output:      n - if it is an ugly number, else -1
// *******************************************************

int print_nthUglyNumber(int n)
{
	int c = 0;
	bool ret_val = false;

	vector<int> vect_of_divisors = get_prime_divisors(n);//get_divisors(n);

	for(int i = 0; i < vect_of_divisors.size(); i++)
	{
		//cout << vect_of_divisors[i] << " " ;
		if((vect_of_divisors[i] == 1) || (vect_of_divisors[i] == 2) || (vect_of_divisors[i] == 3) || (vect_of_divisors[i] == 5))
		{
            c++;
			ret_val = true;
		}
		else
		{
			ret_val = false;
		}
	}
	//cout << "ret_val: " << ret_val << endl;

	if(ret_val)
	{
		return n;
	}
	else
	{
		return -1;
	}
}

// *******************************************************
// Function: nthuglyNumber()
// Description: Function to find the n-th ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
// Example:
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
// ugly numbers.
// Note: 
// 1) 1 is typically treated as an ugly number.
// 2) n does not exceed 1690.
// Input: The n-th ugly number
// Output: The n-th ugly number
// Hint #1: The naive approach is to call isUgly for every number until you 
// reach the nth one. Most numbers are not ugly. Try to focus your effort 
// on generating only the ugly ones.
//
// Hint #2: An ugly number must be multiplied by either 2, 3, or 5 from a 
// smaller ugly number.
//
// Hint #3: The key is how to maintain the order of the ugly numbers. 
// Try a similar approach of merging from three sorted lists: L1, L2, and L3.
//
// Hint #4: Assume you have Uk, the kth ugly number. 
// Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
// *******************************************************
// NOTE: The above is an excerpt from leetcode.com, however the implementation
// is not from leetcode.com

void nthuglyNumber(int n)
{
	int count = n;
	cout << "n: " << n << " ";
	for(int i = 1; i <=count ; i++)
	{
		int temp = print_nthUglyNumber(i);
		if(temp != -1)
		{
			cout << "nthUglyNumber: " << temp << " " << endl;
		}
		else
		{
			count++;
		}
	}
}

//3,9,20,null,null,15,7
void main()
{
	TreeNode l1(9), r1(20), l2(15), r2(7) ;
	TreeNode root(3, &l1, &r1);
	//traverseTree(&root);

	/*int array[] = {0,1,0,1,1,0,0,1};
	
	vector<int> inp_cells, output;
	inp_cells.assign(array, array + sizeof(array));

	output = prison_cells_v2(inp_cells, 7);
	for(int i = 0; i < 8; i++)
	{
		cout << output.at(i);
	}*/

	//cout << "Output of isprime(number):" << isprime(5) << endl;
	//int arr_ugly_div[] = {2,3,5};
	int c = 0;
	bool ret_val = false;

	//vector<int> vect_of_uglynum_divisors;
	//vect_of_uglynum_divisors.assign(arr_ugly_div, arr_ugly_div + 3);

	vector<int> vect_of_divisors = get_prime_divisors(11);
	//sort(vect_of_divisors.begin(), vect_of_divisors.end());

	for(int i = 0; i < vect_of_divisors.size(); i++)
	{
		//cout << vect_of_divisors[i] << " " ;
		if((vect_of_divisors[i] == 1) || (vect_of_divisors[i] == 2) || (vect_of_divisors[i] == 3) || (vect_of_divisors[i] == 5))
		{
            c++;
			ret_val = true;
		}
		else
		{
			ret_val = false;
		}
	}
	//cout << "ret_val: " << ret_val << endl;
	nthuglyNumber(10);

	/*for(int j = 1; j <= 10; j++)
	{
		int temp = print_nthUglyNumber(j);
		cout << "nthUglyNumber:" << temp << " " ;
	}*/

	//unordered_set<int> set_of_divisors;

	while(1);
}
