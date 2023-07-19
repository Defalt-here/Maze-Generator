#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define BLOCK (char)254
#define BLANK (char)32
char maze[10][50];
int rowCell = 1;
int colCell = 1;
int count = 0;
int main()
{
    srand(time(0));
    initiaise_maze();
    while(rowCell != 49)
    {
        path();
        system("cls");
        display();
        printf("%d",colCell);
    }
    system("cls");
    while(count != 90){
        make_way();
        count++;
        //printf("%d\n",count);
    }
    display();
    return 0;
}
void path()
{
    if(colCell > 8){
        colCell--;
    }
    if(colCell < 2){
        colCell++;
    }
    if(rowCell > 48){
        rowCell--;
    }
    if(rowCell < 2){
        rowCell++;
    }
    if(get_direction() == 4)
    {
        colCell++;
    }
    else if(get_direction() == 3 || get_direction() == 6)
    {
        rowCell++;
    }
    else if(get_direction() == 2 || get_direction() == 5)
    {
        colCell--;
    }
    else if(get_direction() == 1)
    {
        rowCell--;
    }
    if(maze[rowCell][colCell] == BLOCK)
    {
        maze[rowCell][colCell] = BLANK;
    }
    else if(maze[rowCell][colCell] == BLANK)
    {
        maze[rowCell][colCell] = BLANK;
    }
}
void make_way()
{
    //if(colCell < 9 && colCell > 0 && rowCell < 48 && rowCell > 0)
    //{
    if(colCell > 8 || colCell < 2)
    {
        randCell();
    }
    if(rowCell > 48 || rowCell < 2)
    {
        randCell();
    }
    if(get_direction() == 1)
    {
        colCell++;
    }
    else if(get_direction() == 2 || get_direction() == 5)
    {
        rowCell++;
    }
    else if(get_direction() == 3 || get_direction() == 6)
    {
        colCell--;
    }
    else if(get_direction() == 4)
    {
        rowCell--;
    }
    if(maze[rowCell][colCell] == BLOCK)
    {
        maze[rowCell][colCell] = BLANK;
    }
    else if(maze[rowCell][colCell] == BLANK)
    {
        randCell();
    }
}
void initiaise_maze() // 10 Rows and 50 Columns
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            maze[j][i] = BLOCK;
        }
    }
}
void display()
{
    for(int i = 0; i < 10; i++)
    {
        printf("\n");
        for(int j = 0; j < 50; j++)
        {
            printf("%c", maze[j][i]);
        }
    }
}
int get_direction()
{
    int randDirect = rand();
    randDirect = 1 + randDirect%6;
    return randDirect;
}

void randCell()
{
    int randColl = rand();// 10 Rows and 50 Columns
    int randRow = rand();
    randRow = 1 + randColl%49;
    randColl = 1 + randRow%9;
    rowCell = randRow;
    colCell = randColl;
}
