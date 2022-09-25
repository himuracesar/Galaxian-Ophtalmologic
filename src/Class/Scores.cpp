#include "Scores.h"

Scores::Scores()
{
	pXml = DOGNULL;
	vScores.clear();
}

Scores::~Scores()
{

}

DOGvoid Scores::UpdateScores(SCORE s)
{
	pXml = unique_ptr<XMLParser>(new XMLParser());
	pXml->Init("glx/xml/scores.xml");

	vScores.clear();

	DOGbool add = false;
	stringstream ss;
	for (auto inx = 1; inx <= TOTAL_SCORES; inx++)
	{
		ss.str("");
		ss << "/SCORES/POSITION" << inx << "/SCORE";
		DOGint _score = pXml->GetDatai(ss.str());
		ss.str("");
		ss << "/SCORES/POSITION" << inx << "/NAME";
		SCORE score;
		score.name = pXml->GetDatac(ss.str());
		ss.str("");
		ss << "/SCORES/POSITION" << inx << "/LEVEL";
		score.level = pXml->GetDatai(ss.str());
		score.score = _score;
		ss.str("");
		ss << "/SCORES/POSITION" << inx << "/ID_SESSION";
		score.idSession = pXml->GetDatai(ss.str());

		if (score.idSession == s.idSession && s.name == score.name)
			continue;

		if (_score < s.score && !add)
		{
			vScores.push_back(s);
			add = true;
		}

		if (vScores.size() == 10)
			break;

		vScores.push_back(score);

		if (vScores.size() == 10)
			break;
	}
}

DOGvoid Scores::Save()
{
	ofstream scoresFile;
	scoresFile.open("glx/xml/scores.xml");
	scoresFile << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
	scoresFile << "<SCORES>\n";

	for (auto iScore = 1; iScore <= TOTAL_SCORES; iScore++)
	{
		scoresFile << "\t<POSITION" << iScore << ">\n";
		scoresFile << "\t\t<NAME>";
		scoresFile << vScores[iScore-1].name;
		scoresFile << "</NAME>\n";
		scoresFile << "\t\t<LEVEL>";
		scoresFile << vScores[iScore-1].level;
		scoresFile << "</LEVEL>\n";
		scoresFile << "\t\t<SCORE>";
		scoresFile <<  vScores[iScore-1].score;
		scoresFile << "</SCORE>\n";
		scoresFile << "\t\t<ID_SESSION>";
		scoresFile << vScores[iScore - 1].idSession;
		scoresFile << "</ID_SESSION>\n";
		scoresFile << "\t</POSITION" << iScore << ">\n";
	}

	scoresFile << "</SCORES>\n";
	scoresFile.close();
}

vector<SCORE> Scores::GetScores()
{
	if (pXml == DOGNULL)
	{
		pXml = unique_ptr<XMLParser>(new XMLParser());
		pXml->Init("glx/xml/scores.xml");
	}

	stringstream ss;
	for (auto iScore = 1; iScore <= TOTAL_SCORES; iScore++)
	{
		SCORE s;
		ss.str("");
		ss << "/SCORES/POSITION" << iScore << "/NAME";
		s.name = pXml->GetDatac(ss.str());
		ss.str("");
		ss << "/SCORES/POSITION" << iScore << "/LEVEL";
		s.level = pXml->GetDatai(ss.str());
		ss.str("");
		ss << "/SCORES/POSITION" << iScore << "/SCORE";
		s.score = pXml->GetDatai(ss.str());
		ss.str("");
		ss << "/SCORES/POSITION" << iScore << "/ID_SESSION";
		s.idSession = pXml->GetDatai(ss.str());

		vScores.push_back(s);
	}

	return vScores;
}