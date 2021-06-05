#include <memory>
#include "Player.h"
#include "TankPLA1.h"
#include "TankPLA2.h"
class TankPLA1;
class TankPLA2;

Player::Player(std::shared_ptr<Tank> tankObject) {
	this->tankObject = tankObject;
	score = 0;
	tanksDestroyed = 0;
}

void Player::render() {
	if (!tankObject) {
		return;
	}
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			break;
		}
	}
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	if (keystates[SDL_SCANCODE_W]) {
		tankObject->moveUp();
	}
	else if (keystates[SDL_SCANCODE_D]) {
		tankObject->moveRight();
	}
	else if (keystates[SDL_SCANCODE_A]) {
		tankObject->moveLeft();
	}
	else if (keystates[SDL_SCANCODE_S]) {
		tankObject->moveDown();
	}
	if (keystates[SDL_SCANCODE_SPACE]) {
		tankObject->strike(shared_from_this());
	}
	tankObject->render();
}

std::shared_ptr<Tank> Player::getObject() {
	return tankObject;
}

void Player::increaseScore(unsigned int score) {
	this->score += score;
}
void Player::increaseTanksDestroyed(unsigned int count) {
	this->tanksDestroyed += count;
	if (this->tanksDestroyed > 0 && this->tanksDestroyed % this->tanksDestroyedRequired == 0) {
		this->tankObject.reset(new TankPLA2(this->tankObject->getLevelData()->level->getRenderer(), static_cast<int>(this->tankObject->getPosition()->rect.x), static_cast<int>(this->tankObject->getPosition()->rect.y), 32, 32, this->tankObject->getLevelData(), false));
	}
}

unsigned int Player::getScore() {
	return score;
}
unsigned int Player::getTanksDestroyed() {
	return tanksDestroyed;
}

Player::~Player() {
	if(tankObject)
		tankObject->destroyObject();
}

void Player::renderGui() {
	if (!tankObject) {
		return;
	}

	char str[20] = "Your hp: ";
	char hp[10] = "\0";
	_itoa_s(tankObject->getHp(), hp, 10);
	strcat_s(str, hp);

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(tankObject->getLevelData()->level->getFont(), str, { 100, 149, 237, 255 });
	SDL_Texture* Message = SDL_CreateTextureFromSurface(tankObject->getLevelData()->level->getRenderer(), surfaceMessage);
	SDL_Rect Message_rect = { tankObject->getLevelData()->windowWidth - 140,  tankObject->getLevelData()->windowHeight - 50, 120, 40 };
	SDL_RenderCopy(tankObject->getLevelData()->level->getRenderer(), Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);

	char str1[20] = "Your score: ";
	char score[10] = "\0";
	_itoa_s(this->getScore(), score, 10);
	strcat_s(str1, score);

	surfaceMessage = TTF_RenderText_Solid(tankObject->getLevelData()->level->getFont(), str1, { 100, 149, 237, 255 });
	Message = SDL_CreateTextureFromSurface(tankObject->getLevelData()->level->getRenderer(), surfaceMessage);
	Message_rect = { tankObject->getLevelData()->windowWidth - 140,  tankObject->getLevelData()->windowHeight - 100, 120, 40 };
	SDL_RenderCopy(tankObject->getLevelData()->level->getRenderer(), Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

void Player::destroyTankObject() {
	tankObject.reset();
}
void Player::changeTankObject(std::shared_ptr<Tank> obj) {
	tankObject = obj;
}