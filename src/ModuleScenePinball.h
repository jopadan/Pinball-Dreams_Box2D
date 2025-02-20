#pragma once
#include "Module.h"
#include "p2List.h"
#include "Globals.h"

#define TIMER 2000
class PhysBody;
class b2RevoluteJoint;
class b2PrismaticJoint;
enum scene_state
{
	START,
	PLAY,
	END,
};

class punctuation
{
public:
	uint value = 0u;
	uint multipilier = 1u;
	punctuation()
	{}
	~punctuation()
	{}
	//operators
	int operator+= (const int add) 
	{
		int ret = add * multipilier + value;
		value = ret;
		return ret;
	}

};

class ModuleScenePinball : public Module
{
public:
	ModuleScenePinball(Application* app, bool start_enabled = true);
	~ModuleScenePinball();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	void MoveCamera();
	void Input();
	void getSensor(char* name);
	void Warp(uint iterator);
	void Light(bool &active);
	void FiveHpts(bool &active);
	void Fuel(bool &active);
	void Ignition(bool &active);
	void SunRun();
	void balltrap();
	void Passage();
	void blitbuttons();
	void Death();
	void ResetVar();
	void CreateBodies();
	void Blit();
	void BlitUI();


private:
	scene_state state;
	punctuation currentpts;
	punctuation previouspts;
	punctuation highestpts;
	bool CurrScore, PrevScore, MaxScore;


	PhysBody* ball;

	PhysBody* doorL;
	PhysBody* doorR;
	PhysBody* rotAxisL;
	PhysBody* rotAxisR;
	PhysBody* FlipperL;
	PhysBody* FlipperR;
	PhysBody* SlingshotL;
	PhysBody* SlingshotR;
	PhysBody* Bumper1;
	PhysBody* Bumper2;
	PhysBody* Target1;
	PhysBody* Target2;
	PhysBody* Map;
	PhysBody* BalltrapChain;

	

	PhysBody* kickerBase;
	PhysBody* kicker;
	PhysBody* SSLPiston;
	PhysBody* SSRPiston;
	PhysBody* SSLPistonBase;
	PhysBody* SSRPistonBase;
	PhysBody* Trap;
	b2RevoluteJoint* FlipperLJoint;
	b2RevoluteJoint* FlipperRJoint;
	b2RevoluteJoint* trapJoint;

	b2PrismaticJoint* KickerJoint;
	b2PrismaticJoint* SSLJoint;
	b2PrismaticJoint* SSRJoint;
	b2PrismaticJoint* DoorLJoint;
	b2PrismaticJoint* DoorRJoint;

	PhysBody* Hole;
	PhysBody* DoorSensor;

	PhysBody* DeathSensor;
	PhysBody* ignition1;
	PhysBody* ignition2;
	PhysBody* ignition3;

	PhysBody* sun;

	PhysBody* F_sensor;
	PhysBody* U_sensor;
	PhysBody* E_sensor;
	PhysBody* L_sensor;

	PhysBody* sensor500;
	PhysBody* sensor502;

	PhysBody* W_sensor;
	PhysBody* A_sensor;
	PhysBody* R_sensor;
	PhysBody* P_sensor;

	PhysBody* L2_sensor;
	PhysBody* I_sensor;
	PhysBody* G_sensor;
	PhysBody* H_sensor;
	PhysBody* T_sensor;
	PhysBody* Passage_Sensor;
	PhysBody* Blue_sensor;
	PhysBody* Blue_sensor_out;
	PhysBody* Blue_sensor_2;
	PhysBody* Blue_sensor_out_2;

	SDL_Texture* board;
	SDL_Texture* flipper_Left;
	SDL_Texture* flipper_Right;
	SDL_Texture* balltex;
	SDL_Texture* bar_points;

	//Camera
	bool movecam = true;
	// Constants for blit flipper Right
	float Flipper_R_rotation = 0;
	int Flipper_R_positon_x = 0;
	int Flipper_R_positon_y = 0;

	//Constants for blit fliper Left
	float Flipper_L_rotation = 0;
	int Flipper_L_positon_x = 0;
	int Flipper_L_positon_y = 0;


	//Constant for blit puntuation_bar
	
	//Puntuation variables
	int font_puntuation = -1;
	char points[10];
	char lives[10];
	uint balls;

	//Sensor bools
	bool warp, Wlight, Alight, Rlight, Plight, Wactive, Aactive, Ractive, Pactive;
	bool L2active, Iactive, Gactive, Hactive, Tactive;
	uint lightcounter = 1u;
	bool FiveH1, FiveH2;
	bool Factive, Uactive, Eactive, Lactive;
	bool Sun1, Sun2, Sun3, Sun1Reward, Sun2Reward, Sun3Reward;
	uint Suncounter = 1u;
	uint BalltrapCounter = 1u;
	bool Ignition1, Ignition2, Ignition3;
	int ignitionit;
	uint passagecounter;
	uint puntuation;
	int puntuation_x;
	bool end;
	float KickerjointMotor;

	bool sensor_Blue;
	bool sensor_Blue2;
	bool collectFuel;
	bool fivemil;
	bool tenmil;
	bool extraball;
	bool trap;
	int traptimer;
	
	//Animations
	SDL_Texture* fuel;
	SDL_Rect F_fuel;
	SDL_Rect U_fuel;
	SDL_Rect E_fuel;
	SDL_Rect L_fuel;

	SDL_Texture* lights;
	SDL_Rect L_lights;
	SDL_Rect I_lights;
	SDL_Rect G_lights;
	SDL_Rect H_lights;
	SDL_Rect T_lights;

	SDL_Texture* warp_button;
	SDL_Rect W_warp;
	SDL_Rect A_warp;
	SDL_Rect R_warp;
	SDL_Rect P_warp;

	SDL_Texture* ignition_button;
	SDL_Rect Ignition_button;

	SDL_Texture* sun_button;
	SDL_Rect Ssun_button;
	SDL_Rect Usun_button;
	SDL_Rect Nsun_button;

	SDL_Texture* multiplier_button;
	SDL_Rect multiplier_x2;
	SDL_Rect multiplier_x3;
	SDL_Rect multiplier_x4;
	SDL_Rect multiplier_x6;
	SDL_Rect multiplier_x8;

	SDL_Texture* numbers_buttons;
	SDL_Rect number_50;
	SDL_Rect number_100;
	SDL_Rect number_250;
	SDL_Rect number_500;
	SDL_Rect number_750;
	SDL_Rect number_1000;
	SDL_Rect number_2500;

	SDL_Texture* ignition;
	SDL_Rect ignitionRect[9];

	SDL_Texture* Blue_button;
	SDL_Rect blue_button;

	SDL_Texture* Red_square;
	SDL_Rect red_square;

	SDL_Texture* Words;
	SDL_Rect words[6];

	SDL_Texture* Kicker;
	SDL_Rect kickerRect;
	int worditerator;
	int Kickerposy;

	SDL_Texture* arrows;
	SDL_Rect arrowrect[5];
};

