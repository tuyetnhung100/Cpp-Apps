#include <iostream>
using namespace std;

struct Answer {
	string answerText;
	bool isTrue;
};

struct Question {
	string questionText;
	Answer option[3];
};

void printAnswerInfo(Answer answer) {
	cout << answer.answerText << endl;
}

void printQuestionInfo(Question quest) {
	cout << quest.questionText << endl;
	for (int i = 0; i < 3; i++) {
		cout << i+1 << ". ";
		printAnswerInfo(quest.option[i]);
	}
}

void checkAnswer(bool isCorrect) {
	if (isCorrect) 
		cout << "Correct!" << endl;
	else 
		cout << "Incorrect!" << endl;
}

void checkChoice(int choice, Question quest) {
	if (choice == 1) {
		checkAnswer(quest.option[0].isTrue);
	} else if (choice == 2) {
		checkAnswer(quest.option[1].isTrue);
	} else if (choice == 3) {
		checkAnswer(quest.option[2].isTrue);
	} else {
		cout << "Invalid option!" << endl;
	}
}

int main() {
	int choice;
	Answer answer1a, answer1b, answer1c;
	answer1a.answerText = "USA";
	answer1a.isTrue = false;
	answer1b.answerText = "India";
	answer1b.isTrue = false;
	answer1c.answerText = "Vatican City";
	answer1c.isTrue = true;

	Answer answer2a, answer2b, answer2c;
	answer2a.answerText = "Elephant";
	answer2a.isTrue = false;
	answer2b.answerText = "Blue whale";
	answer2b.isTrue = true;
	answer2c.answerText = "Great white shark";
	answer2c.isTrue = false;

	Answer answer3a, answer3b, answer3c;
	answer3a.answerText = "118 elements";
	answer3a.isTrue = true;
	answer3b.answerText = "119 elements";
	answer3b.isTrue = false;
	answer3c.answerText = "120 elements";
	answer3c.isTrue = false;


	Question quest1;
	quest1.questionText = "What is the smallest country?";
	quest1.option[0] = answer1a;
	quest1.option[1] = answer1b;
	quest1.option[2] = answer1c;

	Question quest2;
        quest2.questionText = "What's the biggest animal in the world?"; 
        quest2.option[0] = answer2a;
        quest2.option[1] = answer2b;
        quest2.option[2] = answer2c;

	Question quest3;
        quest3.questionText = "How many elements are there in the periodic table?";
        quest3.option[0] = answer3a;
        quest3.option[1] = answer3b;
        quest3.option[2] = answer3c;

	printQuestionInfo(quest1);
	cout << "Choose 1-3: ";
	cin >> choice;
	checkChoice(choice, quest1);
	cout << endl;

	printQuestionInfo(quest2);
	cout << "Choose 1-3: ";
	cin >> choice;              	
	checkChoice(choice, quest2);
	cout << endl;

	printQuestionInfo(quest3);
	cout << "Choose 1-3: ";
	cin >> choice;
	checkChoice(choice, quest3);
}
