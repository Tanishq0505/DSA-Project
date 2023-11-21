#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a quiz question
struct Question
{
    char question[1000];
    char options[4][200];
    int correctOption;
};

// Structure to represent a quiz
struct Quiz
{
    char title[100];
    struct Question questions[10]; // Up to 10 questions
    int numQuestions;
};

// Function to add a question to a quiz
void addQuestion(struct Quiz *quiz, const char *question, const char *options[4], int correctOption)
{
    if (quiz->numQuestions < 10)
    {
        strcpy(quiz->questions[quiz->numQuestions].question, question);
        for (int i = 0; i < 4; i++)
        {
            strcpy(quiz->questions[quiz->numQuestions].options[i], options[i]);
        }
        quiz->questions[quiz->numQuestions].correctOption = correctOption;
        quiz->numQuestions++;
    }
    else
    {
        printf("Quiz is full. Cannot add more questions.\n");
    }
}

// Function to take a quiz
int takeQuiz(struct Quiz *quiz)
{
    int score = 0;
    for (int i = 0; i < quiz->numQuestions; i++)
    {
        printf("Question %d: %s\n", i + 1, quiz->questions[i].question);
        for (int j = 0; j < 4; j++)
        {
            printf("%d. %s\n", j + 1, quiz->questions[i].options[j]);
        }
        int userChoice;
        printf("Your choice (1-4): ");
        scanf("%d", &userChoice);
        if (userChoice == quiz->questions[i].correctOption)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. Correct answer: %d\n", quiz->questions[i].correctOption);
        }
    }
    return score;
}

int main()
{
    struct Quiz myQuiz;
    strcpy(myQuiz.title, "My First Quiz");
    myQuiz.numQuestions = 0;

    // Add questions to the quiz
    const char *options1[4] = {"Option A: Array", "Option B: Stack", "Option C: Queues", "Option D: All of the above"};
    addQuestion(&myQuiz, "Example of linear dta structure include?", options1, 4); // Correct option is 1 (Option A)

    const char *options2[4] = {"Option A:empty", "Option B: Full", "Option C: Contain some data", "Option D:None of these"};
    addQuestion(&myQuiz, "if TOP=MAX-1, then the stack is ?", options2, 2); // Correct option is 2 (Option B)
    const char *options3[4] = {"Option A: Top ", "Option B: Rear", "Option C: Front", "Option D: Mid"};
    addQuestion(&myQuiz, "In Stack insertion is done at?", options3, 1); // Take the quiz
    const char *options4[4] = {"Option A: Dennis Ritchie", "Option B:David Bekham", "Option C:Guido van Rossum", "Option D: American"};
    addQuestion(&myQuiz, "Who discovered c ", options4, 1); // Take the quiz
    const char *options5[4] = {"Option A: Array", "Option B:Linked List", "Option C:Tree ", "Option D: Graph"};
    addQuestion(&myQuiz, "Data Structure used in hierarchical data model ", options5, 3); // Take the quiz
    printf("Welcome to the '%s' quiz!\n", myQuiz.title);
    int score = takeQuiz(&myQuiz);
    printf("Your score: %d/%d\n", score, myQuiz.numQuestions);

    return 0;
}
