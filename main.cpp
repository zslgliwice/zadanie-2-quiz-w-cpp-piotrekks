#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure representing a single question with answer options
struct Question {
    string questionText;
    vector<string> answerOptions;
    int correctAnswerIndex;
};

// Function to ask a question and check the answer
bool askQuestion(const Question& question) {
    cout << question.questionText << endl;

    for (size_t i = 0; i < question.answerOptions.size(); i++) {
        cout << i + 1 << ". " << question.answerOptions[i] << endl;
    }

    int userAnswerIndex;
    cout << "Wybierz numer odpowiedzi: ";
    cin >> userAnswerIndex;

    if (userAnswerIndex >= 1 && userAnswerIndex <= question.answerOptions.size()) {
        return (userAnswerIndex - 1 == question.correctAnswerIndex);
    }
    else {
        cout << "Niepoprawny numer odpowiedzi." << endl;
        return false;
    }
}

int main() {
    int score = 0;

    // Array of questions
    Question questions[] = {
        {"Jaka jest stolica Francji?", {"Paryz", "Berlin", "Londyn", "Rzym"}, 0},
        {"Ile wynosi 4 * 5?", {"15", "20", "25", "30"}, 1},
        {"Kto jest autorem dramatu 'Hamlet'?", {"Shakespeare", "Dostojewski", "Hemingway", "Twain"}, 0},
        {"Ktory kraj jest znany jako 'Kraina Kwitnacej Wisni'?", {"Japonia", "Chiny", "Indie", "Korea Południowa"}, 0},
        {"Jakie jezioro jest najwieksze na swiecie?", {"Bajkał", "Morze Kaspijskie", "Jezioro Michigan", "Jezioro Wiktorii"}, 0},
        {"Ile planet jest w naszym Ukladzie Slonecznym?", {"6", "7", "8", "9"}, 2}
    };

    for (int i = 0; i < 6; i++) {
        if (askQuestion(questions[i])) {
            cout << "Poprawna odpowiedz! Zdobywasz punkt." << endl;
            cout << endl;
            score++;
        }
        else {
            cout << "Niepoprawna odpowiedz." << endl;
            cout << endl;
        }
    }

    cout << "Twoj wynik to: " << score << "/6 punktow." << endl;

    return 0;
}
