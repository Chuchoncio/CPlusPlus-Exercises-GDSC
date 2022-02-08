#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    int num1, num2, greatestCommonDivisor, prevNum2;
    int timesDivTwoNum1, timesDivThreeNum1, timesDivFiveNum1, timesDivSevenNum1;
    int timesDivTwoNum2, timesDivThreeNum2, timesDivFiveNum2, timesDivSevenNum2;

    timesDivTwoNum1 = 0;
    timesDivThreeNum1 = 0;
    timesDivFiveNum1 = 0;
    timesDivSevenNum1 = 0;
    timesDivTwoNum2 = 0;
    timesDivThreeNum2 = 0;
    timesDivFiveNum2 = 0;
    timesDivSevenNum2 = 0;

    num1 = 64;
    num2 = 48;
    greatestCommonDivisor = 1;

    while (num1 != 1 || num2 != 1)
    {
        cout << num1 << " ";

        if (num1 != 1)
        {
            if (num1 % 2 == 0)
            {
                num1 /= 2 ;
                timesDivTwoNum1++;
            }
            else if (num1 % 3 == 0)
            {
                num1 /= 3 ;
                timesDivThreeNum1++;
            }
            else if (num1 % 5 == 0)
            {
                num1 /= 5 ;
                timesDivFiveNum1++;
            }
            else if (num1 % 7 == 0)
            {
                num1 /= 7 ;
                timesDivSevenNum1++;
            }
        }

        cout << num2 << endl;

        if (num2 != 1)
        {
            if (num2 % 2 == 0)
            {
                num2 /= 2;
                timesDivTwoNum2++;
            }
            else if (num2 % 3 == 0)
            {
                num2 /= 3;
                timesDivThreeNum2++;
            }
            else if (num2 % 5 == 0)
            {
                num2 /= 5;
                timesDivFiveNum2++;
            }
            else if (num2 % 7 == 0)
            {
                num2 /= 7;
                timesDivSevenNum2++;
            }
        }
    }

    if( timesDivTwoNum1 > 0 && timesDivTwoNum2 > 0)
    {
        if( timesDivTwoNum1 == timesDivTwoNum2 )
            greatestCommonDivisor *= pow(2,timesDivTwoNum1);
        else if( timesDivTwoNum1 > timesDivTwoNum2 )
            greatestCommonDivisor *= pow(2,timesDivTwoNum2);
        else
            greatestCommonDivisor *= pow(2,timesDivTwoNum1);
    }

    if( timesDivThreeNum1 > 0 && timesDivThreeNum2 > 0 )
    {
        if( timesDivThreeNum1 == timesDivThreeNum2 )
            greatestCommonDivisor *= pow(2,timesDivThreeNum1);
        else if( timesDivThreeNum1 > timesDivThreeNum2 )
            greatestCommonDivisor *= pow(2,timesDivThreeNum2);
        else
            greatestCommonDivisor *= pow(2,timesDivThreeNum1);
    }

    if( timesDivFiveNum1 > 0 && timesDivFiveNum2 > 0 )
    {
        if( timesDivFiveNum1 == timesDivFiveNum2 )
            greatestCommonDivisor *= pow(2,timesDivFiveNum1);
        else if( timesDivFiveNum1 > timesDivFiveNum2 )
            greatestCommonDivisor *= pow(2,timesDivFiveNum2);
        else
            greatestCommonDivisor *= pow(2,timesDivFiveNum1);
    }

    if( timesDivSevenNum1 > 0 && timesDivSevenNum2 > 0 )
    {
        if( timesDivSevenNum1 == timesDivSevenNum2 )
            greatestCommonDivisor *= pow(2,timesDivSevenNum1);
        else if( timesDivSevenNum1 > timesDivSevenNum2 )
            greatestCommonDivisor *= pow(2,timesDivSevenNum1);
        else
            greatestCommonDivisor *= pow(2,timesDivSevenNum1);
    }

    cout << "The Greatest Common Divisor is: " << greatestCommonDivisor << endl;

    return 0;
}