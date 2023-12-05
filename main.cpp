//tik-tak-toe
//positions are: 11 12 13
//               21 22 23
//               31 32 33
#include <iostream>

using namespace std;

int  xWin = 0, oWin = 0;

void resetMatrix(int matrix[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = 0; 
        }
    }
}

void print(int matrix[4][4])
{
    for(int i = 1; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            if (matrix[i][j] == 1)
            {
                cout<<"X ";
            }
            else if (matrix[i][j] == 4)
            {
                cout<<"O ";
            }
            else cout << "_ ";            
        }
        cout << endl;
    }
}

bool win(int matrix[4][4])
{
    int sum = 0;
    //horisontal
    for(int i = 1; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            sum+= matrix[i][j];
        }
        if (sum == 3)
        {
            cout<<"CONGTATULATIONS!! X WON";
            xWin++;
            return true;
        }
        else if (sum == 12)
        {
            cout<<"CONGTATULATIONS!! O WON";
            oWin++;
            return true;
        }
        else sum = 0;
    }
    //vertical
    for(int i = 1; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            sum+= matrix[j][i];
        }
        if (sum == 3)
        {
            cout<<"CONGTATULATIONS!! X WON";
            xWin++;
            return true;
        }
        else if (sum == 12)
        {
            cout<<"CONGTATULATIONS!! O WON";
            oWin++;
            return true;
        }
        else sum = 0;
    }
    //diagonal
    if ((matrix[1][1] + matrix[2][2] + matrix[3][3]) == 3)
    {
        cout<<"CONGTATULATIONS!! X WON";
        xWin++;
        return true;
    }
    else if ((matrix[1][1] + matrix[2][2] + matrix[3][3]) == 12)
    {
        cout<<"CONGTATULATIONS!! O WON";
        oWin++;
        return true;
    }
    else if ((matrix[1][3] + matrix[2][2] + matrix[3][1]) == 3)
    {
        cout<<"CONGTATULATIONS!! X WON";
        xWin++;
        return true;
    }
    else if ((matrix[1][3] + matrix[2][2] + matrix[3][1]) == 12)
    {
        cout<<"CONGTATULATIONS!! O WON";
        oWin++;
        return true;
    }
    return false;
}

int main()
{
    int matrix[4][4] = {0};
    int x, o, a, b;
    char c;
    do 
    {
        resetMatrix(matrix);
        for (int i=0; i<5; i++)
        {
            //player x
            cout <<"player x: ";
            cin >> x;
            a = x / 10;
            b = x % 10;
            while(((matrix[a][b] == 1) || (matrix[a][b] == 4)) || ((x!=11) && (x!=12) && (x!=13) && (x!=21) && (x!=22) && (x!=23) && (x!=31) && (x!=32) && (x!=33)))
            {
                cout <<"Invalid input. Player x again: ";
                cin >> x;
                a = x / 10;
                b = x % 10;
            }
            matrix[a][b] = 1;
            print(matrix);
            
            if (win(matrix))
                break;

            //DRAW
            if (i == 4)
            {
                cout << "Sorry, it's a draw." << endl;
                break;;
            }
            //player 0
            cout <<"player O: ";
            cin >> o;
            a = o / 10;
            b = o % 10;
            while(((matrix[a][b] == 1) || (matrix[a][b] == 4)) || ((o!=11) && (o!=12) && (o!=13) && (o!=21) && (o!=22) && (o!=23) && (o!=31) && (o!=32) && (o!=33)))
            {
                cout <<"Invalid input. Player o again: ";
                cin >> o;
                a = o / 10;
                b = o % 10;
            }
            matrix[a][b] = 4;
            print(matrix);

            if (win(matrix))
                break;
        }
        cout << endl << "The current result is: X:= " << xWin << " O:= " << oWin << endl; 
        cout <<  "Do you want to play another game?: [Y]es/[N]o " << endl;
        cin >> c;
        while ((toupper(c)!='Y') && (toupper(c)!='N'))
        {
            cout << "Invalid input! Please choose [Y]es/[N]o" << endl;
            cin >> c;
        }
    }while (toupper(c) == 'Y');

    return 0;
}