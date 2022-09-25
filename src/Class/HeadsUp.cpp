#include "HeadsUp.h"

HeadsUp::HeadsUp()
{
	pText = pScore = pNivel = DOGNULL;
	vVidas.clear();
	playerName = "";
	ss.str("");
	points = highScore = nivel = vidas = 0;
	color = BLACK;
	pXml = DOGNULL;
}

HeadsUp::~HeadsUp()
{
	DOG_SAFE_DELETE(pText);
	DOG_SAFE_DELETE(pScore);

	for (auto inx = 0; inx < vVidas.size(); inx++)
	{
		DOG_SAFE_DELETE(vVidas[inx]);
	}
	vVidas.clear();
}

DOGvoid HeadsUp::Init()
{
	pText = new TextSDL("glx/fonts/PressStart2P.ttf");
	pText->SetSize(15);
	pText->SetFlipV(true);

	pScore = new TextSDL("glx/fonts/PressStart2P.ttf");
	pScore->SetSize(15);
	pScore->SetFlipV(true);

	pNivel = new TextSDL("glx/fonts/PressStart2P.ttf");
	pNivel->SetSize(15);
	pNivel->SetFlipV(true);

	pXml = unique_ptr<XMLParser>(new XMLParser());
	pXml->Init("glx/xml/headsup.xml");

	playerName = pXml->GetDatac("/HEADSUP/NAME");
	points = pXml->GetDatai("/HEADSUP/SCORE");
	highScore = 0;
	nivel = pXml->GetDatai("/HEADSUP/LEVEL");
	vidas = pXml->GetDatai("/HEADSUP/LIFES");
	IDSession = pXml->GetDatai("/HEADSUP/ID_SESSION");

	if (pXml->GetDatai("/HEADSUP/GAME_OVER") == 1)
	{
		gameOver = true;
	}
	else
	{
		gameOver = false;
	}

	DOGfloat _x = 415.0f;
	for (auto i = 0; i < vidas; i++)
	{
		vVidas.push_back(new Sprite("glx/img/nave2.0.png", 32, 21));
		vVidas[i]->TranslateAbs(_x, 10.0f, 0.0f);
		_x += vVidas[i]->GetWidth() + 3;
	}

	/*vVidas.push_back(new Sprite("glx/img/nave2.0.png", 32, 21));
	vVidas.push_back(new Sprite("glx/img/nave2.0.png", 32, 21));*/
	//vVidas.push_back(new Sprite("glx/img/nave2.0.png", 32, 21));

	/*vVidas[0]->TranslateAbs(410.0f, 17.0f, 0.0f);
	vVidas[1]->TranslateAbs(442.0f, 17.0f, 0.0f);*/
	//vVidas[2]->TranslateAbs(474.0f, 17.0f, 0.0f);

	//vidas = vVidas.size();

	ss.clear();
}

DOGvoid HeadsUp::Update(DOGfloat elapsedTime)
{
	pText->Update(elapsedTime);
	pScore->Update(elapsedTime);
	pNivel->Update(elapsedTime);

	for (auto inx = 0; inx < vVidas.size(); inx++)
	{
		vVidas[inx]->Update(elapsedTime);
	}
}

DOGvoid HeadsUp::Render()
{
	pText->Render(playerName, 15.0f, 5.0f, color);

	ss.str("");
	ss << points;
	pScore->Render(ss.str(), 15.0f + pText->GetWidth() + 50.0f, 5.0f, color);

	ss.str("");
	ss << "Nivel " << nivel;
	pNivel->Render(ss.str(), 15.0f + pText->GetWidth() + 50.0f + pScore->GetWidth() + 50.0f, 5.0f, color);

	for (auto inx = 0; inx < vVidas.size(); inx++)
	{
		vVidas[inx]->Render();
	}
}

string HeadsUp::GetPlayerName()
{
	return playerName;
}

DOGvoid HeadsUp::SetPlayerName(string name)
{
	playerName = name;
}

DOGint HeadsUp::GetPoints()
{
	return points;
}

DOGvoid HeadsUp::SetPoints(DOGint points)
{
	this->points = points;
}

DOGint HeadsUp::GetHighScore()
{
	return highScore;
}

DOGvoid HeadsUp::SetHighScore(DOGint highScore)
{
	this->highScore = highScore;
}

DOGint HeadsUp::GetNivel()
{
	return nivel;
}

DOGvoid HeadsUp::SetNivel(DOGint nivel)
{
	this->nivel = nivel;
}

DOGint HeadsUp::GetVidas()
{
	return vidas;
}

DOGvoid HeadsUp::SetVidas(DOGint vidas)
{
	this->vidas = vidas;
}

DOGvoid HeadsUp::SetColor(DOGCOLOR& c)
{
	color.r = abs(1.0f - c.r);
	color.g = abs(1.0f - c.g);
	color.b = abs(1.0f - c.b);
	color.a = 1.0f;
}

DOGCOLOR& HeadsUp::GetColor()
{
	return color;
}

DOGvoid HeadsUp::LostLife()
{
	if (!vVidas.empty())
	{
		DOG_SAFE_DELETE(vVidas[vVidas.size() - 1]);
		vVidas.erase(vVidas.begin() + vVidas.size() - 1);
	}
	vidas--;
}

DOGvoid HeadsUp::Save()
{
	ofstream myfile;
	myfile.open("glx/xml/headsup.xml");
	//myfile << "Writing this to a file.\n";
	myfile << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
	myfile << "<HEADSUP>\n";
	myfile << "\t<NAME>\n";
	myfile << "\t\t" << playerName << "\n";
	myfile << "\t</NAME>\n";
	myfile << "\t<SCORE>\n";
	myfile << "\t\t" << points << "\n";
	myfile << "\t</SCORE>\n";
	myfile << "\t<LEVEL>\n";
	myfile << "\t\t" << nivel << "\n";
	myfile << "\t</LEVEL>\n";
	myfile << "\t<LIFES>\n";
	myfile << "\t\t" << vidas << "\n";
	myfile << "\t</LIFES>\n";
	myfile << "\t<GAME_OVER>\n";
	if(gameOver)
		myfile << "\t\t" << 1 << "\n";
	else
		myfile << "\t\t" << 0 << "\n";
	myfile << "\t</GAME_OVER>\n";
	myfile << "\t<ID_SESSION>\n";
	myfile << "\t\t" << IDSession << "\n";
	myfile << "\t</ID_SESSION>\n";
	myfile << "</HEADSUP>\n";
	myfile.close();
}

DOGvoid HeadsUp::SetGameOver(DOGbool b)
{
	gameOver = b;
}

DOGbool HeadsUp::IsGameOver()
{
	return gameOver;
}

DOGvoid HeadsUp::SetIDSession(DOGint id)
{
	IDSession = id;
}

DOGint HeadsUp::GetIDSession()
{
	return IDSession;
}