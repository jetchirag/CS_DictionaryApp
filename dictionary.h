#include<stdio.h>
#include<iostream>
#include<time.h>
#include<chrono>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int searchWord(json j) {
    // This function will search the meaning of the word inputted in the json j
    char w[50];

    printf("Enter word: ");
    scanf("%s", w);

    if (j.contains(w)) {
        printf("Meaning of word %s: \n", w);
        cout << j.at(w);
    } else {
        printf("Word not found");
    };

    return 0;

}

int playQuiz(json j) {
    cout << "\n\n";
    short int score = 0;
    const long int max_size = j.size();
    srand(time(NULL));

    while (true) {
        int counter;
        string quiz_meaning;
        string w[4];
        short int while_loop = 1;
        while (while_loop) {
            counter = 0;
            long int rand_value = rand() % max_size;

            for (auto it = j.begin(); it != j.end(); ++it) {
                if (counter == rand_value) {
                    if (w[0].empty()) {
                        quiz_meaning = it.value();
                        w[0] = it.key();
                    } else if (w[1].empty()) {
                        w[1] = it.key();
                    } else if (w[2].empty()) {
                        w[2] = it.key();
                    } else if (w[3].empty()) {
                        w[3] = it.key();
                    } else {
                        while_loop = 0;
                        break;
                    }
                } else if (counter == rand_value + 1) {
                    break;
                }
                counter++;
            }

        }

        cout << quiz_meaning << "\n\n";
        cout << "Select Correct Word:-\n";

        // Shuffl the words
        short int random_place = rand() % 4;

        // Change value of w[0] with w[random_place];
        string temp_value = w[random_place];
        w[random_place] = w[0];
        w[0] = temp_value;

        for (short int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << w[i] << "\n";
        }

        // Print total points
        cout << "\nScore: " << score << "\n";

        // Time limit logic
        // chrono::steady_clock::time_point begin = chrono::steady_clock::now();



        // Take input for quiz answer
        int quiz_answer;
        cout << "Correct choice? [1-4] (5 to quit) (6 to skip [-1]): ";
        scanf("%d", & quiz_answer);

        if (quiz_answer == 5) {
            cout << "\nYou quit.\nTotal Score: " << score;
            return 0;
        }
        if (quiz_answer == 6) {
            cout<<"\n\nSkipped Word (-1): \n";
            score -= 1;
        }
        else if (quiz_answer == random_place + 1) {
            cout << "\n\nCorrect Answer (+4)\n";
            score += 4;
        } else {
            cout << "\n\nIncorrect Answer (-2)\n";
            score -= 2;
        }
        if (score < 0) {
            cout << "You lost.";
            return 0;
        }
    }

    return 0;
}