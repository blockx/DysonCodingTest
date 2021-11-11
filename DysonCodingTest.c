// DysonCodingTest.c : This file contains the 'main' function. Program execution begins and ends there.
//

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

/* Given 4 digits A, B, C and D determine how many times of a clock they can form
times are in 24hr format eg AB:CD

1/2 digit : {00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}
3rd digit : {0, 1, 2, 3, 4, 5}
4th digit : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

Take all the perms of the numbers and validate against the above tests ??
Efficiency is not required

4 * 3 * 2 * 1 = 24 perms of the 4 digits are
    {A,B,C,D}
    {A,B,D,C}
    {A,C,B,D}
    {A,C,D,B}
    {A,D,B,C}
    {A,D,C,B}
    {B,A,C,D}
    {B,A,D,C}
    {B,C,A,D}
    {B,C,D,A}
    {B,D,A,C}
    {B,D,C,A}
    {C,A,B,D}
    {C,A,D,B}
    {C,B,A,D}
    {C,B,D,A}
    {C,D,A,B}
    {C,D,B,A}
    {D,A,B,C}
    {D,A,C,B}
    {D,B,A,C}
    {D,B,C,A}
    {D,C,A,B}
    {D,C,B,A}

    simplest way is generate an array of all the perms and step through it testing the digits as above
*/

int perm_array[24][4];

void perm_digits(A, B, C, D)
{
    perm_array[0][0] = A; perm_array[0][1] = B; perm_array[0][2] = C; perm_array[0][3] = D;
    perm_array[1][0] = A; perm_array[1][1] = B; perm_array[1][2] = D; perm_array[1][3] = C;
    perm_array[2][0] = A; perm_array[2][1] = C; perm_array[2][2] = B; perm_array[2][3] = D;
    perm_array[3][0] = A; perm_array[3][1] = C; perm_array[3][2] = D; perm_array[3][3] = B;
    perm_array[4][0] = A; perm_array[4][1] = D; perm_array[4][2] = B; perm_array[4][3] = C;
    perm_array[5][0] = A; perm_array[5][1] = D; perm_array[5][2] = C; perm_array[5][3] = B;
    perm_array[6][0] = B; perm_array[6][1] = A; perm_array[6][2] = C; perm_array[6][3] = D;
    perm_array[7][0] = B; perm_array[7][1] = A; perm_array[7][2] = D; perm_array[7][3] = C;
    perm_array[8][0] = B; perm_array[8][1] = C; perm_array[8][2] = A; perm_array[8][3] = D;
    perm_array[9][0] = B; perm_array[9][1] = C; perm_array[9][2] = D; perm_array[9][3] = A;
    perm_array[10][0] = B; perm_array[10][1] = D; perm_array[10][2] = A; perm_array[10][3] = C;
    perm_array[11][0] = B; perm_array[11][1] = D; perm_array[11][2] = C; perm_array[11][3] = A;
    perm_array[12][0] = C; perm_array[12][1] = A; perm_array[12][2] = B; perm_array[12][3] = D;
    perm_array[13][0] = C; perm_array[13][1] = A; perm_array[13][2] = D; perm_array[13][3] = B;
    perm_array[14][0] = C; perm_array[14][1] = B; perm_array[14][2] = A; perm_array[14][3] = D;
    perm_array[15][0] = C; perm_array[15][1] = B; perm_array[15][2] = D; perm_array[15][3] = A;
    perm_array[16][0] = C; perm_array[16][1] = D; perm_array[16][2] = A; perm_array[16][3] = B;
    perm_array[17][0] = C; perm_array[17][1] = D; perm_array[17][2] = B; perm_array[17][3] = A;
    perm_array[18][0] = D; perm_array[18][1] = A; perm_array[18][2] = B; perm_array[18][3] = C;
    perm_array[19][0] = D; perm_array[19][1] = A; perm_array[19][2] = C; perm_array[19][3] = B;
    perm_array[20][0] = D; perm_array[20][1] = B; perm_array[20][2] = A; perm_array[20][3] = C;
    perm_array[21][0] = D; perm_array[21][1] = B; perm_array[21][2] = C; perm_array[21][3] = A;
    perm_array[22][0] = D; perm_array[22][1] = C; perm_array[22][2] = A; perm_array[22][3] = B;
    perm_array[23][0] = D; perm_array[23][1] = C; perm_array[23][2] = B; perm_array[23][3] = A;
}

int uniqueness_divisor (int A, int B, int C, int D)
{
    int divisor = 1;

    if (A == B) divisor *= 2; 
    if (A == C) divisor *= 2;
    if (A == D) divisor *= 2;
    if (B == C) divisor *= 2;
    if (B == D) divisor *= 2;
    if (C == D) divisor *= 2;

    return divisor;
}

int solution(int A, int B, int C, int D) 
{
    // write your code in C99 (gcc 6.2.0)
    perm_digits(A, B, C, D);

    int valid_time_count = 0;
    for (int i = 0; i < 24; i ++)
    {
        int hours = (perm_array[i][0] * 10) + perm_array[i][1];
        int tens = perm_array[i][2];
        int mins = perm_array[i][3];

        if ((hours <= 23) && (tens <= 5))
        {
            valid_time_count++;
        }
    }

    return valid_time_count;
}


int main(void)
{
    return solution(2, 3, 3, 2);
}

