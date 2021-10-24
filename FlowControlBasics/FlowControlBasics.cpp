// FlowControlBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "structs.h";
#include <iostream>

void PrintThruthTable();
void CompareTwoNumbers();
void CalculatePrice();
void ConvertDayNumber();
void CheckLeapYear();
void ConvertSeconds();
void UseActorState();
void UsePoint2f();

int main()
{
	srand(unsigned int(time(nullptr)));
	PrintThruthTable();
	CompareTwoNumbers();
	CalculatePrice();
	ConvertDayNumber();
	CheckLeapYear();
	ConvertSeconds();
	UseActorState();
	UsePoint2f();
}

void UsePoint2f() {
	Point2f p1;
	Point2f p2{};
	Point2f p3(26,25);

	std::cout << "-- Define and use Point2f --\n";
	std::cout << "Values after definition\n";
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]\n";
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]\n";
	

	p1.x = 20;
	p1.y = 3;

	p2.x = 30;
	p2.y = 40;

	++p3.x;
	--p3.y;
	std::cout << "Values after changing the members\n";
	std::cout << "p1: [" << p1.x << ", " << p1.y << "]\n";
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]\n";
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]\n";
}

enum class ActorState {
	running,
	flying,
	falling
};

void UseActorState() {
	std::cout << "-- Define and use ActorState --\n";
	int index{ rand() % 3 + 0};
	ActorState state(static_cast<ActorState>(index));

	switch (state)
	{
	case ActorState::running:
		std::cout << "Running\n\n";
		break;
	case ActorState::flying:
		std::cout << "Flying\n\n";
		break;
	case ActorState::falling:
		std::cout << "Falling\n\n";
		break;
	default:
		break;
	}
}

void ConvertSeconds() {
	int input{};


	std::cout << "-- Convert seconds --\n";
	std::cout << "Number of seconds? ";
	std::cin >> input;

	int days{ input / (24 * 3600) };
	input = input % (24 * 3600);
	int hours{ input / 3600 };
	input %= 3600;
	int minutes{ input / 60 };
	int seconds{ input %= 60 };

	std::cout << "days: " << days << "\n";
	std::cout << "hours: " << hours << "\n";
	std::cout << "minutes: " << minutes << "\n";
	std::cout << "seconds: " << seconds << "\n\n";
}

void CheckLeapYear() {
	int year{};
	int days{};
	int days28{ 28 };
	int days29{ 29 };

	std::cout << "-- check leap year --\n";
	std::cout << "Year?";
	std::cin >> year;

	if (year % 4 != 0) {
		days = days28;
	}
	else if (year % 100 != 0) {
		days = days29;
	}
	else if (year % 400 != 0) {
		days = days28;
	}
	else {
		days = days29;
	}

	std::cout << year << ": " << days << "\n\n";
}

void ConvertDayNumber() {
	int number{};
	std::cout << "Day number[1, 7]?";
	std::cin >> number;

	if (number <= 0 || number > 7) {
		std::cout << "wrong day number!!\n\n";
	}

	switch (number)
	{
	case 1:
		std::cout << "Monday\n";
		break;
	case 2:
		std::cout << "Tuesday\n";
		break;
	case 3:
		std::cout << "Wednesday\n";
		break;
	case 4:
		std::cout << "Thursday\n";
		break;
	case 5:
		std::cout << "Friday\n";
		break;
	case 6:
		std::cout << "Saturday\n";
		break;
	case 7:
		std::cout << "Sunday\n";
		break;
	}

	if (number >= 1 && number <= 7) {
		if (number <= 5) {
			std::cout << "no weekend\n";
			if (number == 1)
				std::cout << "Start of the week\n\n";
			else if (number >= 2 || number <= 4)
				std::cout << "Middle of the week\n\n";
			else
				std::cout << "Nearly weekend\n\n";
		}

		else
			std::cout << "weekend\n\n";
	}
}

void CalculatePrice() {
	int quantity{};
	float price{};

	std::cout << "-- calculate price --\n";
	std::cout << "Nr. of ballpoints?";
	std::cin >> quantity;

	if (quantity < 20 && quantity > 0) {
		price = 4.f;
	}
	else if (quantity < 50 && quantity >= 20) {
		price = 3.50f;
	}
	else if (quantity <= 100 && quantity >= 50) {
		price = 3.25f;
	}
	else if (quantity > 100) {
		price = 3.10f;
	}
	else {
		std::cout << "The entered amount is not possible to calculate!!\n\n";
		return;
	}

	float totalPrice{ quantity * price };
	std::cout << "Total price is: " << totalPrice << "\n\n";
}

void CompareTwoNumbers() {
	int firstNumber{ rand() % 10 + 0 };
	int secondNumber{ rand() % 10 + 0 };
	std::string comparedResult{};

	std::cout << "The first number is: " << firstNumber << "\n";
	std::cout << "The second number is: " << secondNumber << "\n";

	if (firstNumber == secondNumber) {
		secondNumber = rand() % 10 + 0;
	}

	if (secondNumber > firstNumber) {
		comparedResult = "larger than ";
	}

	if (secondNumber < firstNumber) {
		comparedResult = "smaller than ";
	}

	std::cout << "The second number is " << comparedResult << "the first number.\n\n";

}

void PrintThruthTable() {
	bool boolTrue{ true };
	bool boolFalse{ false };

	std::cout << "Logical binary AND-operator(&&)\n\n";

	std::cout << "true and true is: " << std::boolalpha << (boolTrue && boolFalse) << "\n";
	std::cout << "true and false is: " << std::boolalpha << (boolTrue && !boolFalse) << "\n";
	std::cout << "false and false is: " << std::boolalpha << (!boolTrue && !boolFalse) << "\n";
	std::cout << "false and true is: " << std::boolalpha << (!boolTrue && boolFalse) << "\n\n";

	std::cout << "Logical binary OR-operator(||)\n\n";

	std::cout << "true and true is: " << std::boolalpha << (boolTrue || boolFalse) << "\n";
	std::cout << "true and false is: " << std::boolalpha << (boolTrue || !boolFalse) << "\n";
	std::cout << "false and false is: " << std::boolalpha << (!boolTrue || !boolFalse) << "\n";
	std::cout << "false and true is: " << std::boolalpha << (!boolFalse || boolFalse) << "\n\n";

	std::cout << "Logical unary NOT-operator(!)\n\n";

	std::cout << "!true is: " << std::boolalpha << (!boolTrue) << "\n";
	std::cout << "!false is: " << std::boolalpha << (!boolFalse) << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
