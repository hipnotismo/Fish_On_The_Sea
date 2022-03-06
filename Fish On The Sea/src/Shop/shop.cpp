#include "shop.h"

#include <iostream>
namespace fish {
	namespace shop {

		void initShop(Vector2& mainSize, Vector2& mainPos,Vector2& openSize, Vector2& openPos, Vector2& closeSize, Vector2& closePos,
			Vector2& leftArrowSize, Vector2& leftArrowPos, Vector2& rightArrowSize, Vector2& rightArrowPos, Vector2& itemSize, Vector2& itemPos,
			int& item, Vector2& buySize, Vector2& buyPos, Texture2D& CloseTex1, Texture2D& CloseTex2) {

			mainSize = { static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10 )* 2 ),
			static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2) };
			mainPos = { static_cast<float>(GetScreenWidth())/10,static_cast<float> (GetScreenHeight()) / 10};

			openSize = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenWidth()) / 10)};
			openPos = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenHeight()) / 10) };

			closeSize = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenWidth()) / 10) };
			closePos = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenHeight()) / 10) };

			leftArrowSize = { mainSize .x / 3, mainSize.y / 10};
			leftArrowPos = {mainPos.x,mainSize.y};
	
			rightArrowSize = { mainSize.x / 3, mainSize.y / 10 };
			rightArrowPos = { static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2) -83, leftArrowPos.y};

			itemSize = { mainSize.x ,mainSize.y - leftArrowSize.y*2};
			itemPos = {mainPos.x, mainPos.y};

			item = 1;

			buySize = { mainSize.x / 3, mainSize.y / 10 };
			buyPos = { mainSize.x / 2 - buySize.x / 9, leftArrowPos.y - buySize.y };

			CloseTex1 = LoadTexture("res/Shop_buttons/x1.png");
			CloseTex2 = LoadTexture("res/Shop_buttons/x2.png");
			
		}

		void drawShop(Vector2& mainSize, Vector2& mainPos) {
#if _DEBUG
			DrawRectangle(static_cast<int>(mainPos.x), static_cast<int>(mainPos.y), static_cast<int>(mainSize.x), static_cast<int>(mainSize.y), ORANGE);
#endif
		}

		void drawOpen(Vector2& openSize, Vector2& openPos, Texture2D& CloseTex1, Texture2D& CloseTex2){
#if _DEBUG
			DrawRectangle(static_cast<int>(openPos.x), static_cast<int>(openPos.y), static_cast<int>(openSize.x), static_cast<int>(openSize.y), ORANGE);
#endif
			if (CheckCollisionPointRec(GetMousePosition(), { openPos.x ,openPos.y ,openSize.x ,openSize.y })) {
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
					DrawTexture(CloseTex1, static_cast<int>(openPos.x), static_cast<int>(openPos.y), WHITE);
				}
				else {
					DrawTexture(CloseTex1, static_cast<int>(openPos.x), static_cast<int>(openPos.y), WHITE);
				}

				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					//gameManager::Screens = gameManager::GameScreen::Game;
				}
			}
			else {
				DrawTexture(CloseTex1, static_cast<int>(openPos.x), static_cast<int>(openPos.y), WHITE);

			}

		}

		void drawClose(Vector2& closeSize, Vector2& closePos, Texture2D& CloseTex1, Texture2D& CloseTex2) {
#if _DEBUG
			DrawRectangle(static_cast<int>(closePos.x), static_cast<int>(closePos.y), static_cast<int>(closeSize.x), static_cast<int>(closeSize.y), RED);
#endif
			DrawTexture(CloseTex1, static_cast<int>(closePos.x), static_cast<int>(closePos.y), WHITE);

		}

		void drawLeftArrow(Vector2& leftArrowSize, Vector2& leftArrowPos) {
			DrawRectangle(static_cast<int>(leftArrowPos.x), static_cast<int>(leftArrowPos.y), static_cast<int>(leftArrowSize.x),
				static_cast<int>(leftArrowSize.y), RED);
		}

		void drawRightArrow(Vector2& rightArrowSize, Vector2& rightArrowPos) {
			DrawRectangle(static_cast<int>(rightArrowPos.x), static_cast<int>(rightArrowPos.y), static_cast<int>(rightArrowSize.x),
				static_cast<int>(rightArrowSize.y), RED);
		}

		void drawItem(Vector2& itemSize, Vector2& itemPos, int& item) {
			switch (item){
			case 1:
				DrawRectangle(static_cast<int>(itemPos.x), static_cast<int>(itemPos.y), static_cast<int>(itemSize.x),
					static_cast<int>(itemSize.y), BLUE);
				break;
			case 2:
				DrawRectangle(static_cast<int>(itemPos.x), static_cast<int>(itemPos.y), static_cast<int>(itemSize.x),
					static_cast<int>(itemSize.y), MAGENTA);
				break;
			case 3:
				DrawRectangle(static_cast<int>(itemPos.x), static_cast<int>(itemPos.y), static_cast<int>(itemSize.x),
					static_cast<int>(itemSize.y), COLORALPHA);
				break;
			default:
				break;
			}
		}

		void increaseItem(int& item) {
			if (item < 3) {
				item++;
				std::cout << item << std::endl;
			}
		}

		void decreaseItem(int& item) {
			if (item > 1) {
				item--;
				std::cout << item << std::endl;
			}
		}

		void drawBuy(Vector2& butSize, Vector2& buyPos) {
			DrawRectangle(static_cast<int>(buyPos.x), static_cast<int>(buyPos.y), static_cast<int>(butSize.x),
				static_cast<int>(butSize.y), RED);
		}

		void upgradeItem(int& item, int& capasity, int& reach, int& points) {
			switch (item) {
			case 1:
				switch (capasity){				
				case 1:
					if (points > 100) {
						std::cout << " it works" << std::endl;

						capasity = 2;
						points = points - 50;
					}
					break;
				case 2:
					if (points > 1000) {
						std::cout << " it works" << std::endl;

						capasity = 3;
						points = points - 50;
					}
					break;
				case 3:
					if (points > 2000) {
						std::cout << " it works" << std::endl;

						capasity = 4;
						points = points - 50;
					}
					break;
				default:
					break;
				}
				break;
			case 2:
				switch (reach) {
				case 1:
					if (points > 600) {
						std::cout << " it works2" << std::endl;

						reach = 2;
						points = points - 50;
					}
					break;
				case 2:
					if (points > 2000) {
						std::cout << " it works2" << std::endl;

						reach = 3;
						points = points - 50;
					}
					break;
				case 3:
					if (points > 4000) {
						std::cout << " it works2" << std::endl;

						reach = 4;
						points = points - 50;
					}
					break;
				default:
					break;
				}
				break;
			case 3:
				switch (reach) {
				case 1:
					if (points > 600) {
						std::cout << " it works2" << std::endl;

						reach = 2;
						points = points - 50;
					}
					break;
				case 2:
					if (points > 2000) {
						std::cout << " it works2" << std::endl;

						reach = 3;
						points = points - 50;
					}
					break;
				case 3:
					if (points > 4000) {
						std::cout << " it works2" << std::endl;

						reach = 4;
						points = points - 50;
					}
					break;
				default:
					break;
				}
			
				break;
			default:
				break;
			}
		}
	}
}