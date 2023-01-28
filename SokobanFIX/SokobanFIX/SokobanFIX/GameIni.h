#include <SFML/Graphics.hpp>
#include "MainRoom.h"

class GameIni :public MainRoom
{
public:
	GameIni();

	virtual void Step() override;
};
