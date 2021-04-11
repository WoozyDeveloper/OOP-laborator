#pragma once
class PilotF1
{
private:
	char nume[30];
	int varsta, record, nr_pole_position;
public:
	char* GetName();
	int GetVarsta();
	int GetRecord();
	int GetNrPolePosition();


	void SetName(const char*);
	void SetVarsta(int);
	void SetRecord(int);
	void SetNrPolePos(int);
};