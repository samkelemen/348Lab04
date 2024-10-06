#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int element_of(int* set, int size, int num)
{   
    /* Returns 1, if num is an elemnt of the array, set.
     * Returns 0 otherwise.
     */
    // Iterates over the indices of the set
    for (int i = 0; i < size; i++)
    {
        // If num equals an element of the set
        if (set[i] == num)
        {   
            // Return 1, as the num is an element of the set
            return 1;
        }
    }
    // If num is not equal to any of the elements of set, return 0
    return 0;
}

int valid_score(int* combination, int len_combination)
{   
    /* Takes in a combination and the number of elements, and returns 1 or 0,
     * 1 for the score being valid (including only possible scores in football)
     * and 0 for the score being invalid (including score amounts that are impossible,
     * for example: 4 points cannot be scored at once in football.)
     */
    // Define the valid points that can be scored in one event. 
    int points[] = {6, 7, 8, 3, 2};
    int len_points = 5;

    // Initialize is_valid to 1.
    int is_valid = 1;

    // Iterate over the indices of combination
    for (int i = 0; i < len_combination; i++)
    {
        // If the ith element of combination is not a valid number of points
        if (element_of(points, len_points, combination[i]) == 0)
        {   
            // Set is_valid to 0 (False)
            is_valid = 0;
            // Break out of loop since we know it's not valid already
            break;
        }
    }
    return is_valid;
}

void print_score(int* combination, int len_combination)
{   
    /* Given a score combination, prints the inputted score in the following format:
     * "%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", num_td_plus2, num_td_plus_fg, num_td, num_fg, num_safety
     */
    // Initialize counters for each of the score types at zero
    int num_td_plus2 = 0;
    int num_td_plus_fg = 0;
    int num_td = 0;
    int num_fg = 0;
    int num_safety = 0;

    // Iterate over each index of the combination
    for (int i = 0; i < len_combination; i++)
    {   
        // For each scoring method, increment the num if 
        switch (combination[i]) {
            case 8: num_td_plus2++;
                    break;
            case 7: num_td_plus_fg++;
                    break;
            case 6: num_td++;
                    break;
            case 3: num_fg++;
                    break;
            case 2: num_safety++;
                    break;
        }
    }
    // Print the score
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", num_td_plus2, num_td_plus_fg, num_td, num_fg, num_safety);
}

void score_combinations(int score, int sum, int* combination, int len_combination, int start)
{   
    /* Recursively finds all combinations of numbers that sum to the given score. Then prints 
     * each combination if each of the numbers is a valid number of points that can be scored
     * at once in a game of american football.
     */
    // If the combination sums to the given score and the combination is a valid score in football
    if (sum == score && valid_score(combination, len_combination) == 1)
    {   
        // Print the combination
        print_score(combination, len_combination);
    }
    
    // Make a recursive call to the function to calculate all possible valid score combinations
    for (int j = start; j <= score - sum; j++)
    {   
        // Set the last element of the combination to j
        combination[len_combination] = j;
        // Make the recursive call
        score_combinations(score, sum + j, combination, len_combination + 1, j);
    }
}

int main()
{
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        // Ask for and read in a score.
        int score;
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        // If score is 0 or 1
        if (score == 0 || score == 1)
        {
            // Stop asking for input. End the program  
            break;
        }

        // Dynamically allocate an block of memory large enough for score number of bits.
        int* combination = malloc(score * sizeof(int));

        // Call the score combinations function to print the possible score combinations.
        score_combinations(score, 0, combination, 0, 1);
    }
}