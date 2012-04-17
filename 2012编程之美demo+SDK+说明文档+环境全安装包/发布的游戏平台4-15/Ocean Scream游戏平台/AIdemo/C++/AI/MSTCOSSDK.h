//Ocean Scream SDK By LiJiancheng in BUAA MSTC
#pragma once
#include <string>
#include <vector>
#include <WinSock2.h>
using namespace std;
const float MaxArmor = 1000;
const float Acceleration = 10;
const float MaxSpeed = 25;
const float AngularRate = 60;
const float ShipBoundingRadius = 15;
const float IslandBoundingRadius = 32;
const float CannonSpan = 4;
const float CannonAngle = 90;
const float CannonRange = 250;
const float ResourceRadius = 196;
const float ResourceRestoreRate[6] = { 0, 5, 10, 15, 25, 50 };
const int MapWidth = 2048;
const int MapHeight = 1536;
const float RangeOfView = 400;

#ifdef CSTYLE
extern "C"{
	int init_Interface(char* host, int port);
	int finalize_Interface();

	int Running();
	int Ship();
	void Attack(int sourceShip, int targetShip);
	void MoveTo(int sourceShip, float x, float y);

	int getShip_ID(int index);
	int getShip_Faction(int index);
	int getShip_X(int index);
	int getShip_Y(int index);
}
#else

#define DLL_EXPORT

#ifdef DLL_EXPORT
#define DLL_DESCRIPTOR __declspec(dllexport)
#else
#define DLL_DESCRIPTOR __declspec(dllimport)
#endif

DLL_DESCRIPTOR class ShipInfo
{
public:
	ShipInfo(int ID, int Faction, float Armor, float PositionX, float PositionY, float VelocityX, float VelocityY, float CurrentSpeed,
            float DirectionX, float DirectionY, float Rotation, bool IsMoving, bool IsBlocked, bool IsRotating, float CooldownRemain[2]);
	int ID;
	int Faction;
	float Armor;
	float CooldownRemain[2];
	float CurrentSpeed;
	float DirectionX;
	float DirectionY;
	bool IsBlocked;
	bool IsMoving;
	bool IsRotating;
	float PositionX;
	float PositionY;
	float Rotation;
	float VelocityX;
	float VelocityY;
};

DLL_DESCRIPTOR class ResourceInfo
{
public:
	ResourceInfo(int ID, int Faction, float PositionX, float PositionY);
	int ID;
	int Faction;
	float PositionX;
	float PositionY;
};

DLL_DESCRIPTOR class OSInterface
{
public:
	OSInterface(string host, int port);
	void Attack(int sourceShip, int targetShip);
	void MoveTo(int sourceShip, float x, float y);
	void StartMoving(int ship);
	void StartRotating(int ship,float target);
	void StartRotatingTo(int ship,float x,float y);
	void Stop(int ship);
	void StopRotating(int ship);
	bool Running() const;
	void GetReady();
	void SendInfo(string name,int r,int g,int b) const;
	int Faction;
	void Data();
	vector<ShipInfo> Ship;
	vector<ResourceInfo> Resource;
private:
	SOCKET server;
	bool running;
	bool IsEnd(string response);
};

DLL_DESCRIPTOR class MSTCOSSDK
{
public:
	static void MSTCOSSDK::StartGame(int argc, char* argv[], void (*Iteration)(OSInterface* const Interface));
	OSInterface Interface;
private:
	MSTCOSSDK(string host, int port, string name, string color, void (*Iteration)(OSInterface* const Interface));
	void (*Iteration)(OSInterface* const Interface);
	void Start();
};

#undef DLL_SAMPLE_API

#endif