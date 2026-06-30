#include <stdio.h>

int main() {
    char questions[5][100] = {
        "What is the capital of India?",
        "Which language is used for Android development (modern)?",
        "What does CPU stand for?",
        "Which data structure uses FIFO?",
        "What is the size of int in C (typically)?"
    };

    char options[5][4][50] = {
        {"a) Mumbai", "b) Delhi", "c) Chennai", "d) Kolkata"},
        {"a) Python", "b) Kotlin", "c) Swift", "d) Ruby"},
        {"a) Central Processing Unit", "b) Computer Processing Unit", "c) Central Program Unit", "d) Control Processing Unit"},
        {"a) Stack", "b) Tree", "c) Queue", "d) Graph"},
        {"a) 2 bytes", "b) 4 bytes", "c) 8 bytes", "d) 1 byte"}
    };

    char answers[5] = {'b', 'b', 'a', 'c', 'b'};
    char userAnswer;
    int score = 0;

    printf("===== QUIZ APPLICATION =====\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Q%d: %s\n", i + 1, questions[i]);
        for (int j = 0; j < 4; j++)
            printf("%s\n", options[i][j]);

        printf("Your answer (a/b/c/d): ");
        scanf(" %c", &userAnswer);

        if (userAnswer == answers[i]) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! Correct answer: %c\n\n", answers[i]);
        }
    }

    printf("===== QUIZ OVER =====\n");
    printf("Your score: %d out of 5\n", score);

    return 0;
}