#pragma once
#ifndef GALAXIAN_SCORES_H
#define GALAXIAN_SCORES_H

#include "DogEngine/Core/DogStdafx.h"

#include "XMLParser.h"
#include "GlxCommons.h"

#define TOTAL_SCORES 10

class Scores
{
	public:
		Scores();
		virtual ~Scores();

		DOGvoid UpdateScores(SCORE s);
		DOGvoid Save();

		vector<SCORE> GetScores();

	private:
		unique_ptr<XMLParser> pXml;

		vector<SCORE> vScores;
};

#endif