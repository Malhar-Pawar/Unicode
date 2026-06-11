#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int COP()   //Continue Operation?
{
	int cp;
	printf("\nWhat Next?\n1.\tChange Calculator\n2.\tUse Current Calculator\n3.\tExit Calculator\n");
	scanf(" %d", &cp);
	if(cp<1 || cp>3)
	{
		printf("Invalid Selection\n");
		return 1;
	}
	if(cp==1) return 1;
	if(cp==2) return 0;
	if(cp==3) exit(0);
}

void Basic()
{
	//Initializations
	float a,b,R;
	int cp,cop;
	char op;

	//Heading and Input1
	printf("\t\t---Arithmetic Calculator---\n\n");
	printf("Input:\t");
	scanf(" %f", &a);
	while(1)
	{
		//Operation Type and Input Validation
		printf("Input Operation Type (+,-,*,/):\t");
		scanf(" %c", &op);
		if(op!='+' && op!='-' && op!='*' && op!='/')
		{
			printf("Invalid Operation Type\n\n");
			continue;
		}

		//Input2
		printf("Input:\t");
		scanf(" %f", &b);

		//Operations
		switch(op)
		{
		case '+':
		{
			R=a+b;
			printf("\tResult: %.2f\n", R);
			break;
		}
		case '-':
		{
			R=a-b;
			printf("\tResult: %.2f\n", R);
			break;
		}
		case '*':
		{
			R=a*b;
			printf("\tResult: %.2f\n", R);
			break;
		}
		case '/':
		{
			if(b==0)
			{
				printf("Error\n");
				break;
			}
			R=a/b;
			printf("\tResult: %.2f\n", R);
			break;
		}
		}

		//Continue Operations?
		cop=COP();
		if(cop==0)
		{
			a=R;
			continue;
		}
		if(cop==1) break;
	}
}

void SciCal()    //Scientific Calculator
{
	//Initializations
	float a,b,R;
	int op,cop;

	//Heading
	printf("\t\t---Scientific Calculator---\n\n");
	while(1)
	{
		//Operation Type and Input Validation
		printf("Input Operation Type:\n1.\tArithmetic\n2.\tSin\t\t3.\tCos\t\t4.\tTan\n5.\tarcSin\t6.\tarcCos\t7.\tarcTan\n8.\tLogarithmic\n9.\tExponential\n10.\tAbsolute Value\n\n");
		scanf(" %d", &op);
		if(op<1 || op>10)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Operations
		switch(op)
		{
		case 1:
		{
			Basic();
			continue;
		}
		case 2:
		{
			printf("Input (in Rad):\t");
			scanf(" %f", &a);
			R = sin(a);
			printf("\tResult: %.2f\n", R);
			break;
		}
		case 3:
		{
			printf("Input (in Rad):\t");
			scanf(" %f", &a);
			R = cos(a);
			printf("\tResult: %.2f\n", R);
			break;
		}
		case 4:
		{
			printf("Input (in Rad):\t");
			scanf(" %f", &a);
			R = tan(a);
			printf("\tResult: %.2f\n", R);
			break;
		}
		case 5:
		{
			printf("Input (in Rad):\t");
			scanf(" %f", &a);
			R = asin(a);
			printf("\tResult: %.2f\n", R);
			break;
		}
		case 6:
		{
			printf("Input (in Rad):\t");
			scanf(" %f", &a);
			R = acos(a);
			printf("\tResult: %.2f\n", R);
			break;
		}
		case 7:
		{
			printf("Input (in Rad):\t");
			scanf(" %f", &a);
			R = atan(a);
			printf("\tResult: %.2f\n", R);
			break;
		}
		case 8:
		{
			printf("Input:\t");
			scanf(" %f", &a);
			R = log(a);
			printf("\tResult: %.2f\n", R);
			break;
		}
		case 9:
		{
			printf("Input:\t");
			scanf(" %f", &a);
			R = exp(a);
			printf("\tResult: %.2f\n", R);
			break;
		}
		case 10:
		{
			printf("Input:\t");
			scanf(" %f", &a);
			R = fabs(a);
			printf("\tResult: %.2f\n", R);
			break;
		}
		}
		//Continue Operations?
		cop=COP();
		if(cop==1) break;
	}
}

void PerCal()
{
	//Initializations
	float a,b,R;
	int op,cop;

	//Heading and Operation Type
	printf("\t\t---Percentage Calculator---\n\n");
	while(1)
	{
		//Operation Type and Input Validation
		printf("Input Operation Type:\n1.\tValue to Percentage\n2.\tPercentage to Value\n\n");
		scanf(" %d", &op);
		if(op<1 || op>2)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Operations
		switch(op)
		{
		case 1:
		{
			printf("Input:\t");
			scanf(" %f", &a);
			printf("Input:\t");
			scanf(" %f", &b);
			R= (a/b)*100;
			printf("\tResult: %.2f %\n",R);
			break;
		}
		case 2:
		{
			printf("Input (%):\t");
			scanf(" %f", &a);
			printf("Input (Value):\t");
			scanf(" %f", &b);
			R= (a*b)/100;
			printf("\tResult: %.2f\n",R);
			break;
		}
		}
		//Continue Operations?
		cop=COP();
		if(cop==1) break;
	}
}

void GCD()
{
	//Initializations
	int a,b,R,cop,temp;

	//Heading
	printf("\t\t---GCD Calculator---\n\n");
	while(1)
	{
		printf("Input:\t");
		scanf(" %d", &a);
		printf("Input:\t");
		scanf(" %d", &b);
		if(a==b)
		{
		}
		else
		{
			do
			{
				if(a<b)
				{
					temp=a;
					a=b;
					b=temp;
				}
				R=a%b;
				a=b;
				b=R;
			}
			while(R!=0);
		}
		printf("\tGCD: %d\n", a);

		//Continue Operations?
		cop=COP();
		if(cop==1) break;
	}
}

void ZS()
{
	//Initializations
	float a,b,c,R;
	int cop;

	//Heading
	printf("\t\t--- Z-Score Calculator---\n\n");
	while(1)
	{
		printf("Enter Score:\t");
		scanf(" %f", &a);
		printf("Enter Mean:\t\t");
		scanf(" %f", &b);
		printf("Enter Standard Deviation:\t");
		scanf(" %f", &c);
		R = (a-b)/c;
		printf("\tZ-Score = %.2f\n\n",R);

		//Continue Operation?
		cop=COP();
		if(cop==1) break;
	}
}

void AREA()
{
	//Initializations
	float a,b,R;
	int op, cop;

	//Heading
	printf("\t\t---Area Calculator---\n\n");
	while(1)
	{
		//Operation Type and Input Validation
		printf("Input Operation Type:\n1.\tTriangle\n2.\tSquare\n3.\tRectangle\n4.\tParallelogram\n5.\tRhombus\n6.\tCircle\n");
		scanf(" %d", &op);
		if(op<1 || op>6)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Operations
		switch(op)
		{
		case 1:
		{
			printf("Enter Base:\n");
			scanf(" %f", &a);
			printf("Enter Height:\n");
			scanf(" %f", &b);
			R = (a*b)/2;
			printf("\tArea of Triangle: %.2f\n", R);
			break;
		}
		case 2:
		{
			printf("Enter Side Length:\n");
			scanf(" %f", &a);
			R = a*a;
			printf("\tArea of Square: %.2f\n", R);
			break;
		}
		case 3:
		{
			printf("Enter Length:\n");
			scanf(" %f", &a);
			printf("Enter Width:\n");
			scanf(" %f", &b);
			R = a*b;
			printf("\tArea of Rectangle: %.2f\n", R);
			break;
		}
		case 4:
		{
			printf("Enter Base:\n");
			scanf(" %f", &a);
			printf("Enter Height:\n");
			scanf(" %f", &b);
			R = (a*b);
			printf("\tArea of Parallelogram: %.2f\n", R);
			break;
		}
		case 5:
		{
			printf("Enter Diagonal 1:\n");
			scanf(" %f", &a);
			printf("Enter Diagonal 2:\n");
			scanf(" %f", &b);
			R = (a*b)/2;
			printf("\tArea of Rhombus: %.2f\n", R);
			break;
		}
		case 6:
		{
			printf("Enter Radius:\n");
			scanf(" %f", &a);
			R = 3.14159*a*a;
			printf("\tArea of Circle: %.2f\n", R);
			break;
		}
		}
		//Continue Operation?
		cop=COP();
		if(cop==1) break;
	}
}

void VOL()
{
	//Initializations
	float a,b,c,R;
	int op,cop;

	//Heading
	printf("\t\t---Volume Calculator---\n\n");
	while(1)
	{
		//Operation Type and Input Validation
		printf("Input Operation Type:\n1.\tCone\n2.\tCube\n3.\tCuboid\n4.\tSquare Pyramid\n5.\tCylinder\n6.\tSphere\n");
		scanf(" %d", &op);
		if(op<1 || op>6)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Operations
		switch(op)
		{
		case 1:
		{
			printf("Enter Radius:\n");
			scanf(" %f", &a);
			printf("Enter Height:\n");
			scanf(" %f", &b);
			R = (3.14159*a*a*b)/3;
			printf("\tVolume of Cone: %.2f\n", R);
			break;
		}
		case 2:
		{
			printf("Enter Side Length:\n");
			scanf(" %f", &a);
			R = a*a*a;
			printf("\tVolume of Cube: %.2f\n", R);
			break;
		}
		case 3:
		{
			printf("Enter Length:\n");
			scanf(" %f", &a);
			printf("Enter Width:\n");
			scanf(" %f", &b);
			printf("Enter Height:\n");
			scanf(" %f", &c);
			R = a*b*c;
			printf("\tVolume of Cuboid: %.2f\n", R);
			break;
		}
		case 4:
		{
			printf("Enter Base Length:\n");
			scanf(" %f", &a);
			printf("Enter Height:\n");
			scanf(" %f", &b);
			R = (a*a*b)/3;
			printf("\tVolume of Square Pyramid: %.2f\n", R);
			break;
		}
		case 5:
		{
			printf("Enter Radius:\n");
			scanf(" %f", &a);
			printf("Enter Height:\n");
			scanf(" %f", &b);
			R = 3.14159*a*a*b;
			printf("\tVolume of Cyclinder: %.2f\n", R);
			break;
		}
		case 6:
		{
			printf("Enter Radius:\n");
			scanf(" %f", &a);
			R = 3.14159*a*a*a*1.33333;
			printf("\tVolume of Sphere: %.2f\n", R);
			break;
		}
		}

		//Continue Operation?
		cop=COP();
		if(cop==1) break;
	}
}

void SICal()
{
	//Initializations
	float a,b,c,R;
	int op,cop;

	//Heading
	printf("\t\t---SI Calculator---\n\n");
	while(1)
	{
		printf("Enter Principle Amount:\t");
		scanf(" %f", &a);
		printf("Enter Annual Interest Rate(%):\t");
		scanf(" %f", &b);
		printf("Enter Time Period (In Years):\t");
		scanf(" %f", &c);
		R=(a*b*c)/100;
		printf("\tSimple Interest: %.2f\n", R);

		//Continue Operation?
		cop=COP();
		if(cop==1) break;
	}
}

void PTCal()
{
	//Initializations
	float a,b,R;
	int op,cop;

	//Heading
	printf("\t\t---Pythagorean Theorem Calculator---\n\n");
	while(1)
	{
		//Input Options and Input Handelling
		printf("Input Operation Type\n1.\tFind Base\n2.\tFind Height\n3.\tFind Hypotenuse\n");
		scanf(" %d", &op);
		if(op<1 || op>3)
		{
			printf("Invalid Selection\n\n");
			continue;
		}

		//Operations
		switch(op)
		{
		case 1:
		{
			printf("Input Hypotenuse Length:\t");
			scanf(" %f", &a);
			printf("Input Height Length:\t");
			scanf(" %f", &b);
			R=(a*a)-(b*b);
			R=sqrt(R);
			printf("\tLength of Base:\t%.2f\n", R);
			break;
		}
		case 2:
		{
			printf("Input Hypotenuse Length:\t");
			scanf(" %f", &a);
			printf("Input Base Length:\t");
			scanf(" %f", &b);
			R=(a*a)-(b*b);
			R=sqrt(R);
			printf("\tLength of Height:\t%.2f\n", R);
			break;
		}
		case 3:
		{
			printf("Input Base Length:\t");
			scanf(" %f", &a);
			printf("Input Height Length:\t");
			scanf(" %f", &b);
			R=(a*a)+(b*b);
			R=sqrt(R);
			printf("\tLength of Hypotenuse:\t%.2f\n", R);
			break;
		}
		}

		//Continue Operations?
		cop=COP();
		if(cop==1) break;
	}
}

void RNG()
{
	//Initializations
	int a,b,R,temp,df,cop;

	//Heading
	printf("\t\t---Random Number Generator---\n\n");
	while(1)
	{
		//Range Input and Validation
		printf("Input the Range:\t");
		scanf(" %d %d", &a, &b);
		if(a==b)
		{
			printf("Invalid Range\n\n");
			continue;
		}
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}

		//Range bounded Random Number
		R=(rand()%(b-a+1))+a;
		printf("\tRandom Number:\t%d\n",R);
		//Continue Operations?
		cop=COP();
		if(cop==1) break;
	}
}

int main()
{
	//Initializations and Heading
	int CalSel,cp;
	srand(time(0));
	printf("\t\t\t\t-----All In One Calculator-----\n\n");

	//Calculator Selection
	while(1)
	{
		printf("Select the Calculator you Need (Input the Respective Index Numbers):\n1.\tArithmetic Calculator\n2.\tScientific Calculator\n3.\tPercentage Calculator\n4.\tGCD Calculator\n5.\tZ-Score Calculator\n6.\tArea Calculator\n7.\tVolume Calculator\n8.\tSimple Interest Calculator\n9.\tPythagorean Theorem Calculator\n10.\tRandom Number Generator\n\n");

		//User Input and Redirection
		scanf(" %d", &CalSel);
		if(CalSel<1 || CalSel>10)
		{
			printf("Invalid Selection\n\n");
			continue;
		}
		switch(CalSel)
		{
		case 1:
		{
			Basic();
			break;
		}
		case 2:
		{
			SciCal();
			break;
		}
		case 3:
		{
			PerCal();
			break;
		}
		case 4:
		{
			GCD();
			break;
		}
		case 5:
		{
			ZS();
			break;
		}
		case 6:
		{
			AREA();
			break;
		}
		case 7:
		{
			VOL();
			break;
		}
		case 8:
		{
			SICal();
			break;
		}
		case 9:
		{
			PTCal();
			break;
		}
		case 10:
		{
			RNG();
			break;
		}
		}
	}
	return 0;
}
