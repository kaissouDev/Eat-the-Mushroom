#pragma once
#include <raylib.h>
#include <fmt/core.h>
#include <iostream>
class Button {
public:
	Color backgroundColor;
	Color textColor;
	Color hoverColor;
	Color currentColor;
	std::string text;

	Rectangle body;

	Button(Color backgroundColor, Color textColor, Color hoverColor, Rectangle body,std::string text);
	void hover();
	bool isClicked();
	void draw();
};