#include <stdio.h>
#include <string.h>

/* ---------- FUNCTION DECLARATION ---------- */
int match(char text[100], char pattern[100]);

/* ---------- MAIN FUNCTION ---------- */
int main() {
    char text[100], pattern[100];
    int position;

    printf("*** Naive String Matching Algorithm ***\n");

    // Input the main string
    printf("Enter the string: ");
    scanf("%[^\n]", text);

    // Input the pattern to search
    printf("Enter the pattern to match: ");
    scanf(" %[^\n]", pattern);

    // Call matching function
    position = match(text, pattern);

    // Display result
    if (position == -1)
        printf("\nNo match found.\n");
    else
        printf("\nMatch found at position %d.\n", position);

    return 0;
}

/* ---------- MATCHING FUNCTION ---------- */
int match(char text[100], char pattern[100]) {
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) // All characters matched
            return i + 1; // Return 1-based position
    }
    return -1;
}
