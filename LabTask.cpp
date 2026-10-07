#include<iostream>
using namespace std;

string NumericCheck(string input)
{
    for(int i = 0; i < input.length(); i++)
    {
        if((int)input[i] < 48 || (int)input[i] > 57)
        {
            return "Not Numeric";
        }
    }
    return "Numeric Constant";
}

void OperatorCheck(string input)
{
    int count = 1;

    for(int i = 0; i < input.length(); i++)
    {
        if((int)input[i] == 43 ||(int)input[i] == 45 || (int)input[i] == 42 ||(int)input[i] == 47 || (int)input[i] == 37 || (int)input[i] == 61)
        {
            cout << "Operator " << count << ": " << input[i] << endl;
            count++;
        }
    }

    if(count == 1)
    {
        cout << "No Operator Found" << endl;
    }
}

string CommentCheck(string input)
{
    int n = input.length();

    if(n >= 2 && (int)input[0] == 47 && (int)input[1] == 47)
    {
        return "Single Line Comment";
    }

    if(n >= 4 &&
       (int)input[0] == 47 && (int)input[1] == 42 && (int)input[n-2] == 42 && (int)input[n-1] == 47)
    {
        return "Multiple Line Comment";
    }

    return "Not Comment";
}

string IdentifierCheck(string input)
{
    if(input.length() == 0)
    {
        return "Not Identifier";
    }

    if(!(((int)input[0] >= 65 && (int)input[0] <= 90) || ((int)input[0] >= 97 && (int)input[0] <= 122) || (int)input[0] == 95))
    {
        return "Not Identifier";
    }

    for(int i = 1; i < input.length(); i++)
    {
        if(!(((int)input[i] >= 65 && (int)input[i] <= 90) || ((int)input[i] >= 97 && (int)input[i] <= 122) || ((int)input[i] >= 48 && (int)input[i] <= 57) || (int)input[i] == 95))
        {
            return "Not Identifier";
        }
    }

    return "Identifier";
}

int main()
{
string input;
cout << "Enter Numeric Input: ";
cin >> input;
cout << NumericCheck(input) << endl;
cout << "Enter Expression: ";
cin >> input;
OperatorCheck(input);
cout << "Enter Comment: ";
cin >> input;
cout << CommentCheck(input) << endl;
cout << "Enter Identifier: ";
cin >> input;
cout << IdentifierCheck(input) << endl;
 return 0;
}