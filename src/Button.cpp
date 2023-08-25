#include "Button.hpp"

Button::Button(Color backgroundColor, Color textColor, Color hoverColor, Rectangle body,std::string text) {
	this->backgroundColor = backgroundColor;
	this->textColor = textColor;
	this->hoverColor = hoverColor;
	this->body = body;
	this->text = text;
	currentColor = backgroundColor;
}
void Button::hover() {
	Vector2 mousePos = GetMousePosition();
	if (mousePos.x > body.x &&
		mousePos.y > body.y &&
		mousePos.x < body.x + body.width &&
		mousePos.y < body.y + body.height)
		currentColor = hoverColor;
	else currentColor = backgroundColor;
}
bool Button::isClicked() {
	Vector2 mousePos = GetMousePosition();
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
		mousePos.x > body.x &&
		mousePos.y > body.y &&
		mousePos.x < body.x + body.width &&
		mousePos.y < body.y + body.height
		) {
		return true;
	}
	else return false;
}

void Button::draw() {
	DrawRectangle(body.x, body.y, body.width, body.height, currentColor);
	DrawText(text.data(), body.x+body.width/2-MeasureText(text.data(),30)/2, body.y, 30, textColor);
}