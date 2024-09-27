/***************************************************************
CSCI 241         John White     Spring 2024

Programmer: z19942444

Section: 241-0002

Date Due: ASAP

Purpose: Compute the score of a dice game.
***************************************************************/

/*

    /ᐠ - ˕ -マ

    @hiibolt on GitHub 

*/

bool is_even ( int num ) {
    return num % 2 == 0;
};
bool is_odd ( int num ) {
    return num % 2 != 0;
};

/**
 * @brief Compute the score of a dice game
 * 
 * @param array The array of dice values
 * 
 * @return The score of the game
 */
int compute_score (int array[][4] ) {
    int score = 0;

    /*
    1. Start with a score of 0,
    2. If all four corners are even numbers, add 20 pts to the score,
    3. If all four corners are odd numbers, add 20 pts to the score,
    4. If all four dice on a diagonal are even numbers, add 20 pts to the score,
    5. If all four dice on a diagonal are odd numbers, add 20 pts to the score,
    6. If all four dice on any row are even numbers, add 20 pts to the score,
    7. If all four dice on any row are odd numbers, add 20 pts to the score,
    8. If all four dice on any column are even numbers, add 20 pts to the score,
    9. If all four dice on any column are odd numbers, add 20 pts to the score,
    10. Add to the score the total value (sum) of all 16 dice.
    */

    // Check if the four cornenrs are even, then check if they are odd
    if ( is_even(array[0][0]) && is_even(array[0][3]) && is_even(array[3][0]) && is_even(array[3][3]) ) {
        score += 20;
    } else if ( is_odd(array[0][0]) && is_odd(array[0][3]) && is_odd(array[3][0]) && is_odd(array[3][3]) ) {
        score += 20;
    }

    // Check if the first diagonal is even, then check if they are odd
    if ( is_even(array[0][0]) && is_even(array[1][1]) && is_even(array[2][2]) && is_even(array[3][3]) ) {
        score += 20;
    } else if ( is_odd(array[0][0]) && is_odd(array[1][1]) && is_odd(array[2][2]) && is_odd(array[3][3]) ) {
        score += 20;
    }

    // Check if the second diagonal is even, then check if they are odd
    if ( is_even(array[0][3]) && is_even(array[1][2]) && is_even(array[2][1]) && is_even(array[3][0]) ) {
        score += 20;
    } else if ( is_odd(array[0][3]) && is_odd(array[1][2]) && is_odd(array[2][1]) && is_odd(array[3][0]) ) {
        score += 20;
    }

    // Check if the rows are even, then check if they are odd
    for ( int i = 0; i < 4; i++ ) {
        if ( is_even(array[i][0]) && is_even(array[i][1]) && is_even(array[i][2]) && is_even(array[i][3]) ) {
            score += 20;
            break;
        } else if ( is_odd(array[i][0]) && is_odd(array[i][1]) && is_odd(array[i][2]) && is_odd(array[i][3]) ) {
            score += 20;
            break;
        }
    }

    // Check if the columns are even, then check if they are odd
    for ( int i = 0; i < 4; i++ ) {
        if ( is_even(array[0][i]) && is_even(array[1][i]) && is_even(array[2][i]) && is_even(array[3][i]) ) {
            score += 20;
            break;
        } else if ( is_odd(array[0][i]) && is_odd(array[1][i]) && is_odd(array[2][i]) && is_odd(array[3][i]) ) {
            score += 20;
            break;
        }
    }

    // Add the total value of all 16 dice
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 4; j++ ) {
            score += array[i][j];
        }
    }

    return score;
};