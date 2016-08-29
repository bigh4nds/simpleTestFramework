#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<fstream>
#include<float.h>

using namespace std;

class QuadraticSolution
{
	private:
		
		float before_sqrt, inside_sqrt, after_sqrt, x1, x2;
		float coeffs[4];
		int i;
		float a,b,c;
		char output[100];
		char *pch;

	public:
		
		QuadraticSolution()
		{
			a = b = c = 0;
			before_sqrt = inside_sqrt = after_sqrt = 0;
			x1 = x2 = 0;
			i = 0;

			calculateRoots();
		}

		bool IsFiniteNumber (float x)
		{
			return (x <= FLT_MAX && x >= -FLT_MAX);
		}

		void calculateRoots ()
		{
			ifstream myReadFile;
			myReadFile.open("./input.txt");
		
			if (myReadFile.is_open()) 
			{
				while (!myReadFile.eof()) 
				{
					myReadFile >> output;
	
				    pch = strtok(output,",");
					while (pch != NULL)
					{
						coeffs[i] = atof(pch);
						//cout << endl << coeffs[i] << "\t" << IsFiniteNumber(coeffs[i]);
						pch = strtok(NULL, ",");
						i++;
					}
				}
			}
			myReadFile.close();

			a = coeffs[0];
			b = coeffs[1];
			c = coeffs[2];
			
			if (a == 0)
			{
				x1 = -c / b;
				x2 = -c / b;
			}
			else
			{
				b = b/a;
				c = c/a;

				before_sqrt = (b/2)*(-1);
				inside_sqrt = pow(0.5*b,2)-c;

				if (inside_sqrt < 0 || (!IsFiniteNumber(a)) || (!IsFiniteNumber(b)) || (!IsFiniteNumber(c)) )
				{
					cout << "Error" << endl;
					exit(0);
				}
				else
					after_sqrt=sqrt (inside_sqrt);
		
				x1=before_sqrt+after_sqrt;
				x2=before_sqrt-after_sqrt;
	
			}
				cout << x1 << endl;
				cout << x2 << endl;
		}
};
		
int main () {
	QuadraticSolution qs;
	return 0;
}
 	

